#pragma once

#include <string.h>
#include "types.hpp"
using lithos::string;

namespace lithos::algo {
  string reverse(string str) {
    string out;
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