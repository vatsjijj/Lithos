#pragma once

#include <fstream>
#include <filesystem>
#include "types.hpp"
#include "testing.hpp"
using lithos::string, lithos::assertf;

namespace lithos {
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