#include <pc.hpp>
#include <wasm-stream.hpp>
#include <exceptions.hpp>
#include <compile.hpp>

int main () {
  std::ifstream file("../test.wasm", std::ios::binary | std::ios::ate);
  std::streamsize size = file.tellg();
  if (size < 0) {
    throw std::runtime_error("cant read file size < 0");
  }
  file.seekg(0, std::ios::beg);
  std::vector<uint8_t> buffer;
  buffer.resize(size);
  file.read((char*)buffer.data(), size);
  if (file.fail()) {
    throw std::runtime_error("cant read file");
  }
  auto stream = WASMStream(buffer);
  compile(stream);
  std::cout << "Succes";
}
