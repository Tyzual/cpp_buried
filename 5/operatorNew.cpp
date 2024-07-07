#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>

class Img {
public:
  enum class Type {
    SRGB = 0,
    GREYSCALE,
  };

  struct MetaData {
    Type type;
    uint32_t width;
    uint32_t height;
  };

  Img(const MetaData &meta)
      : meta_(meta) {}

  uint8_t *rawData() {
    return reinterpret_cast<uint8_t *>(this) + offsetof(Img, data_);
  }

private:
  MetaData meta_;
  char *data_[0];

public:
  void *operator new(size_t size, const MetaData &meta) {
    size_t allocSize = meta.height * meta.width;
    switch (meta.type) {
    case Type::SRGB: {
      allocSize *= 4;
      break;
    }
    case Type::GREYSCALE:
      break;
    }
    std::cout << "img type:" << static_cast<int>(meta.type)
              << ", alloc size:" << allocSize << std::endl;
    return malloc(size + allocSize);
  }

  void operator delete(void *ptr) { free(ptr); }
};

int main() {
  Img::MetaData greyMeta;
  greyMeta.width = 128;
  greyMeta.height = 128;
  greyMeta.type = Img::Type::GREYSCALE;
  Img *greyImg = new (greyMeta) Img(greyMeta);
  greyImg->rawData()[100] = 255;
  std::cout << static_cast<int>(
                   *(reinterpret_cast<unsigned char *>(greyImg) + sizeof(Img) + 100))
            << std::endl;
  delete greyImg;

  Img imgStack(greyMeta);

  Img::MetaData srgbMeta;
  srgbMeta.width = 128;
  srgbMeta.height = 128;
  srgbMeta.type = Img::Type::SRGB;
  Img *srgbImg = new (srgbMeta) Img(srgbMeta);
  srgbImg->rawData()[100 * 4] = 255;
  delete srgbImg;
  return 0;
}