/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:    |
   | http://www.php.net/license/3_01.txt                           |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to   |
   | license@php.net so we can mail you a copy immediately.        |
   +----------------------------------------------------------------------+
*/
#include "hphp/runtime/base/builtin-functions.h"
#include "hphp/runtime/ext/extension.h"

#include <sodium.h>

#include <limits>

#define crypto_kx_BYTES crypto_scalarmult_BYTES
#define crypto_kx_PUBLICKEYBYTES crypto_scalarmult_SCALARBYTES
#define crypto_kx_SECRETKEYBYTES crypto_scalarmult_SCALARBYTES

#ifndef crypto_pwhash_scryptsalsa208sha256_STRPREFIX
#define crypto_pwhash_scryptsalsa208sha256_STRPREFIX "$7$"
#endif

#if defined(crypto_aead_chacha20poly1305_IETF_NPUBBYTES) \
 && !defined(crypto_aead_chacha20poly1305_ietf_NPUBBYTES)
#define crypto_aead_chacha20poly1305_ietf_NPUBBYTES \
  crypto_aead_chacha20poly1305_IETF_NPUBBYTES
#endif

#if defined(crypto_aead_chacha20poly1305_KEYBYTES) \
  && !defined(crypto_aead_chacha20poly1305_ietf_KEYBYTES)
#define crypto_aead_chacha20poly1305_ietf_KEYBYTES \
  crypto_aead_chacha20poly1305_KEYBYTES
#define crypto_aead_chacha20poly1305_ietf_NSECBYTES \
  crypto_aead_chacha20poly1305_NSECBYTES
#define crypto_aead_chacha20poly1305_ietf_ABYTES \
  crypto_aead_chacha20poly1305_ABYTES
#endif

