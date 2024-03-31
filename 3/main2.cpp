#include <iostream>
#include <list>
#include <vector>

template <typename T>
class PointerDect {
 public:
  // PointerDect<int>::type ==> vector
  using type = std::vector<int>;  // vector 表示"假"类型
};

template <>
class PointerDect<int*> {
 public:
  // PointerDect<int*>::type ==> list
  using type = std::list<int>;  // list 表示"真"类型
};

namespace helper {

template <typename T>
T Value(const T& t, const std::vector<int>& not_used) {
  std::cout << "not pointer" << std::endl;
  return t;
}

template <typename T>
auto Value(const T& t, const std::list<int>& not_used) -> decltype(*t) {
  std::cout << "is pointer" << std::endl;
  return *t;
}

}  // namespace helper

template <typename T>
void Value(const T& t) {
  int i = 0;
  i = helper::Value(t, typename PointerDect<T>::type());
  std::cout << i << std::endl;
}

int main() {
  int j = 100;
  Value(j);
  j = 200;
  Value(&j);
  return 0;
}