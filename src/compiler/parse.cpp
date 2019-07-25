#include "parse.hpp"
#include "exceptions.hpp"

bool verify_header(WASMStream stream) {
  return stream.read_u32() == MAGIC_BYTES && stream.read_u32() == VERSION_NUMBER;
}