namespace HPHP {

namespace {

const StaticString s_arithmetic_overflow("arithmetic overflow");

[[noreturn]]
void throwSodiumException(const String& message) {
  Array params;
  params.append(message);
  throw_object("SodiumException", params, true /* init */);
}

const StaticString s_non_string_reference(
  "ByRef parameter is not a string"
);

String sodium_separate_string(VRefParam string_ref) {
  if (!string_ref.isString()) {
    throwSodiumException(s_non_string_reference);
  }
  auto string = string_ref.toString();
  auto data = string.get();
  if (!data->hasMultipleRefs()) {
    return string;
  }
  String copy(string, CopyString);
  string_ref.assignIfRef(copy);
  return copy;
}

/* Not just wrapping bin2hex() because sodium_bin2hex() is resistant to timing
 * attacks, while the (faster) standard implementation isn't. */
String HHVM_FUNCTION(sodium_bin2hex,
                     const String& binary) {
  if (binary.size() > StringData::MaxSize / 2) {
    throwSodiumException(s_arithmetic_overflow);
  }

  size_t hex_len = binary.size() * 2;
  String hex = String(hex_len, ReserveString);
  sodium_bin2hex(
    hex.mutableData(),
    hex_len + 1,
    reinterpret_cast<const unsigned char*>(binary.data()),
    binary.size()
  );
  hex.setSize(hex_len);

  return hex;
}

/* Not just wrapping hex2bin() because sodium_bin2hex()
 *  - is resistant to timing attacks, while the (faster) standard implementation
 *    isn't
 *  - supports ignoring certain characters - eg for ipv6:
 *    `sodium_hex2bin('[::1]', '[:]')` === 1`
 */
String HHVM_FUNCTION(sodium_hex2bin,
                     const String& hex,
                     const Variant& /* ?string */ ignore) {
  const size_t hex_len = hex.size();
  const size_t bin_len = hex_len / 2;
  String binary(bin_len, ReserveString);

  const char* ignore_chars = nullptr;
  if (ignore.isString()) {
    ignore_chars = ignore.asCStrRef().data();
  };

  size_t real_bin_len;

  auto result = sodium_hex2bin(
    reinterpret_cast<unsigned char*>(binary.mutableData()),
    bin_len,
    hex.data(),
    hex_len,
    ignore_chars,
    &real_bin_len,
    nullptr
  );
  if (result != 0 || real_bin_len > bin_len) {
    throwSodiumException(s_arithmetic_overflow);
  }
  binary.setSize(real_bin_len);

  return binary;
}

const StaticString s_memzero_needs_string("memzero: a PHP string is required");

void HHVM_FUNCTION(sodium_memzero,
                   VRefParam buffer) {
  if (!buffer.isString()) {
    throwSodiumException(s_memzero_needs_string);
  }
  auto data = buffer.getStringData();
  /* /// Single ref ///
   * $x = 'foo';
   * sodium_memzero($x);
   * // $x is now null, and the memory was securely wiped
   *
   * /// Multiple refs ///
   * $x = 'foo';
   * $y = $x;
   * sodium_memzero($x);
   * // $x is now null; not securely wiped as that would change the value of $y
   * sodium_memzero($y);
   * // $y is now null, and the memory used by $y's stringdata (and previously
   * $x) is now wiped.
   */
  if (data->hasExactlyOneRef() && !data->empty()) {
    sodium_memzero(data->mutableData(), data->size());
  }
  buffer.assignIfRef(init_null());
}

const StaticString s_increment_needs_string(
  "increment(): a PHP string is required"
);

void HHVM_FUNCTION(sodium_increment,
                   VRefParam buffer_ref) {
  if (!buffer_ref.isString()) {
    throwSodiumException(s_increment_needs_string);
  }

  String buffer = sodium_separate_string(buffer_ref);

  if (buffer.empty()) {
    return;
  }

  sodium_increment(
    reinterpret_cast<unsigned char*>(buffer.mutableData()),
    buffer.size()
  );
}

const StaticString
  s_add_needs_string("add(): PHP strings are required"),
  s_add_same_lengths("add(): values must have the same length");

void HHVM_FUNCTION(sodium_add,
                   VRefParam value_ref,
                   const String& add) {
  if (!value_ref.isString()) {
    throwSodiumException(s_add_needs_string);
  }

  String value = sodium_separate_string(value_ref);
  if (value.size() != add.size()) {
    throwSodiumException(s_add_same_lengths);
  }

  sodium_add(
    reinterpret_cast<unsigned char*>(value.mutableData()),
    reinterpret_cast<const unsigned char*>(add.data()),
    value.size()
  );
}

const StaticString s_memcmp_argument_sizes(
  "memcmp(): arguments have different sizes"
);

int64_t HHVM_FUNCTION(sodium_memcmp,
                      const String& a,
                      const String& b) {
  if (a.size() != b.size()) {
    throwSodiumException(s_memcmp_argument_sizes);
  }
  return sodium_memcmp(a.data(), b.data(), a.size());
}

const StaticString s_compare_argument_sizes(
  "compare(): arguments have different sizes"
);

int64_t HHVM_FUNCTION(sodium_compare,
                      const String& a,
                      const String& b) {
  if (a.size() != b.size()) {
    throwSodiumException(s_compare_argument_sizes);
  }

  return sodium_compare(
    reinterpret_cast<const unsigned char*>(a.data()),
    reinterpret_cast<const unsigned char*>(b.data()),
    a.size()
  );
}

const StaticString
  s_crypto_scalarmult_size(
    "crypto_scalarmult(): scalar and point must be "
    "CRYPTO_SCALARMULT_SCALARBYTES bytes"
  ),
  s_crypto_scalarmult_internal_error("crypto_scalarmult(): internal error");

String HHVM_FUNCTION(sodium_crypto_scalarmult,
                     const String& n,
                     const String& p) {
  if (
    n.size() != crypto_scalarmult_SCALARBYTES ||
    p.size() != crypto_scalarmult_SCALARBYTES
  ) {
    throwSodiumException(s_crypto_scalarmult_size);
  }

  String q(crypto_scalarmult_BYTES, ReserveString);
  const auto result = crypto_scalarmult(
    reinterpret_cast<unsigned char*>(q.mutableData()),
    reinterpret_cast<const unsigned char*>(n.data()),
    reinterpret_cast<const unsigned char*>(p.data())
  );
  if (result != 0) {
    throwSodiumException(s_crypto_scalarmult_internal_error);
  }
  q.setSize(crypto_scalarmult_BYTES);
  return q;
}

const StaticString
  s_crypto_generichash_unsupported_output_length(
    "crypto_generichash(): unsupported output length"
  ),
  s_crypto_generichash_unsupported_key_len(
    "crypto_generichash(): unsupported key length"
  ),
  s_crypto_generichash_internal_error(
    "crypto_generichash(): internal error"
  );

String HHVM_FUNCTION(sodium_crypto_generichash,
                     const String& message,
                     const Variant& /* ?string */ key,
                     const Variant& /* ?int */ length) {
  size_t hash_len(crypto_generichash_BYTES);
  if (length.isInteger()) {
    hash_len = length.asInt64Val();
  }

  if (
    hash_len < crypto_generichash_BYTES_MIN ||
    hash_len > crypto_generichash_BYTES_MAX
  ) {
    throwSodiumException(s_crypto_generichash_unsupported_output_length);
  }

  size_t key_len = 0;
  const unsigned char* key_data = nullptr;
  if (key.isString()) {
    key_len = key.asCStrRef().size();
    key_data = reinterpret_cast<const unsigned char*>(key.asCStrRef().data());
  }
  if (
    key_len != 0 && (
      key_len < crypto_generichash_KEYBYTES_MIN ||
      key_len > crypto_generichash_KEYBYTES_MAX
    )
  ) {
    throwSodiumException(s_crypto_generichash_unsupported_key_len);
  }

  String hash = String(hash_len, ReserveString);
  auto result = crypto_generichash(
    reinterpret_cast<unsigned char*>(hash.mutableData()),
    hash_len,
    reinterpret_cast<const unsigned char*>(message.data()),
    message.size(),
    key_data,
    key_len
  );
  if (result != 0) {
    throwSodiumException(s_crypto_generichash_internal_error);
  }
  hash.setSize(hash_len);
  return hash;
}

const StaticString
  s_crypto_generichash_init_unsupported_output_length(
    "crypto_generichash_init(): unsupported output length"
  ),
  s_crypto_generichash_init_unsupported_key_len(
    "crypto_generichash_init(): unsupported key length"
  ),
  s_crypto_generichash_init_internal_error(
    "crypto_generichash_init(): internal error"
  );

String HHVM_FUNCTION(sodium_crypto_generichash_init,
                     const Variant& /* ?string */ key,
                     const Variant& /* ?int */ length) {
  size_t hash_len(crypto_generichash_BYTES);
  if (length.isInteger()) {
    hash_len = length.asInt64Val();
  }

  if (
    hash_len < crypto_generichash_BYTES_MIN ||
    hash_len > crypto_generichash_BYTES_MAX
  ) {
    throwSodiumException(s_crypto_generichash_init_unsupported_output_length);
  }

  size_t key_len = 0;
  const unsigned char* key_data = nullptr;
  if (key.isString()) {
    key_len = key.asCStrRef().size();
    key_data = reinterpret_cast<const unsigned char*>(key.asCStrRef().data());
  }
  if (
    key_len != 0 && (
      key_len < crypto_generichash_KEYBYTES_MIN ||
      key_len > crypto_generichash_KEYBYTES_MAX
    )
  ) {
    throwSodiumException(s_crypto_generichash_init_unsupported_key_len);
  }

  crypto_generichash_state state_tmp;
  auto result = crypto_generichash_init(
    &state_tmp,
    key_data,
    key_len,
    hash_len
  );
  if (result != 0) {
    throwSodiumException(s_crypto_generichash_init_internal_error);
  }

  size_t state_len = sizeof(crypto_generichash_state);
  String state(state_len, ReserveString);
  memcpy(state.mutableData(), &state_tmp, state_len);
  state.setSize(state_len);
  sodium_memzero(&state_tmp, state_len);
  return state;
}

const StaticString
  s_crypto_generichash_update_state_reference_required(
    "crypto_generichash_update(): a reference to a state is required"
  ),
  s_crypto_generichash_update_incorrect_state_length(
    "crypto_generichash_update(): incorrect state length"
  ),
  s_crypto_generichash_update_internal_error(
    "crypto_generichash_update(): internal_error"
  );

bool HHVM_FUNCTION(sodium_crypto_generichash_update,
                   VRefParam /* string& */ state_ref,
                   const String& msg) {
  if (!state_ref.isString()) {
    throwSodiumException(s_crypto_generichash_update_state_reference_required);
  }

  auto state = sodium_separate_string(state_ref);
  size_t state_len = sizeof(crypto_generichash_state);
  if (state.size() != state_len) {
    throwSodiumException(s_crypto_generichash_update_incorrect_state_length);
  }

  crypto_generichash_state state_tmp;
  memcpy(&state_tmp, state.data(), state_len);
  auto result = crypto_generichash_update(
    &state_tmp,
    reinterpret_cast<const unsigned char*>(msg.data()),
    msg.size()
  );
  if (result != 0) {
    throwSodiumException(s_crypto_generichash_update_internal_error);
  }
  memcpy(state.mutableData(), &state_tmp, state_len);
  sodium_memzero(&state_tmp, state_len);
  return true;
}

const StaticString
  s_crypto_generichash_final_state_reference_required(
    "crypto_generichash_final(): a reference to a state is required"
  ),
  s_crypto_generichash_final_incorrect_state_length(
    "crypto_generichash_final(): incorrect state length"
  ),
  s_crypto_generichash_final_unsupported_output_length(
    "crypto_generichash_final(): unsupported output length"
  ),
  s_crypto_generichash_final_internal_error(
    "crypto_generichash_final(): internal_error"
  );
String HHVM_FUNCTION(sodium_crypto_generichash_final,
                     VRefParam /* string& */ state_ref,
                     const Variant& /* ?int */ length) {
  if (!state_ref.isString()) {
    throwSodiumException(s_crypto_generichash_final_state_reference_required);
  }

  auto state = sodium_separate_string(state_ref);
  size_t state_len = sizeof(crypto_generichash_state);
  if (state.size() != state_len) {
    throwSodiumException(s_crypto_generichash_final_incorrect_state_length);
  }

  size_t hash_len = crypto_generichash_BYTES;
  if (length.isInteger()) {
    hash_len = length.asInt64Val();
  }
  if (
    hash_len < crypto_generichash_BYTES_MIN ||
    hash_len > crypto_generichash_BYTES_MAX
  ) {
    throwSodiumException(s_crypto_generichash_final_unsupported_output_length);
  }

  String hash(hash_len, ReserveString);
  crypto_generichash_state state_tmp;
  memcpy(&state_tmp, state.data(), state_len);
  auto result = crypto_generichash_final(
    &state_tmp,
    reinterpret_cast<unsigned char*>(hash.mutableData()),
    hash_len
  );
  if (result != 0) {
    throwSodiumException(s_crypto_generichash_final_internal_error);
  }
  hash.setSize(hash_len);

  sodium_memzero(state.mutableData(), state_len);
  state_ref.assignIfRef(init_null());

  return hash;
}

const StaticString
  s_shorthash_key_size(
    "crypto_shorthash(): key size should be CRYPTO_SHORTHASH_KEYBYTES bytes"
  ),
  s_shorthash_internal_error(
    "crypto_shorthash(): internal error"
  );

String HHVM_FUNCTION(sodium_crypto_shorthash,
                     const String& message,
                     const String& key) {
  if (key.size() != crypto_shorthash_KEYBYTES) {
    throwSodiumException(s_shorthash_key_size);
  }
  String hash(crypto_shorthash_BYTES, ReserveString);
  const auto result = crypto_shorthash(
    reinterpret_cast<unsigned char*>(hash.mutableData()),
    reinterpret_cast<const unsigned char*>(message.data()),
    message.size(),
    reinterpret_cast<const unsigned char*>(key.data())
  );
  if (result != 0) {
   throwSodiumException(s_shorthash_internal_error);
  }
  hash.setSize(crypto_shorthash_BYTES);
  return hash;
}

#ifdef crypto_pwhash_SALTBYTES
const StaticString
  s_pwhash_salt_size("salt should be CRYPTO_PWHASH_SALTBYTES bytes"),
  s_pwhash_internal_error("crypto_pwhash(): internal error");

String HHVM_FUNCTION(sodium_crypto_pwhash,
                     int64_t hash_len,
                     const String& password,
                     const String& salt,
                     int64_t opslimit,
                     int64_t memlimit) {
  if (password.empty()) {
    raise_warning("empty password");
  }
  if (salt.size() != crypto_pwhash_SALTBYTES) {
    throwSodiumException(s_pwhash_salt_size);
  }
  if (opslimit < crypto_pwhash_OPSLIMIT_INTERACTIVE) {
    raise_warning("number of operations for the argon2i function is low");
  }
  if (memlimit < crypto_pwhash_MEMLIMIT_INTERACTIVE) {
    raise_warning("maximum memory for the argon2i function is low");
  }

  String hash(hash_len, ReserveString);
  const auto result = crypto_pwhash(
    reinterpret_cast<unsigned char*>(hash.mutableData()),
    hash_len,
    password.data(),
    password.size(),
    reinterpret_cast<const unsigned char*>(salt.data()),
    opslimit,
    memlimit,
    crypto_pwhash_alg_default()
  );
  if (result != 0) {
    throwSodiumException(s_pwhash_internal_error);
  }
  hash.setSize(hash_len);
  return hash;
}

const StaticString s_pwhash_str_internal_error(
  "crypto_pwhash_str(): internal error"
);

String HHVM_FUNCTION(sodium_crypto_pwhash_str,
                     const String& password,
                     int64_t opslimit,
                     int64_t memlimit) {
  if (password.empty()) {
    raise_warning("empty password");
  }
  if (opslimit < crypto_pwhash_OPSLIMIT_INTERACTIVE) {
    raise_warning("number of operations for the argon2i function is low");
  }
  if (memlimit < crypto_pwhash_MEMLIMIT_INTERACTIVE) {
    raise_warning("maximum memory for the argon2i function is low");
  }

  const size_t hash_len = crypto_pwhash_STRBYTES - 1;
  String hash(hash_len, ReserveString);
  const auto result = crypto_pwhash_str(
    reinterpret_cast<char*>(hash.mutableData()),
    password.data(),
    password.size(),
    opslimit,
    memlimit
  );
  if (result != 0) {
    throwSodiumException(s_pwhash_str_internal_error);
  }
  // This is a printable string: the binary data is already base64-encoded by
  // libsodium
  hash.setSize(strlen(hash.data()));
  return hash;
}

bool HHVM_FUNCTION(sodium_crypto_pwhash_str_verify,
                   const String& hash,
                   const String& password) {
  if (password.empty()) {
    raise_warning("empty password");
  }
  const auto result = crypto_pwhash_str_verify(
    hash.data(),
    password.data(),
    password.size()
  );
  return result == 0;
}
#endif // crypto_pwhash_SALTBYTES

const StaticString
  s_pwhash_scrypt_bad_salt_size(
    "crypto_pwhash_scryptsalsa208sha256(): "
    "salt should be CRYPTO_PWHASH_SCRYPTSALSA208SHA256_SALTBYTES bytes"
  ),
  s_pwhash_scrypt_internal_error(
    "crypto_pwhash_scryptsalsa208sha256(): internal error"
  );

String HHVM_FUNCTION(sodium_crypto_pwhash_scryptsalsa208sha256,
                     int64_t length,
                     const String& password,
                     const String& salt,
                     int64_t opslimit,
                     int64_t memlimit) {
  if (password.empty()) {
    raise_warning("empty password");
  }
  if (salt.size() != crypto_pwhash_scryptsalsa208sha256_SALTBYTES) {
    throwSodiumException(s_pwhash_scrypt_bad_salt_size);
  }
  if (opslimit < crypto_pwhash_scryptsalsa208sha256_opslimit_interactive()) {
    raise_warning("number of operations for the scrypt function is low");
  }
  if (memlimit < crypto_pwhash_scryptsalsa208sha256_memlimit_interactive()) {
    raise_warning("maximum memory for the scrypt function is low");
  }

  String hash(length, ReserveString);
  const auto result = crypto_pwhash_scryptsalsa208sha256(
    reinterpret_cast<unsigned char*>(hash.mutableData()),
    length,
    password.data(),
    password.size(),
    reinterpret_cast<const unsigned char*>(salt.data()),
    opslimit,
    memlimit
  );
  if (result != 0) {
    throwSodiumException(s_pwhash_scrypt_internal_error);
  }
  hash.setSize(length);
  return hash;
}

const StaticString
  s_pwhash_scrypt_str_internal_error(
    "crypto_pwhash_scryptsalsa208sha256_str(): internal error"
  );

String HHVM_FUNCTION(sodium_crypto_pwhash_scryptsalsa208sha256_str,
                     const String& password,
                     int64_t opslimit,
                     int64_t memlimit) {
  if (password.empty()) {
    raise_warning("empty password");
  }
  if (opslimit < crypto_pwhash_scryptsalsa208sha256_opslimit_interactive()) {
    raise_warning("number of operations for the scrypt function is low");
  }
  if (memlimit < crypto_pwhash_scryptsalsa208sha256_memlimit_interactive()) {
    raise_warning("maximum memory for the scrypt function is low");
  }

  String hash(crypto_pwhash_scryptsalsa208sha256_STRBYTES - 1, ReserveString);
  const auto result = crypto_pwhash_scryptsalsa208sha256_str(
    hash.mutableData(),
    password.data(),
    password.size(),
    opslimit,
    memlimit
  );
  if (result != 0) {
    throwSodiumException(s_pwhash_scrypt_str_internal_error);
  }
  hash.setSize(crypto_pwhash_scryptsalsa208sha256_STRBYTES - 1);
  return hash;
}

bool HHVM_FUNCTION(
  sodium_crypto_pwhash_scryptsalsa208sha256_str_verify,
  const String& hash,
  const String& password
) {
  if (password.empty()) {
    raise_warning("empty password");
  }
  if (hash.size() != crypto_pwhash_scryptsalsa208sha256_STRBYTES - 1) {
    raise_warning("wrong size for the hashed password");
    return false;
  }

  const auto result = crypto_pwhash_scryptsalsa208sha256_str_verify(
    hash.data(),
    password.data(),
    password.size()
  );
  return result == 0;
}

const StaticString
  s_crypto_auth_key_size(
   "crypto_auth(): key must be CRYPTO_AUTH_KEYBYTES bytes"
  ),
  s_crypto_auth_internal_error(
   "crypto_auth(): internal error"
  );

String HHVM_FUNCTION(sodium_crypto_auth,
                    const String& message,
                    const String& key) {
  if (key.size() != crypto_auth_KEYBYTES) {
   throwSodiumException(s_crypto_auth_key_size);
  }
  String mac(crypto_auth_BYTES, ReserveString);
  const auto result = crypto_auth(
   reinterpret_cast<unsigned char*>(mac.mutableData()),
   reinterpret_cast<const unsigned char*>(message.data()),
   message.size(),
   reinterpret_cast<const unsigned char*>(key.data())
  );
  if (result != 0) {
   throwSodiumException(s_crypto_auth_internal_error);
  }
  mac.setSize(crypto_auth_BYTES);
  return mac;
}

const StaticString
  s_crypto_auth_verify_key_size(
   "crypto_auth_verify(): key must be CRYPTO_AUTH_KEYBYTES bytes"
  ),
  s_crypto_auth_mac_size(
   "crypto_auth_verify(): authentication tag must be CRYPTO_AUTH_BYTES bytes"
  ),
  s_crypto_auth_verify_internal_error(
   "crypto_auth_verify(): internal error"
  );

bool HHVM_FUNCTION(sodium_crypto_auth_verify,
                   const String& mac,
                   const String& message,
                   const String& key) {
  if (key.size() != crypto_auth_KEYBYTES) {
   throwSodiumException(s_crypto_auth_verify_key_size);
  }
  if (mac.size() != crypto_auth_BYTES) {
   throwSodiumException(s_crypto_auth_mac_size);
  }
  const auto result = crypto_auth_verify(
   reinterpret_cast<const unsigned char*>(mac.data()),
   reinterpret_cast<const unsigned char*>(message.data()),
   message.size(),
   reinterpret_cast<const unsigned char*>(key.data())
  );
  return (result == 0);
}

const StaticString
  s_crypto_secretbox_nonce_size(
    "crypto_secretbox(): nonce size should be CRYPTO_SECRETBOX_NONCEBYTES bytes"
  ),
  s_crypto_secretbox_key_size(
    "crypto_secretbox(): key size should be CRYPTO_SECRETBOX_KEYBYTES bytes"
  ),
  s_crypto_secretbox_internal_error(
    "crypto_secretbox(): internal error"
  );

String HHVM_FUNCTION(sodium_crypto_secretbox,
                     const String& plaintext,
                     const String& nonce,
                     const String& key) {
  if (nonce.size() != crypto_secretbox_NONCEBYTES) {
    throwSodiumException(s_crypto_secretbox_nonce_size);
  }
  if (key.size() != crypto_secretbox_KEYBYTES) {
    throwSodiumException(s_crypto_secretbox_key_size);
  }
  if (
    StringData::MaxSize - plaintext.size()
      <= crypto_secretbox_MACBYTES
  ) {
    throwSodiumException(s_arithmetic_overflow);
  }

  const size_t ciphertext_len = plaintext.size() + crypto_secretbox_MACBYTES;
  String ciphertext(ciphertext_len, ReserveString);
  const auto result = crypto_secretbox_easy(
    reinterpret_cast<unsigned char*>(ciphertext.mutableData()),
    reinterpret_cast<const unsigned char*>(plaintext.data()),
    plaintext.size(),
    reinterpret_cast<const unsigned char*>(nonce.data()),
    reinterpret_cast<const unsigned char*>(key.data())
  );
  if (result != 0) {
    throwSodiumException(s_crypto_secretbox_internal_error);
  }
  ciphertext.setSize(ciphertext_len);
  return ciphertext;
}

const StaticString
  s_crypto_secretbox_open_nonce_size(
    "crypto_secretbox_open(): nonce size should be CRYPTO_SECRETBOX_NONCEBYTES "
    "bytes"
  ),
  s_crypto_secretbox_open_key_size(
    "crypto_secretbox_open(): key size should be CRYPTO_SECRETBOX_KEYBYTES "
    "bytes"
  );

Variant HHVM_FUNCTION(sodium_crypto_secretbox_open,
                      const String& ciphertext,
                      const String& nonce,
                      const String& key) {
  if (nonce.size() != crypto_secretbox_NONCEBYTES) {
    throwSodiumException(s_crypto_secretbox_open_nonce_size);
  }
  if (key.size() != crypto_secretbox_KEYBYTES) {
    throwSodiumException(s_crypto_secretbox_open_key_size);
  }
  if (ciphertext.size() < crypto_secretbox_MACBYTES) {
    return false;
  }

  size_t plaintext_len = ciphertext.size() - crypto_secretbox_MACBYTES;
  String plaintext(plaintext_len, ReserveString);
  const auto result = crypto_secretbox_open_easy(
    reinterpret_cast<unsigned char*>(plaintext.mutableData()),
    reinterpret_cast<const unsigned char*>(ciphertext.data()),
    ciphertext.size(),
    reinterpret_cast<const unsigned char*>(nonce.data()),
    reinterpret_cast<const unsigned char*>(key.data())
  );
  if (result != 0) {
    return false;
  }
  plaintext.setSize(plaintext_len);
  return plaintext;
}

const StaticString s_crypto_box_keypair_internal_error(
  "crypto_box_keypair(): internal error"
);

String HHVM_FUNCTION(sodium_crypto_box_keypair) {
  // Doing this construction to avoid leaving the secret key in memory
  // somewhere when using temporaries
  const size_t keypair_len =
    crypto_box_SECRETKEYBYTES + crypto_box_PUBLICKEYBYTES;
  String keypair(keypair_len, ReserveString);
  auto secret_key = reinterpret_cast<unsigned char*>(
    keypair.mutableData()
  );
  auto public_key = secret_key + crypto_box_SECRETKEYBYTES;

  const auto result = crypto_box_keypair(
    public_key,
    secret_key
  );

  if (result != 0) {
    throwSodiumException(s_crypto_box_keypair_internal_error);
  }
  keypair.setSize(keypair_len);
  return keypair;
}

const StaticString
  s_crypto_box_seed_keypair_seed_size(
    "crypto_box_seed_keypair(): seed should be CRYPTO_BOX_SEEDBYTES bytes"
  ),
  s_crypto_box_seed_internal_error(
    "crypto_box_seed_keypair(): internal error"
  );

String HHVM_FUNCTION(sodium_crypto_box_seed_keypair,
                     const String& seed) {
  if (seed.size() != crypto_box_SEEDBYTES) {
    throwSodiumException(s_crypto_box_seed_keypair_seed_size);
  }

  // Doing this construction to avoid leaving the secret key in memory
  // somewhere when using temporaries
  const size_t keypair_len =
   crypto_box_SECRETKEYBYTES + crypto_box_PUBLICKEYBYTES;
  String keypair(keypair_len, ReserveString);
  unsigned char* public_key = reinterpret_cast<unsigned char*>(
    keypair.mutableData() + crypto_box_SECRETKEYBYTES
  );
  unsigned char* secret_key = reinterpret_cast<unsigned char*>(
    keypair.mutableData()
  );

  const auto result = crypto_box_seed_keypair(
    public_key,
    secret_key,
    reinterpret_cast<const unsigned char*>(seed.data())
  );
  if (result != 0) {
    throwSodiumException(s_crypto_box_seed_internal_error);
  }
  keypair.setSize(keypair_len);
  return keypair;
}

const StaticString s_crypto_box_publickey_from_secretkey_key_size(
  "crypto_box_seed_publickey_from_secretkey(): key should be "
  "CRYPTO_BOX_SECRETKEYBYTES bytes"
);

String HHVM_FUNCTION(sodium_crypto_box_publickey_from_secretkey,
                     const String& secretkey) {
  if (secretkey.size() != crypto_box_SECRETKEYBYTES) {
    throwSodiumException(s_crypto_box_publickey_from_secretkey_key_size);
  }

  String publickey(crypto_box_PUBLICKEYBYTES, ReserveString);

  static_assert(crypto_scalarmult_BYTES == crypto_box_PUBLICKEYBYTES, "");
  static_assert(crypto_scalarmult_SCALARBYTES == crypto_box_SECRETKEYBYTES, "");
  crypto_scalarmult_base(
    reinterpret_cast<unsigned char*>(publickey.mutableData()),
    reinterpret_cast<const unsigned char*>(secretkey.data())
  );

  publickey.setSize(crypto_box_PUBLICKEYBYTES);
  return publickey;
}

const StaticString
  s_crypto_kx_secret_key_size(
    "crypto_kx(): secret key must be CRYPTO_KX_SECRETKEY bytes"
  ),
  s_crypto_kx_public_key_size(
    "crypto_kx(): public keys must be CRYPTO_KX_PUBLICKEY bytes"
  ),
  s_crypto_kx_internal_error(
    "crypto_kx(): internal error"
  );

String HHVM_FUNCTION(sodium_crypto_kx,
                     const String& secretkey,
                     const String& publickey,
                     const String& client_publickey,
                     const String& server_publickey) {
  if (secretkey.size() != crypto_kx_SECRETKEYBYTES) {
    throwSodiumException(s_crypto_kx_secret_key_size);
  }
  if (
    publickey.size() != crypto_kx_PUBLICKEYBYTES ||
    client_publickey.size() != crypto_kx_PUBLICKEYBYTES ||
    server_publickey.size() != crypto_kx_PUBLICKEYBYTES
  ) {
    throwSodiumException(s_crypto_kx_public_key_size);
  }

  static_assert(crypto_scalarmult_SCALARBYTES == crypto_kx_PUBLICKEYBYTES, "");
  static_assert(crypto_scalarmult_SCALARBYTES == crypto_kx_SECRETKEYBYTES, "");

  unsigned char q[crypto_scalarmult_BYTES];
  const auto result = crypto_scalarmult(
    q,
    reinterpret_cast<const unsigned char*>(secretkey.data()),
    reinterpret_cast<const unsigned char*>(publickey.data())
  );
  if (result != 0) {
    throwSodiumException(s_crypto_kx_internal_error);
  }

  String sharedkey(crypto_kx_BYTES, ReserveString);
  crypto_generichash_state state;
  crypto_generichash_init(&state, nullptr, 0, crypto_generichash_BYTES);
  crypto_generichash_update(&state, q, sizeof q);
  sodium_memzero(q, sizeof q);
  crypto_generichash_update(
    &state,
    reinterpret_cast<const unsigned char*>(client_publickey.data()),
    client_publickey.size()
  );
  crypto_generichash_update(
    &state,
    reinterpret_cast<const unsigned char*>(server_publickey.data()),
    server_publickey.size()
  );
  crypto_generichash_final(
    &state,
    reinterpret_cast<unsigned char*>(sharedkey.mutableData()),
    crypto_kx_BYTES
  );
  sharedkey.setSize(crypto_kx_BYTES);
  return sharedkey;
}


const StaticString
  s_crypto_box_nonce_size(
    "crypto_box(): nonce size should be CRYPTO_BOX_NONCEBYTES bytes"
  ),
  s_crypto_box_keypair_size(
    "crypto_box(): keypair size should be CRYPTO_BOX_KEYPAIRBYTES bytes"
  ),
  s_crypto_box_internal_error(
    "crypto_box(): internal error"
  );

String HHVM_FUNCTION(sodium_crypto_box,
                     const String& plaintext,
                     const String& nonce,
                     const String& keypair) {
  if (nonce.size() != crypto_box_NONCEBYTES) {
    throwSodiumException(s_crypto_box_nonce_size);
  }
  if (keypair.size() != crypto_box_SECRETKEYBYTES + crypto_box_PUBLICKEYBYTES) {
    throwSodiumException(s_crypto_box_keypair_size);
  }

  auto secretkey = reinterpret_cast<const unsigned char*>(
    keypair.data()
  );
  auto publickey = secretkey + crypto_box_SECRETKEYBYTES;

  if (
    StringData::MaxSize - plaintext.size() <= crypto_box_MACBYTES
  ) {
    throwSodiumException(s_arithmetic_overflow);
  }

  String ciphertext(plaintext.size() + crypto_box_MACBYTES, ReserveString);
  const auto result = crypto_box_easy(
    reinterpret_cast<unsigned char*>(ciphertext.mutableData()),
    reinterpret_cast<const unsigned char*>(plaintext.data()),
    plaintext.size(),
    reinterpret_cast<const unsigned char*>(nonce.data()),
    publickey,
    secretkey
  );
  if (result != 0) {
    throwSodiumException(s_crypto_box_internal_error);
  }
  ciphertext.setSize(plaintext.size() + crypto_box_MACBYTES);
  return ciphertext;
}

const StaticString
  s_crypto_box_open_nonce_size(
    "crypto_box_open(): nonce size should be CRYPTO_BOX_NONCEBYTES bytes"
  ),
  s_crypto_box_open_keypair_size(
    "crypto_box_open(): keypair size should be CRYPTO_BOX_KEYPAIRBYTES bytes"
  );

Variant HHVM_FUNCTION(sodium_crypto_box_open,
                     const String& ciphertext,
                     const String& nonce,
                     const String& keypair) {
  if (nonce.size() != crypto_box_NONCEBYTES) {
    throwSodiumException(s_crypto_box_open_nonce_size);
  }
  if (keypair.size() != crypto_box_SECRETKEYBYTES + crypto_box_PUBLICKEYBYTES) {
    throwSodiumException(s_crypto_box_open_keypair_size);
  }
  if (ciphertext.size() < crypto_box_MACBYTES) {
    return false;
  }

  auto secretkey = reinterpret_cast<const unsigned char*>(
    keypair.data()
  );
  auto publickey = reinterpret_cast<const unsigned char*>(
    keypair.data() + crypto_box_SECRETKEYBYTES
  );

  String plaintext(ciphertext.size() - crypto_box_MACBYTES, ReserveString);
  const auto result = crypto_box_open_easy(
    reinterpret_cast<unsigned char*>(plaintext.mutableData()),
    reinterpret_cast<const unsigned char*>(ciphertext.data()),
    ciphertext.size(),
    reinterpret_cast<const unsigned char*>(nonce.data()),
    publickey,
    secretkey
  );
  if (result != 0) {
    return false;
  }
  plaintext.setSize(ciphertext.size() - crypto_box_MACBYTES);
  return plaintext;
}

#ifdef crypto_box_SEALBYTES

const StaticString
  s_crypto_box_seal_key_size(
    "crypto_box_seal(): public key size should be "
    "CRYPTO_BOX_PUBLICKEYBYTES bytes"
  ),
  s_crypto_box_seal_internal_error(
    "crypto_box_seal(): internal error"
  );
String HHVM_FUNCTION(sodium_crypto_box_seal,
                     const String& plaintext,
                     const String& publickey) {
  if (publickey.size() != crypto_box_PUBLICKEYBYTES) {
    throwSodiumException(s_crypto_box_seal_key_size);
  }
  if (
    StringData::MaxSize - plaintext.size()
      <= crypto_box_SEALBYTES
  ) {
    throwSodiumException(s_arithmetic_overflow);
  }

  const size_t ciphertext_len = plaintext.size() + crypto_box_SEALBYTES;
  String ciphertext(ciphertext_len, ReserveString);
  const auto result = crypto_box_seal(
    reinterpret_cast<unsigned char*>(ciphertext.mutableData()),
    reinterpret_cast<const unsigned char*>(plaintext.data()),
    plaintext.size(),
    reinterpret_cast<const unsigned char*>(publickey.data())
  );
  if (result != 0) {
    throwSodiumException(s_crypto_box_seal_internal_error);
  }
  ciphertext.setSize(ciphertext_len);
  return ciphertext;
}

const StaticString
  s_crypto_box_seal_open_keypair_size(
    "crypto_box_seal_open(): keypair size should be CRYPTO_BOX_KEYPAIRBYTES "
    "bytes"
  );

Variant HHVM_FUNCTION(sodium_crypto_box_seal_open,
                     const String& ciphertext,
                     const String& keypair) {
  if (keypair.size() != crypto_box_SECRETKEYBYTES + crypto_box_PUBLICKEYBYTES) {
    throwSodiumException(s_crypto_box_seal_open_keypair_size);
  }
  if (ciphertext.size() < crypto_box_SEALBYTES) {
    return false;
  }

  auto secretkey = reinterpret_cast<const unsigned char*>(
    keypair.data()
  );
  auto publickey = reinterpret_cast<const unsigned char*>(
    keypair.data() + crypto_box_SECRETKEYBYTES
  );

  const size_t plaintext_len = ciphertext.size() - crypto_box_SEALBYTES;
  String plaintext(plaintext_len, ReserveString);
  const auto result = crypto_box_seal_open(
    reinterpret_cast<unsigned char*>(plaintext.mutableData()),
    reinterpret_cast<const unsigned char*>(ciphertext.data()),
    ciphertext.size(),
    publickey,
    secretkey
  );
  if (result != 0) {
    return false;
  }
  plaintext.setSize(plaintext_len);
  return plaintext;
}
#endif // crypto_box_SEALBYTES

const StaticString s_crypto_sign_keypair_internal_error(
  "crypto_sign_keypair(): internal error"
);

String HHVM_FUNCTION(sodium_crypto_sign_keypair) {
  // Using this construction to avoid leaving secretkey in memory somewhere from
  // a temporary variable
  const size_t keypair_size =
   crypto_sign_SECRETKEYBYTES + crypto_sign_PUBLICKEYBYTES;
  String keypair(keypair_size, ReserveString);
  auto secretkey = reinterpret_cast<unsigned char*>(keypair.mutableData());
  auto publickey = secretkey + crypto_sign_SECRETKEYBYTES;

  const auto result = crypto_sign_keypair(
    publickey,
    secretkey
  );
  if (result != 0) {
    throwSodiumException(s_crypto_sign_keypair_internal_error);
  }
  keypair.setSize(keypair_size);
  return keypair;
}

const StaticString
  s_crypto_sign_seed_keypair_seed_size(
    "crypto_sign_seed_keypair(): seed should be CRYPTO_SIGN_SEEDBYTES bytes"
  ),
  s_crypto_sign_seed_keypair_internal_error(
    "crypto_sign_seed_keypair(): internal error"
  );

String HHVM_FUNCTION(sodium_crypto_sign_seed_keypair,
                     const String& seed) {
  if (seed.size() != crypto_sign_SEEDBYTES) {
    throwSodiumException(s_crypto_sign_seed_keypair_seed_size);
  }

  // Using this construction to avoid leaving secretkey in memory somewhere from
  // a temporary variable
  const size_t keypair_size =
    crypto_sign_SECRETKEYBYTES + crypto_sign_PUBLICKEYBYTES;
  String keypair(keypair_size, ReserveString);
  auto secretkey = reinterpret_cast<unsigned char*>(keypair.mutableData());
  auto publickey = secretkey + crypto_sign_SECRETKEYBYTES;

  const auto result = crypto_sign_seed_keypair(
    publickey,
    secretkey,
    reinterpret_cast<const unsigned char*>(seed.data())
  );
  if (result != 0) {
    throwSodiumException(s_crypto_sign_seed_keypair_internal_error);
  }
  keypair.setSize(keypair_size);
  return keypair;
}

const StaticString
  s_crypto_sign_publickey_from_secretkey_size(
    "crypto_sign_publickey_from_secretkey(): secretkey should be "
    "CRYPTO_SIGN_SECRETKEYBYTES bytes"
  ),
  s_crypto_sign_publickey_from_secretkey_internal_error(
    "crypto_sign_publickey_from_secretkey(): internal error"
  );

String HHVM_FUNCTION(sodium_crypto_sign_publickey_from_secretkey,
                     const String& secretkey) {
  if (secretkey.size() != crypto_sign_SECRETKEYBYTES) {
    throwSodiumException(s_crypto_sign_publickey_from_secretkey_size);
  }

  String publickey(crypto_sign_PUBLICKEYBYTES, ReserveString);
  const auto result = crypto_sign_ed25519_sk_to_pk(
    reinterpret_cast<unsigned char*>(publickey.mutableData()),
    reinterpret_cast<const unsigned char*>(secretkey.data())
  );
  if (result != 0) {
    throwSodiumException(s_crypto_sign_publickey_from_secretkey_internal_error);
  }
  publickey.setSize(crypto_sign_PUBLICKEYBYTES);
  return publickey;
}

const StaticString
  s_crypto_sign_key_size(
    "crypto_sign(): secret key size should be CRYPTO_SIGN_SECRETKEYBYTES bytes"
  ),
  s_crypto_sign_internal_error(
    "crypto_sign(): internal_error"
  );

String HHVM_FUNCTION(sodium_crypto_sign,
                     const String& message,
                     const String& secretkey) {
  if (secretkey.size() != crypto_sign_SECRETKEYBYTES) {
    throwSodiumException(s_crypto_sign_key_size);
  }
  if (
    StringData::MaxSize - message.size() <= crypto_sign_BYTES
  ) {
    throwSodiumException(s_arithmetic_overflow);
  }

  const size_t signed_message_buffer_size = message.size() + crypto_sign_BYTES;
  unsigned long long signed_message_len;
  String signed_message(signed_message_buffer_size, ReserveString);
  const auto result = crypto_sign(
    reinterpret_cast<unsigned char*>(signed_message.mutableData()),
    &signed_message_len,
    reinterpret_cast<const unsigned char*>(message.data()),
    message.size(),
    reinterpret_cast<const unsigned char*>(secretkey.data())
  );
  if (result != 0) {
    throwSodiumException(s_crypto_sign_internal_error);
  }

  if (
    signed_message_len == 0 ||
    signed_message_len >= StringData::MaxSize ||
    signed_message_len > signed_message_buffer_size
  ) {
    throwSodiumException(s_arithmetic_overflow);
  }
  signed_message.setSize(signed_message_len);
  return signed_message;
}

const StaticString s_crypto_sign_open_key_size(
  "crypto_sign_open(): public key size should be CRYPTO_SIGN_PUBLICKEYBYTES "
  "bytes"
);

Variant HHVM_FUNCTION(sodium_crypto_sign_open,
                      const String& signed_message,
                      const String& publickey) {
  if (publickey.size() != crypto_sign_PUBLICKEYBYTES) {
    throwSodiumException(s_crypto_sign_open_key_size);
  }

  String message(signed_message.size(), ReserveString);
  unsigned long long message_len;
  const auto result = crypto_sign_open(
    reinterpret_cast<unsigned char*>(message.mutableData()),
    &message_len,
    reinterpret_cast<const unsigned char*>(signed_message.data()),
    signed_message.size(),
    reinterpret_cast<const unsigned char*>(publickey.data())
  );
  if (result != 0) {
    return false;
  }

  if (
    message_len >= StringData::MaxSize ||
    message_len > signed_message.size()
  ) {
    throwSodiumException(s_arithmetic_overflow);
  }
  message.setSize(message_len);
  return message;
}

const StaticString
  s_crypto_sign_detached_key_size(
    "crypto_sign_detached(): secret key size should be "
    "CRYPTO_SIGN_SECRETKEYBYTES bytes"
  ),
  // Inconsistent: https://github.com/jedisct1/libsodium-php/issues/122
  s_crypto_sign_detached_internal_error(
    "crypto_sign_detached(): internal_error"
  ),
  // Inconsistent: https://github.com/jedisct1/libsodium-php/issues/122
  s_crypto_sign_detached_signature_size(
    "crypto_sign_detached(): signature has a bogus size"
  );

String HHVM_FUNCTION(sodium_crypto_sign_detached,
                     const String& message,
                     const String& secretkey) {
  if (secretkey.size() != crypto_sign_SECRETKEYBYTES) {
    throwSodiumException(s_crypto_sign_detached_key_size);
  }
  if (
    StringData::MaxSize - message.size() <= crypto_sign_BYTES
  ) {
    throwSodiumException(s_arithmetic_overflow);
  }

  static_assert(crypto_sign_BYTES < StringData::MaxSize, "");

  String signature(crypto_sign_BYTES, ReserveString);
  signature.setSize(crypto_sign_BYTES);
  bzero(signature.mutableData(), crypto_sign_BYTES);

  unsigned long long signature_len;
  const auto result = crypto_sign_detached(
    reinterpret_cast<unsigned char*>(signature.mutableData()),
    &signature_len,
    reinterpret_cast<const unsigned char*>(message.data()),
    message.size(),
    reinterpret_cast<const unsigned char*>(secretkey.data())
  );
  if (result != 0) {
    throwSodiumException(s_crypto_sign_detached_internal_error);
  }

  if (
    signature_len == 0 ||
    signature_len > crypto_sign_BYTES
  ) {
    throwSodiumException(s_crypto_sign_detached_signature_size);
  }

  // Intentionally returning a signatured that is crypto_sign_BYTES long instead
  // of signature_len: this has always been required by
  // sodium_crypto_sign_verify_detached(), so this just avoids the need for
  // end-users to pad with null bytes.

  return signature;
}

const StaticString
  s_crypto_sign_verify_detached_signature_size(
    "crypto_sign_verify_detached(): signature size should be "
    "CRYPTO_SIGN_BYTES bytes"
  ),
  s_crypto_sign_verify_detached_key_size(
    "crypto_sign_verify_detached(): public key size should be "
    "CRYPTO_SIGN_PUBLICKEYBYTES bytes"
  );

bool HHVM_FUNCTION(sodium_crypto_sign_verify_detached,
                     const String& signature,
                     const String& message,
                     const String& publickey) {
  if (signature.size() != crypto_sign_BYTES) {
    throwSodiumException(s_crypto_sign_verify_detached_signature_size);
  }
  if (publickey.size() != crypto_sign_PUBLICKEYBYTES) {
    throwSodiumException(s_crypto_sign_verify_detached_key_size);
  }

  const auto result = crypto_sign_verify_detached(
    reinterpret_cast<const unsigned char*>(signature.data()),
    reinterpret_cast<const unsigned char*>(message.data()),
    message.size(),
    reinterpret_cast<const unsigned char*>(publickey.data())
  );
  return result == 0;
}

const StaticString
  s_sign_sk_to_box_sk_key_size(
    "crypto_sign_ed25519_sk_to_curve25519(): Ed25519 key should be "
    "CRYPTO_SIGN_SECRETKEYBYTES bytes"
  ),
  s_sign_sk_to_box_sk_internal_error(
    "crypto_sign_ed25519_sk_to_curve25519(): internal error"
  );

String HHVM_FUNCTION(sodium_crypto_sign_ed25519_sk_to_curve25519,
                     const String& eddsakey) {
  if (eddsakey.size() != crypto_sign_SECRETKEYBYTES) {
    throwSodiumException(s_sign_sk_to_box_sk_key_size);
  }

  String ecdhkey(crypto_box_SECRETKEYBYTES, ReserveString);
  const auto result = crypto_sign_ed25519_sk_to_curve25519(
    reinterpret_cast<unsigned char*>(ecdhkey.mutableData()),
    reinterpret_cast<const unsigned char*>(eddsakey.data())
  );
  if (result != 0) {
    throwSodiumException(s_sign_sk_to_box_sk_internal_error);
  }
  ecdhkey.setSize(crypto_box_SECRETKEYBYTES);
  return ecdhkey;
}

const StaticString
  s_sign_pk_to_box_pk_key_size(
    "crypto_sign_ed25519_pk_to_curve25519(): Ed25519 key should be "
    "CRYPTO_SIGN_PUBLICKEYBYTES bytes"
  ),
  s_sign_pk_to_box_pk_internal_error(
    "crypto_sign_ed25519_pk_to_curve25519(): internal error"
  );

String HHVM_FUNCTION(sodium_crypto_sign_ed25519_pk_to_curve25519,
                     const String& eddsakey) {
  if (eddsakey.size() != crypto_sign_PUBLICKEYBYTES) {
    throwSodiumException(s_sign_pk_to_box_pk_key_size);
  }

  String ecdhkey(crypto_box_PUBLICKEYBYTES, ReserveString);
  const auto result = crypto_sign_ed25519_pk_to_curve25519(
    reinterpret_cast<unsigned char*>(ecdhkey.mutableData()),
    reinterpret_cast<const unsigned char*>(eddsakey.data())
  );
  if (result != 0) {
    throwSodiumException(s_sign_pk_to_box_pk_internal_error);
  }
  ecdhkey.setSize(crypto_box_PUBLICKEYBYTES);
  return ecdhkey;
}

const StaticString
  s_crypto_stream_bad_length("crypto_stream(): invalid length"),
  s_crypto_stream_nonce_size(
    "crypto_stream(): nonce should be CRYPTO_STREAM_NONCEBYTES bytes"
  ),
  s_crypto_stream_key_size(
    "crypto_stream(): key should be CRYPTO_STREAM_KEYEBYTES bytes"
  ),
  s_crypto_stream_internal_error("crypto_stream(): internal error");

String HHVM_FUNCTION(sodium_crypto_stream,
                     int64_t length,
                     const String& nonce,
                     const String& key) {
  if (length <= 0 || length >= StringData::MaxSize) {
    throwSodiumException(s_crypto_stream_bad_length);
  }
  if (nonce.size() != crypto_stream_NONCEBYTES) {
    throwSodiumException(s_crypto_stream_nonce_size);
  }
  if (key.size() != crypto_stream_KEYBYTES) {
    throwSodiumException(s_crypto_stream_key_size);
  }

  String ciphertext(length, ReserveString);
  const auto result = crypto_stream(
    reinterpret_cast<unsigned char*>(ciphertext.mutableData()),
    length,
    reinterpret_cast<const unsigned char*>(nonce.data()),
    reinterpret_cast<const unsigned char*>(key.data())
  );
  if (result != 0) {
    throwSodiumException(s_crypto_stream_internal_error);
  }
  ciphertext.setSize(length);
  return ciphertext;
}

const StaticString
  s_crypto_stream_xor_nonce_size(
    "crypto_stream_xor(): nonce should be CRYPTO_STREAM_NONCEBYTES bytes"
  ),
  s_crypto_stream_xor_key_size(
    "crypto_stream_xor(): key should be CRYPTO_STREAM_KEYEBYTES bytes"
  ),
  s_crypto_stream_xor_internal_error("crypto_stream_xor(): internal error");

String HHVM_FUNCTION(sodium_crypto_stream_xor,
                     const String& message,
                     const String& nonce,
                     const String& key) {
  if (nonce.size() != crypto_stream_NONCEBYTES) {
    throwSodiumException(s_crypto_stream_xor_nonce_size);
  }
  if (key.size() != crypto_stream_KEYBYTES) {
    throwSodiumException(s_crypto_stream_xor_key_size);
  }

  String ciphertext(message.size(), ReserveString);
  const auto result = crypto_stream_xor(
    reinterpret_cast<unsigned char*>(ciphertext.mutableData()),
    reinterpret_cast<const unsigned char*>(message.data()),
    message.size(),
    reinterpret_cast<const unsigned char*>(nonce.data()),
    reinterpret_cast<const unsigned char*>(key.data())
  );
  if (result != 0) {
    throwSodiumException(s_crypto_stream_xor_internal_error);
  }
  ciphertext.setSize(message.size());
  return ciphertext;
}

#define HHVM_SODIUM_AEAD_DECRYPT_FUNCTION(lowercase, uppercase) \
const StaticString\
  s_##lowercase##_decrypt_nonce_size(\
    "crypto_aead_"#lowercase"_decrypt(): public nonce size should be "\
    "CRYPTO_AEAD_"#uppercase"_NPUBBYTES bytes"\
  ),\
  s_##lowercase##_decrypt_key_size(\
    "crypto_aead_"#lowercase"_decrypt(): secret key size should be "\
    "CRYPTO_AEAD_"#uppercase"_KEYBYTES bytes"\
  );\
