#include "lithos/suite.hpp"
#include <string>

void fib(int n) {
  int f[n];
  f[0] = 0;
  f[1] = 1;
  snfor (i, 2, < n, ++) {
    f[i] = f[i - 1] + f[i - 2];
  }
  sfor (i, < n, ++) {
    printf("%d ", f[i]);
  }
}

int main() {
  lithos::print("This is a print test.\n");
  lithos::println("This is a println test.");
  lithos::printendl("This is a printendl test.");
  lithos::string test1 = "printfln";
  lithos::printfln("This is a %s test.", test1);
  lithos::string test2 = "printfendl";
  lithos::printfendl("This is a %s test.", test2);
  assert(1 + 5 == 6);
  // THIS WILL FAIL
  // assert(1 + 5 == 7);

  lithos::KeyPair<lithos::string, lithos::string> kp;
  kp.set("K val", "T val");
  assert((kp.key == "K val" && kp.value == "T val"));

  lithos::KeyPair<lithos::string, lithos::string> kp2("val1", "val2");
  assert((kp2.key == "val1" && kp2.value == "val2"));

  lithos::createFile("DELETEME.txt");
  lithos::removeFile("DELETEME.txt");

  sfor (i, < 10, ++) {
    printf("%d ", i);
  }
  lithos::println();

  int test[4] = {1, 2, 3, 4};
  foreach (num, test) {
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

  lithos::println("\nFib:");
  fib(35);
  lithos::println();

  lithos::writeFile("test.txt", "i am being read!");
  lithos::print(lithos::readFile("test.txt").c_str());
  lithos::println();
  lithos::removeFile("test.txt");

  int y = 7 + 0.1;
  lithos::println(y);
  double yd = cast(double)y + 0.1;
  lithos::println(yd);

  lithos::execCmd("/usr/bin/fortune 2> /dev/null");

  ret 0;
}