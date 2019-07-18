#include"pc.h"

uint32_t read(std::vector<uint8_t> buffer, u_int32_t i) {
  return (uint32_t)(buffer[i * 4] | buffer[i * 4 + 1] << 8 | buffer[i * 4 + 2] << 16 | buffer[i * 4 + 3] << 24);
}

int main () {
  std::ifstream file("test.wasm", std::ios::binary | std::ios::ate);
  std::streamsize size = file.tellg();
  file.seekg(0, std::ios::beg);
  std::vector<uint8_t> buffer(size);
  if (file.read(reinterpret_cast<char*>(buffer.data()), size)) {
    std::cout << std::hex << read(buffer, 0) << '\n';
    std::cout << std::hex << read(buffer, 1) << '\n';    
  }
}