#include"pc.h"

uint32_t read_u32(std::vector<uint8_t> buffer, u_int32_t i) {
  return (uint32_t)(buffer[i * 4] | buffer[i * 4 + 1] << 8 | buffer[i * 4 + 2] << 16 | buffer[i * 4 + 3] << 24);
}

bool verify_header (std::vector<uint8_t> buffer) {
  return read_u32(buffer, 0) == 0x6d736100 && read_u32(buffer, 1) == 1;
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
