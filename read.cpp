#include"pc.h"

const int MAGIC_BYTES = 0x6d736100;
const int VERSION_NUMBER = 1;

uint32_t read_u32(std::vector<uint8_t> buffer, u_int32_t i) {
  uint32_t value = buffer[i];
  value |= buffer[i + 1] << 8;
  value |= buffer[i + 2] << 16;
  value |= buffer[i + 3] << 24;
  return value;
}

bool verify_header (std::vector<uint8_t> buffer) {
  return read_u32(buffer, 0) == MAGIC_BYTES && read_u32(buffer, 4) == VERSION_NUMBER;
}

int main () {
  std::ifstream file("test.wasm", std::ios::binary | std::ios::ate);
  std::streamsize size = file.tellg();
  file.seekg(0, std::ios::beg);
  std::vector<uint8_t> buffer(size);
  if (!file.read(reinterpret_cast<char*>(buffer.data()), size)) {
    std::cout << "cant read file\n";
    return 1;
  }
  if (verify_header(buffer)) {
    std::cout << "succes";
  } else {
    std::cout << "invalid file format";
    return 1;
  }
}
