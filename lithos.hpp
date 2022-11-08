#pragma once

#include <iostream>
#include <fstream>
#include <cstdarg>
#include <string>
#include <filesystem>

namespace lithos {
  // Syntatic sugar.
  #define foreach(val, in) for (auto val : in)
  #define loop while (true)
  #define sfor(var, expr1, expr2) \
    for (int var = 0; var expr1; var expr2)
  #define snfor(var, val, expr1, expr2) \
    for (int var = val; var expr1; var expr2)
  #define ret return
  #define cast(type) (type)

  // Lithos defines a classic C style
  // string type.
  typedef const char* string;

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

  // Takes a single string and prints it.
  void print(string str) {
    std::cout << str;
  }
  void print(std::string str) {
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
  void println(std::string str) {
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
  void printendl(std::string str) {
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
    vprintf(str, list);
    va_end(list);
    printendl();
  }

  // Takes a single string and
  // prints it to stderr.
  void err(string str) {
    fprintf(stderr, str);
  }

  // Takes a single string and
  // prints it to stderr with a
  // newline.
  void errln(string str = "") {
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
    vfprintf(stderr, str, list);
    va_end(list);
    fprintf(stderr, "\n");
  }

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

  // Runs a command but returns nothing.
  void execCmd(string cmd) {
    int result = system(cmd);
    assertf(result == 0, "%s did not return zero.", cmd);
  }

  // Simply creates a file.
  void createFile(string filename) {
    std::fstream file;
    file.open(filename, std::ios::out);
    assertf(file.is_open(), "Failed to open %s.", filename);
    file.close();
  }

  // Takes a filename, and then contents
  // to write to the file.
  // Will create the file if it does not
  // exist.
  void writeFile(
    string filename, string contents = ""
  ) {
    std::fstream file;
    file.open(filename, std::ios::out);
    assertf(file.is_open(), "Failed to open %s.", filename);
    file << contents;
    file.close();
  }

  // Takes a filename, and then contents
  // to append to the file.
  // Will create the file if it does not
  // exist.
  void appendFile(
    string filename, string contents = ""
  ) {
    std::fstream file;
    file.open(filename, std::ios_base::app);
    assertf(file.is_open(), "Failed to open %s.", filename);
    file << contents;
    file.close();
  }
  void appendFile(
    string filename, int contents
  ) {
    std::fstream file;
    file.open(filename, std::ios_base::app);
    assertf(file.is_open(), "Failed to open %s.", filename);
    file << contents;
    file.close();
  }
  void appendFile(
    string filename, float contents
  ) {
    std::fstream file;
    file.open(filename, std::ios_base::app);
    assertf(file.is_open(), "Failed to open %s.", filename);
    file << contents;
    file.close();
  }
  void appendFile(
    string filename, double contents
  ) {
    std::fstream file;
    file.open(filename, std::ios_base::app);
    assertf(file.is_open(), "Failed to open %s.", filename);
    file << contents;
    file.close();
  }

  // Takes a file to read from and rets
  // the content as a string.
  std::string readFile(string filename) {
    std::ifstream file;
    string contents;
    file.open(filename);
    assertf(file.is_open(), "Failed to open %s.", filename);
    std::stringstream buf;
    buf << file.rdbuf();
    file.close();
    return buf.str();
  }

  // Takes a filename, and then deletes the file.
  void removeFile(string filename) {
    assertf(
      std::filesystem::remove(filename),
      "Failed to remove %s.", filename
    );
  }
}