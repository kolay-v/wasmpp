#pragma once
#include "../pc.hpp"

class WASMStream {
public:
  WASMStream(uint8_t* buffer);
  uint32_t read_u32();
private:
  size_t m_offset;
  const uint8_t* m_buffer;
};
