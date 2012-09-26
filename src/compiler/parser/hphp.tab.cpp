
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse         Compilerparse
#define yylex           Compilerlex
#define yyerror         Compilererror
#define yylval          Compilerlval
#define yychar          Compilerchar
#define yydebug         Compilerdebug
#define yynerrs         Compilernerrs
#define yylloc          Compilerlloc

/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "../../../src/util/parser/hphp.y"

#include "parser.h"
#include <util/util.h>
#include <util/logger.h>

// macros for bison
#define YYSTYPE HPHP::HPHP_PARSER_NS::Token
#define YYSTYPE_IS_TRIVIAL 1
#define YYLTYPE HPHP::Location
#define YYLTYPE_IS_TRIVIAL 1
#define YYERROR_VERBOSE
#define YYINITDEPTH 500
#define YYLEX_PARAM _p

#ifdef yyerror
#undef yyerror
#endif
#define yyerror(loc,p,msg) p->fatal(loc,msg)

#ifdef YYLLOC_DEFAULT
# undef YYLLOC_DEFAULT
#endif
#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#define YYLLOC_DEFAULT(Current, Rhs, N)                                 \
  do                                                                    \
    if (YYID (N)) {                                                     \
      (Current).first(YYRHSLOC (Rhs, 1));                               \
      (Current).last (YYRHSLOC (Rhs, N));                               \
    } else {                                                            \
      (Current).line0 = (Current).line1 = YYRHSLOC (Rhs, 0).line1;      \
      (Current).char0 = (Current).char1 = YYRHSLOC (Rhs, 0).char1;      \
    }                                                                   \
  while (YYID (0));                                                     \
  _p->setRuleLocation(&Current);

#define YYCOPY(To, From, Count)                  \
  do {                                           \
    YYSIZE_T yyi;                                \
    for (yyi = 0; yyi < (Count); yyi++) {        \
      (To)[yyi] = (From)[yyi];                   \
    }                                            \
    if (From != From ## a) {                     \
      YYSTACK_FREE (From);                       \
    }                                            \
  }                                              \
  while (YYID (0))

#define YYCOPY_RESET(To, From, Count)           \
  do                                            \
    {                                           \
      YYSIZE_T yyi;                             \
      for (yyi = 0; yyi < (Count); yyi++) {     \
        (To)[yyi] = (From)[yyi];                \
        (From)[yyi].reset();                    \
      }                                         \
      if (From != From ## a) {                  \
        YYSTACK_FREE (From);                    \
      }                                         \
    }                                           \
  while (YYID (0))

#define YYTOKEN_RESET(From, Count)              \
  do                                            \
    {                                           \
      YYSIZE_T yyi;                             \
      for (yyi = 0; yyi < (Count); yyi++) {     \
        (From)[yyi].reset();                    \
      }                                         \
      if (From != From ## a) {                  \
        YYSTACK_FREE (From);                    \
      }                                         \
    }                                           \
  while (YYID (0))

# define YYSTACK_RELOCATE_RESET(Stack_alloc, Stack)                     \
  do                                                                    \
    {                                                                   \
      YYSIZE_T yynewbytes;                                              \
      YYCOPY_RESET (&yyptr->Stack_alloc, Stack, yysize);                \
      Stack = &yyptr->Stack_alloc;                                      \
      yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
      yyptr += yynewbytes / sizeof (*yyptr);                            \
    }                                                                   \
  while (YYID (0))

#define YYSTACK_CLEANUP                         \
  YYTOKEN_RESET (yyvs, yystacksize);            \
  if (yyvs != yyvsa) {                          \
    YYSTACK_FREE (yyvs);                        \
  }                                             \
  if (yyls != yylsa) {                          \
    YYSTACK_FREE (yyls);                        \
  }                                             \


// macros for rules
#define BEXP(e...) _p->onBinaryOpExp(e);
#define UEXP(e...) _p->onUnaryOpExp(e);

using namespace HPHP::HPHP_PARSER_NS;

///////////////////////////////////////////////////////////////////////////////
// helpers

static void no_gap(Parser *_p) {
  if (_p->scanner().hasGap()) {
    HPHP_PARSER_ERROR("XHP: bad spacing", _p);
  }
}

static void scalar_num(Parser *_p, Token &out, const char *num) {
  Token t;
  t.setText(num);
  _p->onScalar(out, T_LNUMBER, t);
}

static void scalar_num(Parser *_p, Token &out, int num) {
  Token t;
  t.setText(boost::lexical_cast<std::string>(num));
  _p->onScalar(out, T_LNUMBER, t);
}

static void scalar_null(Parser *_p, Token &out) {
  Token tnull; tnull.setText("null");
  _p->onConstantValue(out, tnull);
}

///////////////////////////////////////////////////////////////////////////////
// converting constant declartion to "define(name, value);"

static void on_constant(Parser *_p, Token &out, Token *stmts,
                        Token &name, Token &value) {
  Token sname;   _p->onScalar(sname, T_CONSTANT_ENCAPSED_STRING, name);

  Token fname;   fname.setText("define");
  Token params1; _p->onCallParam(params1, NULL, sname, 0);
  Token params2; _p->onCallParam(params2, &params1, value, 0);
  Token call;    _p->onCall(call, 0, fname, params2, 0);
  Token scall;   _p->onExpStatement(scall, call);

  Token stmts0;
  if (!stmts) {
    _p->onStatementListStart(stmts0);
    stmts = &stmts0;
  }
  _p->addStatement(out, *stmts, scall);
}

///////////////////////////////////////////////////////////////////////////////
// continuation transformations

static void prepare_continuation_call(Parser* _p, Token& rhs, const char* cname) {
  if (HPHP::hhvm) {
    Token fname;  fname.setText(std::string("hphp_continuation_") + cname);
    Token empty;
    _p->onCall(rhs, false, fname, empty, NULL, true);
  } else {
    Token name;   name.setText(CONTINUATION_OBJECT_NAME);
    Token var;    _p->onSynthesizedVariable(var, name);
    Token pn;     pn.setText(cname);
    Token pname;  _p->onName(pname, pn, Parser::VarName);
    Token empty;  empty = 1;
                  _p->onObjectMethodCall(rhs, var, pname, empty);
  }
}

static void on_yield_assign(Parser *_p, Token &out, Token &var, Token *expr) {
  Token yield;    _p->onYield(yield, expr, true);
  Token rhs;      prepare_continuation_call(_p, rhs, "receive");
  Token assign;   _p->onAssign(assign, var, rhs, 0);
  Token stmt;     _p->onExpStatement(stmt, assign);

  Token stmts0;   _p->onStatementListStart(stmts0);
  Token stmts1;   _p->addStatement(stmts1, stmts0, yield);
  Token stmts2;   _p->addStatement(stmts2, stmts1, stmt);

  _p->finishStatement(out, stmts2); out = 1;
}

static void on_yield_list_assign(Parser *_p, Token &out, Token &var,
                                 Token *expr) {
  Token yield;    _p->onYield(yield, expr, true);
  Token rhs;      prepare_continuation_call(_p, rhs, "receive");
  Token assign;   _p->onListAssignment(assign, var, &rhs);
  Token stmt;     _p->onExpStatement(stmt, assign);

  Token stmts0;   _p->onStatementListStart(stmts0);
  Token stmts1;   _p->addStatement(stmts1, stmts0, yield);
  Token stmts2;   _p->addStatement(stmts2, stmts1, stmt);

  _p->finishStatement(out, stmts2); out = 1;
}

void prepare_generator(Parser *_p, Token &stmt, Token &params, int count) {
  // 1. add prologue and epilogue to original body and store it back to "stmt"
  {
    Token scall;
    Token switchExp;
    {
      // hphp_unpack_continuation(v___cont__)
      Token name;    name.setText(CONTINUATION_OBJECT_NAME);
      Token var;     _p->onSynthesizedVariable(var, name);
      Token param1;  _p->onCallParam(param1, NULL, var, false);

      Token cname;   cname.setText("hphp_unpack_continuation");
      Token call;    _p->onCall(call, false, cname, param1, NULL, true);

      if (HPHP::hhvm) {
        switchExp = call;
      } else {
        _p->onExpStatement(scall, call);
        Token name;    name.setText(CONTINUATION_OBJECT_NAME);
        Token var;     _p->onSynthesizedVariable(var, name);
        Token pn;      pn.setText("getLabel");
        Token pname;   _p->onName(pname, pn, Parser::VarName);
        Token mcall;
        Token empty;   empty = 1;
                       _p->onObjectMethodCall(mcall, var, pname, empty);
        switchExp = mcall;
      }
    }
    Token sswitch;
    {
      _p->pushLabelScope();
      {
        Token cases;
        for (int i = count; i > 0; i--) {
          std::string si = boost::lexical_cast<std::string>(i);

          Token label;   label.setText(YIELD_LABEL_PREFIX + si);
          Token sgoto;   _p->onGoto(sgoto, label, false);
                         _p->addGoto(label.text(), _p->getLocation(), &sgoto);

          Token stmts0;  _p->onStatementListStart(stmts0);
          Token stmts1;  _p->addStatement(stmts1, stmts0, sgoto);
          Token stmts;   _p->finishStatement(stmts, stmts1); stmts = 1;

          Token snum;    snum.setText(si);
          Token num;     _p->onScalar(num, T_LNUMBER, snum);
          Token scase;   _p->onCase(scase, cases, &num, stmts);
          cases = scase;
        }
        _p->onSwitch(sswitch, switchExp, cases);
      }
      _p->popLabelScope();
    }
    Token sdone;
    {
      Token mcall;  prepare_continuation_call(_p, mcall, "done");
      _p->onExpStatement(sdone, mcall);
    }
    {
      Token stmts0;  _p->onStatementListStart(stmts0);
      Token stmts1;  _p->addStatement(stmts1, stmts0, scall);
      Token stmts2;  _p->addStatement(stmts2, stmts1, sswitch);
      Token stmts3;  _p->addStatement(stmts3, stmts2, stmt);
      Token stmts4;  _p->addStatement(stmts4, stmts3, sdone);

      stmt.reset();
      _p->finishStatement(stmt, stmts4); stmt = 1;
    }
  }

  // 2. prepare a single continuation parameter list and store it in "params"
  {
    Token type;    type.setText("Continuation");
    Token var;     var.setText(CONTINUATION_OBJECT_NAME);
    params.reset();
    _p->onParam(params, NULL, type, var, false, NULL);
  }
}

// create a generator function with original name and parameters
void create_generator(Parser *_p, Token &out, Token &params,
                      Token &name, const std::string &closureName,
                      const char *clsname, Token *modifiers, bool getArgs,
                      Token &origGenFunc, bool isHhvm, Token *attr) {
  _p->pushFuncLocation();
  if (clsname) {
    _p->onMethodStart(name, *modifiers, false);
  } else {
    _p->onFunctionStart(name, false);
  }

  Token scont;
  {
    Token cname;
    if (isHhvm) {
      Token cn;    cn.setText(clsname ? "__CLASS__" : "");
                   _p->onScalar(
                     cname,
                     clsname ? T_CLASS_C : T_CONSTANT_ENCAPSED_STRING,
                     cn);
    } else {
      Token cn;    cn.setText(clsname ? clsname : "");
                   _p->onScalar(cname, T_CONSTANT_ENCAPSED_STRING, cn);
    }

    Token fn;      fn.setText(closureName);
    Token fname;   _p->onScalar(fname, T_CONSTANT_ENCAPSED_STRING, fn);

    Token ofn;     ofn.setText(clsname ? "__METHOD__" : "__FUNCTION__");
    Token oname;   _p->onScalar(oname, clsname ? T_METHOD_C : T_FUNC_C, ofn);

    Token param1;  _p->onCallParam(param1, NULL, cname, false);
                   _p->onCallParam(param1, &param1, fname, false);
                   _p->onCallParam(param1, &param1, oname, false);

    if (getArgs) {
      Token cname;   cname.setText("func_get_args");
      Token empty;
      Token call;    _p->onCall(call, false, cname, empty, NULL);
                     _p->onCallParam(param1, &param1, call, false);
    }

    Token cname0;  cname0.setText("hphp_create_continuation");
    Token call;    _p->onCall(call, false, cname0, param1, NULL, true);
    Token ret;     _p->onReturn(ret, &call);

    Token stmts0;  _p->onStatementListStart(stmts0);
    Token stmts1;  _p->addStatement(stmts1, stmts0, ret);
    _p->finishStatement(scont, stmts1); scont = 1;
  }

  Token ret, ref;
  ret.setText("Continuation");
  ret.setCheck();
  if (clsname) {
    Token closure;
    _p->onMethod(closure, *modifiers, ret, ref, name, params, scont, attr);
    origGenFunc = closure;

    Token stmts0;  _p->onStatementListStart(stmts0);
    Token stmts1;  _p->addStatement(stmts1, stmts0, closure);
    Token stmts2;  _p->addStatement(stmts2, stmts1, out);
    _p->finishStatement(out, stmts2); out = 1;
  } else {
    out.reset();
    _p->onFunction(out, ret, ref, name, params, scont, attr);
    origGenFunc = out;
  }
}

void transform_yield(Parser *_p, Token &stmts, int index,
                     Token *expr, bool assign) {
  Token update;
  {
    // hphp_pack_continuation(v___cont__, label, value)

    Token name;    name.setText(CONTINUATION_OBJECT_NAME);
    Token var;     _p->onSynthesizedVariable(var, name);
    Token param1;  _p->onCallParam(param1, NULL, var, false);

    Token snum;    snum.setText(boost::lexical_cast<std::string>(index));
    Token num;     _p->onScalar(num, T_LNUMBER, snum);
                   _p->onCallParam(param1, &param1, num, false);

    if (expr) {
      _p->onCallParam(param1, &param1, *expr, false);
    } else {
      Token tnull; scalar_null(_p, tnull);
      _p->onCallParam(param1, &param1, tnull, false);
    }

    Token cname;   cname.setText("hphp_pack_continuation");
    Token call;    _p->onCall(call, false, cname, param1, NULL, true);
    _p->onExpStatement(update, call);
  }

  Token lname;   lname.setText(YIELD_LABEL_PREFIX +
                               boost::lexical_cast<std::string>(index));
  Token label;   _p->onLabel(label, lname);
                 _p->addLabel(lname.text(), _p->getLocation(), &label);

  Token stmts0;  _p->onStatementListStart(stmts0);

  if (!expr) {
    Token mcall;   prepare_continuation_call(_p, mcall, "done");
    Token sdone;   _p->onExpStatement(sdone, mcall);
    Token tmp;     _p->addStatement(tmp, stmts0, sdone);
    stmts0 = tmp;
  }

  Token ret;     _p->onReturn(ret, NULL, false);
  Token stmts1;  _p->addStatement(stmts1, stmts0, update);
  Token stmts2;  _p->addStatement(stmts2, stmts1, ret);
  Token stmts3;  _p->addStatement(stmts3, stmts2, label);

  if (assign) {
    _p->finishStatement(stmts, stmts3); stmts = 1;
  } else {
    Token fcall;  prepare_continuation_call(_p, fcall, "raised");
    Token fstmt;  _p->onExpStatement(fstmt, fcall);
    Token stmts4; _p->addStatement(stmts4, stmts3, fstmt);
    _p->finishStatement(stmts, stmts4); stmts = 1;
  }

}

// convert a foreach (by ref or not) to a normal for statement with
// an iterator object.
void transform_foreach(Parser *_p, Token &out, Token &arr, Token &name,
                       Token &value, Token &stmt, int count,
                       bool hasValue, bool byRef) {
  out.reset();

  std::string loopvar = FOREACH_VAR_PREFIX;
  loopvar += boost::lexical_cast<std::string>(count);

  Token init;
  {
    Token cname;    cname.setText(byRef ?
                                  "hphp_get_mutable_iterator" :
                                  "hphp_get_iterator");
    Token param1;   _p->onCallParam(param1, NULL, arr, 0);
    Token call;     _p->onCall(call, 0, cname, param1, NULL);
    Token lname;    lname.setText(loopvar);
    Token var;      _p->onSynthesizedVariable(var, lname);
    Token assign;   _p->onAssign(assign, var, call, false);
    _p->onExprListElem(init, NULL, assign);
  }

  Token cond;
  {
    Token lname;    lname.setText(loopvar);
    Token var;      _p->onSynthesizedVariable(var, lname);
    Token pn;       pn.setText("valid");
    Token pname;    _p->onName(pname, pn, Parser::VarName);
    Token empty;    empty = 1;
    Token valid;    _p->onObjectMethodCall(valid, var, pname, empty);
    _p->onExprListElem(cond, NULL, valid);
  }

  Token step;
  {
    Token lname;    lname.setText(loopvar);
    Token var;      _p->onSynthesizedVariable(var, lname);
    Token pn;       pn.setText("next");
    Token pname;    _p->onName(pname, pn, Parser::VarName);
    Token empty;    empty = 1;
    Token next;     _p->onObjectMethodCall(next, var, pname, empty);
    _p->onExprListElem(step, NULL, next);
  }

  {
    Token stmts0;   _p->onStatementListStart(stmts0);

    if (hasValue) {
      Token skset;
      {
        Token lname;  lname.setText(loopvar);
        Token var;    _p->onSynthesizedVariable(var, lname);
        Token pn;     pn->setText("key");
        Token pname;  _p->onName(pname, pn, Parser::VarName);
        Token empty;  empty = 1;
        Token call;   _p->onObjectMethodCall(call, var, pname, empty);
        Token kset;   _p->onAssign(kset, name, call, false);
        _p->onExpStatement(skset, kset);
      }
      Token stmts1; _p->addStatement(stmts1, stmts0, skset);

      Token svset;
      {
        Token lname;  lname.setText(loopvar);
        Token var;    _p->onSynthesizedVariable(var, lname);
        Token pn;     pn.setText(byRef ? "currentRef" : "current");
        Token pname;  _p->onName(pname, pn, Parser::VarName);
        Token empty;  empty = 1;
        Token call;   _p->onObjectMethodCall(call, var, pname, empty);
        Token vset;   _p->onAssign(vset, value, call, byRef);
        _p->onExpStatement(svset, vset);
      }
      Token stmts2; _p->addStatement(stmts2, stmts1, svset);

      Token stmts3; _p->addStatement(stmts3, stmts2, stmt);
      stmt.reset();
      _p->finishStatement(stmt, stmts3); stmt = 1;
    } else {
      Token svset;
      {
        Token lname;  lname.setText(loopvar);
        Token var;    _p->onSynthesizedVariable(var, lname);
        Token pn;     pn.setText(byRef ? "currentRef" : "current");
        Token pname;  _p->onName(pname, pn, Parser::VarName);
        Token empty;  empty = 1;
        Token call;   _p->onObjectMethodCall(call, var, pname, empty);
        Token vset;   _p->onAssign(vset, name, call, byRef);
        _p->onExpStatement(svset, vset);
      }
      Token stmts1; _p->addStatement(stmts1, stmts0, svset);

      Token stmts2; _p->addStatement(stmts2, stmts1, stmt);
      stmt.reset();
      _p->finishStatement(stmt, stmts2); stmt = 1;
    }
  }

  _p->onFor(out, init, cond, step, stmt);
}

///////////////////////////////////////////////////////////////////////////////

static void user_attribute_check(Parser *_p) {
  if (!_p->enableHipHopSyntax()) {
    HPHP_PARSER_ERROR("User attributes are not enabled", _p);
  }
}

static void finally_statement(Parser *_p) {
  if (!_p->enableFinallyStatement()) {
    HPHP_PARSER_ERROR("Finally statement is not enabled", _p);
  }
}

static void constant_ae(Parser *_p, Token &out, Token &value) {
  const std::string& valueStr = value.text();
  if (valueStr.size() < 3 || valueStr.size() > 5 ||
      (strcasecmp("true", valueStr.c_str()) != 0 &&
       strcasecmp("false", valueStr.c_str()) != 0 &&
       strcasecmp("null", valueStr.c_str()) != 0 &&
       strcasecmp("inf", valueStr.c_str()) != 0 &&
       strcasecmp("nan", valueStr.c_str()) != 0)) {
    HPHP_PARSER_ERROR("User-defined constants are not allowed in user "
                      "attribute expressions", _p);
  }
  _p->onConstantValue(out, value);
}

///////////////////////////////////////////////////////////////////////////////

/**
 * XHP functions: They are defined here, so different parsers don't have to
 * handle XHP rules at all.
 */

static void xhp_tag(Parser *_p, Token &out, Token &label, Token &body) {
  if (!_p->enableXHP()) {
    HPHP_PARSER_ERROR("XHP: not enabled", _p);
  }

  if (!body.text().empty() && body.text() != label.text()) {
    HPHP_PARSER_ERROR("XHP: mismatched tag: '%s' not the same as '%s'",
                      _p, body.text().c_str(), label.text().c_str());
  }

  label.xhpLabel();
  Token name; _p->onName(name, label, Parser::StringName);
  _p->onNewObject(out, name, body);
}

static void xhp_attribute(Parser *_p, Token &out, Token &type, Token &label,
                          Token &def, Token &req) {
  Token num;  scalar_num(_p, num, type.num());
  Token arr1; _p->onArrayPair(arr1, 0, 0, num, 0);

  Token arr2;
  switch (type.num()) {
    case 5: /* class */ {
      Token cls; _p->onScalar(cls, T_CONSTANT_ENCAPSED_STRING, type);
      _p->onArrayPair(arr2, &arr1, 0, cls, 0);
      break;
    }
    case 7: /* enum */ {
      Token arr;   _p->onArray(arr, type);
      _p->onArrayPair(arr2, &arr1, 0, arr, 0);
      break;
    }
    default: {
      Token tnull; scalar_null(_p, tnull);
      _p->onArrayPair(arr2, &arr1, 0, tnull, 0);
      break;
    }
  }

  Token arr3; _p->onArrayPair(arr3, &arr2, 0, def, 0);
  Token arr4; _p->onArrayPair(arr4, &arr3, 0, req, 0);
  _p->onArray(out, arr4);
  out.setText(label);
}

static void xhp_attribute_list(Parser *_p, Token &out, Token *list,
                               Token &decl) {
  if (decl.num() == 0) {
    decl.xhpLabel();
    if (list) {
      out = *list;
      out.setText(list->text() + ":" + decl.text()); // avoiding vector<string>
    } else {
      out.setText(decl);
    }
  } else {
    Token name; _p->onScalar(name, T_CONSTANT_ENCAPSED_STRING, decl);
    _p->onArrayPair(out, list, &name, decl, 0);
    if (list) {
      out.setText(list->text());
    } else {
      out.setText("");
    }
  }
}

static void xhp_attribute_stmt(Parser *_p, Token &out, Token &attributes) {
  if (!_p->enableXHP()) {
    HPHP_PARSER_ERROR("XHP: not enabled", _p);
  }

  Token modifiers;
  Token fname; fname.setText("__xhpAttributeDeclaration");
  {
    Token m;
    Token m1; m1.setNum(T_PROTECTED); _p->onMemberModifier(m, NULL, m1);
    Token m2; m2.setNum(T_STATIC);    _p->onMemberModifier(modifiers, &m, m2);
  }
  _p->pushFuncLocation();
  _p->onMethodStart(fname, modifiers);

  std::vector<std::string> classes;
  HPHP::Util::split(':', attributes.text().c_str(), classes, true);
  Token arrAttributes; _p->onArray(arrAttributes, attributes);

  Token dummy;

  Token stmts0;
  {
    _p->onStatementListStart(stmts0);
  }
  Token stmts1;
  {
    // static $_ = -1;
    Token one;     scalar_num(_p, one, "1");
    Token mone;    UEXP(mone, one, '-', 1);
    Token var;     var.set(T_VARIABLE, "_");
    Token decl;    _p->onStaticVariable(decl, 0, var, &mone);
    Token sdecl;   _p->onStatic(sdecl, decl);
    _p->addStatement(stmts1, stmts0, sdecl);
  }
  Token stmts2;
  {
    // if ($_ === -1) {
    //   $_ = array_merge(parent::__xhpAttributeDeclaration(),
    //                    attributes);
    // }
    Token parent;  parent.set(T_STRING, "parent");
    Token cls;     _p->onName(cls, parent, Parser::StringName);
    Token fname;   fname.setText("__xhpAttributeDeclaration");
    Token param1;  _p->onCall(param1, 0, fname, dummy, &cls);
    Token params1; _p->onCallParam(params1, NULL, param1, 0);

    for (unsigned int i = 0; i < classes.size(); i++) {
      Token parent;  parent.set(T_STRING, classes[i]);
      Token cls;     _p->onName(cls, parent, Parser::StringName);
      Token fname;   fname.setText("__xhpAttributeDeclaration");
      Token param;   _p->onCall(param, 0, fname, dummy, &cls);

      Token params; _p->onCallParam(params, &params1, param, 0);
      params1 = params;
    }

    Token params2; _p->onCallParam(params2, &params1, arrAttributes, 0);

    Token name;    name.set(T_STRING, "array_merge");
    Token call;    _p->onCall(call, 0, name, params2, NULL);
    Token tvar;    tvar.set(T_VARIABLE, "_");
    Token var;     _p->onSimpleVariable(var, tvar);
    Token assign;  _p->onAssign(assign, var, call, 0);
    Token exp;     _p->onExpStatement(exp, assign);
    Token block;   _p->onBlock(block, exp);

    Token tvar2;   tvar2.set(T_VARIABLE, "_");
    Token var2;    _p->onSimpleVariable(var2, tvar2);
    Token one;     scalar_num(_p, one, "1");
    Token mone;    UEXP(mone, one, '-', 1);
    Token cond;    BEXP(cond, var2, mone, T_IS_IDENTICAL);
    Token dummy1, dummy2;
    Token sif;     _p->onIf(sif, cond, block, dummy1, dummy2);
    _p->addStatement(stmts2, stmts1, sif);
  }
  Token stmts3;
  {
    // return $_;
    Token tvar;    tvar.set(T_VARIABLE, "_");
    Token var;     _p->onSimpleVariable(var, tvar);
    Token ret;     _p->onReturn(ret, &var);
    _p->addStatement(stmts3, stmts2, ret);
  }
  Token stmt;
  {
    _p->finishStatement(stmt, stmts3);
    stmt = 1;
  }
  {
    Token params, ret, ref; ref = 1;
    _p->onMethod(out, modifiers, ret, ref, fname, params, stmt, 0, false);
  }
}

static void xhp_collect_attributes(Parser *_p, Token &out, Token &stmts) {
  Token *attr = _p->xhpGetAttributes();
  if (attr) {
    Token stmt;
    xhp_attribute_stmt(_p, stmt, *attr);
    _p->onClassStatement(out, stmts, stmt);
  } else {
    out = stmts;
  }
}

static void xhp_category_stmt(Parser *_p, Token &out, Token &categories) {
  if (!_p->enableXHP()) {
    HPHP_PARSER_ERROR("XHP: not enabled", _p);
  }

  Token fname;     fname.setText("__xhpCategoryDeclaration");
  Token m1;        m1.setNum(T_PROTECTED);
  Token modifiers; _p->onMemberModifier(modifiers, 0, m1);
  _p->pushFuncLocation();
  _p->onMethodStart(fname, modifiers);

  Token stmts0;
  {
    _p->onStatementListStart(stmts0);
  }
  Token stmts1;
  {
    // static $_ = categories;
    Token arr;     _p->onArray(arr, categories);
    Token var;     var.set(T_VARIABLE, "_");
    Token decl;    _p->onStaticVariable(decl, 0, var, &arr);
    Token sdecl;   _p->onStatic(sdecl, decl);
    _p->addStatement(stmts1, stmts0, sdecl);
  }
  Token stmts2;
  {
    // return $_;
    Token tvar;    tvar.set(T_VARIABLE, "_");
    Token var;     _p->onSimpleVariable(var, tvar);
    Token ret;     _p->onReturn(ret, &var);
    _p->addStatement(stmts2, stmts1, ret);
  }
  Token stmt;
  {
    _p->finishStatement(stmt, stmts2);
    stmt = 1;
  }
  {
    Token params, ret, ref; ref = 1;
    _p->onMethod(out, modifiers, ret, ref, fname, params, stmt, 0, false);
  }
}

static void xhp_children_decl_tag(Parser *_p, Token &arr, Token &tag) {
  Token num;  scalar_num(_p, num, tag.num());
  Token arr1; _p->onArrayPair(arr1, &arr, 0, num, 0);

  Token name;
  if (tag.num() == 3 || tag.num() == 4) {
    _p->onScalar(name, T_CONSTANT_ENCAPSED_STRING, tag);
  } else if (tag.num() >= 0) {
    scalar_null(_p, name);
  } else {
    HPHP_PARSER_ERROR("XHP: unknown children declaration", _p);
  }
  Token arr2; _p->onArrayPair(arr2, &arr1, 0, name, 0);
  arr = arr2;
}

static void xhp_children_decl(Parser *_p, Token &out, Token &op1, int op,
                              Token *op2) {
  Token num; scalar_num(_p, num, op);
  Token arr; _p->onArrayPair(arr, 0, 0, num, 0);

  if (op2) {
    Token arr1; _p->onArrayPair(arr1, &arr,  0, op1,  0);
    Token arr2; _p->onArrayPair(arr2, &arr1, 0, *op2, 0);
    _p->onArray(out, arr2);
  } else {
    xhp_children_decl_tag(_p, arr, op1);
    _p->onArray(out, arr);
  }
}

static void xhp_children_paren(Parser *_p, Token &out, Token exp, int op) {
  Token num;  scalar_num(_p, num, op);
  Token arr1; _p->onArrayPair(arr1, 0, 0, num, 0);

  Token num5; scalar_num(_p, num5, 5);
  Token arr2; _p->onArrayPair(arr2, &arr1, 0, num5, 0);

  Token arr3; _p->onArrayPair(arr3, &arr2, 0, exp, 0);
  _p->onArray(out, arr3);
}

