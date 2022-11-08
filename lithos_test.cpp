#include "lithos.hpp"
#include <string>

int main() {
  lithos::print("This is a print test.\n");
  lithos::println("This is a println test.");
  lithos::printendl("This is a printendl test.");
  lithos::string test1 = "printfln";
  lithos::printfln("This is a %s test.", test1);
  lithos::string test2 = "printfendl";
  lithos::printfendl("This is a %s test.", test2);
  std::string t = "test!!";
  lithos::string test3 = lithos::toStr(t);
  lithos::printfln(
    "%s %s %s: %s",
    "C++ does not like it when you use Lithos strings",
    "instead of std::strings, so lithos::toStr() should",
    "fix it because printfln breaks when std::string is used",
    test3
  );
  lithos::assert(1 + 5 == 6);
  // THIS WILL FAIL
  // lithos::assert(1 + 5 == 7);

  lithos::KeyPair<lithos::string, lithos::string> kp;
  kp.set("K val", "T val");
  lithos::assert((kp.key == "K val" && kp.value == "T val"));

  lithos::KeyPair<lithos::string, lithos::string> kp2("val1", "val2");
  lithos::assert((kp2.key == "val1" && kp2.value == "val2"));

  lithos::createFile("DELETEME.txt");
  lithos::removeFile("DELETEME.txt");

  sfor (i, < 10, ++) {
    printf("%d ", i);
  }
  lithos::println();

  int test[4] = {1, 2, 3, 4};
  foreach(num, test) {
    lithos::println(num);
  }

  int x = 0;
  loop {
    if (x == 10) {
      break;
    }
    printf("%d ", x);
    x++;
  }
  lithos::println();

  return 0;
}