\
Variant HHVM_FUNCTION(sodium_crypto_aead_##lowercase##_decrypt,\
                      const String& ciphertext,\
                      const String& ad,\
                      const String& pnonce,\
                      const String& secretkey) {\
  if (pnonce.size() != crypto_aead_##lowercase##_NPUBBYTES) {\
    throwSodiumException(s_##lowercase##_decrypt_nonce_size);\
  }\
  if (secretkey.size() != crypto_aead_##lowercase##_KEYBYTES) {\
    throwSodiumException(s_##lowercase##_decrypt_key_size);\
  }\
\
  if (ciphertext.size() < crypto_aead_##lowercase##_ABYTES) {\
    return false;\
  }\
\
  String plaintext(ciphertext.size(), ReserveString);\
  unsigned long long plaintext_len;\
  const auto result = crypto_aead_##lowercase##_decrypt(\
    reinterpret_cast<unsigned char*>(plaintext.mutableData()),\
    &plaintext_len,\
    nullptr, /* secret nonce */ \
    reinterpret_cast<const unsigned char*>(ciphertext.data()),\
    ciphertext.size(),\
    reinterpret_cast<const unsigned char*>(ad.data()),\
    ad.size(),\
    reinterpret_cast<const unsigned char*>(pnonce.data()),\
    reinterpret_cast<const unsigned char*>(secretkey.data())\
  );\
  if (result != 0) {\
    return false;\
  }\
  if (plaintext_len > ciphertext.size()) {\
    throwSodiumException(s_arithmetic_overflow);\
  }\
  plaintext.setSize(plaintext_len);\
  return plaintext;\
}

#define HHVM_SODIUM_AEAD_ENCRYPT_FUNCTION(lowercase, uppercase) \
const StaticString\
  s_##lowercase##_encrypt_nonce_size(\
    "crypto_aead_"#lowercase"_encrypt(): public nonce size should be "\
    "CRYPTO_AEAD_"#uppercase"_NPUBBYTES bytes"\
  ),\
  s_##lowercase##_encrypt_key_size(\
    "crypto_aead_"#lowercase"_encrypt(): secret key size should be "\
    "CRYPTO_AEAD_"#uppercase"_KEYBYTES bytes"\
  ),\
  s_##lowercase##_encrypt_internal_error(\
    "crypto_aead_"#lowercase"_encrypt(): internal error"\
  );\