static void xhp_children_stmt(Parser *_p, Token &out, Token &children) {
  if (!_p->enableXHP()) {
    HPHP_PARSER_ERROR("XHP: not enabled", _p);
  }

  Token fname;     fname.setText("__xhpChildrenDeclaration");
  Token m1;        m1.setNum(T_PROTECTED);
  Token modifiers; _p->onMemberModifier(modifiers, 0, m1);
  _p->pushFuncLocation();
  _p->onMethodStart(fname, modifiers);

  Token stmts0;
  {
    _p->onStatementListStart(stmts0);
  }
  Token stmts1;
  {
    // static $_ = children;
    Token arr;
    if (children.num() == 2) {
      arr = children;
    } else if (children.num() >= 0) {
      scalar_num(_p, arr, children.num());
    } else {
      HPHP_PARSER_ERROR("XHP: XHP unknown children declaration", _p);
    }
    Token var;     var.set(T_VARIABLE, "_");
    Token decl;    _p->onStaticVariable(decl, 0, var, &arr);
    Token sdecl;   _p->onStatic(sdecl, decl);
    _p->addStatement(stmts1, stmts0, sdecl);
  }
  Token stmts2;
  {
    // return $_;
    Token tvar;    tvar.set(T_VARIABLE, "_");
    Token var;     _p->onSimpleVariable(var, tvar);
    Token ret;     _p->onReturn(ret, &var);
    _p->addStatement(stmts2, stmts1, ret);
  }
  Token stmt;
  {
    _p->finishStatement(stmt, stmts2);
    stmt = 1;
  }
  {
    Token params, ret, ref; ref = 1;
    _p->onMethod(out, modifiers, ret, ref, fname, params, stmt, 0, false);
  }
}

/* This is called from strict-mode productions (sm_*) to throw an
 * error if we're not in strict mode */
static void only_in_strict_mode(Parser *_p) {
  if (!_p->scanner().isStrictMode()) {
    HPHP_PARSER_ERROR("Syntax only allowed in strict mode", _p);
  }
}

///////////////////////////////////////////////////////////////////////////////

static int yylex(YYSTYPE *token, HPHP::Location *loc, Parser *_p) {
  return _p->scan(token, loc);
}


/* Line 189 of yacc.c  */
#line 939 "hphp.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_REQUIRE_ONCE = 258,
     T_REQUIRE = 259,
     T_EVAL = 260,
     T_INCLUDE_ONCE = 261,
     T_INCLUDE = 262,
     T_LOGICAL_OR = 263,
     T_LOGICAL_XOR = 264,
     T_LOGICAL_AND = 265,
     T_PRINT = 266,
     T_SR_EQUAL = 267,
     T_SL_EQUAL = 268,
     T_XOR_EQUAL = 269,
     T_OR_EQUAL = 270,
     T_AND_EQUAL = 271,
     T_MOD_EQUAL = 272,
     T_CONCAT_EQUAL = 273,
     T_DIV_EQUAL = 274,
     T_MUL_EQUAL = 275,
     T_MINUS_EQUAL = 276,
     T_PLUS_EQUAL = 277,
     T_BOOLEAN_OR = 278,
     T_BOOLEAN_AND = 279,
     T_IS_NOT_IDENTICAL = 280,
     T_IS_IDENTICAL = 281,
     T_IS_NOT_EQUAL = 282,
     T_IS_EQUAL = 283,
     T_IS_GREATER_OR_EQUAL = 284,
     T_IS_SMALLER_OR_EQUAL = 285,
     T_SR = 286,
     T_SL = 287,
     T_INSTANCEOF = 288,
     T_UNSET_CAST = 289,
     T_BOOL_CAST = 290,
     T_OBJECT_CAST = 291,
     T_ARRAY_CAST = 292,
     T_STRING_CAST = 293,
     T_DOUBLE_CAST = 294,
     T_INT_CAST = 295,
     T_DEC = 296,
     T_INC = 297,
     T_CLONE = 298,
     T_NEW = 299,
     T_EXIT = 300,
     T_IF = 301,
     T_ELSEIF = 302,
     T_ELSE = 303,
     T_ENDIF = 304,
     T_LNUMBER = 305,
     T_DNUMBER = 306,
     T_STRING = 307,
     T_STRING_VARNAME = 308,
     T_VARIABLE = 309,
     T_NUM_STRING = 310,
     T_INLINE_HTML = 311,
     T_CHARACTER = 312,
     T_BAD_CHARACTER = 313,
     T_ENCAPSED_AND_WHITESPACE = 314,
     T_CONSTANT_ENCAPSED_STRING = 315,
     T_ECHO = 316,
     T_DO = 317,
     T_WHILE = 318,
     T_ENDWHILE = 319,
     T_FOR = 320,
     T_ENDFOR = 321,
     T_FOREACH = 322,
     T_ENDFOREACH = 323,
     T_DECLARE = 324,
     T_ENDDECLARE = 325,
     T_AS = 326,
     T_SWITCH = 327,
     T_ENDSWITCH = 328,
     T_CASE = 329,
     T_DEFAULT = 330,
     T_BREAK = 331,
     T_GOTO = 332,
     T_CONTINUE = 333,
     T_FUNCTION = 334,
     T_CONST = 335,
     T_RETURN = 336,
     T_TRY = 337,
     T_CATCH = 338,
     T_THROW = 339,
     T_USE = 340,
     T_GLOBAL = 341,
     T_PUBLIC = 342,
     T_PROTECTED = 343,
     T_PRIVATE = 344,
     T_FINAL = 345,
     T_ABSTRACT = 346,
     T_STATIC = 347,
     T_VAR = 348,
     T_UNSET = 349,
     T_ISSET = 350,
     T_EMPTY = 351,
     T_HALT_COMPILER = 352,
     T_CLASS = 353,
     T_INTERFACE = 354,
     T_EXTENDS = 355,
     T_IMPLEMENTS = 356,
     T_OBJECT_OPERATOR = 357,
     T_DOUBLE_ARROW = 358,
     T_LIST = 359,
     T_ARRAY = 360,
     T_CLASS_C = 361,
     T_METHOD_C = 362,
     T_FUNC_C = 363,
     T_LINE = 364,
     T_FILE = 365,
     T_COMMENT = 366,
     T_DOC_COMMENT = 367,
     T_OPEN_TAG = 368,
     T_OPEN_TAG_WITH_ECHO = 369,
     T_CLOSE_TAG = 370,
     T_WHITESPACE = 371,
     T_START_HEREDOC = 372,
     T_END_HEREDOC = 373,
     T_DOLLAR_OPEN_CURLY_BRACES = 374,
     T_CURLY_OPEN = 375,
     T_PAAMAYIM_NEKUDOTAYIM = 376,
     T_NAMESPACE = 377,
     T_NS_C = 378,
     T_DIR = 379,
     T_NS_SEPARATOR = 380,
     T_YIELD = 381,
     T_XHP_LABEL = 382,
     T_XHP_TEXT = 383,
     T_XHP_ATTRIBUTE = 384,
     T_XHP_CATEGORY = 385,
     T_XHP_CATEGORY_LABEL = 386,
     T_XHP_CHILDREN = 387,
     T_XHP_ENUM = 388,
     T_XHP_REQUIRED = 389,
     T_TRAIT = 390,
     T_INSTEADOF = 391,
     T_TRAIT_C = 392,
     T_VARARG = 393,
     T_STRICT_INT_MAP = 394,
     T_STRICT_STR_MAP = 395,
     T_STRICT_ERROR = 396,
     T_FINALLY = 397
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int line0;
  int char0;
  int line1;
  int char1;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 1136 "hphp.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
