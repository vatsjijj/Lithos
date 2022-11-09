#pragma once

namespace lithos {
  #define foreach(val, in) for (auto val : in)
  #define loop while (true)
  #define sfor(var, expr1, expr2) \
    for (int var = 0; var expr1; var expr2)
  #define snfor(var, val, expr1, expr2) \
    for (int var = val; var expr1; var expr2)
  #define ret return
  #define cast(type) (type)
}