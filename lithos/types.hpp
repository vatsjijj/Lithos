#pragma once

#include <string>
#include "list.hpp"

namespace lithos {
  // Lithos defines a classic C style
  // string type.
  typedef const char* cstring;
  typedef std::string string;

  // Result and Err, unsure of what this could
  // be used for.
  typedef enum {
    Result, Err
  } LithosResult;

  // KeyPair, it's a pair of keys/types and it
  // generates a structure based on those types.
  template<class K, class T>
  struct KeyPair {
    KeyPair(K k, T val) :
    key(k),
    value(val) {}

    KeyPair() {}

    // Sets key = k and value = val.
    void set(K k, T val) {
      key = k;
      value = val;
    }

    K key;
    T value;
  };
}