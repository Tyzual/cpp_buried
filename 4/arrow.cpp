#include <iostream>
#include <ostream>

struct SomeThing {
  int someThing_{};
  void saySomeThing() { std::cout << "say: " << someThing_ << std::endl; }
};

class MyPtr {
public:
  MyPtr(SomeThing *p) : ptr_(p) {}

  ~MyPtr() { delete ptr_; }

  SomeThing *operator->() { return ptr_; }

  const SomeThing *operator->() const { return ptr_; }

private:
  SomeThing *ptr_;
};

int main() {
  MyPtr p{new SomeThing()};
  p->someThing_ = 100;
  p->saySomeThing();

  return 0;
}