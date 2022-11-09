#pragma once

#include <iostream>
#include <cstdarg>
#include "types.hpp"
using lithos::string, lithos::cstring;

namespace lithos {
  // Takes a single string and prints it.
  void print(string str) {
    std::cout << str;
  }
  void print(cstring str) {
    std::cout << str;
  }
  void print(int num) {
    std::cout << num;
  }
  void print(float num) {
    std::cout << num;
  }
  void print(double num) {
    std::cout << num;
  }

  void println() {
    std::cout << "\n";
  }
  // Takes a single string and prints it with a newline.
  void println(string str) {
    std::cout << str << "\n";
  }
  void println(cstring str) {
    std::cout << str << "\n";
  }
  void println(int num) {
    std::cout << num << "\n";
  }
  void println(float num) {
    std::cout << num << "\n";
  }
  void println(double num) {
    std::cout << num << "\n";
  }

  void printendl() {
    std::cout << std::endl;
  }
  // Takes a single string and prints it with an endl.
  void printendl(string str) {
    std::cout << str << std::endl;
  }
  void printendl(cstring str) {
    std::cout << str << std::endl;
  }
  void printendl(int num) {
    std::cout << num << std::endl;
  }
  void printendl(float num) {
    std::cout << num << std::endl;
  }
  void printendl(double num) {
    std::cout << num << std::endl;
  }

  // Takes a formatted string and
  // a variable number of argsuments,
  // then prints it with a newline.
  void printfln(string str = "", ...) {
    va_list list;
    va_start(list, str);
    vprintf(str.c_str(), list);
    va_end(list);
    println();
  }
  void printfln(cstring str = "", ...) {
    va_list list;
    va_start(list, str);
    vprintf(str, list);
    va_end(list);
    println();
  }

  // Takes a formatted string and
  // a variable number of arguments,
  // then prints it with an endl.
  void printfendl(string str = "", ...) {
    va_list list;
    va_start(list, str);
    vprintf(str.c_str(), list);
    va_end(list);
    printendl();
  }
  void printfendl(cstring str = "", ...) {
    va_list list;
    va_start(list, str);
    vprintf(str, list);
    va_end(list);
    printendl();
  }

  // Takes a single string and
  // prints it to stderr.
  void err(string str) {
    fprintf(stderr, str.c_str());
  }
  void err(cstring str) {
    fprintf(stderr, str);
  }

  // Takes a single string and
  // prints it to stderr with a
  // newline.
  void errln(string str = "") {
    fprintf(stderr, str.c_str());
    fprintf(stderr, "\n");
  }
  void errln(cstring str = "") {
    fprintf(stderr, str);
    fprintf(stderr, "\n");
  }

  // Takes a formatted string and
  // a variable number of arguments,
  // then prints it.
  // Prints to stderr.
  void errf(string str, ...) {
    va_list list;
    va_start(list, str);
    vfprintf(stderr, str.c_str(), list);
    va_end(list);
  }
  void errf(cstring str, ...) {
    va_list list;
    va_start(list, str);
    vfprintf(stderr, str, list);
    va_end(list);
  }

  // Takes a formatted string and
  // a variable number of arguments,
  // then prints it with a newline.
  // Prints to stderr.
  void errfln(string str = "", ...) {
    va_list list;
    va_start(list, str);
    vfprintf(stderr, str.c_str(), list);
    va_end(list);
    fprintf(stderr, "\n");
  }
  void errfln(cstring str = "", ...) {
    va_list list;
    va_start(list, str);
    vfprintf(stderr, str, list);
    va_end(list);
    fprintf(stderr, "\n");
  }
}