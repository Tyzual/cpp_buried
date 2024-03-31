
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

template <typename T> class DefrecenWrapper {
public:
  DefrecenWrapper(T *v) : value_(v) {}

  AssignWrapper<T> operator*() { return AssignWrapper<T>(value_); }

private:
  T *value_;
};

template <typename T> DefrecenWrapper<T> safeAssignPtr(T *ptr) {
  return DefrecenWrapper<T>(ptr);
}

int main() {
  int *ptr{new int()};

  *safeAssignPtr(ptr) = 40;

  delete ptr;
  return 0;
}