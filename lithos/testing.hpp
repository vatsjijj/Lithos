#pragma once

#include "types.hpp"
#include "display.hpp"
using lithos::string, lithos::errfln;

namespace lithos {
  // Define custom assert macro.
  #define assert(expr) \
    if (!(expr)) \
      lithos::fail(__FILE__, __LINE__, #expr)
  
  // Checks if expression is true, if not,
  // error with message.
  // If expression is false, exit.
  void fail(
    string file, int line, string expr
  ) {
    errfln(
      "Assertion '%s' failed in file '%s', line %d.",
      expr, file, line
    );
    exit(1);
  }
}