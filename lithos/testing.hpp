#pragma once

#include "types.hpp"
#include "display.hpp"
using lithos::cstring, lithos::errfln;

namespace lithos {
  // Define custom assert macro.
  #define assert(expr) \
    if (!(expr)) \
      lithos::fail(__FILE__, __LINE__, #expr)
  
  // Checks if expression is true, if not,
  // error with message.
  // If expression is false, exit.
  void fail(
    cstring file, int line, cstring expr
  ) {
    errfln(
      "Assertion '%s' failed in file '%s', line %d.",
      expr, file, line
    );
    exit(1);
  }
}