#include <cctype>
#include <iostream>
#include <set>
#include <string>

struct MyCompare {
  bool operator()(const std::string &lhs, const std::string &rhs) const {
    const auto is_digit = [](const std::string &str) {
      for (const auto &it : str) {
        if (!std::isdigit(it)) {
          return false;
        }
      }
      return true;
    };

    auto is_lhs_digit = is_digit(lhs);
    auto is_rhs_digit = is_digit(rhs);
    if (is_lhs_digit && is_rhs_digit) {
      auto lhs_number = std::stoull(lhs);
      auto rhs_number = std::stoull(rhs);
      return lhs_number < rhs_number;
    }

    return lhs < rhs;
  }
};

int main() {
  // std::set<std::string> set;
  std::set<std::string, MyCompare> set;
  set.insert("2");
  set.insert("1");
  set.insert("11");
  set.insert("a");
  set.insert("ab");
  set.insert("b");
  set.insert("c");
  for (const auto &it : set) {
    std::cout << it << std::endl;
  }

  return 0;
}