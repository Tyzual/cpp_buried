
#include <iostream>
#include <iterator>

template <typename T> class AssignWrapper {
public:
  AssignWrapper(T *v) : value_(v) {}

  template <typename U> void operator=(U &&u) {
    if (value_) {
      std::cout << "assign" << std::endl;
      *value_ = std::forward<U>(u);
    } else {
      std::cout << "not assign" << std::endl;
    }
  }

private:
  T *value_;
};

#if 0
template <typename T> class DefrecenWrapper {
public:
  DefrecenWrapper(T *v) : value_(v) {}

  AssignWrapper<T> operator*() { return AssignWrapper<T>(value_); }

private:
  T *value_;
};
#endif

// template <typename T> AssignWrapper<T> safeAssign(T *ptr) {
//   return AssignWrapper<T>(ptr);
// }

int main() {
  int *ptr{new int()};

  // AssignWrapper<int> w(ptr);
  // w = 30;

  // safeAssign(ptr) = 40;
  delete ptr;
  return 0;
}