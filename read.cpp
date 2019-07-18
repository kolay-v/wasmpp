#include<iostream>
#include<vector>
#include<fstream>

int main () {
  std::ifstream file("test.wasm", std::ios::binary | std::ios::ate);
  std::streamsize size = file.tellg();
  file.seekg(0, std::ios::beg);
  std::vector<uint8_t> buffer(size);
  if (file.read(reinterpret_cast<char*>(buffer.data()), size)) {
    std::cout << std::hex << (uint32_t)(buffer[0] | buffer[1] << 8 | buffer[2] << 16 | buffer[3] << 24) << '\n';
    std::cout << std::hex << (int)buffer[4];
    std::cout << std::hex << (int)buffer[5];
    std::cout << std::hex << (int)buffer[6];
    std::cout << std::hex << (int)buffer[7] << '\n';
  }
}