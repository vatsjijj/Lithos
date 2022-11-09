#pragma once

#include <fstream>
#include <filesystem>
#include "types.hpp"
#include "testing.hpp"
using lithos::cstring;

namespace lithos {
  // Runs a command but returns nothing.
  void execCmd(cstring cmd) {
    int result = system(cmd);
    assert(result == 0);
  }
  void execCmd(string cmd) {
    int result = system(cmd.c_str());
    assert(result == 0);
  }

  // Simply creates a file.
  void createFile(string filename) {
    std::fstream file;
    file.open(filename.c_str(), std::ios::out);
    assert(file.is_open());
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
    file.open(filename.c_str(), std::ios::out);
    assert(file.is_open());
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
    assert(file.is_open());
    file << contents;
    file.close();
  }
  void appendFile(
    string filename, int contents
  ) {
    std::fstream file;
    file.open(filename, std::ios_base::app);
    assert(file.is_open());
    file << contents;
    file.close();
  }
  void appendFile(
    string filename, float contents
  ) {
    std::fstream file;
    file.open(filename, std::ios_base::app);
    assert(file.is_open());
    file << contents;
    file.close();
  }
  void appendFile(
    string filename, double contents
  ) {
    std::fstream file;
    file.open(filename, std::ios_base::app);
    assert(file.is_open());
    file << contents;
    file.close();
  }

  // Takes a file to read from and rets
  // the content as a string.
  std::string readFile(string filename) {
    std::ifstream file;
    string contents;
    file.open(filename);
    assert(file.is_open());
    std::stringstream buf;
    buf << file.rdbuf();
    file.close();
    return buf.str();
  }

  // Takes a filename, and then deletes the file.
  void removeFile(string filename) {
    assert(std::filesystem::remove(filename));
  }
}