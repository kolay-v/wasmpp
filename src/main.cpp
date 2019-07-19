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
  std::ifstream file("../test.wasm", std::ios::binary | std::ios::ate);
  std::streamsize size = file.tellg();
  if (size < 0) {
    throw std::runtime_error("cant read file size < 0");
  }
  file.seekg(0, std::ios::beg);
  std::vector<uint8_t> buffer(size);
  file.read(reinterpret_cast<char*>(buffer.data()), size);
  if (file.fail()) {
    throw std::runtime_error("cant read file");
  }
  if (!verify_header(buffer)) {
    throw std::invalid_argument("Invalid file format");
  }
  std::cout << "Succes";
}
