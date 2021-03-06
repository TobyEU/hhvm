<?hh

function gen_func_num_args_simple() {
  yield func_num_args();
}

function gen_func_get_args_simple() {
  yield func_get_args();
}

function gen_func_get_arg_simple($idx) {
  yield func_get_arg($idx);
}

function gen_func_num_args_arg($arg) {
  yield func_num_args();
}

function gen_func_get_args_arg($arg) {
  yield func_get_args();
}

function gen_func_get_arg_arg($arg, $idx) {
  yield func_get_arg($idx);
}

function gen_func_num_args_varenv($dst, $src) {
  $$dst = $src;
  yield func_num_args();
}

function gen_func_get_args_varenv($dst, $src) {
  $$dst = $src;
  yield func_get_args();
}

function gen_func_get_arg_varenv($dst, $src, $idx) {
  $$dst = $src;
  yield func_get_arg($idx);
}

function test(string $generator, array $args) {
  $gen = call_user_func_array($generator, $args);
  foreach ($gen as $val) {
    var_dump($val);
  }
}

function test_num_args(string $type, array $extra_args) {
  test(
    'gen_func_num_args_'.$type,
    array_merge(
      array_slice(func_get_args(), 2),
      $extra_args
    )
  );
}

function test_get_args(string $type, array $extra_args) {
  test(
    'gen_func_get_args_'.$type,
    array_merge(
      array_slice(func_get_args(), 2),
      $extra_args
    )
  );
}

function test_get_arg(string $type, array $extra_args) {
  $cnt = count($extra_args) + func_num_args() - 1;

  for ($i = -1; $i <= $cnt; ++$i) {
    test(
      'gen_func_get_arg_'.$type,
      array_merge(
        array_slice(func_get_args(), 2),
        array($i),
        $extra_args
      )
    );
  }
}

$extra_args_set = array(
  array(),
  array('hello'),
  array('hello', 47),
);

foreach ($extra_args_set as $extra_args) {
  test_num_args('simple', $extra_args);
  test_get_args('simple', $extra_args);
  test_get_arg('simple', $extra_args);

  test_num_args('arg', $extra_args, 'defined_arg');
  test_get_args('arg', $extra_args, 'defined_arg');
  test_get_arg('arg', $extra_args, 'defined_arg');

  foreach (array('dst', 'src', 'idx', 'undef') as $dst) {
    test_num_args('varenv', $extra_args, $dst, 'replacement');
    test_get_args('varenv', $extra_args, $dst, 'replacement');
    test_get_arg('varenv', $extra_args, $dst, 'replacement');
  }
}
