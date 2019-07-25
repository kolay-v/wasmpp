#include"exceptions.hpp"

const char* CompileError::what() const throw() {
  return "hi";
}

CompileError::CompileError() {}