struct yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (struct yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   9462

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  172
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  185
/* YYNRULES -- Number of rules.  */
#define YYNRULES  650
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1194

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   397

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,   170,     2,   167,    47,    31,   171,
     162,   163,    45,    42,     8,    43,    44,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,   164,
      36,    13,    37,    25,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,   169,    30,     2,   168,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   165,    29,   166,    50,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     9,    10,    11,    12,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    27,    28,
      32,    33,    34,    35,    38,    39,    40,    41,    49,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      22,    26,    27,    34,    35,    41,    45,    48,    52,    54,
      56,    59,    63,    68,    70,    74,    76,    79,    83,    85,
      88,    92,    98,   103,   106,   107,   109,   111,   113,   115,
     119,   127,   138,   139,   146,   147,   156,   157,   168,   169,
     176,   179,   183,   186,   190,   193,   197,   201,   205,   211,
     220,   224,   228,   232,   238,   240,   242,   243,   253,   259,
     274,   280,   284,   288,   291,   294,   304,   305,   306,   312,
     314,   315,   317,   318,   320,   321,   333,   334,   347,   348,
     349,   359,   360,   361,   372,   373,   381,   382,   391,   392,
     399,   400,   408,   410,   412,   414,   416,   418,   421,   424,
     427,   428,   431,   432,   435,   436,   438,   442,   444,   448,
     451,   452,   454,   457,   459,   464,   466,   471,   473,   478,
     480,   485,   489,   495,   499,   504,   509,   515,   521,   526,
     527,   529,   531,   538,   539,   547,   548,   551,   552,   556,
     557,   561,   563,   565,   566,   569,   573,   579,   584,   589,
     595,   603,   610,   612,   613,   615,   618,   622,   627,   631,
     633,   635,   638,   643,   647,   653,   655,   659,   662,   663,
     664,   669,   670,   676,   679,   680,   691,   692,   704,   705,
     710,   714,   718,   722,   728,   731,   734,   735,   742,   748,
     753,   757,   759,   761,   762,   767,   772,   774,   776,   778,
     780,   782,   784,   786,   791,   793,   795,   799,   802,   803,
     804,   808,   809,   811,   815,   817,   819,   821,   823,   827,
     832,   837,   842,   844,   846,   849,   852,   855,   859,   863,
     865,   867,   869,   871,   875,   877,   879,   881,   882,   884,
     887,   889,   891,   893,   895,   897,   899,   903,   909,   911,
     915,   921,   926,   930,   932,   934,   935,   937,   944,   948,
     953,   960,   964,   967,   971,   975,   979,   983,   987,   991,
     995,   999,  1003,  1007,  1011,  1014,  1017,  1020,  1023,  1027,
    1031,  1035,  1039,  1043,  1047,  1051,  1055,  1059,  1063,  1067,
    1071,  1075,  1079,  1083,  1087,  1090,  1093,  1096,  1099,  1103,
    1107,  1111,  1115,  1119,  1123,  1127,  1131,  1135,  1139,  1145,
    1150,  1152,  1155,  1158,  1161,  1164,  1167,  1170,  1173,  1176,
    1179,  1181,  1183,  1187,  1190,  1191,  1203,  1205,  1207,  1212,
    1217,  1222,  1224,  1226,  1230,  1235,  1236,  1240,  1245,  1247,
    1250,  1255,  1258,  1259,  1260,  1269,  1270,  1272,  1273,  1279,
    1280,  1283,  1284,  1286,  1288,  1292,  1294,  1298,  1300,  1302,
    1303,  1308,  1309,  1314,  1316,  1317,  1322,  1323,  1328,  1330,
    1332,  1334,  1336,  1338,  1340,  1342,  1344,  1346,  1348,  1350,
    1352,  1354,  1356,  1358,  1360,  1362,  1364,  1366,  1368,  1370,
    1372,  1374,  1376,  1378,  1380,  1382,  1384,  1386,  1388,  1390,
    1392,  1394,  1396,  1398,  1400,  1402,  1404,  1406,  1408,  1410,
    1412,  1414,  1416,  1418,  1420,  1422,  1424,  1426,  1428,  1430,
    1432,  1434,  1436,  1438,  1440,  1442,  1444,  1446,  1448,  1450,
    1452,  1454,  1456,  1458,  1460,  1462,  1464,  1466,  1468,  1470,
    1472,  1474,  1479,  1481,  1483,  1485,  1488,  1490,  1492,  1494,
    1496,  1498,  1500,  1502,  1505,  1509,  1512,  1516,  1517,  1518,
    1520,  1522,  1526,  1527,  1529,  1531,  1533,  1535,  1537,  1539,
    1541,  1543,  1545,  1547,  1549,  1553,  1556,  1558,  1560,  1563,
    1566,  1571,  1573,  1577,  1581,  1583,  1585,  1587,  1589,  1593,
    1597,  1601,  1604,  1605,  1607,  1608,  1614,  1618,  1622,  1624,
    1626,  1628,  1630,  1634,  1637,  1639,  1641,  1643,  1645,  1647,
    1650,  1653,  1658,  1662,  1665,  1666,  1672,  1676,  1680,  1682,
    1686,  1688,  1691,  1692,  1696,  1697,  1702,  1705,  1706,  1710,
    1714,  1716,  1718,  1720,  1722,  1727,  1732,  1736,  1740,  1746,
    1750,  1755,  1757,  1759,  1761,  1766,  1771,  1775,  1781,  1786,
    1788,  1793,  1798,  1805,  1812,  1821,  1828,  1835,  1837,  1840,
    1845,  1850,  1852,  1854,  1859,  1861,  1862,  1864,  1867,  1869,
    1874,  1879,  1883,  1887,  1893,  1897,  1902,  1907,  1911,  1917,
    1920,  1924,  1931,  1932,  1934,  1939,  1942,  1943,  1949,  1953,
    1957,  1959,  1966,  1971,  1976,  1979,  1982,  1985,  1987,  1990,
    1992,  1997,  2001,  2005,  2012,  2016,  2018,  2020,  2022,  2027,
    2032,  2035,  2038,  2043,  2046,  2049,  2051,  2055,  2059,  2061,
    2064,  2066,  2071,  2074,  2075,  2080,  2083,  2087,  2089,  2093,
    2094,  2097,  2101,  2103,  2106,  2109,  2111,  2113,  2122,  2128,
    2130
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     173,     0,    -1,   174,    -1,   174,   175,    -1,    -1,   186,
      -1,   198,    -1,   201,    -1,   208,    -1,   116,   162,   163,
     164,    -1,   141,   180,   164,    -1,    -1,   141,   180,   165,
     176,   174,   166,    -1,    -1,   141,   165,   177,   174,   166,
      -1,   104,   178,   164,    -1,   183,   164,    -1,   178,     8,
     179,    -1,   179,    -1,   180,    -1,   144,   180,    -1,   180,
      90,    71,    -1,   144,   180,    90,    71,    -1,    71,    -1,
     180,   144,    71,    -1,   180,    -1,   144,   180,    -1,   141,
     144,   180,    -1,   180,    -1,   144,   180,    -1,   141,   144,
     180,    -1,   183,     8,   348,    13,   309,    -1,    99,   348,
      13,   309,    -1,   184,   185,    -1,    -1,   186,    -1,   198,
      -1,   201,    -1,   208,    -1,   165,   184,   166,    -1,    65,
     162,   275,   163,   186,   230,   232,    -1,    65,   162,   275,
     163,    26,   184,   231,   233,    68,   164,    -1,    -1,    82,
     162,   275,   163,   187,   224,    -1,    -1,    81,   188,   186,
      82,   162,   275,   163,   164,    -1,    -1,    84,   162,   274,
     164,   274,   164,   274,   163,   189,   222,    -1,    -1,    91,
     162,   275,   163,   190,   227,    -1,    95,   164,    -1,    95,
     275,   164,    -1,    97,   164,    -1,    97,   275,   164,    -1,
     100,   164,    -1,   100,   275,   164,    -1,   145,    95,   164,
      -1,   145,   275,   164,    -1,   327,    13,   145,   275,   164,
      -1,   123,   162,   339,   163,    13,   145,   275,   164,    -1,
     105,   238,   164,    -1,   111,   240,   164,    -1,    80,   273,
     164,    -1,   113,   162,   346,   163,   164,    -1,   164,    -1,
      75,    -1,    -1,    86,   162,   275,    90,   221,   220,   163,
     191,   223,    -1,    88,   162,   226,   163,   225,    -1,   101,
     165,   184,   166,   102,   162,   302,    73,   163,   165,   184,
     166,   192,   195,    -1,   101,   165,   184,   166,   193,    -1,
     103,   275,   164,    -1,    96,    71,   164,    -1,   275,   164,
      -1,    71,    26,    -1,   192,   102,   162,   302,    73,   163,
     165,   184,   166,    -1,    -1,    -1,   194,   161,   165,   184,
     166,    -1,   193,    -1,    -1,    31,    -1,    -1,    98,    -1,
      -1,   197,   196,   349,   199,   162,   234,   163,   353,   165,
     184,   166,    -1,    -1,   326,   197,   196,   349,   200,   162,
     234,   163,   353,   165,   184,   166,    -1,    -1,    -1,   214,
     211,   202,   215,   216,   165,   203,   241,   166,    -1,    -1,
      -1,   326,   214,   211,   204,   215,   216,   165,   205,   241,
     166,    -1,    -1,   118,   212,   206,   217,   165,   241,   166,
      -1,    -1,   326,   118,   212,   207,   217,   165,   241,   166,
      -1,    -1,   154,   213,   209,   165,   241,   166,    -1,    -1,
     326,   154,   213,   210,   165,   241,   166,    -1,   349,    -1,
     146,    -1,   349,    -1,   349,    -1,   117,    -1,   110,   117,
      -1,   109,   117,    -1,   119,   302,    -1,    -1,   120,   218,
      -1,    -1,   119,   218,    -1,    -1,   302,    -1,   218,     8,
     302,    -1,   302,    -1,   219,     8,   302,    -1,   122,   221,
      -1,    -1,   327,    -1,    31,   327,    -1,   186,    -1,    26,
     184,    85,   164,    -1,   186,    -1,    26,   184,    87,   164,
      -1,   186,    -1,    26,   184,    83,   164,    -1,   186,    -1,
      26,   184,    89,   164,    -1,    71,    13,   309,    -1,   226,
       8,    71,    13,   309,    -1,   165,   228,   166,    -1,   165,
     164,   228,   166,    -1,    26,   228,    92,   164,    -1,    26,
     164,   228,    92,   164,    -1,   228,    93,   275,   229,   184,
      -1,   228,    94,   229,   184,    -1,    -1,    26,    -1,   164,
      -1,   230,    66,   162,   275,   163,   186,    -1,    -1,   231,
      66,   162,   275,   163,    26,   184,    -1,    -1,    67,   186,
      -1,    -1,    67,    26,   184,    -1,    -1,   235,     8,   157,
      -1,   235,    -1,   157,    -1,    -1,   356,    73,    -1,   356,
      31,    73,    -1,   356,    31,    73,    13,   309,    -1,   356,
      73,    13,   309,    -1,   235,     8,   356,    73,    -1,   235,
       8,   356,    31,    73,    -1,   235,     8,   356,    31,    73,
      13,   309,    -1,   235,     8,   356,    73,    13,   309,    -1,
     237,    -1,    -1,   275,    -1,    31,   327,    -1,   237,     8,
     275,    -1,   237,     8,    31,   327,    -1,   238,     8,   239,
      -1,   239,    -1,    73,    -1,   167,   327,    -1,   167,   165,
     275,   166,    -1,   240,     8,    73,    -1,   240,     8,    73,
      13,   309,    -1,    73,    -1,    73,    13,   309,    -1,   241,
     242,    -1,    -1,    -1,   267,   243,   271,   164,    -1,    -1,
     269,   355,   244,   271,   164,    -1,   272,   164,    -1,    -1,
     268,   197,   196,   349,   162,   245,   234,   163,   353,   266,
      -1,    -1,   326,   268,   197,   196,   349,   162,   246,   234,
     163,   353,   266,    -1,    -1,   148,   247,   252,   164,    -1,
     149,   260,   164,    -1,   151,   262,   164,    -1,   104,   219,
     164,    -1,   104,   219,   165,   248,   166,    -1,   248,   249,
      -1,   248,   250,    -1,    -1,   182,   140,    71,   155,   219,
     164,    -1,   251,    90,   268,    71,   164,    -1,   251,    90,
     269,   164,    -1,   182,   140,    71,    -1,    71,    -1,   254,
      -1,    -1,   252,     8,   253,   254,    -1,   255,   296,   257,
     258,    -1,   146,    -1,    56,    -1,    53,    -1,    58,    -1,
      55,    -1,   302,    -1,   112,    -1,   152,   165,   256,   166,
      -1,    57,    -1,   308,    -1,   256,     8,   308,    -1,    13,
     309,    -1,    -1,    -1,    51,   259,   153,    -1,    -1,   261,
      -1,   260,     8,   261,    -1,   150,    -1,   263,    -1,    71,
      -1,   115,    -1,   162,   264,   163,    -1,   162,   264,   163,
      45,    -1,   162,   264,   163,    25,    -1,   162,   264,   163,
      42,    -1,   263,    -1,   265,    -1,   265,    45,    -1,   265,
      25,    -1,   265,    42,    -1,   264,     8,   264,    -1,   264,
      29,   264,    -1,    71,    -1,   146,    -1,   150,    -1,   164,
      -1,   165,   184,   166,    -1,   269,    -1,   112,    -1,   269,
      -1,    -1,   270,    -1,   269,   270,    -1,   106,    -1,   107,
      -1,   108,    -1,   111,    -1,   110,    -1,   109,    -1,   271,
       8,    73,    -1,   271,     8,    73,    13,   309,    -1,    73,
      -1,    73,    13,   309,    -1,   272,     8,   348,    13,   309,
      -1,    99,   348,    13,   309,    -1,   273,     8,   275,    -1,
     275,    -1,   273,    -1,    -1,   327,    -1,   123,   162,   339,
     163,    13,   275,    -1,   327,    13,   275,    -1,   327,    13,
      31,   327,    -1,   327,    13,    31,    63,   304,   307,    -1,
      63,   304,   307,    -1,    62,   275,    -1,   327,    24,   275,
      -1,   327,    23,   275,    -1,   327,    22,   275,    -1,   327,
      21,   275,    -1,   327,    20,   275,    -1,   327,    19,   275,
      -1,   327,    18,   275,    -1,   327,    17,   275,    -1,   327,
      16,   275,    -1,   327,    15,   275,    -1,   327,    14,   275,
      -1,   327,    60,    -1,    60,   327,    -1,   327,    59,    -1,
      59,   327,    -1,   275,    27,   275,    -1,   275,    28,   275,
      -1,   275,     9,   275,    -1,   275,    11,   275,    -1,   275,
      10,   275,    -1,   275,    29,   275,    -1,   275,    31,   275,
      -1,   275,    30,   275,    -1,   275,    44,   275,    -1,   275,
      42,   275,    -1,   275,    43,   275,    -1,   275,    45,   275,
      -1,   275,    46,   275,    -1,   275,    47,   275,    -1,   275,
      41,   275,    -1,   275,    40,   275,    -1,    42,   275,    -1,
      43,   275,    -1,    48,   275,    -1,    50,   275,    -1,   275,
      33,   275,    -1,   275,    32,   275,    -1,   275,    35,   275,
      -1,   275,    34,   275,    -1,   275,    36,   275,    -1,   275,
      39,   275,    -1,   275,    37,   275,    -1,   275,    38,   275,
      -1,   275,    49,   304,    -1,   162,   275,   163,    -1,   275,
      25,   275,    26,   275,    -1,   275,    25,    26,   275,    -1,
     345,    -1,    58,   275,    -1,    57,   275,    -1,    56,   275,
      -1,    55,   275,    -1,    54,   275,    -1,    53,   275,    -1,
      52,   275,    -1,    64,   305,    -1,    51,   275,    -1,   311,
      -1,   277,    -1,   168,   306,   168,    -1,    12,   275,    -1,
      -1,   197,   196,   162,   276,   234,   163,   353,   280,   165,
     184,   166,    -1,   282,    -1,   278,    -1,   124,   162,   340,
     163,    -1,   278,    61,   335,   169,    -1,   279,    61,   335,
     169,    -1,   277,    -1,   347,    -1,   162,   275,   163,    -1,
     104,   162,   281,   163,    -1,    -1,   281,     8,    73,    -1,
     281,     8,    31,    73,    -1,    73,    -1,    31,    73,    -1,
      36,   293,   283,    37,    -1,   287,    46,    -1,    -1,    -1,
     287,    37,   284,   289,    36,    46,   285,   286,    -1,    -1,
     146,    -1,    -1,   287,   290,    13,   288,   291,    -1,    -1,
     289,   292,    -1,    -1,   296,    -1,   147,    -1,   165,   275,
     166,    -1,   147,    -1,   165,   275,   166,    -1,   282,    -1,
     299,    -1,    -1,   293,    26,   294,   299,    -1,    -1,   293,
      43,   295,   299,    -1,   299,    -1,    -1,   296,    26,   297,
     299,    -1,    -1,   296,    43,   298,   299,    -1,    71,    -1,
      64,    -1,    98,    -1,    99,    -1,   100,    -1,   145,    -1,
     101,    -1,   102,    -1,   161,    -1,   103,    -1,    65,    -1,
      66,    -1,    68,    -1,    67,    -1,    82,    -1,    83,    -1,
      81,    -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,
      88,    -1,    89,    -1,    49,    -1,    90,    -1,    91,    -1,
      92,    -1,    93,    -1,    94,    -1,    95,    -1,    97,    -1,
      96,    -1,    80,    -1,    12,    -1,   117,    -1,   118,    -1,
     119,    -1,   120,    -1,    63,    -1,    62,    -1,   112,    -1,
       5,    -1,     7,    -1,     6,    -1,     4,    -1,     3,    -1,
     141,    -1,   104,    -1,   105,    -1,   114,    -1,   115,    -1,
     116,    -1,   111,    -1,   110,    -1,   109,    -1,   108,    -1,
     107,    -1,   106,    -1,   113,    -1,   123,    -1,   124,    -1,
       9,    -1,    11,    -1,    10,    -1,   125,    -1,   127,    -1,
     126,    -1,   128,    -1,   129,    -1,   143,    -1,   142,    -1,
     154,    -1,   156,    -1,   181,   162,   236,   163,    -1,   303,
      -1,   111,    -1,   333,    -1,   182,   350,    -1,   146,    -1,
     182,    -1,   146,    -1,   337,    -1,   111,    -1,   146,    -1,
     180,    -1,   144,   180,    -1,   141,   144,   180,    -1,   162,
     163,    -1,   162,   275,   163,    -1,    -1,    -1,    78,    -1,
     342,    -1,   162,   236,   163,    -1,    -1,    69,    -1,    70,
      -1,    79,    -1,   128,    -1,   129,    -1,   143,    -1,   125,
      -1,   156,    -1,   126,    -1,   127,    -1,   142,    -1,   136,
      78,   137,    -1,   136,   137,    -1,   308,    -1,   181,    -1,
      42,   309,    -1,    43,   309,    -1,   124,   162,   312,   163,
      -1,   310,    -1,   182,   140,    71,    -1,   146,   140,    71,
      -1,   181,    -1,    72,    -1,   347,    -1,   308,    -1,   170,
     342,   170,    -1,   171,   342,   171,    -1,   136,   342,   137,
      -1,   314,   313,    -1,    -1,     8,    -1,    -1,   314,     8,
     309,   122,   309,    -1,   314,     8,   309,    -1,   309,   122,
     309,    -1,   309,    -1,    69,    -1,    70,    -1,    79,    -1,
     136,    78,   137,    -1,   136,   137,    -1,    69,    -1,    70,
      -1,    71,    -1,   315,    -1,    71,    -1,    42,   316,    -1,
      43,   316,    -1,   124,   162,   318,   163,    -1,    61,   318,
     169,    -1,   319,   313,    -1,    -1,   319,     8,   317,   122,
     317,    -1,   319,     8,   317,    -1,   317,   122,   317,    -1,
     317,    -1,   320,     8,   317,    -1,   317,    -1,   320,   313,
      -1,    -1,   162,   321,   163,    -1,    -1,   323,     8,    71,
     322,    -1,    71,   322,    -1,    -1,   325,   323,   313,    -1,
      41,   324,    40,    -1,   332,    -1,   300,    -1,   330,    -1,
     331,    -1,   328,    61,   335,   169,    -1,   328,   165,   275,
     166,    -1,   327,   121,    71,    -1,   327,   121,   332,    -1,
     327,   121,   165,   275,   166,    -1,   301,   140,   332,    -1,
     329,   162,   236,   163,    -1,   300,    -1,   330,    -1,   331,
      -1,   328,    61,   335,   169,    -1,   328,   165,   275,   166,
      -1,   327,   121,    71,    -1,   327,   121,   165,   275,   166,
      -1,   329,   162,   236,   163,    -1,   332,    -1,   328,    61,
     335,   169,    -1,   328,   165,   275,   166,    -1,   327,   121,
      71,   162,   236,   163,    -1,   327,   121,   332,   162,   236,
     163,    -1,   327,   121,   165,   275,   166,   162,   236,   163,
      -1,   301,   140,    71,   162,   236,   163,    -1,   301,   140,
     332,   162,   236,   163,    -1,   333,    -1,   336,   333,    -1,
     333,    61,   335,   169,    -1,   333,   165,   275,   166,    -1,
     334,    -1,    73,    -1,   167,   165,   275,   166,    -1,   275,
      -1,    -1,   167,    -1,   336,   167,    -1,   332,    -1,   338,
      61,   335,   169,    -1,   338,   165,   275,   166,    -1,   337,
     121,    71,    -1,   337,   121,   332,    -1,   337,   121,   165,
     275,   166,    -1,   301,   140,   332,    -1,   338,    61,   335,
     169,    -1,   338,   165,   275,   166,    -1,   337,   121,    71,
      -1,   337,   121,   165,   275,   166,    -1,   339,     8,    -1,
     339,     8,   327,    -1,   339,     8,   123,   162,   339,   163,
      -1,    -1,   327,    -1,   123,   162,   339,   163,    -1,   341,
     313,    -1,    -1,   341,     8,   275,   122,   275,    -1,   341,
       8,   275,    -1,   275,   122,   275,    -1,   275,    -1,   341,
       8,   275,   122,    31,   327,    -1,   341,     8,    31,   327,
      -1,   275,   122,    31,   327,    -1,    31,   327,    -1,   342,
     343,    -1,   342,    78,    -1,   343,    -1,    78,   343,    -1,
      73,    -1,    73,    61,   344,   169,    -1,    73,   121,    71,
      -1,   138,   275,   166,    -1,   138,    72,    61,   275,   169,
     166,    -1,   139,   327,   166,    -1,    71,    -1,    74,    -1,
      73,    -1,   114,   162,   346,   163,    -1,   115,   162,   327,
     163,    -1,     7,   275,    -1,     6,   275,    -1,     5,   162,
     275,   163,    -1,     4,   275,    -1,     3,   275,    -1,   327,
      -1,   346,     8,   327,    -1,   301,   140,    71,    -1,    71,
      -1,   355,    71,    -1,    71,    -1,    71,    36,   354,    37,
      -1,    36,   351,    -1,    -1,    71,    36,   352,    40,    -1,
     355,    37,    -1,   355,     8,   351,    -1,   355,    -1,   355,
       8,   352,    -1,    -1,    26,   355,    -1,    71,     8,   354,
      -1,    71,    -1,    25,   355,    -1,    71,   350,    -1,   124,
      -1,   146,    -1,   162,    98,   162,   352,   163,    26,   355,
     163,    -1,   162,   355,     8,   352,   163,    -1,   355,    -1,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   987,   987,   992,   994,   997,   999,  1000,  1001,  1002,
    1003,  1005,  1005,  1007,  1007,  1009,  1010,  1015,  1017,  1020,
    1021,  1022,  1023,  1027,  1028,  1032,  1034,  1035,  1039,  1041,
    1042,  1046,  1049,  1054,  1056,  1059,  1060,  1061,  1062,  1065,
    1066,  1070,  1075,  1075,  1079,  1079,  1083,  1082,  1086,  1086,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,
    1100,  1101,  1102,  1103,  1104,  1105,  1108,  1106,  1112,  1114,
    1122,  1125,  1126,  1130,  1131,  1138,  1144,  1148,  1148,  1154,
    1155,  1159,  1160,  1164,  1169,  1168,  1179,  1178,  1192,  1194,
    1191,  1212,  1214,  1210,  1231,  1230,  1239,  1237,  1249,  1248,
    1259,  1257,  1269,  1270,  1274,  1277,  1280,  1281,  1282,  1285,
    1287,  1290,  1291,  1294,  1295,  1298,  1299,  1303,  1304,  1309,
    1310,  1313,  1314,  1318,  1319,  1323,  1324,  1328,  1329,  1333,
    1334,  1339,  1340,  1345,  1346,  1347,  1348,  1351,  1354,  1356,
    1359,  1360,  1364,  1366,  1369,  1372,  1375,  1376,  1379,  1380,
    1384,  1386,  1387,  1388,  1392,  1393,  1394,  1396,  1398,  1400,
    1402,  1405,  1411,  1412,  1415,  1416,  1417,  1419,  1424,  1425,
    1428,  1429,  1430,  1434,  1435,  1437,  1438,  1442,  1446,  1449,
    1449,  1453,  1452,  1456,  1460,  1458,  1472,  1469,  1481,  1481,
    1483,  1485,  1487,  1489,  1493,  1494,  1495,  1498,  1504,  1507,
    1513,  1516,  1520,  1522,  1522,  1527,  1532,  1536,  1537,  1538,
    1539,  1540,  1541,  1542,  1544,  1548,  1549,  1554,  1555,  1559,
    1559,  1561,  1565,  1567,  1573,  1578,  1579,  1581,  1585,  1586,
    1587,  1588,  1592,  1593,  1594,  1595,  1596,  1597,  1599,  1604,
    1607,  1608,  1612,  1613,  1616,  1617,  1620,  1621,  1624,  1625,
    1629,  1630,  1631,  1632,  1633,  1634,  1637,  1639,  1641,  1642,
    1645,  1647,  1651,  1652,  1656,  1657,  1661,  1662,  1664,  1665,
    1666,  1669,  1671,  1672,  1673,  1674,  1675,  1676,  1677,  1678,
    1679,  1680,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,
    1689,  1690,  1691,  1692,  1693,  1694,  1695,  1696,  1697,  1698,
    1699,  1700,  1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,
    1709,  1710,  1711,  1712,  1714,  1715,  1717,  1719,  1720,  1721,
    1722,  1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,
    1732,  1733,  1734,  1735,  1736,  1736,  1743,  1744,  1748,  1752,
    1754,  1759,  1760,  1761,  1765,  1766,  1770,  1771,  1772,  1773,
    1777,  1780,  1786,  1787,  1786,  1795,  1796,  1800,  1799,  1802,
    1805,  1806,  1809,  1813,  1816,  1819,  1826,  1827,  1830,  1831,
    1831,  1833,  1833,  1837,  1838,  1838,  1840,  1840,  1844,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,  1855,
    1856,  1857,  1858,  1859,  1860,  1861,  1862,  1863,  1864,  1865,
    1866,  1867,  1868,  1869,  1870,  1871,  1872,  1873,  1874,  1875,
    1876,  1877,  1878,  1879,  1880,  1881,  1882,  1883,  1884,  1885,
    1886,  1887,  1888,  1889,  1890,  1891,  1892,  1893,  1894,  1895,
    1896,  1897,  1898,  1899,  1900,  1901,  1902,  1903,  1904,  1905,
    1906,  1907,  1908,  1909,  1910,  1911,  1912,  1913,  1914,  1915,
    1916,  1920,  1925,  1927,  1928,  1932,  1933,  1936,  1937,  1940,
    1941,  1942,  1944,  1946,  1947,  1953,  1954,  1955,  1959,  1960,
    1961,  1964,  1966,  1970,  1971,  1972,  1974,  1975,  1976,  1977,
    1978,  1979,  1980,  1981,  1982,  1985,  1990,  1991,  1992,  1993,
    1994,  1996,  1999,  2002,  2007,  2008,  2009,  2010,  2011,  2012,
    2013,  2018,  2020,  2023,  2024,  2027,  2030,  2032,  2034,  2038,
    2039,  2040,  2042,  2045,  2049,  2050,  2051,  2054,  2055,  2056,
    2057,  2058,  2060,  2063,  2065,  2068,  2071,  2073,  2075,  2078,
    2080,  2083,  2085,  2088,  2089,  2093,  2096,  2100,  2100,  2105,
    2108,  2109,  2110,  2111,  2112,  2114,  2115,  2117,  2119,  2121,
    2124,  2129,  2130,  2131,  2132,  2134,  2135,  2137,  2139,  2144,
    2145,  2147,  2151,  2154,  2157,  2163,  2167,  2174,  2175,  2180,
    2182,  2183,  2186,  2187,  2190,  2191,  2195,  2196,  2200,  2201,
    2203,  2205,  2207,  2209,  2211,  2217,  2219,  2221,  2223,  2228,
    2229,  2230,  2232,  2233,  2234,  2238,  2240,  2243,  2245,  2246,
    2247,  2248,  2251,  2253,  2254,  2258,  2259,  2261,  2262,  2268,
    2269,  2271,  2273,  2275,  2277,  2280,  2281,  2282,  2286,  2287,
    2288,  2289,  2290,  2291,  2292,  2296,  2297,  2301,  2310,  2311,
    2317,  2318,  2323,  2324,  2329,  2330,  2331,  2335,  2336,  2340,
    2341,  2345,  2346,  2353,  2354,  2363,  2364,  2365,  2367,  2371,
    2372
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_REQUIRE_ONCE", "T_REQUIRE", "T_EVAL",
  "T_INCLUDE_ONCE", "T_INCLUDE", "','", "T_LOGICAL_OR", "T_LOGICAL_XOR",
  "T_LOGICAL_AND", "T_PRINT", "'='", "T_SR_EQUAL", "T_SL_EQUAL",
  "T_XOR_EQUAL", "T_OR_EQUAL", "T_AND_EQUAL", "T_MOD_EQUAL",
  "T_CONCAT_EQUAL", "T_DIV_EQUAL", "T_MUL_EQUAL", "T_MINUS_EQUAL",
  "T_PLUS_EQUAL", "'?'", "':'", "T_BOOLEAN_OR", "T_BOOLEAN_AND", "'|'",
  "'^'", "'&'", "T_IS_NOT_IDENTICAL", "T_IS_IDENTICAL", "T_IS_NOT_EQUAL",
  "T_IS_EQUAL", "'<'", "'>'", "T_IS_GREATER_OR_EQUAL",
  "T_IS_SMALLER_OR_EQUAL", "T_SR", "T_SL", "'+'", "'-'", "'.'", "'*'",
  "'/'", "'%'", "'!'", "T_INSTANCEOF", "'~'", "'@'", "T_UNSET_CAST",
  "T_BOOL_CAST", "T_OBJECT_CAST", "T_ARRAY_CAST", "T_STRING_CAST",
  "T_DOUBLE_CAST", "T_INT_CAST", "T_DEC", "T_INC", "'['", "T_CLONE",
  "T_NEW", "T_EXIT", "T_IF", "T_ELSEIF", "T_ELSE", "T_ENDIF", "T_LNUMBER",
  "T_DNUMBER", "T_STRING", "T_STRING_VARNAME", "T_VARIABLE",
  "T_NUM_STRING", "T_INLINE_HTML", "T_CHARACTER", "T_BAD_CHARACTER",
  "T_ENCAPSED_AND_WHITESPACE", "T_CONSTANT_ENCAPSED_STRING", "T_ECHO",
  "T_DO", "T_WHILE", "T_ENDWHILE", "T_FOR", "T_ENDFOR", "T_FOREACH",
  "T_ENDFOREACH", "T_DECLARE", "T_ENDDECLARE", "T_AS", "T_SWITCH",
  "T_ENDSWITCH", "T_CASE", "T_DEFAULT", "T_BREAK", "T_GOTO", "T_CONTINUE",
  "T_FUNCTION", "T_CONST", "T_RETURN", "T_TRY", "T_CATCH", "T_THROW",
  "T_USE", "T_GLOBAL", "T_PUBLIC", "T_PROTECTED", "T_PRIVATE", "T_FINAL",
  "T_ABSTRACT", "T_STATIC", "T_VAR", "T_UNSET", "T_ISSET", "T_EMPTY",
  "T_HALT_COMPILER", "T_CLASS", "T_INTERFACE", "T_EXTENDS", "T_IMPLEMENTS",
  "T_OBJECT_OPERATOR", "T_DOUBLE_ARROW", "T_LIST", "T_ARRAY", "T_CLASS_C",
  "T_METHOD_C", "T_FUNC_C", "T_LINE", "T_FILE", "T_COMMENT",
  "T_DOC_COMMENT", "T_OPEN_TAG", "T_OPEN_TAG_WITH_ECHO", "T_CLOSE_TAG",
  "T_WHITESPACE", "T_START_HEREDOC", "T_END_HEREDOC",
  "T_DOLLAR_OPEN_CURLY_BRACES", "T_CURLY_OPEN", "T_PAAMAYIM_NEKUDOTAYIM",
  "T_NAMESPACE", "T_NS_C", "T_DIR", "T_NS_SEPARATOR", "T_YIELD",
  "T_XHP_LABEL", "T_XHP_TEXT", "T_XHP_ATTRIBUTE", "T_XHP_CATEGORY",
  "T_XHP_CATEGORY_LABEL", "T_XHP_CHILDREN", "T_XHP_ENUM", "T_XHP_REQUIRED",
  "T_TRAIT", "T_INSTEADOF", "T_TRAIT_C", "T_VARARG", "T_STRICT_INT_MAP",
  "T_STRICT_STR_MAP", "T_STRICT_ERROR", "T_FINALLY", "'('", "')'", "';'",
  "'{'", "'}'", "'$'", "'`'", "']'", "'\"'", "'\\''", "$accept", "start",
  "top_statement_list", "top_statement", "$@1", "$@2", "use_declarations",
  "use_declaration", "namespace_name", "namespace_string",
  "class_namespace_string", "constant_declaration", "inner_statement_list",
  "inner_statement", "statement", "$@3", "$@4", "$@5", "$@6", "$@7",
  "additional_catches", "finally", "$@8", "optional_finally",
  "is_reference", "function_loc", "function_declaration_statement", "$@9",
  "$@10", "class_declaration_statement", "$@11", "$@12", "$@13", "$@14",
  "$@15", "$@16", "trait_declaration_statement", "$@17", "$@18",
  "class_decl_name", "interface_decl_name", "trait_decl_name",
  "class_entry_type", "extends_from", "implements_list",
  "interface_extends_list", "interface_list", "trait_list",
  "foreach_optional_arg", "foreach_variable", "for_statement",
  "foreach_statement", "while_statement", "declare_statement",
  "declare_list", "switch_case_list", "case_list", "case_separator",
  "elseif_list", "new_elseif_list", "else_single", "new_else_single",
  "parameter_list", "non_empty_parameter_list",
  "function_call_parameter_list", "non_empty_fcall_parameter_list",
  "global_var_list", "global_var", "static_var_list",
  "class_statement_list", "class_statement", "$@19", "$@20", "$@21",
  "$@22", "$@23", "trait_rules", "trait_precedence_rule",
  "trait_alias_rule", "trait_alias_rule_method", "xhp_attribute_stmt",
  "$@24", "xhp_attribute_decl", "xhp_attribute_decl_type",
  "xhp_attribute_enum", "xhp_attribute_default",
  "xhp_attribute_is_required", "$@25", "xhp_category_stmt",
  "xhp_category_decl", "xhp_children_stmt", "xhp_children_paren_expr",
  "xhp_children_decl_expr", "xhp_children_decl_tag", "method_body",
  "variable_modifiers", "method_modifiers", "non_empty_member_modifiers",
  "member_modifier", "class_variable_declaration",
  "class_constant_declaration", "expr_list", "for_expr", "expr", "$@26",
  "array_literal", "dim_expr", "dim_expr_base", "lexical_vars",
  "lexical_var_list", "xhp_tag", "xhp_tag_body", "$@27", "$@28",
  "xhp_opt_end_label", "xhp_attributes", "$@29", "xhp_children",
  "xhp_attribute_name", "xhp_attribute_value", "xhp_child", "xhp_label",
  "$@30", "$@31", "xhp_label_ws", "$@32", "$@33", "xhp_bareword",
  "simple_function_call", "static_class_name",
  "fully_qualified_class_name", "fully_qualified_class_name_no_typeargs",
  "class_name_reference", "exit_expr", "backticks_expr", "ctor_arguments",
  "common_scalar", "static_scalar", "static_class_constant", "scalar",
  "static_array_pair_list", "possible_comma",
  "non_empty_static_array_pair_list", "common_scalar_ae",
  "static_numeric_scalar_ae", "static_scalar_ae",
  "static_array_pair_list_ae", "non_empty_static_array_pair_list_ae",
  "non_empty_static_scalar_list_ae", "static_scalar_list_ae",
  "attribute_static_scalar_list", "non_empty_user_attribute_list",
  "user_attribute_list", "$@34", "non_empty_user_attributes", "variable",
  "dimmable_variable", "callable_variable", "object_method_call",
  "class_method_call", "variable_without_objects", "reference_variable",
  "compound_variable", "dim_offset", "simple_indirect_reference",
  "variable_no_calls", "dimmable_variable_no_calls", "assignment_list",
  "array_pair_list", "non_empty_array_pair_list", "encaps_list",
  "encaps_var", "encaps_var_offset", "internal_functions", "variable_list",
  "class_constant", "sm_name_with_type", "sm_name_with_typevar",
  "sm_typeargs_opt", "sm_type_list_gt", "sm_type_list",
  "sm_opt_return_type", "sm_typevar_list", "sm_type", "sm_type_opt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,    44,   263,
     264,   265,   266,    61,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,    63,    58,   278,   279,   124,
      94,    38,   280,   281,   282,   283,    60,    62,   284,   285,
     286,   287,    43,    45,    46,    42,    47,    37,    33,   288,
     126,    64,   289,   290,   291,   292,   293,   294,   295,   296,
     297,    91,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,    40,    41,    59,   123,   125,    36,    96,    93,
      34,    39
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   172,   173,   174,   174,   175,   175,   175,   175,   175,
     175,   176,   175,   177,   175,   175,   175,   178,   178,   179,
     179,   179,   179,   180,   180,   181,   181,   181,   182,   182,
     182,   183,   183,   184,   184,   185,   185,   185,   185,   186,
     186,   186,   187,   186,   188,   186,   189,   186,   190,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   191,   186,   186,   186,
     186,   186,   186,   186,   186,   192,   192,   194,   193,   195,
     195,   196,   196,   197,   199,   198,   200,   198,   202,   203,
     201,   204,   205,   201,   206,   201,   207,   201,   209,   208,
     210,   208,   211,   211,   212,   213,   214,   214,   214,   215,
     215,   216,   216,   217,   217,   218,   218,   219,   219,   220,
     220,   221,   221,   222,   222,   223,   223,   224,   224,   225,
     225,   226,   226,   227,   227,   227,   227,   228,   228,   228,
     229,   229,   230,   230,   231,   231,   232,   232,   233,   233,
     234,   234,   234,   234,   235,   235,   235,   235,   235,   235,
     235,   235,   236,   236,   237,   237,   237,   237,   238,   238,
     239,   239,   239,   240,   240,   240,   240,   241,   241,   243,
     242,   244,   242,   242,   245,   242,   246,   242,   247,   242,
     242,   242,   242,   242,   248,   248,   248,   249,   250,   250,
     251,   251,   252,   253,   252,   254,   254,   255,   255,   255,
     255,   255,   255,   255,   255,   256,   256,   257,   257,   259,
     258,   258,   260,   260,   261,   262,   262,   262,   263,   263,
     263,   263,   264,   264,   264,   264,   264,   264,   264,   265,
     265,   265,   266,   266,   267,   267,   268,   268,   269,   269,
     270,   270,   270,   270,   270,   270,   271,   271,   271,   271,
     272,   272,   273,   273,   274,   274,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   276,   275,   275,   275,   277,   278,
     278,   279,   279,   279,   280,   280,   281,   281,   281,   281,
     282,   283,   284,   285,   283,   286,   286,   288,   287,   287,
     289,   289,   290,   291,   291,   292,   292,   292,   293,   294,
     293,   295,   293,   296,   297,   296,   298,   296,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   300,   301,   301,   301,   302,   302,   303,   303,   304,
     304,   304,   304,   304,   304,   305,   305,   305,   306,   306,
     306,   307,   307,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   309,   309,   309,   309,
     309,   309,   310,   310,   311,   311,   311,   311,   311,   311,
     311,   312,   312,   313,   313,   314,   314,   314,   314,   315,
     315,   315,   315,   315,   316,   316,   316,   317,   317,   317,
     317,   317,   317,   318,   318,   319,   319,   319,   319,   320,
     320,   321,   321,   322,   322,   323,   323,   325,   324,   326,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   328,   328,   328,   328,   328,   328,   328,   328,   329,
     329,   329,   330,   330,   330,   331,   331,   332,   332,   333,
     333,   333,   334,   334,   335,   335,   336,   336,   337,   337,
     337,   337,   337,   337,   337,   338,   338,   338,   338,   339,
     339,   339,   339,   339,   339,   340,   340,   341,   341,   341,
     341,   341,   341,   341,   341,   342,   342,   342,   342,   343,
     343,   343,   343,   343,   343,   344,   344,   344,   345,   345,
     345,   345,   345,   345,   345,   346,   346,   347,   348,   348,
     349,   349,   350,   350,   351,   351,   351,   352,   352,   353,
     353,   354,   354,   355,   355,   355,   355,   355,   355,   356,
     356
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     4,
       3,     0,     6,     0,     5,     3,     2,     3,     1,     1,
       2,     3,     4,     1,     3,     1,     2,     3,     1,     2,
       3,     5,     4,     2,     0,     1,     1,     1,     1,     3,
       7,    10,     0,     6,     0,     8,     0,    10,     0,     6,
       2,     3,     2,     3,     2,     3,     3,     3,     5,     8,
       3,     3,     3,     5,     1,     1,     0,     9,     5,    14,
       5,     3,     3,     2,     2,     9,     0,     0,     5,     1,
       0,     1,     0,     1,     0,    11,     0,    12,     0,     0,
       9,     0,     0,    10,     0,     7,     0,     8,     0,     6,
       0,     7,     1,     1,     1,     1,     1,     2,     2,     2,
       0,     2,     0,     2,     0,     1,     3,     1,     3,     2,
       0,     1,     2,     1,     4,     1,     4,     1,     4,     1,
       4,     3,     5,     3,     4,     4,     5,     5,     4,     0,
       1,     1,     6,     0,     7,     0,     2,     0,     3,     0,
       3,     1,     1,     0,     2,     3,     5,     4,     4,     5,
       7,     6,     1,     0,     1,     2,     3,     4,     3,     1,
       1,     2,     4,     3,     5,     1,     3,     2,     0,     0,
       4,     0,     5,     2,     0,    10,     0,    11,     0,     4,
       3,     3,     3,     5,     2,     2,     0,     6,     5,     4,
       3,     1,     1,     0,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     3,     2,     0,     0,
       3,     0,     1,     3,     1,     1,     1,     1,     3,     4,
       4,     4,     1,     1,     2,     2,     2,     3,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     3,     5,     1,     3,
       5,     4,     3,     1,     1,     0,     1,     6,     3,     4,
       6,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     4,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     3,     2,     0,    11,     1,     1,     4,     4,
       4,     1,     1,     3,     4,     0,     3,     4,     1,     2,
       4,     2,     0,     0,     8,     0,     1,     0,     5,     0,
       2,     0,     1,     1,     3,     1,     3,     1,     1,     0,
       4,     0,     4,     1,     0,     4,     0,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     2,     3,     0,     0,     1,
       1,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     1,     1,     2,     2,
       4,     1,     3,     3,     1,     1,     1,     1,     3,     3,
       3,     2,     0,     1,     0,     5,     3,     3,     1,     1,
       1,     1,     3,     2,     1,     1,     1,     1,     1,     2,
       2,     4,     3,     2,     0,     5,     3,     3,     1,     3,
       1,     2,     0,     3,     0,     4,     2,     0,     3,     3,
       1,     1,     1,     1,     4,     4,     3,     3,     5,     3,
       4,     1,     1,     1,     4,     4,     3,     5,     4,     1,
       4,     4,     6,     6,     8,     6,     6,     1,     2,     4,
       4,     1,     1,     4,     1,     0,     1,     2,     1,     4,
       4,     3,     3,     5,     3,     4,     4,     3,     5,     2,
       3,     6,     0,     1,     4,     2,     0,     5,     3,     3,
       1,     6,     4,     4,     2,     2,     2,     1,     2,     1,
       4,     3,     3,     6,     3,     1,     1,     1,     4,     4,
       2,     2,     4,     2,     2,     1,     3,     3,     1,     2,
       1,     4,     2,     0,     4,     2,     3,     1,     3,     0,
       2,     3,     1,     2,     2,     1,     1,     8,     5,     1,
       0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,   537,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   467,     0,
     473,   474,    23,   495,   572,    65,   475,     0,    44,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,   453,     0,     0,     0,
       0,   106,     0,     0,     0,   479,   481,   482,   476,   477,
       0,     0,   483,   478,     0,     0,   458,     0,   480,     0,
      64,    34,   576,   468,     0,     0,     3,    25,   494,   457,
       0,     5,    82,     6,     7,     8,     0,     0,   331,   337,
       0,   336,   541,     0,   452,   497,   330,     0,   266,     0,
       0,   542,   543,   540,   567,   571,     0,   320,   496,    23,
     453,     0,     0,    82,   624,   266,   623,     0,   621,   620,
     333,   423,   422,   419,   421,   420,   439,   441,   440,   411,
     401,   417,   416,   379,   388,   389,   391,   390,   378,   410,
     394,   392,   393,   395,   396,   397,   398,   399,   400,   402,
     403,   404,   405,   406,   407,   409,   408,   380,   381,   382,
     384,   385,   387,   425,   426,   435,   434,   433,   432,   431,
     430,   418,   436,   427,   428,   429,   412,   413,   414,   415,
     437,   438,   442,   444,   443,   445,   446,   424,   448,   447,
     383,   449,   450,   386,   359,   368,     0,     0,   304,   305,
     306,   307,   329,   327,   326,   325,   324,   323,   322,   321,
       0,     0,   287,   285,   272,   460,     0,     0,   461,   462,
       0,   472,   578,   459,     0,     0,   328,     0,    74,     0,
     263,     0,     0,   265,     0,     0,     0,    50,     0,     0,
      52,     0,     0,   628,   645,   646,     0,     0,     0,    54,
       0,    34,     0,     0,     0,    18,    19,   170,     0,     0,
     169,   108,   107,   175,     0,     0,     0,     0,     0,   630,
      94,   104,   592,   596,   609,     0,   485,     0,     0,     0,
     607,     0,    13,     0,    26,     0,     0,    98,   105,     0,
       0,     0,   469,     0,   470,     0,     0,     0,     0,   163,
       0,    16,    81,     0,   103,    88,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,   575,   575,     0,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,   284,     0,   575,     0,   163,   575,
       0,   577,   568,   592,     0,     0,     0,   369,   371,     0,
       0,   539,   534,   504,     0,     0,   463,     0,   163,   271,
       0,   575,     0,   465,     0,     0,     0,    62,     0,     0,
     264,     0,     0,     0,     0,     0,    51,    72,    53,   633,
     643,     0,   644,     0,     0,     0,   629,    55,     0,    71,
      20,     0,    15,     0,     0,   171,     0,    60,     0,     0,
      61,   625,     0,     0,     0,     0,     0,   114,     0,   593,
       0,     0,   600,     0,   504,     0,     0,   484,   608,   495,
       0,     0,   606,   500,   605,    27,     4,    10,    11,    56,
      57,     0,   317,    39,    33,    35,    36,    37,    38,     0,
     332,   498,   499,    24,     0,     0,   162,   164,     0,   334,
      84,   110,   290,   292,   291,     0,     0,   288,   289,   293,
     295,   294,   309,   308,   311,   310,   312,   314,   315,   313,
     303,   302,   297,   298,   296,   299,   300,   301,   316,   574,
       0,     0,   627,   549,   567,    96,   100,     0,    91,     0,
       0,   268,   283,   282,   281,   280,   279,   278,   277,   276,
     275,   274,   273,   546,     0,   547,     0,     0,     0,     0,
       0,     0,   622,     0,     0,   350,   352,   351,     0,   362,
     373,   532,   536,   503,   538,     0,   464,   584,     0,   581,
       0,   582,     0,     0,   466,     0,   262,     0,    42,   265,
       0,     0,     0,     0,    48,   633,   632,     0,     0,     0,
       0,     0,     0,     0,     0,   487,     0,   486,    32,   491,
      77,     0,    17,    21,     0,   168,   176,   173,     0,     0,
     618,   619,     9,   642,     0,     0,     0,   592,   589,     0,
     604,     0,   338,   503,   595,   615,   617,   616,     0,   611,
       0,   612,   614,     0,     4,   178,   573,   165,   451,     0,
       0,   650,     0,     0,   112,   319,     0,   339,   340,   163,
     163,   114,     0,    86,   110,     0,   269,     0,   163,     0,
     163,   544,   545,   550,   569,   570,     0,   370,   372,   361,
     357,   374,   376,     0,     0,   524,   509,   510,   518,   511,
       0,     0,   517,   530,   504,     0,   534,   471,     0,   579,
     580,    34,   143,     0,     0,     0,     0,   120,   121,   131,
       0,    34,   129,    68,     0,     0,     0,   635,     0,   637,
       0,   488,   489,   502,     0,     0,     0,     0,    70,     0,
      22,   172,     0,   626,    63,     0,   631,     0,     0,   456,
      28,   633,   113,   115,   178,     0,     0,   590,     0,     0,
     599,     0,   598,   610,     0,    14,     0,   247,     0,   166,
      31,   152,     0,   151,   649,     0,   650,   109,     0,     0,
     318,     0,     0,     0,   178,     0,   112,   472,    58,     0,
     548,     0,     0,     0,     0,     0,     0,   514,   515,   516,
     519,   520,   528,     0,   504,   524,     0,   513,   503,   531,
     533,   535,   583,   145,   147,     0,    34,   127,    43,   265,
     122,     0,     0,     0,     0,   139,   139,    49,     0,   637,
     636,     0,     0,   648,   508,     0,   504,   493,   492,     0,
       0,   174,   641,     0,    29,   455,     0,   247,   594,   592,
       0,   267,   603,   602,     0,     0,    12,     0,     0,   250,
     251,   252,   255,   254,   253,   245,   188,     0,     0,    99,
     177,   179,     0,   244,   248,     0,   247,   167,   639,   650,
       0,   154,     0,   111,    89,   565,   566,   178,   247,   650,
       0,   270,   562,   163,   563,     0,   365,     0,   367,   360,
     363,     0,   358,   375,   377,     0,   522,   503,   523,     0,
     512,   529,   149,     0,     0,    40,     0,     0,     0,   119,
      66,   132,     0,   139,     0,   139,     0,   634,     0,     0,
     638,     0,   490,   503,   501,     0,    34,    30,   116,    95,
       0,     0,     0,   597,   613,     0,     0,   117,     0,   224,
       0,   222,   226,   227,     0,     0,   225,     0,    82,   249,
     181,     0,   183,     0,   246,     0,   345,   150,     0,   155,
       0,   639,   178,   247,   101,     0,    92,     0,   353,     0,
       0,   527,   526,   521,     0,     0,     0,     0,   146,    45,
       0,    46,     0,   130,     0,     0,     0,     0,     0,   133,
       0,   507,   506,     0,     0,   591,    59,   601,     0,     0,
     192,   196,   208,   210,   207,   214,   209,   212,   456,     0,
       0,   202,     0,   211,     0,   190,   239,   240,   241,   232,
       0,   233,   191,   258,     0,     0,     0,     0,    82,   640,
       0,     0,     0,   158,     0,   157,     0,   247,    97,   639,
     178,   564,   355,   366,   364,     0,     0,    34,     0,     0,
     128,     0,    34,   125,    67,     0,   135,     0,   140,   141,
      34,   134,   647,     0,     0,    78,   261,   118,     0,     0,
     203,   189,   218,   223,     0,     0,   228,   235,   236,   234,
       0,     0,   180,     0,     0,     0,     0,     0,    34,   159,
       0,   156,    34,    90,     0,   247,   356,   354,   525,     0,
     148,    41,     0,    34,   123,    47,     0,   136,    34,   138,
     505,    34,    23,   193,     0,   194,   195,     0,     0,   215,
       0,     0,   221,   237,   238,   230,   231,   229,   259,   256,
     184,   182,   260,     0,     0,   348,     0,     0,     0,   161,
       0,    34,    93,     0,   142,     0,     0,   137,     0,     0,
     247,     0,   213,   204,   217,   219,   205,     0,   650,   186,
     349,     0,   344,   335,   160,    85,     0,    34,     0,   126,
      76,   200,     0,   246,   216,     0,   257,     0,   650,     0,
     346,    87,   144,   124,    80,     0,     0,   199,   220,   639,
       0,   347,     0,    79,    69,     0,   198,     0,   639,     0,
     197,   242,    34,   185,     0,     0,     0,   187,     0,   243,
       0,    34,     0,    75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    86,   624,   456,   264,   265,    87,    88,
      89,    90,   300,   464,   465,   684,   241,  1031,   694,   962,
    1164,   708,   709,  1174,   313,   123,   466,   632,   755,   467,
     481,   942,   644,  1020,   437,   641,   468,   461,   642,   315,
     280,   297,    96,   634,   749,   606,   722,   916,   792,   687,
    1085,  1034,   788,   693,   404,   797,   894,  1040,   784,   882,
     885,   956,   742,   743,   475,   476,   269,   270,   274,   737,
     840,   927,  1006,  1138,  1158,   918,  1048,  1095,  1096,  1097,
     990,  1100,   991,   992,  1098,  1102,  1136,  1155,   920,   921,
     925,   999,  1000,  1001,  1183,   841,   842,   843,   844,  1004,
     845,   400,   401,    97,   631,    98,    99,   100,  1011,  1116,
     101,   379,   659,  1022,  1077,   380,   764,   763,   548,   872,
     869,   204,   543,   544,   549,   765,   766,   205,   102,   103,
     723,   104,   231,   236,   303,   389,   105,   588,   589,   106,
     805,   554,   806,   672,   770,   772,   773,   774,   674,   675,
     552,   383,   206,   207,   107,   125,   109,   110,   111,   112,
     113,   114,   115,   510,   116,   233,   234,   440,   443,   444,
     289,   290,   618,   117,   432,   118,   257,   281,   412,   576,
     900,   936,   604,   744,   745
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -918
static const yytype_int16 yypact[] =
{
    -918,   108,  2133,  -918,  7214,  7214,  -112,  7214,  7214,  7214,
    7741,  -918,  7214,  7214,  7214,  7214,  7214,  7214,  7214,  7214,
    7214,  7214,  7214,  7214,   735,   735,  7214,   891,   -69,   -41,
    -918,  -918,   133,  -918,  -918,  -918,  -918,  7214,  -918,    21,
      48,   110,   141,   200,  5183,   106,  5328,  -918,    98,  5473,
     210,  7214,   -24,    -9,    69,   264,   135,   240,   251,   260,
     274,  -918,   396,   319,   326,  -918,  -918,  -918,  -918,  -918,
     401,   312,  -918,  -918,   422,  5618,  -918,   396,  -918,  7214,
    -918,  -918,   339,   382,   497,   497,  -918,   362,   356,  -918,
      32,  -918,   499,  -918,  -918,  -918,    25,  8240,   482,   484,
     505,  -918,    61,   459,  -918,  -918,  -918,   615,  1083,    63,
     451,    70,   120,   458,    66,  -918,   109,  -918,   568,  -918,
    -918,   476,   414,   499,  9291,  1814,  9291,  7214,  9291,  9291,
    9207,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,   469,  -918,   599,   574,  -918,  -918,
     610,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
     356,   507,   554,   554,  -918,   532,   533,   422,   538,   362,
     540,   521,  -918,   560,   124,  5763,  -918,  7214,  -918,    33,
    9291,  5038,  7214,  7214,  7214,   614,  7214,  -918,  8298,   529,
    -918,  8339,   101,   328,  -918,  -918,   198,   681,   625,  -918,
    8380,  -918,  8436,   422,    34,  -918,    29,  -918,   437,    35,
    -918,  -918,  -918,   686,    36,   735,   735,   735,   546,   665,
    -918,  -918,   530,  5908,    46,   313,  -918,  7359,   735,   471,
    -918,   422,  -918,   350,   410,   548,  8477,  -918,  -918,  8615,
    2278,  7214,   418,   547,   516,   418,   330,   288,   639,  6053,
      98,  -918,  -918,    26,  -918,  -918,  -918,  7214,  7214,  7214,
    6199,  7214,  7214,  7214,  7214,  7214,  7214,  7214,  7214,  7214,
    7214,  7214,  7214,  7214,  7214,  7214,  7214,  7214,  7214,  7214,
    7214,  7214,   891,  -918,  7214,  7214,    97,   396,   396,   499,
      25,  1324,  7214,  7214,  7214,  7214,  7214,  7214,  7214,  7214,
    7214,  7214,  7214,  -918,  -918,   256,  7214,  7214,  6053,  7214,
    7214,   339,   126,   530,   552,  6344,  8656,  -918,  -918,   680,
    7487,  -918,   556,   712,   275,   422,   410,   247,  6053,  -918,
     268,  7214,  7214,  -918,  8712,  8754,  7214,  -918,   644,  8795,
     722,   567,  9184,   727,    50,  8849,  -918,  -918,  -918,   699,
    -918,   263,  -918,   584,   744,  8994,  -918,  -918,  2423,  -918,
     320,   -24,  -918,   683,  7214,   554,    -9,  -918,  8994,   690,
    -918,   554,    83,    86,   136,   602,   697,   653,   616,   554,
      91,   735,  9047,   619,   771,   524,   715,  -918,  -918,   730,
    1559,     9,  -918,  -918,  -918,   448,  -918,  -918,  -918,  -918,
    -918,   623,   740,  -918,  -918,  -918,  -918,  -918,  -918,  1771,
    -918,  -918,  -918,  -918,   735,   640,   796,  9291,   792,  -918,
    -918,   717,  9331,  9368,  9207,  7214,  9250,  9413,  9068,  5233,
    1487,  5376,  5521,  5521,  5521,  5521,  1024,  1024,  1024,  1024,
     783,   783,   611,   611,   611,   610,   610,   610,  -918,  9291,
     645,   647,   656,   672,   126,  -918,  -918,   396,  -918,   334,
    7214,  9207,  9207,  9207,  9207,  9207,  9207,  9207,  9207,  9207,
    9207,  9207,  9207,    67,  7214,   678,   673,  7878,   646,   676,
    7919,    92,  -918,  7741,  7741,  -918,  -918,  -918,   828,   534,
    -918,   428,  -918,   777,  -918,   656,   448,  -918,   689,   128,
    7214,  -918,   684,  7960,  -918,  4309,  9291,   687,  -918,  7214,
     346,  8994,   785,  4455,  -918,   818,  -918,   439,   101,   101,
    8994,  8994,   706,   -22,   719,  -918,   729,  -918,  -918,  -918,
     755,   799,  -918,  -918,  8018,  -918,  -918,   858,   735,   709,
    -918,  -918,  -918,   867,   840,   297,   713,   530,   575,   870,
     554,  6489,  -918,  6634,  -918,  -918,  -918,  -918,   711,  -918,
    7214,  -918,  -918,  1843,  -918,  -918,  -918,   554,  -918,  6779,
    8994,   138,   725,   297,   764,  9391,  7214,  -918,  -918,  6053,
    6053,   653,   721,  -918,   717,   891,   554,  8518,  6053,  8059,
    6053,    68,   105,   146,  -918,  -918,   877,  -918,  -918,  -918,
    -918,  -918,  -918,   563,   563,   428,  -918,  -918,  -918,  -918,
     732,   205,  -918,  -918,   887,   733,   556,  -918,  8100,   175,
     180,  -918,  -918,  7214,  4601,   734,   735,   775,   554,  -918,
     888,  -918,  -918,  -918,    11,   263,   263,  -918,   748,   904,
     750,  -918,  -918,  8994,   778,   845,   846,   756,  -918,   758,
    -918,  -918,  8994,   554,  -918,   697,  -918,   779,   422,  -918,
     780,   699,   913,  -918,  -918,    93,   760,   554,  6924,   735,
    9291,   735,  9143,  -918,    43,  -918,  1988,   425,   735,  9291,
    -918,  -918,   762,   918,  -918,   305,   138,  -918,   297,   765,
    9391,   788,   789,   790,  -918,   786,   764,   521,  -918,   793,
     143,   794,  7214,    15,   -52,  7741,  7741,  -918,  -918,  -918,
    -918,  -918,   805,   797,   951,   428,   826,  -918,   428,  -918,
    -918,  -918,   182,  4163,   519,  8891,  -918,  -918,  -918,  7214,
     554,   346,   802,  8994,  2568,   803,   807,  -918,   934,   474,
    -918,   953,   101,  -918,   855,   817,   973,  -918,  -918,   297,
     827,  -918,  -918,   422,   780,  -918,   297,   596,  -918,   530,
    7214,  9207,   554,   554,  7069,   830,  -918,    98,   297,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,   844,   223,  -918,
    -918,  -918,   899,   282,  -918,    41,   798,   554,   972,   272,
     927,   988,   841,   913,  -918,  -918,  -918,  -918,   649,   138,
     842,  -918,  -918,  6053,  -918,  7614,  -918,  7214,  -918,  -918,
    -918,  7214,  -918,  -918,  -918,   428,  -918,   428,  -918,   843,
    -918,  -918,   551,   847,  5038,  -918,   848,  2713,   851,  -918,
    -918,  -918,   852,  -918,   550,  -918,   232,  -918,   263,   101,
    -918,  8994,  -918,  8994,  -918,   932,  -918,   780,  -918,  -918,
      95,  8574,   735,  9291,  -918,   995,    28,  -918,   470,  -918,
      47,  -918,  -918,  -918,   303,   853,  -918,   937,   499,  -918,
    -918,    98,  -918,   899,   798,   101,   907,  -918,   321,  1002,
    8994,   972,  -918,   879,  -918,   856,  -918,   860,  -918,  8158,
    8199,  -918,   896,  -918,   862,   999,   963,  7214,  -918,  -918,
     872,  -918,  4747,  -918,   657,   875,  7214,    20,   318,  -918,
     871,  -918,   919,   880,  2858,  -918,  -918,   554,  8994,   297,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,    51,   881,
      53,  -918,  7741,  -918,   844,  -918,  -918,  -918,  -918,  -918,
      31,   517,  -918,  1027,    54,   396,   937,  1029,   499,  -918,
     882,   883,   974,  1036,  8994,  -918,   885,  1525,  -918,   972,
    -918,  -918,   906,  -918,  -918,   428,  7214,  -918,   889,  8932,
    -918,  4893,  -918,  -918,  -918,   890,  -918,   107,  -918,  -918,
    -918,  -918,  -918,  8994,   892,  -918,  -918,  -918,   296,   695,
    -918,  -918,   148,  -918,   303,   303,   542,  -918,  -918,  -918,
    8994,   982,  -918,   894,    55,  8994,   396,   400,  -918,  1059,
    8994,  -918,  -918,  -918,   910,  1573,  -918,  -918,  -918,  8986,
    4163,  -918,  5038,  -918,  -918,  -918,  3003,  -918,  -918,  4163,
    -918,  -918,   986,  -918,   939,  -918,  -918,   987,    24,  -918,
     470,  8994,  1030,  1054,  -918,  -918,  -918,  -918,  -918,  1072,
    -918,  -918,  -918,   928,  1013,  -918,    96,  3148,  8994,  -918,
    3293,  -918,  -918,  1066,  -918,  3438,   929,  4163,  3583,  1023,
     798,   695,  -918,  -918,  -918,  -918,  -918,  8994,   138,  -918,
    -918,   430,  -918,  -918,  -918,  -918,  3728,  -918,   944,  -918,
    -918,   954,  1039,   559,  -918,   958,  -918,   949,   138,  1040,
    -918,  -918,  4163,  -918,    -4,   297,   950,  -918,  -918,   972,
     957,  -918,   955,  -918,  -918,    57,  -918,     0,   972,   297,
    -918,  -918,  -918,  -918,     0,  1043,  3873,  -918,   965,  -918,
     956,  -918,  4018,  -918
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -918,  -918,  -421,  -918,  -918,  -918,  -918,   710,   -26,    81,
     598,  -918,  -233,  -918,     7,  -918,  -918,  -918,  -918,  -918,
    -918,   -31,  -918,  -918,  -115,     2,     1,  -918,  -918,     3,
    -918,  -918,  -918,  -918,  -918,  -918,     5,  -918,  -918,   782,
     787,   801,  1028,   492,   381,   504,   390,   -25,  -918,   359,
    -918,  -918,  -918,  -918,  -918,  -918,  -463,   117,  -918,  -918,
    -918,  -918,  -734,  -918,  -358,  -918,  -918,   731,  -918,  -697,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,    56,  -918,  -918,  -918,  -918,  -918,  -918,   153,
    -918,   317,  -700,  -918,   -21,  -918,  -817,  -815,  -822,   152,
    -918,  1125,  -536,   924,  -918,  -918,  -918,  -918,  -918,  -918,
     402,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,   179,  -918,  -918,  -365,  -918,    42,
    -614,  -918,  -324,  -918,  -918,   415,   605,   724,  -918,  -918,
    -918,  -424,  -918,  -918,   509,  -540,   399,  -918,  -918,  -918,
     501,  -918,  -918,  -918,  -703,    -2,  -918,  -918,  -918,  -918,
     -14,   -78,  -918,   224,  -918,  -918,  -918,  -356,  -918,  -918,
     692,   558,  -918,  -918,   905,  -918,  -308,   -71,   454,  -682,
    -468,  -917,   465,   -32,   338
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -634
static const yytype_int16 yytable[] =
{
     108,   229,   478,    93,    92,    94,   298,    95,   374,    91,
     538,   673,   852,   232,   800,   550,   258,   541,   508,   747,
     614,   929,   222,   223,  1016,   316,   266,   817,   418,   933,
     558,   934,  1131,   685,   846,   623,   979,   795,   372,  1054,
     310,   396,   421,   426,   429,   293,  1038,   119,   294,   931,
     127,   865,   317,   318,   319,   994,   704,   858,   572,  -206,
    1055,  1050,  1061,  1061,   267,   979,   221,   221,   320,   230,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   598,   342,   235,   598,   870,   279,   279,  1172,   608,
     608,   608,  1074,   608,  1141,   220,   220,   445,     3,   349,
     698,   700,   929,   871,   846,   286,   317,   318,   319,   423,
     263,   237,  -551,   252,   366,   945,   252,   369,  -556,  -554,
     365,  -552,   320,  1038,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   846,   342,   -77,   268,   238,
     943,  1101,   866,   252,  1181,  1182,  -555,   446,   512,   253,
      34,   314,   409,   308,   661,   622,   796,   249,   657,   658,
     867,  -553,    34,   242,  1039,   391,   271,   369,   479,  -587,
    1132,   662,   980,   981,  1056,   905,   311,   397,   422,   427,
     430,   386,   908,   736,  -557,   932,  -454,  -558,   273,   409,
     243,   995,   825,   573,   917,  -206,   800,  1051,  1062,  1111,
     410,  1180,   254,   252,   414,   254,  -551,   798,   367,   648,
    -560,   370,  -556,  -554,   517,  -552,  -585,   420,   881,   108,
     846,  -586,   480,  -588,   255,  1017,   599,   255,   398,   600,
     779,   725,  1177,   888,   609,   656,   818,   365,   975,  1142,
     256,  1184,   254,   256,    82,   455,   425,  -561,   514,   409,
    -555,  1039,   244,   431,   431,   434,   371,   298,   258,   316,
     439,   751,   752,   776,   255,  -553,   451,   514,   252,   392,
     759,   370,   761,  -587,   922,   741,   413,   252,   108,   601,
     256,  -153,    92,   245,   993,   863,   514,   252,  -557,   514,
     221,  -558,   514,  1152,   846,  1153,   229,   221,   221,   221,
      34,   757,   254,  1075,   221,   966,   967,   533,   232,    34,
     221,   929,   513,   896,   575,   951,   850,   952,   923,   559,
    -585,    34,   777,   409,   255,  -586,   555,  -588,    34,   220,
     878,   535,  1012,   409,  1103,  1104,   220,   220,   220,   556,
     256,   284,   246,   220,   411,  1047,   452,  1092,   119,   220,
     513,   439,   846,   557,   996,   261,   561,   686,   851,   577,
    -246,   272,   904,   119,   230,   924,   284,   254,   829,   830,
     831,   832,   833,   834,  1013,   266,   254,   645,   969,  -633,
     873,   874,   275,   284,  1157,   119,   254,    34,   452,   255,
     591,   966,   967,   276,    82,   221,   108,   119,   255,    34,
      92,   534,   277,    82,  1170,   256,   287,   288,   255,   937,
     964,  1114,   968,   560,   256,    82,   278,   717,   717,   610,
     718,   718,    82,   719,   256,   120,   643,   696,   783,   997,
     447,   287,   288,   998,   220,   284,   291,   120,   794,   472,
     302,  1159,  1093,   910,   308,   924,    11,   279,   287,   288,
     663,   664,   627,  1115,   284,   122,   697,   292,    74,   285,
      76,   282,   898,   221,  1041,  1078,   993,   122,   283,   665,
      74,   284,    76,   119,   308,   377,   585,   666,   667,   668,
     471,    82,   -28,  1160,   301,   947,   308,   669,   119,   585,
      34,   697,   378,    82,   457,   458,   221,   646,   309,   915,
     287,   288,   220,   982,   827,   983,   984,   985,   986,   828,
     312,   829,   830,   831,   832,   833,   834,   835,   286,   287,
     288,   119,  1057,  -341,   284,   344,   699,   699,   120,   452,
     -29,   917,   670,   887,   308,   220,   287,   288,   291,  1058,
     661,   221,  1059,   108,   671,  1185,   345,  1105,   688,   511,
     284,   108,   682,   836,   837,   305,   838,   662,   122,   720,
     692,    74,   987,    76,  1106,   883,   884,  1107,   -30,   284,
     536,   839,   308,   539,   452,   615,   713,   616,   617,   346,
     220,   119,   424,    34,    82,   439,   727,   720,   453,   287,
     288,   717,   221,   368,   718,   562,   988,   954,   955,   229,
    -559,   108,   989,  1007,    93,    92,    94,   550,    95,  -342,
      91,   232,   767,   768,   769,   287,   288,    11,   373,   381,
     221,   120,   965,   966,   967,   382,   119,   384,    34,   221,
     221,   220,   585,   438,   287,   288,   339,   340,   341,   342,
     342,   585,   585,   799,   577,   829,   830,   831,   832,   833,
     834,   122,  -453,   974,    74,   365,    76,   385,  -458,   220,
     387,   390,   108,   388,   790,   403,   120,   230,   220,   220,
      11,   787,   814,   407,   415,   827,   416,    82,   726,   428,
     828,   436,   829,   830,   831,   832,   833,   834,   835,   435,
     473,   585,   459,    47,   479,   470,   122,   545,   551,    74,
     553,    76,   720,  1167,    54,    55,   567,   822,   221,   823,
     396,   569,    61,   347,   108,   411,   847,    93,    92,    94,
     571,    95,    82,    91,   836,   837,   578,   838,   827,  1035,
     966,   967,   579,   828,   593,   829,   830,   831,   832,   833,
     834,   835,   909,   597,    30,    31,   602,   220,   603,   348,
     699,   221,   605,   221,    36,   304,   306,   307,   607,   613,
     221,   108,   612,   720,   585,    92,   619,   907,   625,   688,
     720,   620,   108,   585,  1080,   258,    92,   836,   837,  1086,
     838,  -343,   720,   628,   629,   630,   119,  1089,    34,   653,
     220,   930,   220,  1005,   637,   944,   638,   439,   639,   220,
      65,    66,    67,    68,    69,   336,   337,   338,   339,   340,
     341,   583,   342,   221,   640,  1117,   633,    72,    73,  1120,
     650,   660,   651,   448,   928,   654,   120,   454,   676,   683,
    1125,    78,   677,   679,   695,  1127,   690,   707,  1128,   705,
     448,   221,   454,   448,   454,   454,   799,   970,   703,   706,
     710,   712,   220,   714,   585,   715,   122,   716,   724,    74,
     733,    76,   108,   728,   748,   108,   754,   746,  1146,    92,
     762,   958,   720,  1066,   775,   778,   780,   791,   789,   258,
     220,   793,    82,  1009,   829,   830,   831,   832,   833,   834,
     977,   801,   802,   803,  1162,   447,   807,   808,   809,   810,
      11,   816,   819,   813,   308,   848,   849,   875,   124,   126,
     854,   128,   129,   130,  1063,  1008,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   859,  1186,
     224,   855,   856,   720,   221,   857,   862,   864,  1192,   877,
     108,   240,   119,   880,    34,   890,   876,   893,   248,  1033,
     251,   895,   108,   260,   897,   262,    92,   901,   827,   899,
     902,   903,   585,   828,   585,   829,   830,   831,   832,   833,
     834,   835,   906,   220,   919,  1113,   914,    47,   935,   296,
     939,   940,   225,   299,   941,   973,   953,   946,   978,   957,
    1003,  1010,   959,   586,   961,  1014,   963,  1002,  1025,  1019,
     587,   585,   720,  1021,  1026,  1027,   586,   836,   837,   108,
     838,  1028,   226,   587,  1042,   227,  1030,   228,  1084,  1036,
    1060,  1043,  1065,  1044,  1067,  1018,  1049,  1069,  1068,  1070,
    1072,   376,  1076,  1081,  1087,  1109,  1110,  1091,    82,   585,
    -634,  -634,  -634,  -634,   334,   335,   336,   337,   338,   339,
     340,   341,  1118,   342,   720,  1121,  -201,  1130,   108,  1129,
     108,  1135,    92,  1055,   108,  1137,  1140,   108,    92,  1124,
    1139,    92,  1147,  1149,  1151,   585,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,  1163,  1165,
    1166,  1168,  1169,  1171,  1176,   108,  1188,  1179,   108,    92,
    1178,  1191,    92,   108,   585,   108,   108,    92,  1190,    92,
      92,   592,   518,  1173,   515,   350,   756,   860,   853,   720,
    1175,   585,   363,   364,   108,   753,   585,  1053,    92,   516,
     889,   585,   596,   720,  1088,   926,  1133,   595,  1064,   394,
     108,   395,   239,  1187,    92,   868,   399,   240,   402,   586,
     405,  1052,   861,   771,   879,   815,   587,   781,   586,   586,
     812,   433,   585,     0,   108,   587,   587,   938,    92,     0,
     108,     0,     0,     0,    92,     0,     0,     0,     0,   585,
       0,     0,     0,   721,   365,     0,     0,   442,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,   585,     0,
       0,     0,     0,     0,     0,   469,     0,     0,   586,     0,
       0,   721,     0,   477,     0,   587,     0,     0,     0,     0,
       0,   482,   483,   484,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,     0,     0,   509,   509,
       0,     0,     0,     0,     0,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,     0,     0,     0,
     509,   537,   477,   509,   540,   689,     0,     0,     0,   521,
       0,   586,     0,     0,   701,   702,     0,     0,   587,     0,
     586,     0,   477,     0,     0,   509,   563,   587,     0,     0,
     566,     0,     0,     0,     0,     0,     0,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   721,     0,   594,     0,
       0,     0,     0,     0,   740,   519,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,    12,    13,     0,     0,
       0,     0,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,     0,
       0,   586,     0,    30,    31,   119,    33,    34,   587,     0,
       0,     0,     0,    36,     0,     0,     0,   721,     0,   635,
       0,     0,     0,     0,   721,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,   721,   804,     0,     0,
       0,     0,     0,     0,     0,   120,   811,     0,    58,    59,
       0,     0,     0,     0,   647,     0,     0,   121,    64,    65,
      66,    67,    68,    69,     0,     0,     0,     0,   649,     0,
      70,     0,     0,     0,     0,   122,    72,    73,    74,   520,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,     0,   678,     0,    79,     0,     0,     0,
       0,    82,    83,   240,    84,    85,     0,     0,     0,   586,
       0,   586,     0,     0,     0,     0,   587,     0,   587,     0,
       0,     0,     0,     0,     0,     0,   721,   891,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   730,   342,   732,   586,     0,
       0,     0,     0,     0,   734,   587,     0,     0,     0,     0,
       0,     0,     0,   739,     0,     0,     0,     0,     0,     0,
     750,     0,     0,   477,   477,     0,    11,     0,   317,   318,
     319,     0,   477,     0,   477,     0,   586,   721,     0,     0,
       0,     0,     0,   587,   320,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   785,   342,     0,
       0,     0,   586,     0,    11,     0,     0,     0,     0,   587,
       0,     0,     0,     0,   827,   971,     0,   972,     0,   828,
       0,   829,   830,   831,   832,   833,   834,   835,     0,     0,
       0,   586,     0,     0,     0,     0,  1094,     0,   587,     0,
       0,     0,   821,     0,  1099,     0,     0,     0,   586,     0,
       0,     0,     0,   586,  1015,   587,     0,     0,   586,     0,
     587,     0,   827,   836,   837,   587,   838,   828,     0,   829,
     830,   831,   832,   833,   834,   835,   821,     0,     0,     0,
       0,  1073,     0,     0,     0,     0,     0,     0,   721,   586,
       0,     0,  1046,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,   240,     0,     0,   586,     0,     0,     0,
       0,   836,   837,   587,   838,   621,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   586,  1154,     0,  1071,  1122,
       0,     0,   587,     0,   911,     0,     0,     0,   913,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   721,     0,     0,     0,  1090,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   721,     0,     0,
     317,   318,   319,     0,  1108,     0,     0,   477,     0,  1112,
       0,   949,     0,     0,  1119,   950,   320,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,     0,
     342,     0,     0,     0,     0,  1134,     0,   375,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,     0,
       0,     0,  1144,     0,     0,     0,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,     0,     0,
       0,  1156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   363,   364,     0,     0,     0,     0,    10,
       0,  1029,     0,     0,    11,    12,    13,     0,     0,     0,
    1037,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,    29,     0,
       0,     0,    30,    31,    32,    33,    34,     0,    35,     0,
       0,     0,    36,    37,    38,    39,     0,    40,     0,    41,
       0,    42,     0,     0,    43,   365,     0,   626,    44,    45,
      46,    47,    48,    49,    50,     0,    51,    52,    53,     0,
    1079,     0,    54,    55,    56,     0,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,    71,    72,    73,    74,    75,    76,
       0,     4,     5,     6,     7,     8,     0,    77,     0,    78,
       9,     0,     0,     0,     0,    79,     0,    80,    81,   735,
      82,    83,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,    11,
      12,    13,     0,     0,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,    29,     0,     0,     0,    30,    31,    32,
      33,    34,     0,    35,     0,     0,     0,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,    48,    49,    50,
       0,    51,    52,    53,     0,     0,     0,    54,    55,    56,
       0,    57,    58,    59,    60,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,    71,
      72,    73,    74,    75,    76,     0,     4,     5,     6,     7,
       8,     0,    77,     0,    78,     9,     0,     0,     0,     0,
      79,     0,    80,    81,   826,    82,    83,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,    29,     0,
       0,     0,    30,    31,    32,    33,    34,     0,    35,     0,
       0,     0,    36,    37,    38,    39,     0,    40,     0,    41,
       0,    42,     0,     0,    43,     0,     0,     0,    44,    45,
      46,    47,    48,    49,    50,     0,    51,    52,    53,     0,
       0,     0,    54,    55,    56,     0,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,    71,    72,    73,    74,    75,    76,
       0,     4,     5,     6,     7,     8,     0,    77,     0,    78,
       9,     0,     0,     0,     0,    79,     0,    80,    81,     0,
      82,    83,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,    11,
      12,    13,     0,     0,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,    29,     0,     0,     0,    30,    31,    32,
      33,    34,     0,    35,     0,     0,     0,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,     0,     0,     0,    54,    55,    56,
       0,    57,    58,    59,     0,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,   122,
      72,    73,    74,    75,    76,     0,     4,     5,     6,     7,
       8,     0,    77,     0,    78,     9,     0,     0,     0,     0,
      79,     0,    80,    81,   463,    82,    83,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,    29,     0,
       0,     0,    30,    31,    32,    33,    34,     0,    35,     0,
       0,     0,    36,    37,    38,    39,     0,    40,     0,    41,
       0,    42,     0,     0,    43,     0,     0,     0,    44,    45,
      46,    47,     0,    49,    50,     0,    51,     0,    53,     0,
       0,     0,    54,    55,    56,     0,    57,    58,    59,     0,
      61,    62,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,   122,    72,    73,    74,    75,    76,
       0,     4,     5,     6,     7,     8,     0,    77,     0,    78,
       9,     0,     0,     0,     0,    79,     0,    80,    81,   590,
      82,    83,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,    11,
      12,    13,     0,     0,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,    29,     0,     0,     0,    30,    31,    32,
      33,    34,     0,    35,     0,     0,     0,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,   892,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,     0,     0,     0,    54,    55,    56,
       0,    57,    58,    59,     0,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,   122,
      72,    73,    74,    75,    76,     0,     4,     5,     6,     7,
       8,     0,    77,     0,    78,     9,     0,     0,     0,     0,
      79,     0,    80,    81,     0,    82,    83,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,    29,     0,
       0,     0,    30,    31,    32,    33,    34,     0,    35,     0,
       0,     0,    36,    37,    38,    39,   960,    40,     0,    41,
       0,    42,     0,     0,    43,     0,     0,     0,    44,    45,
      46,    47,     0,    49,    50,     0,    51,     0,    53,     0,
       0,     0,    54,    55,    56,     0,    57,    58,    59,     0,
      61,    62,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,   122,    72,    73,    74,    75,    76,
       0,     4,     5,     6,     7,     8,     0,    77,     0,    78,
       9,     0,     0,     0,     0,    79,     0,    80,    81,     0,
      82,    83,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,    11,
      12,    13,     0,     0,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,    29,     0,     0,     0,    30,    31,    32,
      33,    34,     0,    35,     0,     0,     0,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,     0,     0,     0,    54,    55,    56,
       0,    57,    58,    59,     0,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,   122,
      72,    73,    74,    75,    76,     0,     4,     5,     6,     7,
       8,     0,    77,     0,    78,     9,     0,     0,     0,     0,
      79,     0,    80,    81,  1045,    82,    83,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,    29,     0,
       0,     0,    30,    31,    32,    33,    34,     0,    35,     0,
       0,     0,    36,    37,    38,    39,     0,    40,     0,    41,
    1126,    42,     0,     0,    43,     0,     0,     0,    44,    45,
      46,    47,     0,    49,    50,     0,    51,     0,    53,     0,
       0,     0,    54,    55,    56,     0,    57,    58,    59,     0,
      61,    62,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,   122,    72,    73,    74,    75,    76,
       0,     4,     5,     6,     7,     8,     0,    77,     0,    78,
       9,     0,     0,     0,     0,    79,     0,    80,    81,     0,
      82,    83,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,    11,
      12,    13,     0,     0,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,    29,     0,     0,     0,    30,    31,    32,
      33,    34,     0,    35,     0,     0,     0,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,     0,     0,     0,    54,    55,    56,
       0,    57,    58,    59,     0,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,   122,
      72,    73,    74,    75,    76,     0,     4,     5,     6,     7,
       8,     0,    77,     0,    78,     9,     0,     0,     0,     0,
      79,     0,    80,    81,  1143,    82,    83,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,    29,     0,
       0,     0,    30,    31,    32,    33,    34,     0,    35,     0,
       0,     0,    36,    37,    38,    39,     0,    40,     0,    41,
       0,    42,     0,     0,    43,     0,     0,     0,    44,    45,
      46,    47,     0,    49,    50,     0,    51,     0,    53,     0,
       0,     0,    54,    55,    56,     0,    57,    58,    59,     0,
      61,    62,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,   122,    72,    73,    74,    75,    76,
       0,     4,     5,     6,     7,     8,     0,    77,     0,    78,
       9,     0,     0,     0,     0,    79,     0,    80,    81,  1145,
      82,    83,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,    11,
      12,    13,     0,     0,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,    29,     0,     0,     0,    30,    31,    32,
      33,    34,     0,    35,     0,     0,     0,    36,    37,    38,
      39,     0,    40,  1148,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,     0,     0,     0,    54,    55,    56,
       0,    57,    58,    59,     0,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,   122,
      72,    73,    74,    75,    76,     0,     4,     5,     6,     7,
       8,     0,    77,     0,    78,     9,     0,     0,     0,     0,
      79,     0,    80,    81,     0,    82,    83,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,    29,     0,
       0,     0,    30,    31,    32,    33,    34,     0,    35,     0,
       0,     0,    36,    37,    38,    39,     0,    40,     0,    41,
       0,    42,     0,     0,    43,     0,     0,     0,    44,    45,
      46,    47,     0,    49,    50,     0,    51,     0,    53,     0,
       0,     0,    54,    55,    56,     0,    57,    58,    59,     0,
      61,    62,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,   122,    72,    73,    74,    75,    76,
       0,     4,     5,     6,     7,     8,     0,    77,     0,    78,
       9,     0,     0,     0,     0,    79,     0,    80,    81,  1150,
      82,    83,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,    11,
      12,    13,     0,     0,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,    29,     0,     0,     0,    30,    31,    32,
      33,    34,     0,    35,     0,     0,     0,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,     0,     0,     0,    54,    55,    56,
       0,    57,    58,    59,     0,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,   122,
      72,    73,    74,    75,    76,     0,     4,     5,     6,     7,
       8,     0,    77,     0,    78,     9,     0,     0,     0,     0,
      79,     0,    80,    81,  1161,    82,    83,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,    29,     0,
       0,     0,    30,    31,    32,    33,    34,     0,    35,     0,
       0,     0,    36,    37,    38,    39,     0,    40,     0,    41,
       0,    42,     0,     0,    43,     0,     0,     0,    44,    45,
      46,    47,     0,    49,    50,     0,    51,     0,    53,     0,
       0,     0,    54,    55,    56,     0,    57,    58,    59,     0,
      61,    62,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,   122,    72,    73,    74,    75,    76,
       0,     4,     5,     6,     7,     8,     0,    77,     0,    78,
       9,     0,     0,     0,     0,    79,     0,    80,    81,  1189,
      82,    83,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,    11,
      12,    13,     0,     0,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,    29,     0,     0,     0,    30,    31,    32,
      33,    34,     0,    35,     0,     0,     0,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,     0,     0,     0,    54,    55,    56,
       0,    57,    58,    59,     0,    61,    62,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,   122,
      72,    73,    74,    75,    76,     0,     4,     5,     6,     7,
       8,     0,    77,     0,    78,     9,     0,     0,     0,     0,
      79,     0,    80,    81,  1193,    82,    83,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,    29,     0,
       0,     0,    30,    31,    32,    33,    34,     0,    35,     0,
       0,     0,    36,    37,    38,    39,     0,    40,     0,    41,
       0,    42,     0,     0,    43,     0,     0,     0,    44,    45,
      46,    47,     0,    49,    50,     0,    51,     0,    53,     0,
       0,     0,    54,    55,    56,     0,    57,    58,    59,     0,
      61,    62,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,   122,    72,    73,    74,    75,    76,
       0,     0,     4,     5,     6,     7,     8,    77,     0,    78,
       0,     9,     0,     0,     0,    79,     0,    80,    81,     0,
      82,    83,     0,    84,    85,   681,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,    12,    13,     0,     0,     0,     0,    14,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,    29,     0,     0,     0,    30,    31,
      32,    33,    34,     0,    35,     0,     0,     0,    36,    37,
      38,    39,     0,    40,     0,    41,     0,    42,     0,     0,
      43,     0,     0,     0,    44,    45,    46,    47,     0,    49,
      50,     0,    51,     0,    53,     0,     0,     0,     0,     0,
      56,     0,    57,    58,    59,     0,     0,     0,     0,     0,
       0,     0,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,     0,     0,     0,    70,     0,     0,     0,     0,
     122,    72,    73,    74,    75,    76,     0,     0,     4,     5,
       6,     7,     8,     0,     0,    78,     0,     9,     0,     0,
       0,    79,     0,    80,    81,     0,    82,    83,     0,    84,
      85,   691,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,    12,    13,     0,
       0,     0,     0,    14,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,    27,    28,
      29,     0,     0,     0,    30,    31,    32,    33,    34,     0,
      35,     0,     0,     0,    36,    37,    38,    39,     0,    40,
       0,    41,     0,    42,     0,     0,    43,     0,     0,     0,
      44,    45,    46,    47,     0,    49,    50,     0,    51,     0,
      53,     0,     0,     0,     0,     0,    56,     0,    57,    58,
      59,     0,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,     0,     0,
       0,    70,     0,     0,     0,     0,   122,    72,    73,    74,
      75,    76,     0,     0,     4,     5,     6,     7,     8,     0,
       0,    78,     0,     9,     0,     0,     0,    79,     0,    80,
      81,     0,    82,    83,     0,    84,    85,   786,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,     0,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,    14,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,    26,    27,    28,    29,     0,     0,     0,
      30,    31,    32,    33,    34,     0,    35,     0,     0,     0,
      36,    37,    38,    39,     0,    40,     0,    41,     0,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
       0,    49,    50,     0,    51,     0,    53,     0,     0,     0,
       0,     0,    56,     0,    57,    58,    59,     0,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,     0,    70,     0,     0,
       0,     0,   122,    72,    73,    74,    75,    76,     0,     0,
       4,     5,     6,     7,     8,     0,     0,    78,     0,     9,
       0,     0,     0,    79,     0,    80,    81,     0,    82,    83,
       0,    84,    85,  1032,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,     0,     0,    12,
      13,     0,     0,     0,     0,    14,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,    29,     0,     0,     0,    30,    31,    32,    33,
      34,     0,    35,     0,     0,     0,    36,    37,    38,    39,
       0,    40,     0,    41,     0,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,     0,    49,    50,     0,
      51,     0,    53,     0,     0,     0,     0,     0,    56,     0,
      57,    58,    59,     0,     0,     0,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
       0,     0,     0,    70,     0,     0,     0,     0,   122,    72,
      73,    74,    75,    76,     0,     0,     4,     5,     6,     7,
       8,     0,     0,    78,     0,     9,     0,     0,     0,    79,
       0,    80,    81,     0,    82,    83,     0,    84,    85,  1083,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,    29,     0,
       0,     0,    30,    31,    32,    33,    34,     0,    35,     0,
       0,     0,    36,    37,    38,    39,     0,    40,     0,    41,
       0,    42,     0,     0,    43,     0,     0,     0,    44,    45,
      46,    47,     0,    49,    50,     0,    51,     0,    53,     0,
       0,     0,     0,     0,    56,     0,    57,    58,    59,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,   122,    72,    73,    74,    75,    76,
       0,     4,     5,     6,     7,     8,     0,     0,     0,    78,
       9,     0,     0,     0,     0,    79,     0,    80,    81,     0,
      82,    83,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
      12,    13,     0,     0,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,    29,     0,     0,     0,    30,    31,    32,
      33,    34,     0,    35,     0,     0,     0,    36,    37,    38,
      39,     0,    40,     0,    41,     0,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,    49,    50,
       0,    51,     0,    53,     0,     0,     0,     0,     0,    56,
       0,    57,    58,    59,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,   122,
      72,    73,    74,    75,    76,     0,     4,     5,     6,     7,
       8,     0,     0,     0,    78,     9,     0,     0,     0,     0,
      79,     0,    80,    81,     0,    82,    83,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,     0,     0,
       0,     0,    30,    31,   119,    33,    34,     0,     0,     0,
       0,     0,    36,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,    47,   342,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   120,     0,     0,    58,    59,     0,
       0,     0,     0,     0,     0,     0,   121,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,   122,    72,    73,    74,     0,    76,
       0,     4,     5,     6,     7,     8,     0,     0,     0,    78,
       9,     0,     0,     0,     0,    79,     0,   247,     0,     0,
      82,    83,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
      12,    13,     0,     0,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,     0,     0,     0,     0,    30,    31,   119,
      33,    34,     0,     0,     0,     0,     0,    36,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,     0,   342,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
       0,     0,    58,    59,     0,     0,     0,     0,     0,     0,
       0,   121,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,   122,
      72,    73,    74,     0,    76,     0,     4,     5,     6,     7,
       8,     0,     0,     0,    78,     9,     0,     0,     0,     0,
      79,     0,   250,     0,     0,    82,    83,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,     0,     0,
       0,     0,    30,    31,   119,    33,    34,     0,     0,     0,
       0,     0,    36,  -634,  -634,  -634,  -634,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,     0,
     342,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   120,     0,     0,    58,    59,     0,
       0,     0,     0,     0,     0,     0,   121,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,   122,    72,    73,    74,     0,    76,
       0,     4,     5,     6,     7,     8,     0,     0,     0,    78,
       9,     0,     0,     0,     0,    79,     0,   259,     0,     0,
      82,    83,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
      12,    13,     0,     0,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,     0,     0,     0,     0,    30,    31,   119,
      33,    34,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295,     0,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
       0,     0,    58,    59,     0,     0,     0,     0,     0,     0,
       0,   121,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,   122,
      72,    73,    74,     0,    76,     0,     4,     5,     6,     7,
       8,     0,     0,     0,    78,     9,     0,     0,     0,     0,
      79,     0,     0,     0,     0,    82,    83,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,     0,     0,
       0,     0,    30,    31,   119,    33,    34,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   120,     0,     0,    58,    59,     0,
       0,     0,     0,     0,     0,     0,   121,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,   122,    72,    73,    74,     0,    76,
       0,     4,     5,     6,     7,     8,     0,     0,     0,    78,
       9,     0,     0,     0,     0,    79,   393,     0,     0,     0,
      82,    83,     0,    84,    85,     0,     0,     0,     0,   441,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
      12,    13,     0,     0,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,     0,     0,     0,     0,    30,    31,   119,
      33,    34,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
       0,     0,    58,    59,     0,     0,     0,     0,     0,     0,
       0,   121,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,   122,
      72,    73,    74,     0,    76,     0,     4,     5,     6,     7,
       8,     0,     0,     0,    78,     9,     0,     0,     0,     0,
      79,     0,     0,     0,     0,    82,    83,     0,    84,    85,
       0,     0,     0,     0,   474,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,     0,     0,
       0,     0,    30,    31,   119,    33,    34,     0,     0,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   120,     0,     0,    58,    59,     0,
       0,     0,     0,     0,     0,     0,   121,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,   122,    72,    73,    74,     0,    76,
       0,     0,     4,     5,     6,     7,     8,     0,     0,    78,
       0,     9,     0,     0,     0,    79,     0,     0,     0,     0,
      82,    83,     0,    84,    85,   485,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,    12,    13,     0,     0,     0,     0,    14,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,     0,     0,     0,     0,    30,    31,
     119,    33,    34,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,     0,     0,    58,    59,     0,     0,     0,     0,     0,
       0,     0,   121,    64,    65,    66,    67,    68,    69,     0,
       0,     0,     0,     0,     0,    70,     0,     0,     0,     0,
     122,    72,    73,    74,     0,    76,     0,     4,     5,     6,
       7,     8,     0,     0,     0,    78,     9,     0,     0,     0,
       0,    79,     0,     0,     0,     0,    82,    83,     0,    84,
      85,     0,     0,     0,     0,   519,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,    12,    13,     0,     0,
       0,     0,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,     0,
       0,     0,     0,    30,    31,   119,    33,    34,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,     0,     0,    58,    59,
       0,     0,     0,     0,     0,     0,     0,   121,    64,    65,
      66,    67,    68,    69,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,     0,   122,    72,    73,    74,     0,
      76,     0,     4,     5,     6,     7,     8,     0,     0,     0,
      78,     9,     0,     0,     0,     0,    79,     0,     0,     0,
       0,    82,    83,     0,    84,    85,     0,     0,     0,     0,
     729,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,    12,    13,     0,     0,     0,     0,    14,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,     0,     0,     0,     0,    30,    31,
     119,    33,    34,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,     0,     0,    58,    59,     0,     0,     0,     0,     0,
       0,     0,   121,    64,    65,    66,    67,    68,    69,     0,
       0,     0,     0,     0,     0,    70,     0,     0,     0,     0,
     122,    72,    73,    74,     0,    76,     0,     4,     5,     6,
       7,     8,     0,     0,     0,    78,     9,     0,     0,     0,
       0,    79,     0,     0,     0,     0,    82,    83,     0,    84,
      85,     0,     0,     0,     0,   731,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,    12,    13,     0,     0,
       0,     0,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,     0,
       0,     0,     0,    30,    31,   119,    33,    34,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,     0,     0,    58,    59,
       0,     0,     0,     0,     0,     0,     0,   121,    64,    65,
      66,    67,    68,    69,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,     0,   122,    72,    73,    74,     0,
      76,     0,     4,     5,     6,     7,     8,     0,     0,     0,
      78,     9,     0,     0,     0,     0,    79,     0,     0,     0,
       0,    82,    83,     0,    84,    85,     0,     0,     0,     0,
     738,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,    12,    13,     0,     0,     0,     0,    14,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,     0,     0,     0,     0,    30,    31,
     119,    33,    34,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,     0,     0,    58,    59,     0,     0,     0,     0,     0,
       0,     0,   121,    64,    65,    66,    67,    68,    69,     0,
       0,     0,     0,     0,     0,    70,     0,     0,     0,     0,
     122,    72,    73,    74,     0,    76,     0,     4,     5,     6,
       7,     8,     0,     0,     0,    78,     9,     0,     0,     0,
       0,    79,     0,     0,     0,     0,    82,    83,     0,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,    12,    13,     0,     0,
       0,     0,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,     0,
       0,     0,     0,    30,    31,   119,    33,    34,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,     0,     0,    58,    59,
       0,     0,     0,     0,     0,     0,     0,   121,    64,    65,
      66,    67,    68,    69,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,     0,   122,    72,    73,    74,   820,
      76,     0,     4,     5,     6,     7,     8,     0,     0,     0,
      78,     9,     0,     0,     0,     0,    79,     0,     0,     0,
       0,    82,    83,     0,    84,    85,     0,     0,     0,     0,
     912,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,    12,    13,     0,     0,     0,     0,    14,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,     0,     0,     0,     0,    30,    31,
     119,    33,    34,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,     0,     0,    58,    59,     0,     0,     0,     0,     0,
       0,     0,   121,    64,    65,    66,    67,    68,    69,     0,
       0,     0,     0,     0,     0,    70,     0,     0,     0,     0,
     122,    72,    73,    74,     0,    76,     0,     4,     5,     6,
       7,     8,     0,     0,     0,    78,     9,     0,     0,     0,
       0,    79,     0,     0,     0,     0,    82,    83,     0,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,    12,    13,     0,     0,
       0,     0,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,     0,
       0,     0,     0,    30,    31,   119,    33,    34,     0,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,     0,     0,    58,    59,
       0,     0,     0,     0,     0,     0,     0,   121,    64,    65,
      66,    67,    68,    69,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,     0,   122,    72,    73,    74,     0,
      76,     0,     4,     5,     6,     7,     8,     0,     0,     0,
      78,     9,     0,     0,     0,     0,    79,     0,     0,     0,
       0,    82,    83,     0,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,    12,    13,     0,     0,     0,     0,    14,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,     0,     0,     0,     0,    30,    31,
     119,   449,    34,     0,     0,     0,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,     0,     0,    58,    59,     0,     0,     0,     0,     0,
       0,     0,   121,    64,    65,    66,    67,    68,    69,     0,
     131,   132,   133,   134,   135,    70,   136,   137,   138,   139,
     122,    72,    73,    74,     0,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,    79,     0,     0,   546,     0,    82,    83,     0,    84,
      85,     0,     0,   547,     0,     0,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
     142,   143,   144,   145,   146,   147,     0,     0,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,     0,
     190,   191,   192,   193,   194,   195,   196,   131,   132,   133,
     134,   135,     0,   136,   137,   138,   139,     0,   197,   198,
     199,     0,   200,     0,     0,     0,     0,     0,     0,     0,
       0,   201,     0,   202,     0,     0,     0,     0,   203,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     948,     0,     0,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,   143,   144,
     145,   146,   147,     0,     0,   148,     0,     0,     0,     0,
       0,     0,     0,     0,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,     0,   190,   191,   192,
     193,   194,   195,   196,   131,   132,   133,   134,   135,     0,
     136,   137,   138,   139,     0,   197,   198,   199,     0,   200,
       0,     0,     0,     0,     0,     0,     0,     0,   201,     0,
     202,     0,     0,     0,     0,   203,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   142,   143,   144,   145,   146,   147,
       0,     0,   148,     0,     0,     0,     0,     0,     0,     0,
       0,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,     0,   190,   191,   192,   193,   194,   195,
     196,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   197,   198,   199,     0,   200,   317,   318,   319,
       0,     0,     0,     0,     0,   201,     0,   202,     0,     0,
       0,     0,   203,   320,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,     0,   342,   317,   318,
     319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   320,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,     0,   342,   317,
     318,   319,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   320,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,     0,   342,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   317,   318,   319,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   320,   652,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,     0,   342,   317,   318,
     319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   320,   655,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,     0,   342,   317,
     318,   319,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   320,   680,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,     0,   342,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   317,   318,   319,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   320,   711,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,     0,   342,   317,   318,
     319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   320,   760,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,     0,   342,   317,
     318,   319,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   320,   782,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,     0,   342,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   317,   318,   319,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   320,  1023,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,     0,   342,   317,   318,
     319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   320,  1024,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,     0,   342,   317,
     318,   319,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   343,   320,     0,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,     0,   342,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   317,   318,   319,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   320,   406,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,     0,   342,   317,   318,   319,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   320,   408,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,     0,   342,   317,   318,   319,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   320,   417,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,     0,   342,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   317,   318,   319,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   320,
     419,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,     0,   342,   317,   318,   319,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     320,   460,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,     0,   342,   317,   318,   319,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   320,   758,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,     0,   342,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   317,   318,   319,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   320,   976,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
       0,   342,     0,   317,   318,   319,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   462,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,     0,   342,   317,   318,   319,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   542,
     320,     0,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,     0,   342,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   317,   318,
     319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   320,   564,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,     0,   342,     0,
     317,   318,   319,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   320,   565,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,     0,
     342,   317,   318,   319,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   320,   568,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
       0,   342,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   317,   318,   319,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   320,   574,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,     0,   342,   580,   581,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   886,     0,   317,   318,   319,     0,
       0,     0,     0,    30,    31,   119,     0,     0,     0,     0,
       0,     0,   320,    36,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,  1082,   342,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,     0,   342,   582,    65,
      66,    67,    68,    69,     0,     0,     0,     0,     0,     0,
     583,     0,     0,     0,     0,   122,    72,    73,    74,     0,
     584,     0,     0,     0,     0,     0,     0,     0,     0,  1123,
      78,     0,   317,   318,   319,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   320,   611,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,     0,   342,   317,   318,   319,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   320,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   320,   342,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,     0,   342,     0,     0,   317,
     318,   319,     0,     0,     0,   824,     0,     0,     0,     0,
       0,     0,     0,     0,   570,   320,   636,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,     0,   342,
     317,   318,   319,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   320,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,     0,
     342,   318,   319,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   320,     0,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   319,
     342,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   320,     0,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,     0,   342,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,     0,
     342,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,     0,   342
};

static const yytype_int16 yycheck[] =
{
       2,    27,   310,     2,     2,     2,    77,     2,   123,     2,
     368,   551,   746,    27,   696,   380,    48,   373,   342,   633,
     444,   843,    24,    25,   941,    96,    52,   724,   261,   846,
     388,   846,     8,   569,   737,   456,     8,    26,   116,     8,
       8,     8,     8,     8,     8,    71,    26,    71,    74,     8,
     162,    36,     9,    10,    11,     8,    78,   754,     8,     8,
      29,     8,     8,     8,    73,     8,    24,    25,    25,    27,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     8,    49,   162,     8,   147,    71,    71,   102,     8,
       8,     8,  1019,     8,     8,    24,    25,    61,     0,   107,
     578,   579,   934,   165,   817,   137,     9,    10,    11,    90,
     144,   162,    61,    25,    61,   859,    25,    61,    61,    61,
     121,    61,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,   858,    49,   161,   167,    26,
     857,    13,   147,    25,   164,   165,    61,   121,    71,    71,
      73,   146,    71,   144,    26,   166,   165,    71,   543,   544,
     165,    61,    73,   162,   164,    61,   117,    61,   162,    61,
     166,    43,   164,   165,   163,   809,   164,   164,   164,   164,
     164,   227,   816,   624,    61,   164,   140,    61,    73,    71,
     162,   164,   169,   163,   828,   164,   898,   164,   164,   164,
     252,   164,   124,    25,   256,   124,   165,   695,   165,   162,
     162,   165,   165,   165,   349,   165,    61,   263,   778,   241,
     943,    61,   313,    61,   146,   942,   163,   146,   241,   163,
     674,   607,  1169,   789,   163,   163,   163,   121,   163,   163,
     162,  1178,   124,   162,   167,   291,   268,   162,   346,    71,
     165,   164,   162,   275,   276,   277,   167,   348,   310,   350,
     282,   639,   640,    78,   146,   165,   288,   365,    25,   165,
     648,   165,   650,   165,    71,   157,    98,    25,   300,   163,
     162,   163,   300,   162,   918,   162,   384,    25,   165,   387,
     268,   165,   390,  1130,  1017,  1130,   342,   275,   276,   277,
      73,   645,   124,  1020,   282,    93,    94,    71,   342,    73,
     288,  1153,   346,   796,    71,   875,    31,   877,   115,    71,
     165,    73,   137,    71,   146,   165,    71,   165,    73,   268,
     774,   365,    31,    71,  1054,  1055,   275,   276,   277,   385,
     162,    73,   162,   282,    36,   979,    78,    71,    71,   288,
     384,   373,  1075,   387,    71,   165,   390,    31,    73,   411,
      98,   117,   806,    71,   342,   162,    73,   124,   106,   107,
     108,   109,   110,   111,    73,   421,   124,    63,   166,    71,
     765,   766,   162,    73,  1138,    71,   124,    73,    78,   146,
      90,    93,    94,   162,   167,   373,   418,    71,   146,    73,
     418,   165,   162,   167,  1158,   162,   138,   139,   146,   157,
     893,    31,   895,   165,   162,   167,   162,   141,   141,   441,
     144,   144,   167,   146,   162,   111,   517,     8,   681,   146,
     137,   138,   139,   150,   373,    73,   144,   111,   691,   171,
      78,    31,   166,   819,   144,   162,    41,    71,   138,   139,
      42,    43,   474,    73,    73,   141,    37,   165,   144,    78,
     146,   162,     8,   441,   166,  1025,  1100,   141,   162,    61,
     144,    73,   146,    71,   144,    26,   415,    69,    70,    71,
     170,   167,   140,    73,   165,   863,   144,    79,    71,   428,
      73,    37,    43,   167,   164,   165,   474,   519,   162,   827,
     138,   139,   441,    53,    99,    55,    56,    57,    58,   104,
      31,   106,   107,   108,   109,   110,   111,   112,   137,   138,
     139,    71,    25,    61,    73,    61,   578,   579,   111,    78,
     140,  1165,   124,   786,   144,   474,   138,   139,   144,    42,
      26,   519,    45,   565,   136,  1179,    61,    25,   570,   345,
      73,   573,   565,   148,   149,    78,   151,    43,   141,   605,
     573,   144,   112,   146,    42,    66,    67,    45,   140,    73,
     366,   166,   144,   369,    78,    71,   598,    73,    74,   140,
     519,    71,   165,    73,   167,   607,   608,   633,   137,   138,
     139,   141,   570,   162,   144,   391,   146,    66,    67,   645,
     162,   623,   152,   931,   623,   623,   623,   992,   623,    61,
     623,   645,    69,    70,    71,   138,   139,    41,   162,    40,
     598,   111,    92,    93,    94,    71,    71,   140,    73,   607,
     608,   570,   571,   123,   138,   139,    45,    46,    47,    49,
      49,   580,   581,   695,   696,   106,   107,   108,   109,   110,
     111,   141,   140,   906,   144,   121,   146,   144,   140,   598,
     140,   121,   684,   162,   686,    71,   111,   645,   607,   608,
      41,   684,   718,   164,    13,    99,    71,   167,   123,    13,
     104,    36,   106,   107,   108,   109,   110,   111,   112,   163,
      71,   630,   164,    98,   162,   168,   141,    37,   162,   144,
       8,   146,   748,   164,   109,   110,    82,   729,   686,   731,
       8,   164,   117,   118,   736,    36,   738,   736,   736,   736,
      13,   736,   167,   736,   148,   149,   162,   151,    99,    92,
      93,    94,     8,   104,    71,   106,   107,   108,   109,   110,
     111,   112,   166,    73,    69,    70,   164,   686,    71,   154,
     802,   729,   119,   731,    79,    83,    84,    85,   162,     8,
     738,   783,   163,   809,   703,   783,    71,   813,   165,   791,
     816,    61,   794,   712,  1027,   827,   794,   148,   149,  1032,
     151,    61,   828,   163,     8,    13,    71,  1040,    73,   163,
     729,   843,   731,   928,   169,   166,   169,   819,   162,   738,
     125,   126,   127,   128,   129,    42,    43,    44,    45,    46,
      47,   136,    49,   791,   162,  1068,   119,   142,   143,  1072,
     162,    13,   169,   285,   842,   169,   111,   289,    71,   162,
    1083,   156,   163,   169,    36,  1088,    71,   102,  1091,   140,
     302,   819,   304,   305,   306,   307,   898,   899,   162,   140,
      71,    13,   791,   164,   793,     8,   141,    37,   165,   144,
     169,   146,   884,    13,   120,   887,   165,   162,  1121,   887,
      13,   884,   918,  1008,   162,     8,   163,   122,   164,   931,
     819,    13,   167,   935,   106,   107,   108,   109,   110,   111,
     912,   163,     8,   163,  1147,   137,    71,    71,   162,   161,
      41,     8,   162,   144,   144,   163,     8,   122,     4,     5,
     165,     7,     8,     9,  1005,   933,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   162,  1182,
      26,   163,   163,   979,   912,   165,   163,   163,  1191,     8,
     962,    37,    71,   137,    73,   163,   169,   164,    44,   962,
      46,   164,   974,    49,    40,    51,   974,   122,    99,    26,
     163,     8,   901,   104,   903,   106,   107,   108,   109,   110,
     111,   112,   165,   912,   150,  1066,   166,    98,    26,    75,
      73,    13,   111,    79,   163,    73,   163,   165,    13,   162,
      73,   104,   164,   415,   163,    13,   164,   164,   122,   163,
     415,   940,  1048,   163,   162,    26,   428,   148,   149,  1031,
     151,    68,   141,   428,   163,   144,   164,   146,  1031,   164,
      13,   122,    13,   163,   162,   166,   165,    73,   165,    13,
     165,   127,   146,   164,   164,    73,   162,   165,   167,   978,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    13,    49,  1100,   165,    90,    90,  1080,   140,
    1082,    51,  1080,    29,  1086,    13,    73,  1089,  1086,  1082,
     162,  1089,    26,   164,    71,  1014,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   164,   155,
      71,   153,   163,    73,   164,  1117,    73,   162,  1120,  1117,
     163,   165,  1120,  1125,  1043,  1127,  1128,  1125,   163,  1127,
    1128,   421,   350,  1164,   347,   107,   644,   756,   748,  1165,
    1165,  1060,    59,    60,  1146,   641,  1065,   994,  1146,   348,
     791,  1070,   428,  1179,  1037,   838,  1100,   426,  1006,   235,
    1162,   237,    37,  1184,  1162,   763,   242,   243,   244,   571,
     246,   992,   757,   664,   775,   721,   571,   676,   580,   581,
     715,   276,  1101,    -1,  1186,   580,   581,   849,  1186,    -1,
    1192,    -1,    -1,    -1,  1192,    -1,    -1,    -1,    -1,  1118,
      -1,    -1,    -1,   605,   121,    -1,    -1,   283,    -1,    -1,
      -1,   287,    -1,    -1,    -1,    -1,    -1,    -1,  1137,    -1,
      -1,    -1,    -1,    -1,    -1,   301,    -1,    -1,   630,    -1,
      -1,   633,    -1,   309,    -1,   630,    -1,    -1,    -1,    -1,
      -1,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,    -1,    -1,   344,   345,
      -1,    -1,    -1,    -1,    -1,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,    -1,    -1,    -1,
     366,   367,   368,   369,   370,   571,    -1,    -1,    -1,   375,
      -1,   703,    -1,    -1,   580,   581,    -1,    -1,   703,    -1,
     712,    -1,   388,    -1,    -1,   391,   392,   712,    -1,    -1,
     396,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   748,    -1,   424,    -1,
      -1,    -1,    -1,    -1,   630,    31,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    -1,
      -1,   793,    -1,    69,    70,    71,    72,    73,   793,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,   809,    -1,   485,
      -1,    -1,    -1,    -1,   816,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,   828,   703,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   712,    -1,   114,   115,
      -1,    -1,    -1,    -1,   520,    -1,    -1,   123,   124,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,   534,    -1,
     136,    -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,    -1,   560,    -1,   162,    -1,    -1,    -1,
      -1,   167,   168,   569,   170,   171,    -1,    -1,    -1,   901,
      -1,   903,    -1,    -1,    -1,    -1,   901,    -1,   903,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   918,   793,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,   611,    49,   613,   940,    -1,
      -1,    -1,    -1,    -1,   620,   940,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   629,    -1,    -1,    -1,    -1,    -1,    -1,
     636,    -1,    -1,   639,   640,    -1,    41,    -1,     9,    10,
      11,    -1,   648,    -1,   650,    -1,   978,   979,    -1,    -1,
      -1,    -1,    -1,   978,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,   683,    49,    -1,
      -1,    -1,  1014,    -1,    41,    -1,    -1,    -1,    -1,  1014,
      -1,    -1,    -1,    -1,    99,   901,    -1,   903,    -1,   104,
      -1,   106,   107,   108,   109,   110,   111,   112,    -1,    -1,
      -1,  1043,    -1,    -1,    -1,    -1,  1048,    -1,  1043,    -1,
      -1,    -1,   728,    -1,  1049,    -1,    -1,    -1,  1060,    -1,
      -1,    -1,    -1,  1065,   940,  1060,    -1,    -1,  1070,    -1,
    1065,    -1,    99,   148,   149,  1070,   151,   104,    -1,   106,
     107,   108,   109,   110,   111,   112,   762,    -1,    -1,    -1,
      -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,  1100,  1101,
      -1,    -1,   978,    -1,    -1,    -1,  1101,    -1,    -1,    -1,
      -1,    -1,    -1,   789,    -1,    -1,  1118,    -1,    -1,    -1,
      -1,   148,   149,  1118,   151,   166,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1137,  1131,    -1,  1014,   166,
      -1,    -1,  1137,    -1,   820,    -1,    -1,    -1,   824,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1165,    -1,    -1,    -1,  1043,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1179,    -1,    -1,
       9,    10,    11,    -1,  1060,    -1,    -1,   863,    -1,  1065,
      -1,   867,    -1,    -1,  1070,   871,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,  1101,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,  1118,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,  1137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    36,
      -1,   957,    -1,    -1,    41,    42,    43,    -1,    -1,    -1,
     966,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    -1,    75,    -1,
      -1,    -1,    79,    80,    81,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    -1,    91,   121,    -1,   166,    95,    96,
      97,    98,    99,   100,   101,    -1,   103,   104,   105,    -1,
    1026,    -1,   109,   110,   111,    -1,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
      -1,     3,     4,     5,     6,     7,    -1,   154,    -1,   156,
      12,    -1,    -1,    -1,    -1,   162,    -1,   164,   165,   166,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    41,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    -1,    75,    -1,    -1,    -1,    79,    80,    81,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,   101,
      -1,   103,   104,   105,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,    -1,     3,     4,     5,     6,
       7,    -1,   154,    -1,   156,    12,    -1,    -1,    -1,    -1,
     162,    -1,   164,   165,   166,   167,   168,    -1,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    41,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    -1,    75,    -1,
      -1,    -1,    79,    80,    81,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,   101,    -1,   103,   104,   105,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
      -1,     3,     4,     5,     6,     7,    -1,   154,    -1,   156,
      12,    -1,    -1,    -1,    -1,   162,    -1,   164,   165,    -1,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    41,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    -1,    75,    -1,    -1,    -1,    79,    80,    81,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,   103,    -1,   105,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,   117,   118,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,    -1,     3,     4,     5,     6,
       7,    -1,   154,    -1,   156,    12,    -1,    -1,    -1,    -1,
     162,    -1,   164,   165,   166,   167,   168,    -1,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    41,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    -1,    75,    -1,
      -1,    -1,    79,    80,    81,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    -1,   100,   101,    -1,   103,    -1,   105,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,    -1,
     117,   118,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
      -1,     3,     4,     5,     6,     7,    -1,   154,    -1,   156,
      12,    -1,    -1,    -1,    -1,   162,    -1,   164,   165,   166,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    41,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    -1,    75,    -1,    -1,    -1,    79,    80,    81,
      82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,   103,    -1,   105,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,   117,   118,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,    -1,     3,     4,     5,     6,
       7,    -1,   154,    -1,   156,    12,    -1,    -1,    -1,    -1,
     162,    -1,   164,   165,    -1,   167,   168,    -1,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    41,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    -1,    75,    -1,
      -1,    -1,    79,    80,    81,    82,    83,    84,    -1,    86,
      -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    -1,   100,   101,    -1,   103,    -1,   105,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,    -1,
     117,   118,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
      -1,     3,     4,     5,     6,     7,    -1,   154,    -1,   156,
      12,    -1,    -1,    -1,    -1,   162,    -1,   164,   165,    -1,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    41,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    -1,    75,    -1,    -1,    -1,    79,    80,    81,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,   103,    -1,   105,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,   117,   118,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,    -1,     3,     4,     5,     6,
       7,    -1,   154,    -1,   156,    12,    -1,    -1,    -1,    -1,
     162,    -1,   164,   165,   166,   167,   168,    -1,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    41,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    -1,    75,    -1,
      -1,    -1,    79,    80,    81,    82,    -1,    84,    -1,    86,
      87,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    -1,   100,   101,    -1,   103,    -1,   105,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,    -1,
     117,   118,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
      -1,     3,     4,     5,     6,     7,    -1,   154,    -1,   156,
      12,    -1,    -1,    -1,    -1,   162,    -1,   164,   165,    -1,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    41,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    -1,    75,    -1,    -1,    -1,    79,    80,    81,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,   103,    -1,   105,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,   117,   118,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,    -1,     3,     4,     5,     6,
       7,    -1,   154,    -1,   156,    12,    -1,    -1,    -1,    -1,
     162,    -1,   164,   165,   166,   167,   168,    -1,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    41,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    -1,    75,    -1,
      -1,    -1,    79,    80,    81,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    -1,   100,   101,    -1,   103,    -1,   105,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,    -1,
     117,   118,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
      -1,     3,     4,     5,     6,     7,    -1,   154,    -1,   156,
      12,    -1,    -1,    -1,    -1,   162,    -1,   164,   165,   166,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    41,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    -1,    75,    -1,    -1,    -1,    79,    80,    81,
      82,    -1,    84,    85,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,   103,    -1,   105,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,   117,   118,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,    -1,     3,     4,     5,     6,
       7,    -1,   154,    -1,   156,    12,    -1,    -1,    -1,    -1,
     162,    -1,   164,   165,    -1,   167,   168,    -1,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    41,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    -1,    75,    -1,
      -1,    -1,    79,    80,    81,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    -1,   100,   101,    -1,   103,    -1,   105,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,    -1,
     117,   118,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
      -1,     3,     4,     5,     6,     7,    -1,   154,    -1,   156,
      12,    -1,    -1,    -1,    -1,   162,    -1,   164,   165,   166,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    41,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    -1,    75,    -1,    -1,    -1,    79,    80,    81,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,   103,    -1,   105,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,   117,   118,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,    -1,     3,     4,     5,     6,
       7,    -1,   154,    -1,   156,    12,    -1,    -1,    -1,    -1,
     162,    -1,   164,   165,   166,   167,   168,    -1,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    41,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    -1,    75,    -1,
      -1,    -1,    79,    80,    81,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    -1,   100,   101,    -1,   103,    -1,   105,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,    -1,
     117,   118,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
      -1,     3,     4,     5,     6,     7,    -1,   154,    -1,   156,
      12,    -1,    -1,    -1,    -1,   162,    -1,   164,   165,   166,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    41,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    -1,    75,    -1,    -1,    -1,    79,    80,    81,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,   103,    -1,   105,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,   117,   118,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,    -1,     3,     4,     5,     6,
       7,    -1,   154,    -1,   156,    12,    -1,    -1,    -1,    -1,
     162,    -1,   164,   165,   166,   167,   168,    -1,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    41,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    -1,    75,    -1,
      -1,    -1,    79,    80,    81,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    -1,   100,   101,    -1,   103,    -1,   105,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,    -1,
     117,   118,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
      -1,    -1,     3,     4,     5,     6,     7,   154,    -1,   156,
      -1,    12,    -1,    -1,    -1,   162,    -1,   164,   165,    -1,
     167,   168,    -1,   170,   171,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    -1,    75,    -1,    -1,    -1,    79,    80,
      81,    82,    -1,    84,    -1,    86,    -1,    88,    -1,    -1,
      91,    -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,
     101,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,
     111,    -1,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,
     141,   142,   143,   144,   145,   146,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,   156,    -1,    12,    -1,    -1,
      -1,   162,    -1,   164,   165,    -1,   167,   168,    -1,   170,
     171,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,
      75,    -1,    -1,    -1,    79,    80,    81,    82,    -1,    84,
      -1,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    96,    97,    98,    -1,   100,   101,    -1,   103,    -1,
     105,    -1,    -1,    -1,    -1,    -1,   111,    -1,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,    -1,    -1,    -1,   141,   142,   143,   144,
     145,   146,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,   156,    -1,    12,    -1,    -1,    -1,   162,    -1,   164,
     165,    -1,   167,   168,    -1,   170,   171,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    62,    63,    64,    65,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    -1,    75,    -1,    -1,    -1,
      79,    80,    81,    82,    -1,    84,    -1,    86,    -1,    88,
      -1,    -1,    91,    -1,    -1,    -1,    95,    96,    97,    98,
      -1,   100,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,   125,   126,   127,   128,
     129,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,
      -1,    -1,   141,   142,   143,   144,   145,   146,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,   156,    -1,    12,
      -1,    -1,    -1,   162,    -1,   164,   165,    -1,   167,   168,
      -1,   170,   171,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    62,
      63,    64,    65,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    -1,    75,    -1,    -1,    -1,    79,    80,    81,    82,
      -1,    84,    -1,    86,    -1,    88,    -1,    -1,    91,    -1,
      -1,    -1,    95,    96,    97,    98,    -1,   100,   101,    -1,
     103,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,    -1,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,   125,   126,   127,   128,   129,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,   142,
     143,   144,   145,   146,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,   156,    -1,    12,    -1,    -1,    -1,   162,
      -1,   164,   165,    -1,   167,   168,    -1,   170,   171,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    -1,    75,    -1,
      -1,    -1,    79,    80,    81,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    -1,   100,   101,    -1,   103,    -1,   105,    -1,
      -1,    -1,    -1,    -1,   111,    -1,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,   156,
      12,    -1,    -1,    -1,    -1,   162,    -1,   164,   165,    -1,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    -1,    75,    -1,    -1,    -1,    79,    80,    81,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,
      -1,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,   156,    12,    -1,    -1,    -1,    -1,
     162,    -1,   164,   165,    -1,   167,   168,    -1,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    98,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,    -1,   146,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,   156,
      12,    -1,    -1,    -1,    -1,   162,    -1,   164,    -1,    -1,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    79,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,    -1,   146,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,   156,    12,    -1,    -1,    -1,    -1,
     162,    -1,   164,    -1,    -1,   167,   168,    -1,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,    -1,   146,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,   156,
      12,    -1,    -1,    -1,    -1,   162,    -1,   164,    -1,    -1,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,    -1,   146,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,   156,    12,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,    -1,   167,   168,    -1,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,    -1,   146,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,   156,
      12,    -1,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,
     167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,    -1,   146,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,   156,    12,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,    -1,   167,   168,    -1,   170,   171,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,    -1,   146,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,   156,
      -1,    12,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,
     167,   168,    -1,   170,   171,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,
     141,   142,   143,   144,    -1,   146,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,   156,    12,    -1,    -1,    -1,
      -1,   162,    -1,    -1,    -1,    -1,   167,   168,    -1,   170,
     171,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,   141,   142,   143,   144,    -1,
     146,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
     156,    12,    -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,
      -1,   167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,
     141,   142,   143,   144,    -1,   146,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,   156,    12,    -1,    -1,    -1,
      -1,   162,    -1,    -1,    -1,    -1,   167,   168,    -1,   170,
     171,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,   141,   142,   143,   144,    -1,
     146,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
     156,    12,    -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,
      -1,   167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,
     141,   142,   143,   144,    -1,   146,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,   156,    12,    -1,    -1,    -1,
      -1,   162,    -1,    -1,    -1,    -1,   167,   168,    -1,   170,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,
     146,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
     156,    12,    -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,
      -1,   167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,
     141,   142,   143,   144,    -1,   146,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,   156,    12,    -1,    -1,    -1,
      -1,   162,    -1,    -1,    -1,    -1,   167,   168,    -1,   170,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,   141,   142,   143,   144,    -1,
     146,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
     156,    12,    -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,
      -1,   167,   168,    -1,   170,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,   127,   128,   129,    -1,
       3,     4,     5,     6,     7,   136,     9,    10,    11,    12,
     141,   142,   143,   144,    -1,   146,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
      -1,   162,    -1,    -1,    37,    -1,   167,   168,    -1,   170,
     171,    -1,    -1,    46,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
     123,   124,   125,   126,   127,   128,   129,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    12,    -1,   141,   142,
     143,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,   156,    -1,    -1,    -1,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      66,    67,    68,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,   123,   124,   125,
     126,   127,   128,   129,     3,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    -1,   141,   142,   143,    -1,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
     156,    -1,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,   123,   124,   125,   126,   127,   128,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   142,   143,    -1,   145,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,
      -1,    -1,   161,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,   166,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   166,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   166,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,   166,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   166,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   166,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,   166,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   166,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   164,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   164,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,   164,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
     164,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,   164,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   164,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   164,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   163,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,   163,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   163,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   163,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    79,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,   163,    49,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,   124,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,   141,   142,   143,   144,    -1,
     146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
     156,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   122,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    25,    49,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    11,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   173,   174,     0,     3,     4,     5,     6,     7,    12,
      36,    41,    42,    43,    48,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    62,    63,    64,    65,
      69,    70,    71,    72,    73,    75,    79,    80,    81,    82,
      84,    86,    88,    91,    95,    96,    97,    98,    99,   100,
     101,   103,   104,   105,   109,   110,   111,   113,   114,   115,
     116,   117,   118,   123,   124,   125,   126,   127,   128,   129,
     136,   141,   142,   143,   144,   145,   146,   154,   156,   162,
     164,   165,   167,   168,   170,   171,   175,   180,   181,   182,
     183,   186,   197,   198,   201,   208,   214,   275,   277,   278,
     279,   282,   300,   301,   303,   308,   311,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   336,   345,   347,    71,
     111,   123,   141,   197,   275,   327,   275,   162,   275,   275,
     275,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      49,    62,    63,    64,    65,    66,    67,    68,    71,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     123,   124,   125,   126,   127,   128,   129,   141,   142,   143,
     145,   154,   156,   161,   293,   299,   324,   325,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     181,   301,   327,   327,   275,   111,   141,   144,   146,   180,
     301,   304,   332,   337,   338,   162,   305,   162,    26,   273,
     275,   188,   162,   162,   162,   162,   162,   164,   275,    71,
     164,   275,    25,    71,   124,   146,   162,   348,   355,   164,
     275,   165,   275,   144,   178,   179,   180,    73,   167,   238,
     239,   117,   117,    73,   240,   162,   162,   162,   162,    71,
     212,   349,   162,   162,    73,    78,   137,   138,   139,   342,
     343,   144,   165,   180,   180,    95,   275,   213,   349,   275,
     184,   165,    78,   306,   342,    78,   342,   342,   144,   162,
       8,   164,    31,   196,   146,   211,   349,     9,    10,    11,
      25,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    49,   164,    61,    61,   140,   118,   154,   197,
     214,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    59,    60,   121,    61,   165,   162,    61,
     165,   167,   333,   162,   196,    13,   275,    26,    43,   283,
     287,    40,    71,   323,   140,   144,   180,   140,   162,   307,
     121,    61,   165,   163,   275,   275,     8,   164,   186,   275,
     273,   274,   275,    71,   226,   275,   164,   164,   164,    71,
     355,    36,   350,    98,   355,    13,    71,   164,   184,   164,
     180,     8,   164,    90,   165,   327,     8,   164,    13,     8,
     164,   327,   346,   346,   327,   163,    36,   206,   123,   327,
     339,    31,   275,   340,   341,    61,   121,   137,   343,    72,
     275,   327,    78,   137,   343,   180,   177,   164,   165,   164,
     164,   209,   163,   166,   185,   186,   198,   201,   208,   275,
     168,   170,   171,    71,    31,   236,   237,   275,   348,   162,
     349,   202,   275,   275,   275,    26,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   304,   275,
     335,   335,    71,   332,   333,   212,   213,   196,   211,    31,
     145,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,    71,   165,   332,   335,   275,   236,   335,
     275,   339,   163,   294,   295,    37,    37,    46,   290,   296,
     299,   162,   322,     8,   313,    71,   180,   332,   236,    71,
     165,   332,   335,   275,   163,   163,   275,    82,   163,   164,
      90,    13,     8,   163,   163,    71,   351,   355,   162,     8,
      42,    43,   124,   136,   146,   181,   182,   308,   309,   310,
     166,    90,   179,    71,   275,   239,   309,    73,     8,   163,
     163,   163,   164,    71,   354,   119,   217,   162,     8,   163,
     327,   122,   163,     8,   313,    71,    73,    74,   344,    71,
      61,   166,   166,   174,   176,   165,   166,   327,   163,     8,
      13,   276,   199,   119,   215,   275,    26,   169,   169,   162,
     162,   207,   210,   349,   204,    63,   327,   275,   162,   275,
     162,   169,   166,   163,   169,   166,   163,   299,   299,   284,
      13,    26,    43,    42,    43,    61,    69,    70,    71,    79,
     124,   136,   315,   317,   320,   321,    71,   163,   275,   169,
     166,    26,   186,   162,   187,   274,    31,   221,   327,   309,
      71,    26,   186,   225,   190,    36,     8,    37,   352,   355,
     352,   309,   309,   162,    78,   140,   140,   102,   193,   194,
      71,   166,    13,   327,   164,     8,    37,   141,   144,   146,
     180,   182,   218,   302,   165,   339,   123,   327,    13,    31,
     275,    31,   275,   169,   275,   166,   174,   241,    31,   275,
     309,   157,   234,   235,   355,   356,   162,   302,   120,   216,
     275,   236,   236,   217,   165,   200,   215,   304,   164,   236,
     166,   236,    13,   289,   288,   297,   298,    69,    70,    71,
     316,   316,   317,   318,   319,   162,    78,   137,     8,   313,
     163,   322,   166,   184,   230,   275,    26,   186,   224,   164,
     327,   122,   220,    13,   184,    26,   165,   227,   352,   355,
     351,   163,     8,   163,   309,   312,   314,    71,    71,   162,
     161,   309,   354,   144,   180,   350,     8,   241,   163,   162,
     145,   275,   327,   327,   122,   169,   166,    99,   104,   106,
     107,   108,   109,   110,   111,   112,   148,   149,   151,   166,
     242,   267,   268,   269,   270,   272,   326,   327,   163,     8,
      31,    73,   234,   218,   165,   163,   163,   165,   241,   162,
     216,   307,   163,   162,   163,    36,   147,   165,   282,   292,
     147,   165,   291,   299,   299,   122,   169,     8,   313,   318,
     137,   317,   231,    66,    67,   232,   163,   184,   274,   221,
     163,   309,    89,   164,   228,   164,   228,    40,     8,    26,
     352,   122,   163,     8,   313,   302,   165,   180,   302,   166,
     339,   275,    31,   275,   166,   348,   219,   302,   247,   150,
     260,   261,    71,   115,   162,   262,   263,   243,   197,   270,
     355,     8,   164,   268,   269,    26,   353,   157,   356,    73,
      13,   163,   203,   241,   166,   234,   165,   236,    46,   275,
     275,   317,   317,   163,    66,    67,   233,   162,   186,   164,
      83,   163,   191,   164,   228,    92,    93,    94,   228,   166,
     355,   309,   309,    73,   184,   163,   164,   327,    13,     8,
     164,   165,    53,    55,    56,    57,    58,   112,   146,   152,
     252,   254,   255,   302,     8,   164,    71,   146,   150,   263,
     264,   265,   164,    73,   271,   196,   244,   348,   197,   355,
     104,   280,    31,    73,    13,   309,   353,   241,   166,   163,
     205,   163,   285,   166,   166,   122,   162,    26,    68,   275,
     164,   189,    26,   186,   223,    92,   164,   275,    26,   164,
     229,   166,   163,   122,   163,   166,   309,   302,   248,   165,
       8,   164,   296,   261,     8,    29,   163,    25,    42,    45,
      13,     8,   164,   349,   271,    13,   196,   162,   165,    73,
      13,   309,   165,   166,   353,   241,   146,   286,   317,   275,
     184,   164,   163,    26,   186,   222,   184,   164,   229,   184,
     309,   165,    71,   166,   182,   249,   250,   251,   256,   308,
     253,    13,   257,   264,   264,    25,    42,    45,   309,    73,
     162,   164,   309,   349,    31,    73,   281,   184,    13,   309,
     184,   165,   166,   163,   186,   184,    87,   184,   184,   140,
      90,     8,   166,   254,   309,    51,   258,    13,   245,   162,
      73,     8,   163,   166,   309,   166,   184,    26,    85,   164,
     166,    71,   268,   269,   308,   259,   309,   234,   246,    31,
      73,   166,   184,   164,   192,   155,    71,   164,   153,   163,
     234,    73,   102,   193,   195,   219,   164,   353,   163,   162,
     164,   164,   165,   266,   353,   302,   184,   266,    73,   166,
     163,   165,   184,   166
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (&yylloc, _p, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).line0   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).char0 = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).line1    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).char1  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).line0   = (Current).line1   =		\
	    YYRHSLOC (Rhs, 0).line1;				\
	  (Current).char0 = (Current).char1 =		\
	    YYRHSLOC (Rhs, 0).char1;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).line0, (Loc).char0,	\
	      (Loc).line1,  (Loc).char1)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location, _p); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, HPHP::HPHP_PARSER_NS::Parser *_p)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, _p)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    HPHP::HPHP_PARSER_NS::Parser *_p;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (_p);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, HPHP::HPHP_PARSER_NS::Parser *_p)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, _p)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    HPHP::HPHP_PARSER_NS::Parser *_p;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, _p);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, HPHP::HPHP_PARSER_NS::Parser *_p)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, _p)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    HPHP::HPHP_PARSER_NS::Parser *_p;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , _p);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, _p); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, HPHP::HPHP_PARSER_NS::Parser *_p)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, _p)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    HPHP::HPHP_PARSER_NS::Parser *_p;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (_p);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (HPHP::HPHP_PARSER_NS::Parser *_p);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (HPHP::HPHP_PARSER_NS::Parser *_p)
