#pragma once

#include <string.h>
#include "types.hpp"
using lithos::string, lithos::cstring;

namespace lithos::algo {
  cstring reverse(cstring str) {
    cstring out;
    int length = strlen(str);
    char newStr[length];
    int j = 0;
    for (int i = length - 1; i >= 0; i--) {
       newStr[j] = str[i];
       j++;
    }
    out = newStr;
    return out;
  }
}