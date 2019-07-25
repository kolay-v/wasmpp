#include "wasm-stream.hpp"
#include "exceptions.hpp"

WASMStream::WASMStream(const std::vector<uint8_t>& buffer): m_offset(0), m_buffer(buffer) {}

uint32_t WASMStream::read_u32() {
  uint32_t value = read();
  value |= read() << 8;
  value |= read() << 16;
  value |= read() << 24;
  return value;
}

uint8_t WASMStream::read() {
  m_offset++;
  return m_buffer.at(m_offset - 1);
}

uint32_t WASMStream::read_varuint32() {
  uint8_t b = 0;
  uint32_t result = 0;
  uint32_t shift = 0;
  do {
    if (shift > 32) {
      throw CompileError(/*"varuint32 too large"*/);
    }
    b = read();
    result = ((b & 0x7F) << shift) | result;
    shift += 7;
  } while (b & 0x80);
  return result /* >> 0 */;
}