#else
int
yyparse (_p)
    HPHP::HPHP_PARSER_NS::Parser *_p;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.line0   = yylloc.line1   = 1;
  yylloc.char0 = yylloc.char1 = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	struct yyalloc *yyptr =
	  (struct yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        memset(yyptr, 0, YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE_RESET (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 987 "../../../src/util/parser/hphp.y"
    { _p->popLabelInfo();
                                         _p->saveParseTree((yyval));;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 993 "../../../src/util/parser/hphp.y"
    { _p->addStatement((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 994 "../../../src/util/parser/hphp.y"
    { _p->onStatementListStart((yyval));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 997 "../../../src/util/parser/hphp.y"
    { _p->nns((yyvsp[(1) - (1)]).num() == T_DECLARE);
                                         (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 999 "../../../src/util/parser/hphp.y"
    { _p->nns(); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 1000 "../../../src/util/parser/hphp.y"
    { _p->nns(); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 1001 "../../../src/util/parser/hphp.y"
    { _p->nns(); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 1002 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 1003 "../../../src/util/parser/hphp.y"
    { _p->onNamespaceStart((yyvsp[(2) - (3)]).text());
                                         (yyval).reset();;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 1005 "../../../src/util/parser/hphp.y"
    { _p->onNamespaceStart((yyvsp[(2) - (3)]).text());;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 1006 "../../../src/util/parser/hphp.y"
    { _p->onNamespaceEnd(); (yyval) = (yyvsp[(5) - (6)]);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 1007 "../../../src/util/parser/hphp.y"
    { _p->onNamespaceStart("");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 1008 "../../../src/util/parser/hphp.y"
    { _p->onNamespaceEnd(); (yyval) = (yyvsp[(4) - (5)]);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 1009 "../../../src/util/parser/hphp.y"
    { _p->nns(); (yyval).reset();;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 1010 "../../../src/util/parser/hphp.y"
    { _p->nns();
                                         _p->finishStatement((yyval), (yyvsp[(1) - (2)])); (yyval) = 1;;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 1016 "../../../src/util/parser/hphp.y"
    { ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 1017 "../../../src/util/parser/hphp.y"
    { ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 1020 "../../../src/util/parser/hphp.y"
    { _p->onUse((yyvsp[(1) - (1)]).text(),"");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 1021 "../../../src/util/parser/hphp.y"
    { _p->onUse((yyvsp[(2) - (2)]).text(),"");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 1022 "../../../src/util/parser/hphp.y"
    { _p->onUse((yyvsp[(1) - (3)]).text(),(yyvsp[(3) - (3)]).text());;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 1024 "../../../src/util/parser/hphp.y"
    { _p->onUse((yyvsp[(2) - (4)]).text(),(yyvsp[(4) - (4)]).text());;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 1027 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 1029 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (3)]) + (yyvsp[(2) - (3)]) + (yyvsp[(3) - (3)]);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 1032 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);
                                         (yyval).setText(_p->resolve((yyval).text(),0));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 1034 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 1036 "../../../src/util/parser/hphp.y"
    { (yyval).setText(_p->nsDecl((yyvsp[(3) - (3)]).text()));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 1039 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);
                                         (yyval).setText(_p->resolve((yyval).text(),1));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 1041 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 1043 "../../../src/util/parser/hphp.y"
    { (yyval).setText(_p->nsDecl((yyvsp[(3) - (3)]).text()));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 1047 "../../../src/util/parser/hphp.y"
    { (yyvsp[(3) - (5)]).setText(_p->nsDecl((yyvsp[(3) - (5)]).text()));
                                         on_constant(_p,(yyval),&(yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 1049 "../../../src/util/parser/hphp.y"
    { (yyvsp[(2) - (4)]).setText(_p->nsDecl((yyvsp[(2) - (4)]).text()));
                                         on_constant(_p,(yyval),  0,(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 1055 "../../../src/util/parser/hphp.y"
    { _p->addStatement((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 1056 "../../../src/util/parser/hphp.y"
    { _p->onStatementListStart((yyval));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 1059 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 1060 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 1061 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 1062 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 1065 "../../../src/util/parser/hphp.y"
    { _p->onBlock((yyval), (yyvsp[(2) - (3)]));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 1069 "../../../src/util/parser/hphp.y"
    { _p->onIf((yyval),(yyvsp[(3) - (7)]),(yyvsp[(5) - (7)]),(yyvsp[(6) - (7)]),(yyvsp[(7) - (7)]));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 1074 "../../../src/util/parser/hphp.y"
    { _p->onIf((yyval),(yyvsp[(3) - (10)]),(yyvsp[(6) - (10)]),(yyvsp[(7) - (10)]),(yyvsp[(8) - (10)]));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 1075 "../../../src/util/parser/hphp.y"
    { _p->pushLabelScope();;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 1076 "../../../src/util/parser/hphp.y"
    { _p->popLabelScope();
                                         _p->onWhile((yyval),(yyvsp[(3) - (6)]),(yyvsp[(6) - (6)]));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 1079 "../../../src/util/parser/hphp.y"
    { _p->pushLabelScope();;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 1080 "../../../src/util/parser/hphp.y"
    { _p->popLabelScope();
                                         _p->onDo((yyval),(yyvsp[(3) - (8)]),(yyvsp[(6) - (8)]));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 1083 "../../../src/util/parser/hphp.y"
    { _p->pushLabelScope();;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 1084 "../../../src/util/parser/hphp.y"
    { _p->popLabelScope();
                                         _p->onFor((yyval),(yyvsp[(3) - (10)]),(yyvsp[(5) - (10)]),(yyvsp[(7) - (10)]),(yyvsp[(10) - (10)]));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 1086 "../../../src/util/parser/hphp.y"
    { _p->pushLabelScope();;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 1087 "../../../src/util/parser/hphp.y"
    { _p->popLabelScope();
                                         _p->onSwitch((yyval),(yyvsp[(3) - (6)]),(yyvsp[(6) - (6)]));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 1089 "../../../src/util/parser/hphp.y"
    { _p->onBreak((yyval), NULL);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 1090 "../../../src/util/parser/hphp.y"
    { _p->onBreak((yyval), &(yyvsp[(2) - (3)]));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 1091 "../../../src/util/parser/hphp.y"
    { _p->onContinue((yyval), NULL);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 1092 "../../../src/util/parser/hphp.y"
    { _p->onContinue((yyval), &(yyvsp[(2) - (3)]));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1093 "../../../src/util/parser/hphp.y"
    { _p->onReturn((yyval), NULL);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 1094 "../../../src/util/parser/hphp.y"
    { _p->onReturn((yyval), &(yyvsp[(2) - (3)]));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 1095 "../../../src/util/parser/hphp.y"
    { _p->onYield((yyval), NULL, false);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 1096 "../../../src/util/parser/hphp.y"
    { _p->onYield((yyval), &(yyvsp[(2) - (3)]), false);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 1097 "../../../src/util/parser/hphp.y"
    { on_yield_assign(_p, (yyval), (yyvsp[(1) - (5)]), &(yyvsp[(4) - (5)]));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 1099 "../../../src/util/parser/hphp.y"
    { on_yield_list_assign(_p, (yyval), (yyvsp[(3) - (8)]), &(yyvsp[(7) - (8)]));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 1100 "../../../src/util/parser/hphp.y"
    { _p->onGlobal((yyval), (yyvsp[(2) - (3)]));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1101 "../../../src/util/parser/hphp.y"
    { _p->onStatic((yyval), (yyvsp[(2) - (3)]));;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1102 "../../../src/util/parser/hphp.y"
    { _p->onEcho((yyval), (yyvsp[(2) - (3)]), 0);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1103 "../../../src/util/parser/hphp.y"
    { _p->onUnset((yyval), (yyvsp[(3) - (5)]));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1104 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1105 "../../../src/util/parser/hphp.y"
    { _p->onEcho((yyval), (yyvsp[(1) - (1)]), 1);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1108 "../../../src/util/parser/hphp.y"
    { _p->pushLabelScope();;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1109 "../../../src/util/parser/hphp.y"
    { _p->popLabelScope();
                                         _p->onForEach((yyval),(yyvsp[(3) - (9)]),(yyvsp[(5) - (9)]),(yyvsp[(6) - (9)]),(yyvsp[(9) - (9)]));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1113 "../../../src/util/parser/hphp.y"
    { _p->onBlock((yyval), (yyvsp[(5) - (5)])); (yyval) = T_DECLARE;;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1121 "../../../src/util/parser/hphp.y"
    { _p->onTry((yyval),(yyvsp[(3) - (14)]),(yyvsp[(7) - (14)]),(yyvsp[(8) - (14)]),(yyvsp[(11) - (14)]),(yyvsp[(13) - (14)]),(yyvsp[(14) - (14)]));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1124 "../../../src/util/parser/hphp.y"
    { _p->onTry((yyval), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1125 "../../../src/util/parser/hphp.y"
    { _p->onThrow((yyval), (yyvsp[(2) - (3)]));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1126 "../../../src/util/parser/hphp.y"
    { _p->onGoto((yyval), (yyvsp[(2) - (3)]), true);
                                         _p->addGoto((yyvsp[(2) - (3)]).text(),
                                                     _p->getLocation(),
                                                     &(yyval)); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1130 "../../../src/util/parser/hphp.y"
    { _p->onExpStatement((yyval), (yyvsp[(1) - (2)]));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1131 "../../../src/util/parser/hphp.y"
    { _p->onLabel((yyval), (yyvsp[(1) - (2)]));
                                         _p->addLabel((yyvsp[(1) - (2)]).text(),
                                                      _p->getLocation(),
                                                      &(yyval)); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1143 "../../../src/util/parser/hphp.y"
    { _p->onCatch((yyval), (yyvsp[(1) - (9)]), (yyvsp[(4) - (9)]), (yyvsp[(5) - (9)]), (yyvsp[(8) - (9)]));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1144 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1148 "../../../src/util/parser/hphp.y"
    { finally_statement(_p);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1150 "../../../src/util/parser/hphp.y"
    { _p->onFinally((yyval), (yyvsp[(4) - (5)]));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1155 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1159 "../../../src/util/parser/hphp.y"
    { (yyval) = 1;;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1160 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1164 "../../../src/util/parser/hphp.y"
    { _p->pushFuncLocation();;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1169 "../../../src/util/parser/hphp.y"
    { (yyvsp[(3) - (3)]).setText(_p->nsDecl((yyvsp[(3) - (3)]).text()));
                                         _p->onFunctionStart((yyvsp[(3) - (3)]));
                                         _p->pushLabelInfo();;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1174 "../../../src/util/parser/hphp.y"
    { Token t; t.reset();
                                         _p->onFunction((yyval),t,(yyvsp[(2) - (11)]),(yyvsp[(3) - (11)]),(yyvsp[(6) - (11)]),(yyvsp[(10) - (11)]),0);
                                         _p->popLabelInfo();
                                         _p->popTypeScope();;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1179 "../../../src/util/parser/hphp.y"
    { (yyvsp[(4) - (4)]).setText(_p->nsDecl((yyvsp[(4) - (4)]).text()));
                                         _p->onFunctionStart((yyvsp[(4) - (4)]));
                                         _p->pushLabelInfo();;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1184 "../../../src/util/parser/hphp.y"
    { Token t; t.reset();
                                         _p->onFunction((yyval),t,(yyvsp[(3) - (12)]),(yyvsp[(4) - (12)]),(yyvsp[(7) - (12)]),(yyvsp[(11) - (12)]),&(yyvsp[(1) - (12)]));
                                         _p->popLabelInfo();
                                         _p->popTypeScope();;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1192 "../../../src/util/parser/hphp.y"
    { (yyvsp[(2) - (2)]).setText(_p->nsDecl((yyvsp[(2) - (2)]).text()));
                                         _p->onClassStart((yyvsp[(1) - (2)]).num(),(yyvsp[(2) - (2)]));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1194 "../../../src/util/parser/hphp.y"
    { if (_p->peekClass())
                                           _p->scanner().xhpStatement();;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1196 "../../../src/util/parser/hphp.y"
    { Token stmts;
                                         if (_p->peekClass()) {
                                           xhp_collect_attributes(_p,stmts,(yyvsp[(8) - (9)]));
                                         } else {
                                           stmts = (yyvsp[(8) - (9)]);
                                         }
                                         _p->onClass((yyval),(yyvsp[(1) - (9)]).num(),(yyvsp[(2) - (9)]),(yyvsp[(4) - (9)]),(yyvsp[(5) - (9)]),
                                                     stmts,0);
                                         if (_p->peekClass()) {
                                           _p->xhpResetAttributes();
                                           _p->scanner().xhpReset();
                                         }
                                         _p->popClass();
                                         _p->popTypeScope();;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1212 "../../../src/util/parser/hphp.y"
    { (yyvsp[(3) - (3)]).setText(_p->nsDecl((yyvsp[(3) - (3)]).text()));
                                         _p->onClassStart((yyvsp[(2) - (3)]).num(),(yyvsp[(3) - (3)]));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1214 "../../../src/util/parser/hphp.y"
    { if (_p->peekClass())
                                           _p->scanner().xhpStatement();;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1216 "../../../src/util/parser/hphp.y"
    { Token stmts;
                                         if (_p->peekClass()) {
                                           xhp_collect_attributes(_p,stmts,(yyvsp[(9) - (10)]));
                                         } else {
                                           stmts = (yyvsp[(9) - (10)]);
                                         }
                                         _p->onClass((yyval),(yyvsp[(2) - (10)]).num(),(yyvsp[(3) - (10)]),(yyvsp[(5) - (10)]),(yyvsp[(6) - (10)]),
                                                     stmts,&(yyvsp[(1) - (10)]));
                                         if (_p->peekClass()) {
                                           _p->xhpResetAttributes();
                                           _p->scanner().xhpReset();
                                         }
                                         _p->popClass();
                                         _p->popTypeScope();;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1231 "../../../src/util/parser/hphp.y"
    { (yyvsp[(2) - (2)]).setText(_p->nsDecl((yyvsp[(2) - (2)]).text()));
                                         _p->onClassStart(T_INTERFACE,(yyvsp[(2) - (2)]));;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1234 "../../../src/util/parser/hphp.y"
    { _p->onInterface((yyval),(yyvsp[(2) - (7)]),(yyvsp[(4) - (7)]),(yyvsp[(6) - (7)]),0);
                                         _p->popClass();
                                         _p->popTypeScope();;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1239 "../../../src/util/parser/hphp.y"
    { (yyvsp[(3) - (3)]).setText(_p->nsDecl((yyvsp[(3) - (3)]).text()));
                                         _p->onClassStart(T_INTERFACE,(yyvsp[(3) - (3)]));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1242 "../../../src/util/parser/hphp.y"
    { _p->onInterface((yyval),(yyvsp[(3) - (8)]),(yyvsp[(5) - (8)]),(yyvsp[(7) - (8)]),&(yyvsp[(1) - (8)]));
                                         _p->popClass();
                                         _p->popTypeScope();;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1249 "../../../src/util/parser/hphp.y"
    { (yyvsp[(2) - (2)]).setText(_p->nsDecl((yyvsp[(2) - (2)]).text()));
                                         _p->onClassStart(T_TRAIT, (yyvsp[(2) - (2)]));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1251 "../../../src/util/parser/hphp.y"
    { Token t_ext, t_imp;
                                         t_ext.reset(); t_imp.reset();
                                         _p->onClass((yyval),T_TRAIT,(yyvsp[(2) - (6)]),t_ext,t_imp,
                                                     (yyvsp[(5) - (6)]), 0);
                                         _p->popClass();
                                         _p->popTypeScope();;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1259 "../../../src/util/parser/hphp.y"
    { (yyvsp[(3) - (3)]).setText(_p->nsDecl((yyvsp[(3) - (3)]).text()));
                                         _p->onClassStart(T_TRAIT, (yyvsp[(3) - (3)]));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1261 "../../../src/util/parser/hphp.y"
    { Token t_ext, t_imp;
                                         t_ext.reset(); t_imp.reset();
                                         _p->onClass((yyval),T_TRAIT,(yyvsp[(3) - (7)]),t_ext,t_imp,
                                                     (yyvsp[(6) - (7)]), &(yyvsp[(1) - (7)]));
                                         _p->popClass();
                                         _p->popTypeScope();;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1269 "../../../src/util/parser/hphp.y"
    { _p->pushClass(false); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1270 "../../../src/util/parser/hphp.y"
    { (yyvsp[(1) - (1)]).xhpLabel(); _p->pushTypeScope();
                                         _p->pushClass(true); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1274 "../../../src/util/parser/hphp.y"
    { _p->pushClass(false); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1277 "../../../src/util/parser/hphp.y"
    { _p->pushClass(false); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1280 "../../../src/util/parser/hphp.y"
    { (yyval) = T_CLASS;;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1281 "../../../src/util/parser/hphp.y"
    { (yyval) = T_ABSTRACT;;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1282 "../../../src/util/parser/hphp.y"
    { (yyval) = T_FINAL;;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1286 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1287 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1290 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1291 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1294 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1295 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1298 "../../../src/util/parser/hphp.y"
    { _p->onInterfaceName((yyval), NULL, (yyvsp[(1) - (1)]));;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1300 "../../../src/util/parser/hphp.y"
    { _p->onInterfaceName((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1303 "../../../src/util/parser/hphp.y"
    { _p->onTraitName((yyval), NULL, (yyvsp[(1) - (1)]));;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1305 "../../../src/util/parser/hphp.y"
    { _p->onTraitName((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1309 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1310 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1313 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1314 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]); (yyval) = 1;;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1318 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1320 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1323 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1325 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1328 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1330 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1333 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1335 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1345 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1346 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(3) - (4)]);;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1347 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1348 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(3) - (5)]);;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1353 "../../../src/util/parser/hphp.y"
    { _p->onCase((yyval),(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1355 "../../../src/util/parser/hphp.y"
    { _p->onCase((yyval),(yyvsp[(1) - (4)]),NULL,(yyvsp[(4) - (4)]));;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1356 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1359 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1360 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1365 "../../../src/util/parser/hphp.y"
    { _p->onElseIf((yyval),(yyvsp[(1) - (6)]),(yyvsp[(4) - (6)]),(yyvsp[(6) - (6)]));;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1366 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1371 "../../../src/util/parser/hphp.y"
    { _p->onElseIf((yyval),(yyvsp[(1) - (7)]),(yyvsp[(4) - (7)]),(yyvsp[(7) - (7)]));;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1372 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1375 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1376 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1379 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(3) - (3)]);;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1380 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1385 "../../../src/util/parser/hphp.y"
    { only_in_strict_mode(_p); (yyval) = (yyvsp[(1) - (3)]); ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1386 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1387 "../../../src/util/parser/hphp.y"
    { only_in_strict_mode(_p); (yyval).reset(); ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1388 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1392 "../../../src/util/parser/hphp.y"
    { _p->onParam((yyval),NULL,(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]),0,NULL);;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1393 "../../../src/util/parser/hphp.y"
    { _p->onParam((yyval),NULL,(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),1,NULL);;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1395 "../../../src/util/parser/hphp.y"
    { _p->onParam((yyval),NULL,(yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),1,&(yyvsp[(5) - (5)]));;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1397 "../../../src/util/parser/hphp.y"
    { _p->onParam((yyval),NULL,(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),0,&(yyvsp[(4) - (4)]));;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1399 "../../../src/util/parser/hphp.y"
    { _p->onParam((yyval),&(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]),0,NULL);;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1401 "../../../src/util/parser/hphp.y"
    { _p->onParam((yyval),&(yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]),1,NULL);;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1404 "../../../src/util/parser/hphp.y"
    { _p->onParam((yyval),&(yyvsp[(1) - (7)]),(yyvsp[(3) - (7)]),(yyvsp[(5) - (7)]),1,&(yyvsp[(7) - (7)]));;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1407 "../../../src/util/parser/hphp.y"
    { _p->onParam((yyval),&(yyvsp[(1) - (6)]),(yyvsp[(3) - (6)]),(yyvsp[(4) - (6)]),0,&(yyvsp[(6) - (6)]));;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1411 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1412 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1415 "../../../src/util/parser/hphp.y"
    { _p->onCallParam((yyval),NULL,(yyvsp[(1) - (1)]),0);;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1416 "../../../src/util/parser/hphp.y"
    { _p->onCallParam((yyval),NULL,(yyvsp[(2) - (2)]),1);;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1418 "../../../src/util/parser/hphp.y"
    { _p->onCallParam((yyval),&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),0);;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1420 "../../../src/util/parser/hphp.y"
    { _p->onCallParam((yyval),&(yyvsp[(1) - (4)]),(yyvsp[(4) - (4)]),1);;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1424 "../../../src/util/parser/hphp.y"
    { _p->onGlobalVar((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1425 "../../../src/util/parser/hphp.y"
    { _p->onGlobalVar((yyval), NULL, (yyvsp[(1) - (1)]));;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1428 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1429 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]); (yyval) = 1;;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1430 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(3) - (4)]); (yyval) = 1;;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1434 "../../../src/util/parser/hphp.y"
    { _p->onStaticVariable((yyval),&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),0);;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1436 "../../../src/util/parser/hphp.y"
    { _p->onStaticVariable((yyval),&(yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),&(yyvsp[(5) - (5)]));;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1437 "../../../src/util/parser/hphp.y"
    { _p->onStaticVariable((yyval),0,(yyvsp[(1) - (1)]),0);;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1438 "../../../src/util/parser/hphp.y"
    { _p->onStaticVariable((yyval),0,(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]));;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1443 "../../../src/util/parser/hphp.y"
    { _p->onClassStatement((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
                                         if (_p->peekClass())
                                           _p->scanner().xhpStatement();;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1446 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1449 "../../../src/util/parser/hphp.y"
    { _p->onClassVariableModifer((yyvsp[(1) - (1)]));;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1450 "../../../src/util/parser/hphp.y"
    { _p->onClassVariableStart
                                         ((yyval),&(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),NULL);;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1453 "../../../src/util/parser/hphp.y"
    { _p->onClassVariableModifer((yyvsp[(1) - (2)]));;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1454 "../../../src/util/parser/hphp.y"
    { _p->onClassVariableStart
                                         ((yyval),&(yyvsp[(1) - (5)]),(yyvsp[(4) - (5)]),&(yyvsp[(2) - (5)]));;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1456 "../../../src/util/parser/hphp.y"
    { _p->onClassVariableStart
                                         ((yyval),NULL,(yyvsp[(1) - (2)]),NULL);;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1460 "../../../src/util/parser/hphp.y"
    { _p->onMethodStart((yyvsp[(4) - (5)]), (yyvsp[(1) - (5)]));
                                         _p->pushLabelInfo();;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1465 "../../../src/util/parser/hphp.y"
    { Token t; t.reset();
                                         _p->onMethod((yyval),(yyvsp[(1) - (10)]),t,(yyvsp[(3) - (10)]),(yyvsp[(4) - (10)]),(yyvsp[(7) - (10)]),(yyvsp[(10) - (10)]),0);
                                         _p->popLabelInfo();
                                         _p->popTypeScope();;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1472 "../../../src/util/parser/hphp.y"
    { _p->onMethodStart((yyvsp[(5) - (6)]), (yyvsp[(2) - (6)]));
                                         _p->pushLabelInfo();;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1477 "../../../src/util/parser/hphp.y"
    { Token t; t.reset();
                                         _p->onMethod((yyval),(yyvsp[(2) - (11)]),t,(yyvsp[(4) - (11)]),(yyvsp[(5) - (11)]),(yyvsp[(8) - (11)]),(yyvsp[(11) - (11)]),&(yyvsp[(1) - (11)]));
                                         _p->popLabelInfo();
                                         _p->popTypeScope();;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1481 "../../../src/util/parser/hphp.y"
    { _p->scanner().xhpAttributeDecl();;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1482 "../../../src/util/parser/hphp.y"
    { _p->xhpSetAttributes((yyvsp[(3) - (4)]));;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1484 "../../../src/util/parser/hphp.y"
    { xhp_category_stmt(_p,(yyval),(yyvsp[(2) - (3)]));;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1486 "../../../src/util/parser/hphp.y"
    { xhp_children_stmt(_p,(yyval),(yyvsp[(2) - (3)]));;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1487 "../../../src/util/parser/hphp.y"
    { Token t; t.reset();
                                         _p->onTraitUse((yyval),(yyvsp[(2) - (3)]),t); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1490 "../../../src/util/parser/hphp.y"
    { _p->onTraitUse((yyval),(yyvsp[(2) - (5)]),(yyvsp[(4) - (5)])); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1493 "../../../src/util/parser/hphp.y"
    { _p->onTraitRule((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1494 "../../../src/util/parser/hphp.y"
    { _p->onTraitRule((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1495 "../../../src/util/parser/hphp.y"
    { (yyval).reset(); ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1501 "../../../src/util/parser/hphp.y"
    { _p->onTraitPrecRule((yyval),(yyvsp[(1) - (6)]),(yyvsp[(3) - (6)]),(yyvsp[(5) - (6)])); ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1505 "../../../src/util/parser/hphp.y"
    { _p->onTraitAliasRuleModify((yyval),(yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),
                                                                    (yyvsp[(4) - (5)]));;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1508 "../../../src/util/parser/hphp.y"
    { Token t; t.reset();
                                         _p->onTraitAliasRuleModify((yyval),(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),
                                                                    t);;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1515 "../../../src/util/parser/hphp.y"
    { _p->onTraitAliasRuleStart((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1516 "../../../src/util/parser/hphp.y"
    { Token t; t.reset();
                                         _p->onTraitAliasRuleStart((yyval),t,(yyvsp[(1) - (1)]));;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1520 "../../../src/util/parser/hphp.y"
    { xhp_attribute_list(_p,(yyval),
                                         _p->xhpGetAttributes(),(yyvsp[(1) - (1)]));;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1522 "../../../src/util/parser/hphp.y"
    { _p->scanner().xhpAttributeDecl();;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1523 "../../../src/util/parser/hphp.y"
    { xhp_attribute_list(_p,(yyval), &(yyvsp[(1) - (4)]),(yyvsp[(4) - (4)]));;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1530 "../../../src/util/parser/hphp.y"
    { xhp_attribute(_p,(yyval),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));
                                         (yyval) = 1;;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1532 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = 0;;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1536 "../../../src/util/parser/hphp.y"
    { (yyval) = 1;;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1537 "../../../src/util/parser/hphp.y"
    { (yyval) = 2;;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1538 "../../../src/util/parser/hphp.y"
    { (yyval) = 3;;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1539 "../../../src/util/parser/hphp.y"
    { (yyval) = 4;;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1540 "../../../src/util/parser/hphp.y"
    { (yyval) = 5; (yyval).setText((yyvsp[(1) - (1)]));;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1541 "../../../src/util/parser/hphp.y"
    { (yyval) = 6;;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1543 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(3) - (4)]); (yyval) = 7;;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1544 "../../../src/util/parser/hphp.y"
    { (yyval) = 8;;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1548 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),  0,0,(yyvsp[(1) - (1)]),0);;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1550 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (3)]),0,(yyvsp[(3) - (3)]),0);;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1554 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1555 "../../../src/util/parser/hphp.y"
    { scalar_null(_p, (yyval));;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1559 "../../../src/util/parser/hphp.y"
    { _p->scanner().xhpAttributeDecl();;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1560 "../../../src/util/parser/hphp.y"
    { scalar_num(_p, (yyval), "1");;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1561 "../../../src/util/parser/hphp.y"
    { scalar_num(_p, (yyval), "0");;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1565 "../../../src/util/parser/hphp.y"
    { Token t; scalar_num(_p, t, "1");
                                         _p->onArrayPair((yyval),0,&(yyvsp[(1) - (1)]),t,0);;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1568 "../../../src/util/parser/hphp.y"
    { Token t; scalar_num(_p, t, "1");
                                         _p->onArrayPair((yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),t,0);;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1573 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING, (yyvsp[(1) - (1)]));;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1578 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = 2;;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1579 "../../../src/util/parser/hphp.y"
    { (yyval) = -1;
                                         if ((yyvsp[(1) - (1)]).same("any")) (yyval) = 1;;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1581 "../../../src/util/parser/hphp.y"
    { (yyval) = 0;;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1585 "../../../src/util/parser/hphp.y"
    { xhp_children_paren(_p, (yyval), (yyvsp[(2) - (3)]), 0);;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1586 "../../../src/util/parser/hphp.y"
    { xhp_children_paren(_p, (yyval), (yyvsp[(2) - (4)]), 1);;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1587 "../../../src/util/parser/hphp.y"
    { xhp_children_paren(_p, (yyval), (yyvsp[(2) - (4)]), 2);;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1588 "../../../src/util/parser/hphp.y"
    { xhp_children_paren(_p, (yyval), (yyvsp[(2) - (4)]), 3);;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1592 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1593 "../../../src/util/parser/hphp.y"
    { xhp_children_decl(_p,(yyval),(yyvsp[(1) - (1)]),0,  0);;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1594 "../../../src/util/parser/hphp.y"
    { xhp_children_decl(_p,(yyval),(yyvsp[(1) - (2)]),1,  0);;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1595 "../../../src/util/parser/hphp.y"
    { xhp_children_decl(_p,(yyval),(yyvsp[(1) - (2)]),2,  0);;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1596 "../../../src/util/parser/hphp.y"
    { xhp_children_decl(_p,(yyval),(yyvsp[(1) - (2)]),3,  0);;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1598 "../../../src/util/parser/hphp.y"
    { xhp_children_decl(_p,(yyval),(yyvsp[(1) - (3)]),4,&(yyvsp[(3) - (3)]));;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1600 "../../../src/util/parser/hphp.y"
    { xhp_children_decl(_p,(yyval),(yyvsp[(1) - (3)]),5,&(yyvsp[(3) - (3)]));;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1604 "../../../src/util/parser/hphp.y"
    { (yyval) = -1;
                                         if ((yyvsp[(1) - (1)]).same("any")) (yyval) = 1; else
                                         if ((yyvsp[(1) - (1)]).same("pcdata")) (yyval) = 2;;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1607 "../../../src/util/parser/hphp.y"
    { (yyvsp[(1) - (1)]).xhpLabel();  (yyval) = (yyvsp[(1) - (1)]); (yyval) = 3;;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1608 "../../../src/util/parser/hphp.y"
    { (yyvsp[(1) - (1)]).xhpLabel(0); (yyval) = (yyvsp[(1) - (1)]); (yyval) = 4;;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1612 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1613 "../../../src/util/parser/hphp.y"
    { _p->finishStatement((yyval), (yyvsp[(2) - (3)])); (yyval) = 1;;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1616 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1617 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1620 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1621 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1624 "../../../src/util/parser/hphp.y"
    { _p->onMemberModifier((yyval),NULL,(yyvsp[(1) - (1)]));;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1626 "../../../src/util/parser/hphp.y"
    { _p->onMemberModifier((yyval),&(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1629 "../../../src/util/parser/hphp.y"
    { (yyval) = T_PUBLIC;;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1630 "../../../src/util/parser/hphp.y"
    { (yyval) = T_PROTECTED;;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1631 "../../../src/util/parser/hphp.y"
    { (yyval) = T_PRIVATE;;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1632 "../../../src/util/parser/hphp.y"
    { (yyval) = T_STATIC;;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1633 "../../../src/util/parser/hphp.y"
    { (yyval) = T_ABSTRACT;;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1634 "../../../src/util/parser/hphp.y"
    { (yyval) = T_FINAL;;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1638 "../../../src/util/parser/hphp.y"
    { _p->onClassVariable((yyval),&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),0);;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1640 "../../../src/util/parser/hphp.y"
    { _p->onClassVariable((yyval),&(yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),&(yyvsp[(5) - (5)]));;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1641 "../../../src/util/parser/hphp.y"
    { _p->onClassVariable((yyval),0,(yyvsp[(1) - (1)]),0);;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1642 "../../../src/util/parser/hphp.y"
    { _p->onClassVariable((yyval),0,(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]));;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1646 "../../../src/util/parser/hphp.y"
    { _p->onClassConstant((yyval),&(yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1647 "../../../src/util/parser/hphp.y"
    { _p->onClassConstant((yyval),0,(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1651 "../../../src/util/parser/hphp.y"
    { _p->onExprListElem((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1652 "../../../src/util/parser/hphp.y"
    { _p->onExprListElem((yyval), NULL, (yyvsp[(1) - (1)]));;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1656 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1657 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1661 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1663 "../../../src/util/parser/hphp.y"
    { _p->onListAssignment((yyval), (yyvsp[(3) - (6)]), &(yyvsp[(6) - (6)]));;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1664 "../../../src/util/parser/hphp.y"
    { _p->onAssign((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 0);;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1665 "../../../src/util/parser/hphp.y"
    { _p->onAssign((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]), 1);;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1668 "../../../src/util/parser/hphp.y"
    { _p->onAssignNew((yyval),(yyvsp[(1) - (6)]),(yyvsp[(5) - (6)]),(yyvsp[(6) - (6)]));;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1670 "../../../src/util/parser/hphp.y"
    { _p->onNewObject((yyval), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1671 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_CLONE,1);;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1672 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_PLUS_EQUAL);;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1673 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_MINUS_EQUAL);;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1674 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_MUL_EQUAL);;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1675 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_DIV_EQUAL);;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1676 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_CONCAT_EQUAL);;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1677 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_MOD_EQUAL);;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1678 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_AND_EQUAL);;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1679 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_OR_EQUAL);;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1680 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_XOR_EQUAL);;}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1681 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_SL_EQUAL);;}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1682 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_SR_EQUAL);;}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1683 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(1) - (2)]),T_INC,0);;}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1684 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_INC,1);;}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1685 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(1) - (2)]),T_DEC,0);;}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1686 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_DEC,1);;}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1687 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_BOOLEAN_OR);;}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1688 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_BOOLEAN_AND);;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1689 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_LOGICAL_OR);;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1690 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_LOGICAL_AND);;}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1691 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_LOGICAL_XOR);;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1692 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'|');;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1693 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'&');;}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1694 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'^');;}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1695 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'.');;}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1696 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'+');;}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1697 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'-');;}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1698 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'*');;}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1699 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'/');;}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1700 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'%');;}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1701 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_SL);;}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1702 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_SR);;}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1703 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'+',1);;}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1704 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'-',1);;}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1705 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'!',1);;}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1706 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'~',1);;}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1707 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_IS_IDENTICAL);;}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1708 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_IS_NOT_IDENTICAL);;}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1709 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_IS_EQUAL);;}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1710 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_IS_NOT_EQUAL);;}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1711 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'<');;}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1712 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),
                                              T_IS_SMALLER_OR_EQUAL);;}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1714 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'>');;}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1715 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),
                                              T_IS_GREATER_OR_EQUAL);;}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1718 "../../../src/util/parser/hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_INSTANCEOF);;}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1719 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1720 "../../../src/util/parser/hphp.y"
    { _p->onQOp((yyval), (yyvsp[(1) - (5)]), &(yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));;}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 1721 "../../../src/util/parser/hphp.y"
    { _p->onQOp((yyval), (yyvsp[(1) - (4)]),   0, (yyvsp[(4) - (4)]));;}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1722 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1723 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_INT_CAST,1);;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1724 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_DOUBLE_CAST,1);;}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1725 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_STRING_CAST,1);;}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1726 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_ARRAY_CAST,1);;}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1727 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_OBJECT_CAST,1);;}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1728 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_BOOL_CAST,1);;}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1729 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_UNSET_CAST,1);;}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1730 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_EXIT,1);;}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1731 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'@',1);;}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1732 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1733 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1734 "../../../src/util/parser/hphp.y"
    { _p->onEncapsList((yyval),'`',(yyvsp[(2) - (3)]));;}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1735 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_PRINT,1);;}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1736 "../../../src/util/parser/hphp.y"
    { Token t; _p->onFunctionStart(t);
                                         _p->pushLabelInfo();;}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1740 "../../../src/util/parser/hphp.y"
    { Token u; u.reset();
                                         _p->onClosure((yyval),u,(yyvsp[(2) - (11)]),(yyvsp[(5) - (11)]),(yyvsp[(8) - (11)]),(yyvsp[(10) - (11)]));
                                         _p->popLabelInfo();;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1743 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 1744 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 1748 "../../../src/util/parser/hphp.y"
    { _p->onArray((yyval),(yyvsp[(3) - (4)]),T_ARRAY);;}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 1753 "../../../src/util/parser/hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1755 "../../../src/util/parser/hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1759 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1760 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1761 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1765 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(3) - (4)]);;}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1766 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 1770 "../../../src/util/parser/hphp.y"
    { _p->onClosureParam((yyval),&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),0);;}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1771 "../../../src/util/parser/hphp.y"
    { _p->onClosureParam((yyval),&(yyvsp[(1) - (4)]),(yyvsp[(4) - (4)]),1);;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1772 "../../../src/util/parser/hphp.y"
    { _p->onClosureParam((yyval),  0,(yyvsp[(1) - (1)]),0);;}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1773 "../../../src/util/parser/hphp.y"
    { _p->onClosureParam((yyval),  0,(yyvsp[(2) - (2)]),1);;}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1777 "../../../src/util/parser/hphp.y"
    { no_gap(_p); xhp_tag(_p,(yyval),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]));;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1780 "../../../src/util/parser/hphp.y"
    { _p->scanner().xhpCloseTag();
                                         Token t1; _p->onArray(t1,(yyvsp[(1) - (2)]));
                                         Token t2; _p->onArray(t2,(yyvsp[(2) - (2)]));
                                         _p->onCallParam((yyvsp[(1) - (2)]),NULL,t1,0);
                                         _p->onCallParam((yyval), &(yyvsp[(1) - (2)]),t2,0);
                                         (yyval).setText("");;}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1786 "../../../src/util/parser/hphp.y"
    { _p->scanner().xhpChild();;}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1787 "../../../src/util/parser/hphp.y"
    { _p->scanner().xhpCloseTag();;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 1788 "../../../src/util/parser/hphp.y"
    { _p->onArray((yyvsp[(5) - (8)]),(yyvsp[(1) - (8)]));
                                         _p->onArray((yyvsp[(6) - (8)]),(yyvsp[(4) - (8)]));
                                         _p->onCallParam((yyvsp[(2) - (8)]),NULL,(yyvsp[(5) - (8)]),0);
                                         _p->onCallParam((yyval), &(yyvsp[(2) - (8)]),(yyvsp[(6) - (8)]),0);
                                         (yyval).setText((yyvsp[(8) - (8)]).text());;}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 1795 "../../../src/util/parser/hphp.y"
    { (yyval).reset(); (yyval).setText("");;}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 1796 "../../../src/util/parser/hphp.y"
    { (yyval).reset(); (yyval).setText((yyvsp[(1) - (1)]));;}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1800 "../../../src/util/parser/hphp.y"
    { _p->scanner().xhpAttribute();;}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1801 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(2) - (5)]),(yyvsp[(5) - (5)]),0);;}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1802 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 1805 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (2)]),0,(yyvsp[(2) - (2)]),0);;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1806 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1809 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING, (yyvsp[(1) - (1)]));;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1813 "../../../src/util/parser/hphp.y"
    { (yyvsp[(1) - (1)]).xhpDecode();
                                         _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING, (yyvsp[(1) - (1)]));;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1816 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1819 "../../../src/util/parser/hphp.y"
    { (yyval).reset();
                                         if ((yyvsp[(1) - (1)]).htmlTrim()) {
                                           (yyvsp[(1) - (1)]).xhpDecode();
                                           _p->onScalar((yyval),
                                           T_CONSTANT_ENCAPSED_STRING, (yyvsp[(1) - (1)]));
                                         }
                                       ;}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1826 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]); _p->scanner().xhpChild();;}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1827 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); _p->scanner().xhpChild();;}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 1830 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); no_gap(_p);;}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 1831 "../../../src/util/parser/hphp.y"
    { no_gap(_p);;}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 1832 "../../../src/util/parser/hphp.y"
    { no_gap(_p); (yyval) = (yyvsp[(1) - (4)]) + ":" + (yyvsp[(4) - (4)]);;}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 1833 "../../../src/util/parser/hphp.y"
    { no_gap(_p);;}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 1834 "../../../src/util/parser/hphp.y"
    { no_gap(_p); (yyval) = (yyvsp[(1) - (4)]) + "-" + (yyvsp[(4) - (4)]);;}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 1837 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 1838 "../../../src/util/parser/hphp.y"
    { no_gap(_p);;}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 1839 "../../../src/util/parser/hphp.y"
    { no_gap(_p); (yyval) = (yyvsp[(1) - (4)]) + ":" + (yyvsp[(4) - (4)]);;}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 1840 "../../../src/util/parser/hphp.y"
    { no_gap(_p);;}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1841 "../../../src/util/parser/hphp.y"
    { no_gap(_p); (yyval) = (yyvsp[(1) - (4)]) + "-" + (yyvsp[(4) - (4)]);;}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 1844 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1845 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1846 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 1847 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 1848 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1849 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1850 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 1851 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1852 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 1853 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 1854 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1855 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1856 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1857 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1858 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 1859 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 1860 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 1861 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1862 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1863 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1864 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1865 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1866 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1867 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1868 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 1869 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 1870 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1871 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 1872 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 1873 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 1874 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 1875 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 1876 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 1877 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 1878 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 1879 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 1880 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 1881 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 1882 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 1883 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 1884 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 1885 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 1886 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 1887 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 1888 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 1889 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 1890 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 1891 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 1892 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 1893 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 1894 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 1895 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 1896 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 1897 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 1898 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 1899 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 1900 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 1901 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 1902 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 1903 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 1904 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 1905 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 1906 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 1907 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 1908 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 1909 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 1910 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 1911 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 1912 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 1913 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 1914 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 1915 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 1916 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 1921 "../../../src/util/parser/hphp.y"
    { _p->onCall((yyval),0,(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),NULL);;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 1926 "../../../src/util/parser/hphp.y"
    { _p->onName((yyval),(yyvsp[(1) - (1)]),Parser::StringName);;}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 1927 "../../../src/util/parser/hphp.y"
    { _p->onName((yyval),(yyvsp[(1) - (1)]),Parser::StaticName);;}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 1928 "../../../src/util/parser/hphp.y"
    { _p->onName((yyval),(yyvsp[(1) - (1)]),
                                         Parser::StaticClassExprName);;}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 1932 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 1933 "../../../src/util/parser/hphp.y"
    { (yyvsp[(1) - (1)]).xhpLabel(); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 1936 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 1937 "../../../src/util/parser/hphp.y"
    { (yyvsp[(1) - (1)]).xhpLabel(); (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 1940 "../../../src/util/parser/hphp.y"
    { _p->onName((yyval),(yyvsp[(1) - (1)]),Parser::ExprName);;}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 1941 "../../../src/util/parser/hphp.y"
    { _p->onName((yyval),(yyvsp[(1) - (1)]),Parser::StaticName);;}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 1942 "../../../src/util/parser/hphp.y"
    { (yyvsp[(1) - (1)]).xhpLabel();
                                         _p->onName((yyval),(yyvsp[(1) - (1)]),Parser::StringName);;}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 1944 "../../../src/util/parser/hphp.y"
    { (yyvsp[(1) - (1)]).setText(_p->resolve((yyvsp[(1) - (1)]).text(),1));
                                         _p->onName((yyval),(yyvsp[(1) - (1)]),Parser::StringName);;}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 1946 "../../../src/util/parser/hphp.y"
    { _p->onName((yyval),(yyvsp[(2) - (2)]),Parser::StringName);;}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 1948 "../../../src/util/parser/hphp.y"
    { (yyvsp[(3) - (3)]).setText(_p->nsDecl((yyvsp[(3) - (3)]).text()));
                                         _p->onName((yyval),(yyvsp[(3) - (3)]),Parser::StringName);;}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 1953 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 1954 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 1955 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 1959 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 1960 "../../../src/util/parser/hphp.y"
    { _p->addEncap((yyval), NULL, (yyvsp[(1) - (1)]), 0);;}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 1961 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 1965 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 1966 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 1970 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval), T_LNUMBER,  (yyvsp[(1) - (1)]));;}
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 1971 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval), T_DNUMBER,  (yyvsp[(1) - (1)]));;}
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 1972 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING,  (yyvsp[(1) - (1)]));;}
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 1974 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval), T_LINE,     (yyvsp[(1) - (1)]));;}
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 1975 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval), T_FILE,     (yyvsp[(1) - (1)]));;}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 1976 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval), T_DIR,      (yyvsp[(1) - (1)]));;}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 1977 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval), T_CLASS_C,  (yyvsp[(1) - (1)]));;}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 1978 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval), T_TRAIT_C,  (yyvsp[(1) - (1)]));;}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 1979 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval), T_METHOD_C, (yyvsp[(1) - (1)]));;}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 1980 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval), T_FUNC_C,   (yyvsp[(1) - (1)]));;}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 1981 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval), T_NS_C,  (yyvsp[(1) - (1)]));;}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 1984 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval), T_CONSTANT_ENCAPSED_STRING, (yyvsp[(2) - (3)]));;}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 1986 "../../../src/util/parser/hphp.y"
    { (yyval).setText(""); _p->onScalar((yyval), T_CONSTANT_ENCAPSED_STRING, (yyval));;}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 1990 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 1991 "../../../src/util/parser/hphp.y"
    { _p->onConstantValue((yyval), (yyvsp[(1) - (1)]));;}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 1992 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'+',1);;}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 1993 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'-',1);;}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 1995 "../../../src/util/parser/hphp.y"
    { _p->onArray((yyval),(yyvsp[(3) - (4)]),T_ARRAY);;}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 1996 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2001 "../../../src/util/parser/hphp.y"
    { _p->onClassConst((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 1);;}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2003 "../../../src/util/parser/hphp.y"
    { (yyvsp[(1) - (3)]).xhpLabel();
                                         _p->onClassConst((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 1);;}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2007 "../../../src/util/parser/hphp.y"
    { _p->onConstantValue((yyval), (yyvsp[(1) - (1)]));;}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2008 "../../../src/util/parser/hphp.y"
    { _p->onConstantValue((yyval), (yyvsp[(1) - (1)]));;}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2009 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2010 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2011 "../../../src/util/parser/hphp.y"
    { _p->onEncapsList((yyval),'"',(yyvsp[(2) - (3)]));;}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2012 "../../../src/util/parser/hphp.y"
    { _p->onEncapsList((yyval),'\'',(yyvsp[(2) - (3)]));;}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2014 "../../../src/util/parser/hphp.y"
    { _p->onEncapsList((yyval),T_START_HEREDOC,
                                                          (yyvsp[(2) - (3)]));;}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2019 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2020 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2023 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2024 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2029 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]),0);;}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 2031 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (3)]),  0,(yyvsp[(3) - (3)]),0);;}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 2033 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),  0,&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),0);;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 2034 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),  0,  0,(yyvsp[(1) - (1)]),0);;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 2038 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval), T_LNUMBER,  (yyvsp[(1) - (1)]));;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 2039 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval), T_DNUMBER,  (yyvsp[(1) - (1)]));;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 2040 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING,  (yyvsp[(1) - (1)]));;}
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 2044 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval), T_CONSTANT_ENCAPSED_STRING, (yyvsp[(2) - (3)]));;}
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 2046 "../../../src/util/parser/hphp.y"
    { (yyval).setText(""); _p->onScalar((yyval), T_CONSTANT_ENCAPSED_STRING, (yyval));;}
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 2049 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval),T_LNUMBER,(yyvsp[(1) - (1)]));;}
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 2050 "../../../src/util/parser/hphp.y"
    { _p->onScalar((yyval),T_DNUMBER,(yyvsp[(1) - (1)]));;}
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 2051 "../../../src/util/parser/hphp.y"
    { constant_ae(_p,(yyval),(yyvsp[(1) - (1)]));;}
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 2054 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 2055 "../../../src/util/parser/hphp.y"
    { constant_ae(_p,(yyval),(yyvsp[(1) - (1)]));;}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 2056 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'+',1);;}
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 2057 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'-',1);;}
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 2059 "../../../src/util/parser/hphp.y"
    { _p->onArray((yyval),(yyvsp[(3) - (4)]),T_ARRAY);;}
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 2060 "../../../src/util/parser/hphp.y"
    { _p->onArray((yyval),(yyvsp[(2) - (3)]),T_ARRAY);;}
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 2064 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 2065 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 2070 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]),0);;}
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 2072 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (3)]),  0,(yyvsp[(3) - (3)]),0);;}
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 2074 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),  0,&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),0);;}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 2075 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),  0,  0,(yyvsp[(1) - (1)]),0);;}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 2079 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (3)]),  0,(yyvsp[(3) - (3)]),0);;}
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 2080 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),  0,  0,(yyvsp[(1) - (1)]),0);;}
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 2084 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 2085 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 2088 "../../../src/util/parser/hphp.y"
    { _p->onArray((yyval),(yyvsp[(2) - (3)]),T_ARRAY);;}
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 2089 "../../../src/util/parser/hphp.y"
    { Token t; t.reset();
                                         _p->onArray((yyval),t,T_ARRAY);;}
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 2095 "../../../src/util/parser/hphp.y"
    { _p->onUserAttribute((yyval),&(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));;}
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 2097 "../../../src/util/parser/hphp.y"
    { _p->onUserAttribute((yyval),  0,(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 2100 "../../../src/util/parser/hphp.y"
    { user_attribute_check(_p);;}
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 2102 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 2105 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 2108 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 2109 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 2110 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 2111 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 2113 "../../../src/util/parser/hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 2114 "../../../src/util/parser/hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 2116 "../../../src/util/parser/hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 2118 "../../../src/util/parser/hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 548:

/* Line 1455 of yacc.c  */
#line 2120 "../../../src/util/parser/hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(1) - (5)]),(yyvsp[(4) - (5)]));;}
    break;

  case 549:

/* Line 1455 of yacc.c  */
#line 2123 "../../../src/util/parser/hphp.y"
    { _p->onStaticMember((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 550:

/* Line 1455 of yacc.c  */
#line 2125 "../../../src/util/parser/hphp.y"
    { _p->onCall((yyval),1,(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),NULL);;}
    break;

  case 551:

/* Line 1455 of yacc.c  */
#line 2129 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 552:

/* Line 1455 of yacc.c  */
#line 2130 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 553:

/* Line 1455 of yacc.c  */
#line 2131 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 554:

/* Line 1455 of yacc.c  */
#line 2133 "../../../src/util/parser/hphp.y"
    { _p->onRefDim((yyval),(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]));;}
    break;

  case 555:

/* Line 1455 of yacc.c  */
#line 2134 "../../../src/util/parser/hphp.y"
    { _p->onRefDim((yyval),(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]));;}
    break;

  case 556:

/* Line 1455 of yacc.c  */
#line 2136 "../../../src/util/parser/hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 557:

/* Line 1455 of yacc.c  */
#line 2138 "../../../src/util/parser/hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(1) - (5)]),(yyvsp[(4) - (5)]));;}
    break;

  case 558:

/* Line 1455 of yacc.c  */
#line 2140 "../../../src/util/parser/hphp.y"
    { _p->onCall((yyval),1,(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),NULL);;}
    break;

  case 559:

/* Line 1455 of yacc.c  */
#line 2144 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 560:

/* Line 1455 of yacc.c  */
#line 2146 "../../../src/util/parser/hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 561:

/* Line 1455 of yacc.c  */
#line 2147 "../../../src/util/parser/hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 562:

/* Line 1455 of yacc.c  */
#line 2153 "../../../src/util/parser/hphp.y"
    { _p->onObjectMethodCall((yyval),(yyvsp[(1) - (6)]),(yyvsp[(3) - (6)]),(yyvsp[(5) - (6)]));;}
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 2156 "../../../src/util/parser/hphp.y"
    { _p->onObjectMethodCall((yyval),(yyvsp[(1) - (6)]),(yyvsp[(3) - (6)]),(yyvsp[(5) - (6)]));;}
    break;

  case 564:

/* Line 1455 of yacc.c  */
#line 2159 "../../../src/util/parser/hphp.y"
    { _p->onObjectMethodCall((yyval),(yyvsp[(1) - (8)]),(yyvsp[(4) - (8)]),(yyvsp[(7) - (8)]));;}
    break;

  case 565:

/* Line 1455 of yacc.c  */
#line 2166 "../../../src/util/parser/hphp.y"
    { _p->onCall((yyval),0,(yyvsp[(3) - (6)]),(yyvsp[(5) - (6)]),&(yyvsp[(1) - (6)]));;}
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 2170 "../../../src/util/parser/hphp.y"
    { _p->onCall((yyval),1,(yyvsp[(3) - (6)]),(yyvsp[(5) - (6)]),&(yyvsp[(1) - (6)]));;}
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 2174 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 568:

/* Line 1455 of yacc.c  */
#line 2176 "../../../src/util/parser/hphp.y"
    { _p->onIndirectRef((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 2181 "../../../src/util/parser/hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 570:

/* Line 1455 of yacc.c  */
#line 2182 "../../../src/util/parser/hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 571:

/* Line 1455 of yacc.c  */
#line 2183 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 2186 "../../../src/util/parser/hphp.y"
    { _p->onSimpleVariable((yyval), (yyvsp[(1) - (1)]));;}
    break;

  case 573:

/* Line 1455 of yacc.c  */
#line 2187 "../../../src/util/parser/hphp.y"
    { _p->onDynamicVariable((yyval), (yyvsp[(3) - (4)]), 0);;}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 2190 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 2191 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 576:

/* Line 1455 of yacc.c  */
#line 2195 "../../../src/util/parser/hphp.y"
    { (yyval) = 1;;}
    break;

  case 577:

/* Line 1455 of yacc.c  */
#line 2196 "../../../src/util/parser/hphp.y"
    { (yyval)++;;}
    break;

  case 578:

/* Line 1455 of yacc.c  */
#line 2200 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 2202 "../../../src/util/parser/hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 580:

/* Line 1455 of yacc.c  */
#line 2204 "../../../src/util/parser/hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 2206 "../../../src/util/parser/hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 2208 "../../../src/util/parser/hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 2210 "../../../src/util/parser/hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(1) - (5)]),(yyvsp[(4) - (5)]));;}
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 2213 "../../../src/util/parser/hphp.y"
    { _p->onStaticMember((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 2218 "../../../src/util/parser/hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 2220 "../../../src/util/parser/hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 2222 "../../../src/util/parser/hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 2224 "../../../src/util/parser/hphp.y"
    { _p->onObjectProperty((yyval),(yyvsp[(1) - (5)]),(yyvsp[(4) - (5)]));;}
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 2228 "../../../src/util/parser/hphp.y"
    { _p->onAListVar((yyval),&(yyvsp[(1) - (2)]),NULL);;}
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 2229 "../../../src/util/parser/hphp.y"
    { _p->onAListVar((yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]));;}
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 2231 "../../../src/util/parser/hphp.y"
    { _p->onAListSub((yyval),&(yyvsp[(1) - (6)]),(yyvsp[(5) - (6)]));;}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 2232 "../../../src/util/parser/hphp.y"
    { _p->onAListVar((yyval),NULL,NULL);;}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 2233 "../../../src/util/parser/hphp.y"
    { _p->onAListVar((yyval),NULL,&(yyvsp[(1) - (1)]));;}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 2234 "../../../src/util/parser/hphp.y"
    { _p->onAListSub((yyval),NULL,(yyvsp[(3) - (4)]));;}
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 2239 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 2240 "../../../src/util/parser/hphp.y"
    { (yyval).reset();;}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 2244 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]),0);;}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 2245 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (3)]),  0,(yyvsp[(3) - (3)]),0);;}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 2246 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),  0,&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),0);;}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 2247 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),  0,  0,(yyvsp[(1) - (1)]),0);;}
    break;

  case 601:

