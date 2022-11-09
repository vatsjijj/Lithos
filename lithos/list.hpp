#pragma once

#include <list>
#include "types.hpp"
using lithos::string;

namespace lithos::list {
  // Strange special list type.
  template<class T>
  class List {
    std::list<T> lst;

    public:
      void addAll(std::list<T> lst) {}
      int getSize(std::list<T> lst) {
        return (int)lst.size();
      }
  };
}