#include <iomanip>
#include <iostream>

bool is_ptr(int i) { return false; }

bool is_ptr(int* i) { return true; }

template <typename T>
void fun(const T& t) {
  int i = 0;
  // std::cout << std::boolalpha << is_ptr(t) << std::endl;

  if (is_ptr(t)) {
    i = *t;
  } else {
    i = t;
  }
  // std::cout << i << std::endl;
}

int main() {
  int i = 0;
  fun(i);
  fun(&i);
  return 0;
}