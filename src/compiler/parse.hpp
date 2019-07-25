#pragma once
#include <pc.hpp>
#include "wasm-stream.hpp"

#define MAGIC_BYTES 0x6d736100
#define VERSION_NUMBER 1

bool verify_header(WASMStream stream);
