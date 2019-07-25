#include "compile.hpp"
#include "exceptions.hpp"
#include "parse.hpp"

void compile(WASMStream stream) {
  if (!verify_header(stream)) {
    throw CompileError(/* "Invalid file format" */);
  }
  for (auto i : stream) {
    std::cout << i;
  }
}