/* Line 1455 of yacc.c  */
#line 2250 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (6)]),&(yyvsp[(3) - (6)]),(yyvsp[(6) - (6)]),1);;}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 2252 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (4)]),  0,(yyvsp[(4) - (4)]),1);;}
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 2253 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),  0,&(yyvsp[(1) - (4)]),(yyvsp[(4) - (4)]),1);;}
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 2254 "../../../src/util/parser/hphp.y"
    { _p->onArrayPair((yyval),  0,  0,(yyvsp[(2) - (2)]),1);;}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 2258 "../../../src/util/parser/hphp.y"
    { _p->addEncap((yyval), &(yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), -1);;}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 2260 "../../../src/util/parser/hphp.y"
    { _p->addEncap((yyval), &(yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), 0);;}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 2261 "../../../src/util/parser/hphp.y"
    { _p->addEncap((yyval), NULL, (yyvsp[(1) - (1)]), -1);;}
    break;

  case 608:

/* Line 1455 of yacc.c  */
#line 2263 "../../../src/util/parser/hphp.y"
    { _p->addEncap((yyval), NULL, (yyvsp[(1) - (2)]), 0);
                                         _p->addEncap((yyval), &(yyval), (yyvsp[(2) - (2)]), -1); ;}
    break;

  case 609:

