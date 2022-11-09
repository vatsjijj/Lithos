#pragma once

#include <cstdarg>
#include "types.hpp"
#include "display.hpp"
using lithos::string, lithos::errln;

namespace lithos {
  // Checks if expression is true, if not,
  // error with message.
  // If expression is false, exit.
  void assert(
    bool expr, string message = "Assertion failed."
  ) {
    if (!expr) {
      errln(message);
      exit(1);
    }
  }

  // Checks if expression is true, if not,
  // error with message.
  // If expression is false, exit.
  // Variable arguments.
  void assertf(
    bool expr, string message = "Assertion failed.",
    ...
  ) {
    if (!expr) {
      va_list list;
      va_start(list, message);
      vfprintf(stderr, message, list);
      va_end(list);
      fprintf(stderr, "\n");
      exit(1);
    }
  }
}