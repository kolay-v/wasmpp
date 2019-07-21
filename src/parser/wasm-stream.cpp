#include "wasm-stream.hpp"

WASMStream::WASMStream(const std::vector<uint8_t>* buffer): m_offset(0), m_buffer(*buffer) {}

uint32_t WASMStream::read_u32() {
  uint32_t value = read();
  value |= read() << 8;
  value |= read() << 16;
  value |= read() << 24;
  return value;
}

uint8_t WASMStream::read() {
  m_offset++;
  return m_buffer[m_offset - 1];
}