/* Line 1455 of yacc.c  */
#line 2268 "../../../src/util/parser/hphp.y"
    { _p->onSimpleVariable((yyval), (yyvsp[(1) - (1)]));;}
    break;

  case 610:

/* Line 1455 of yacc.c  */
#line 2270 "../../../src/util/parser/hphp.y"
    { _p->encapRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 611:

/* Line 1455 of yacc.c  */
#line 2272 "../../../src/util/parser/hphp.y"
    { _p->encapObjProp((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 612:

/* Line 1455 of yacc.c  */
#line 2274 "../../../src/util/parser/hphp.y"
    { _p->onDynamicVariable((yyval), (yyvsp[(2) - (3)]), 1);;}
    break;

  case 613:

/* Line 1455 of yacc.c  */
#line 2276 "../../../src/util/parser/hphp.y"
    { _p->encapArray((yyval), (yyvsp[(2) - (6)]), (yyvsp[(4) - (6)]));;}
    break;

  case 614:

/* Line 1455 of yacc.c  */
#line 2277 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 615:

/* Line 1455 of yacc.c  */
#line 2280 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = T_STRING;;}
    break;

  case 616:

/* Line 1455 of yacc.c  */
#line 2281 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = T_NUM_STRING;;}
    break;

  case 617:

/* Line 1455 of yacc.c  */
#line 2282 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = T_VARIABLE;;}
    break;

  case 618:

/* Line 1455 of yacc.c  */
#line 2286 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(3) - (4)]),T_ISSET,1);;}
    break;

  case 619:

/* Line 1455 of yacc.c  */
#line 2287 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(3) - (4)]),T_EMPTY,1);;}
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 2288 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_INCLUDE,1);;}
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 2289 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_INCLUDE_ONCE,1);;}
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 2290 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(3) - (4)]),T_EVAL,1);;}
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 2291 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_REQUIRE,1);;}
    break;

  case 624:

