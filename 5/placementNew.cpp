#include <cstdlib>
#include <iostream>

class Demo {
public:
  Demo() {
    data_ = reinterpret_cast<char *>(malloc(1024));
    std::cout << "malloc data" << std::endl;
  }
  ~Demo() {
    free(data_);
    std::cout << "free data" << std::endl;
  }

  char *data_;
};

Demo* getDemo() {
  static char buffer[1024];
  new (buffer + 2) Demo();
  Demo* pDemo = reinterpret_cast<Demo*>(buffer + 2);
  return pDemo;
}


int main() {
  // 标准的new
  // 1. 运行库申请内存空间(大小足够容纳Demo)
  // 2. 运行库调用构造
  // 标准 delete
  // 1. 运行库调用析构
  // 2. 运行库释放内存空间

#if 0
  auto pDemo = new Demo();
  delete pDemo;
#else

  // char *buffer = reinterpret_cast<char*>(malloc(1024));
  // char *buffer = new char[1024];
  char buffer[1024];

  // buffer[0] = 'a';
  // buffer[1] = 'b';
  // buffer[sizeof(Demo) + 2] = 'c';
  
  new (buffer + 2) Demo();
  Demo* pDemo = reinterpret_cast<Demo*>(buffer + 2);
  pDemo->data_[100] = 3;
  pDemo->~Demo();

  // free(buffer);
  // delete[] buffer;
#endif
  return 0;
}