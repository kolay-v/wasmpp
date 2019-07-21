#include"../pc.hpp"
#include"../parser/wasm-stream.hpp"

static const int MAGIC_BYTES = 0x6d736100;
static const int VERSION_NUMBER = 1;

bool verify_header(WASMStream stream) {
  return stream.read_u32() == MAGIC_BYTES && stream.read_u32() == VERSION_NUMBER;
}

int main () {
  std::ifstream file("../test.wasm", std::ios::binary | std::ios::ate);
  std::streamsize size = file.tellg();
  if (size < 0) {
    throw std::runtime_error("cant read file size < 0");
  }
  file.seekg(0, std::ios::beg);
  std::vector<uint8_t> buffer;
  buffer.reserve((uint8_t)size);
  file.read((char*)buffer.data(), size);
  if (file.fail()) {
    throw std::runtime_error("cant read file");
  }
  WASMStream stream = WASMStream(&buffer);
  if (!verify_header(stream)) {
    throw std::invalid_argument("Invalid file format");
  }
  std::cout << "Succes";
}