/* Line 1455 of yacc.c  */
#line 2292 "../../../src/util/parser/hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_REQUIRE_ONCE,1);;}
    break;

  case 625:

/* Line 1455 of yacc.c  */
#line 2296 "../../../src/util/parser/hphp.y"
    { _p->onExprListElem((yyval), NULL, (yyvsp[(1) - (1)]));;}
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 2297 "../../../src/util/parser/hphp.y"
    { _p->onExprListElem((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 2302 "../../../src/util/parser/hphp.y"
    { _p->onClassConst((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 0);;}
    break;

  case 628:

/* Line 1455 of yacc.c  */
#line 2310 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 629:

/* Line 1455 of yacc.c  */
#line 2311 "../../../src/util/parser/hphp.y"
    { only_in_strict_mode(_p); (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 630:

/* Line 1455 of yacc.c  */
#line 2317 "../../../src/util/parser/hphp.y"
    { _p->pushTypeScope(); (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 631:

/* Line 1455 of yacc.c  */
#line 2318 "../../../src/util/parser/hphp.y"
    { _p->pushTypeScope(); (yyval) = (yyvsp[(1) - (4)]);
                                         only_in_strict_mode(_p); ;}
    break;

  case 632:

/* Line 1455 of yacc.c  */
#line 2323 "../../../src/util/parser/hphp.y"
    { only_in_strict_mode(_p); (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 633:

/* Line 1455 of yacc.c  */
#line 2324 "../../../src/util/parser/hphp.y"
    { (yyval).reset(); ;}
    break;

  case 639:

/* Line 1455 of yacc.c  */
#line 2340 "../../../src/util/parser/hphp.y"
    { (yyval).reset(); ;}
    break;

  case 640:

/* Line 1455 of yacc.c  */
#line 2341 "../../../src/util/parser/hphp.y"
    { only_in_strict_mode(_p); (yyval) = (yyvsp[(2) - (2)]); ;}
    break;

  case 641:

/* Line 1455 of yacc.c  */
#line 2345 "../../../src/util/parser/hphp.y"
    { _p->addTypeVar((yyvsp[(1) - (3)]).text()); ;}
    break;

  case 642:

/* Line 1455 of yacc.c  */
#line 2346 "../../../src/util/parser/hphp.y"
    { _p->addTypeVar((yyvsp[(1) - (1)]).text()); ;}
    break;

  case 643:

/* Line 1455 of yacc.c  */
#line 2353 "../../../src/util/parser/hphp.y"
    { only_in_strict_mode(_p); (yyval).reset(); ;}
    break;

  case 644:

/* Line 1455 of yacc.c  */
#line 2354 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);
                                         /* if the type annotation is a bound
                                            typevar we have to strip it */
                                         if (_p->scanner().isStrictMode() &&
                                             (_p->isTypeVar((yyval).text()) ||
                                              !(yyval).text().compare("mixed"))) {
                                           (yyval).reset();
                                         }
                                       ;}
    break;

  case 645:

/* Line 1455 of yacc.c  */
#line 2363 "../../../src/util/parser/hphp.y"
    { (yyval).setText("array"); ;}
    break;

  case 646:

/* Line 1455 of yacc.c  */
#line 2364 "../../../src/util/parser/hphp.y"
    { (yyvsp[(1) - (1)]).xhpLabel(); (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 647:

/* Line 1455 of yacc.c  */
#line 2366 "../../../src/util/parser/hphp.y"
    { only_in_strict_mode(_p); (yyval).reset(); ;}
    break;

  case 648:

/* Line 1455 of yacc.c  */
#line 2367 "../../../src/util/parser/hphp.y"
    { only_in_strict_mode(_p); (yyval).setText("array"); ;}
    break;

  case 649:

/* Line 1455 of yacc.c  */
#line 2371 "../../../src/util/parser/hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 650:

/* Line 1455 of yacc.c  */
#line 2372 "../../../src/util/parser/hphp.y"
    { (yyval).reset(); ;}
    break;



/* Line 1455 of yacc.c  */
#line 9863 "hphp.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, _p, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (&yylloc, _p, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, _p, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc, _p);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, _p);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, _p, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, _p);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, _p);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
  YYSTACK_CLEANUP;
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 2375 "../../../src/util/parser/hphp.y"

bool Parser::parseImpl() {
  return yyparse(this) == 0;
}

