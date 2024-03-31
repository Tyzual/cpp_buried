#include <iostream>
#include <list>
#include <type_traits>
#include <vector>

namespace helper {
template <typename T>
T Value(const T& t, std::false_type _) {
  std::cout << "not pointer" << std::endl;
  return t;
}

template <typename T>
auto Value(const T& t, std::true_type _) -> decltype(*t) {
  std::cout << "is pointer" << std::endl;
  return *t;
}
}  // namespace helper

template <typename T>
void Value(const T& t) {
  int i = 0;
  // i = helper::Value(t, typename std::is_pointer<T>::type());
  // std::cout << i << std::endl;

  // is_pointer_t<T> ===>
  // is_pointer<T>::type
  using abc = std::is_poiner_t<T>;


  // is_pointer_v<T> ===>
  // is_pointer<T>::value
  auto bcd = std::is_poiner_v<T>();

  if constexpr (std::is_pointer<T>::value) {
    i = *t;
  } else {
    i = t;
  }
  std::cout << i << std::endl;
}

int main() {
  int j = 100;
  Value(j);
  j = 200;
  Value(&j);
  return 0;
}