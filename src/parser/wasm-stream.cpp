#include "wasm-stream.hpp"

WASMStream::WASMStream(uint8_t* buffer): m_offset(0), m_buffer(buffer) {}

uint32_t WASMStream::read_u32() {
  return 1;
}
