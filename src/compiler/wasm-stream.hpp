#pragma once
#include <pc.hpp>

class WASMStream {
public:
  WASMStream(const std::vector<uint8_t>& buffer);
  uint32_t read_u32();
  uint8_t read();
  uint32_t read_varuint32();
private:
  size_t m_offset;
  const std::vector<uint8_t> &m_buffer;
};
