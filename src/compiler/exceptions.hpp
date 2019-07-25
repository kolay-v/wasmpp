#pragma once
#include <pc.hpp>

class CompileError : public std::exception {
public:
  CompileError();
  virtual const char* what() const throw();
};