\
String HHVM_FUNCTION(sodium_crypto_aead_##lowercase##_encrypt,\
                     const String& plaintext,\
                     const String& ad,\
                     const String& pnonce,\
                     const String& secretkey) {\
  if (pnonce.size() != crypto_aead_##lowercase##_NPUBBYTES) {\
    throwSodiumException(s_##lowercase##_encrypt_nonce_size);\
  }\
  if (secretkey.size() != crypto_aead_##lowercase##_KEYBYTES) {\
    throwSodiumException(s_##lowercase##_encrypt_key_size);\
  }\
  if (\
    StringData::MaxSize - plaintext.size() <= crypto_aead_##lowercase##_ABYTES\
  ) {\
    throwSodiumException(s_arithmetic_overflow);\
  }\
\
  const size_t ciphertext_buf_size =\
   plaintext.size() + crypto_aead_##lowercase##_ABYTES;\
  String ciphertext(ciphertext_buf_size, ReserveString);\
  unsigned long long ciphertext_len;\
  const auto result = crypto_aead_##lowercase##_encrypt(\
    reinterpret_cast<unsigned char*>(ciphertext.mutableData()),\
    &ciphertext_len,\
    reinterpret_cast<const unsigned char*>(plaintext.data()),\
    plaintext.size(),\
    reinterpret_cast<const unsigned char*>(ad.data()),\
    ad.size(),\
    nullptr, /* secret nonce */\
    reinterpret_cast<const unsigned char*>(pnonce.data()),\
    reinterpret_cast<const unsigned char*>(secretkey.data())\
  );\
  if (result != 0) {\
    throwSodiumException(s_##lowercase##_encrypt_internal_error);\
  }\
  if (ciphertext_len == 0 || ciphertext_len > ciphertext_buf_size) {\
    throwSodiumException(s_arithmetic_overflow);\
  }\
  ciphertext.setSize(ciphertext_len);\
  return ciphertext;\
}

HHVM_SODIUM_AEAD_ENCRYPT_FUNCTION(chacha20poly1305, CHACHA20POLY1305);
HHVM_SODIUM_AEAD_DECRYPT_FUNCTION(chacha20poly1305, CHACHA20POLY1305);

#ifdef crypto_aead_aes256gcm_KEYBYTES
bool HHVM_FUNCTION(sodium_crypto_aead_aes256gcm_is_available) {
  return crypto_aead_aes256gcm_is_available();
}
HHVM_SODIUM_AEAD_ENCRYPT_FUNCTION(aes256gcm, AES256GCM);
HHVM_SODIUM_AEAD_DECRYPT_FUNCTION(aes256gcm, AES256GCM);
#endif

#ifdef crypto_aead_chacha20poly1305_IETF_NPUBBYTES
HHVM_SODIUM_AEAD_ENCRYPT_FUNCTION(chacha20poly1305_ietf, CHACHA20POLY1305_IETF);
HHVM_SODIUM_AEAD_DECRYPT_FUNCTION(chacha20poly1305_ietf, CHACHA20POLY1305_IETF);
#endif

#ifdef crypto_aead_xchacha20poly1305_IETF_NPUBBYTES
HHVM_SODIUM_AEAD_ENCRYPT_FUNCTION(xchacha20poly1305_ietf,
                                  XCHACHA20POLY1305_IETF);
HHVM_SODIUM_AEAD_DECRYPT_FUNCTION(xchacha20poly1305_ietf,
                                  XCHACHA20POLY1305_IETF);
#endif

#define HHVM_REGISTER_AEAD_DEFINITIONS(lowercase, uppercase)\
    HHVM_RC_INT(\
      SODIUM_CRYPTO_AEAD_##uppercase##_KEYBYTES,\
      crypto_aead_##lowercase##_KEYBYTES\
    );\
    HHVM_RC_INT(\
      SODIUM_CRYPTO_AEAD_##uppercase##_NSECBYTES,\
      crypto_aead_##lowercase##_NSECBYTES\
    );\
    HHVM_RC_INT(\
      SODIUM_CRYPTO_AEAD_##uppercase##_NPUBBYTES,\
      crypto_aead_##lowercase##_NPUBBYTES\
    );\
    HHVM_RC_INT(\
      SODIUM_CRYPTO_AEAD_##uppercase##_ABYTES,\
      crypto_aead_##lowercase##_ABYTES\
    );\
    HHVM_FE(sodium_crypto_aead_##lowercase##_decrypt);\
    HHVM_FE(sodium_crypto_aead_##lowercase##_encrypt)

struct SodiumExtension final : Extension {
  SodiumExtension() : Extension("libsodium", "0.1-hhvm") {}

  void moduleInit() override {
    if (sodium_init() != 0) {
      raise_error("sodium_init()");
    }

    HHVM_RC_STR(SODIUM_LIBRARY_VERSION, sodium_version_string());
    HHVM_RC_INT(SODIUM_LIBRARY_MAJOR_VERSION, sodium_library_version_major());
    HHVM_RC_INT(SODIUM_LIBRARY_MINOR_VERSION, sodium_library_version_minor());

    HHVM_FE(sodium_bin2hex);
    HHVM_FE(sodium_hex2bin);
    HHVM_FE(sodium_memzero);
    HHVM_FE(sodium_increment);
    HHVM_FE(sodium_add);
    HHVM_FE(sodium_memcmp);
    HHVM_FE(sodium_compare);

    HHVM_RC_INT(SODIUM_CRYPTO_SCALARMULT_BYTES, crypto_scalarmult_BYTES);
    HHVM_RC_INT(
      SODIUM_CRYPTO_SCALARMULT_SCALARBYTES,
      crypto_scalarmult_SCALARBYTES
    );
    HHVM_FE(sodium_crypto_scalarmult);

    HHVM_FE(sodium_crypto_generichash);
    HHVM_FE(sodium_crypto_generichash_init);
    HHVM_FE(sodium_crypto_generichash_update);
    HHVM_FE(sodium_crypto_generichash_final);
    HHVM_FE(sodium_crypto_shorthash);

#ifdef crypto_pwhash_SALTBYTES
    HHVM_RC_INT(SODIUM_CRYPTO_PWHASH_SALTBYTES, crypto_pwhash_SALTBYTES);
    HHVM_RC_STR(SODIUM_CRYPTO_PWHASH_STRPREFIX, crypto_pwhash_STRPREFIX);
    HHVM_RC_INT(
      SODIUM_CRYPTO_PWHASH_OPSLIMIT_INTERACTIVE,
      crypto_pwhash_OPSLIMIT_INTERACTIVE
    );
    HHVM_RC_INT(
      SODIUM_CRYPTO_PWHASH_MEMLIMIT_INTERACTIVE,
      crypto_pwhash_MEMLIMIT_INTERACTIVE
    );
    HHVM_RC_INT(
      SODIUM_CRYPTO_PWHASH_OPSLIMIT_MODERATE,
      crypto_pwhash_OPSLIMIT_MODERATE
    );
    HHVM_RC_INT(
      SODIUM_CRYPTO_PWHASH_MEMLIMIT_MODERATE,
      crypto_pwhash_MEMLIMIT_MODERATE
    );
    HHVM_RC_INT(
      SODIUM_CRYPTO_PWHASH_OPSLIMIT_SENSITIVE,
      crypto_pwhash_OPSLIMIT_SENSITIVE
    );
    HHVM_RC_INT(
      SODIUM_CRYPTO_PWHASH_MEMLIMIT_SENSITIVE,
      crypto_pwhash_MEMLIMIT_SENSITIVE
    );
    HHVM_FE(sodium_crypto_pwhash);
    HHVM_FE(sodium_crypto_pwhash_str);
    HHVM_FE(sodium_crypto_pwhash_str_verify);
#endif

    HHVM_RC_STR(
      SODIUM_CRYPTO_PWHASH_SCRYPTSALSA208SHA256_STRPREFIX,
      crypto_pwhash_scryptsalsa208sha256_STRPREFIX
    );
    HHVM_RC_INT(
      SODIUM_CRYPTO_PWHASH_SCRYPTSALSA208SHA256_SALTBYTES,
      crypto_pwhash_scryptsalsa208sha256_SALTBYTES
    );
    HHVM_RC_INT(
      SODIUM_CRYPTO_PWHASH_SCRYPTSALSA208SHA256_OPSLIMIT_INTERACTIVE,
      (int64_t) crypto_pwhash_scryptsalsa208sha256_opslimit_interactive()
    );
    HHVM_RC_INT(
      SODIUM_CRYPTO_PWHASH_SCRYPTSALSA208SHA256_MEMLIMIT_INTERACTIVE,
      (int64_t) crypto_pwhash_scryptsalsa208sha256_memlimit_interactive()
    );
    HHVM_RC_INT(
      SODIUM_CRYPTO_PWHASH_SCRYPTSALSA208SHA256_OPSLIMIT_SENSITIVE,
      (int64_t) crypto_pwhash_scryptsalsa208sha256_opslimit_sensitive()
    );
    HHVM_RC_INT(
      SODIUM_CRYPTO_PWHASH_SCRYPTSALSA208SHA256_MEMLIMIT_SENSITIVE,
      (int64_t) crypto_pwhash_scryptsalsa208sha256_memlimit_sensitive()
    );
    HHVM_FE(sodium_crypto_pwhash_scryptsalsa208sha256);
    HHVM_FE(sodium_crypto_pwhash_scryptsalsa208sha256_str);
    HHVM_FE(sodium_crypto_pwhash_scryptsalsa208sha256_str_verify);

    HHVM_RC_INT(SODIUM_CRYPTO_AUTH_BYTES, crypto_auth_BYTES);
    HHVM_RC_INT(SODIUM_CRYPTO_AUTH_KEYBYTES, crypto_auth_KEYBYTES);
    HHVM_FE(sodium_crypto_auth);
    HHVM_FE(sodium_crypto_auth_verify);

    HHVM_RC_INT(SODIUM_CRYPTO_SECRETBOX_KEYBYTES, crypto_secretbox_KEYBYTES);
    HHVM_RC_INT(SODIUM_CRYPTO_SECRETBOX_MACBYTES, crypto_secretbox_MACBYTES);
    HHVM_RC_INT(
      SODIUM_CRYPTO_SECRETBOX_NONCEBYTES, crypto_secretbox_NONCEBYTES);
    HHVM_FE(sodium_crypto_secretbox);
    HHVM_FE(sodium_crypto_secretbox_open);

    HHVM_RC_INT(SODIUM_CRYPTO_BOX_SECRETKEYBYTES, crypto_box_SECRETKEYBYTES);
    HHVM_RC_INT(SODIUM_CRYPTO_BOX_PUBLICKEYBYTES, crypto_box_PUBLICKEYBYTES);
    HHVM_RC_INT(
      SODIUM_CRYPTO_BOX_KEYPAIRBYTES,
      crypto_box_SECRETKEYBYTES + crypto_box_PUBLICKEYBYTES
    );
    HHVM_RC_INT(SODIUM_CRYPTO_BOX_MACBYTES, crypto_box_MACBYTES);
    HHVM_RC_INT(SODIUM_CRYPTO_BOX_NONCEBYTES, crypto_box_NONCEBYTES);
    HHVM_RC_INT(SODIUM_CRYPTO_BOX_SEEDBYTES, crypto_box_SEEDBYTES);
    HHVM_FE(sodium_crypto_box_keypair);
    HHVM_FE(sodium_crypto_box_seed_keypair);
    HHVM_FE(sodium_crypto_box_publickey_from_secretkey);
    HHVM_FALIAS(
      sodium_crypto_scalarmult_base,
      sodium_crypto_box_publickey_from_secretkey
    );

    HHVM_RC_INT(SODIUM_CRYPTO_KX_BYTES, crypto_kx_BYTES);
    HHVM_RC_INT(SODIUM_CRYPTO_KX_PUBLICKEYBYTES, crypto_kx_PUBLICKEYBYTES);
    HHVM_RC_INT(SODIUM_CRYPTO_KX_SECRETKEYBYTES, crypto_kx_SECRETKEYBYTES);
    HHVM_FE(sodium_crypto_kx);

    HHVM_FE(sodium_crypto_box);
    HHVM_FE(sodium_crypto_box_open);

#ifdef crypto_box_SEALBYTES
    HHVM_RC_INT(SODIUM_CRYPTO_BOX_SEALBYTES, crypto_box_SEALBYTES);
    HHVM_FE(sodium_crypto_box_seal);
    HHVM_FE(sodium_crypto_box_seal_open);
#endif

    HHVM_RC_INT(SODIUM_CRYPTO_SIGN_BYTES, crypto_sign_BYTES);
    HHVM_RC_INT(SODIUM_CRYPTO_SIGN_SEEDBYTES, crypto_sign_SEEDBYTES);
    HHVM_RC_INT(SODIUM_CRYPTO_SIGN_PUBLICKEYBYTES, crypto_sign_PUBLICKEYBYTES);
    HHVM_RC_INT(SODIUM_CRYPTO_SIGN_SECRETKEYBYTES, crypto_sign_SECRETKEYBYTES);
    HHVM_RC_INT(
      SODIUM_CRYPTO_SIGN_KEYPAIRBYTES,
      crypto_sign_PUBLICKEYBYTES + crypto_sign_SECRETKEYBYTES
    );

    HHVM_FE(sodium_crypto_sign_keypair);
    HHVM_FE(sodium_crypto_sign_seed_keypair);
    HHVM_FE(sodium_crypto_sign_publickey_from_secretkey);
    HHVM_FE(sodium_crypto_sign_ed25519_pk_to_curve25519);
    HHVM_FE(sodium_crypto_sign_ed25519_sk_to_curve25519);

    HHVM_FE(sodium_crypto_sign);
    HHVM_FE(sodium_crypto_sign_open);
    HHVM_FE(sodium_crypto_sign_detached);
    HHVM_FE(sodium_crypto_sign_verify_detached);

    HHVM_RC_INT(SODIUM_CRYPTO_STREAM_NONCEBYTES, crypto_stream_NONCEBYTES);
    HHVM_RC_INT(SODIUM_CRYPTO_STREAM_KEYBYTES, crypto_stream_KEYBYTES);
    HHVM_FE(sodium_crypto_stream);
    HHVM_FE(sodium_crypto_stream_xor);

    HHVM_REGISTER_AEAD_DEFINITIONS(chacha20poly1305, CHACHA20POLY1305);
#ifdef crypto_aead_aes256gcm_KEYBYTES
    HHVM_FE(sodium_crypto_aead_aes256gcm_is_available);
    if (crypto_aead_aes256gcm_is_available()) {
      HHVM_REGISTER_AEAD_DEFINITIONS(aes256gcm, AES256GCM);
    }
#endif
#ifdef crypto_aead_chacha20poly1305_IETF_NPUBBYTES
    HHVM_REGISTER_AEAD_DEFINITIONS(chacha20poly1305_ietf,
                                   CHACHA20POLY1305_IETF);
#endif
#ifdef crypto_aead_xchacha20poly1305_IETF_NPUBBYTES
    HHVM_REGISTER_AEAD_DEFINITIONS(xchacha20poly1305_ietf,
                                   XCHACHA20POLY1305_IETF);
#endif

    loadSystemlib();
  }
} s_sodium_extension;

} // namespace

} // namespace HPHP