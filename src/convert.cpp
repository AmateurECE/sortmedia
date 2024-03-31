#include <string>

#include "convert.h"

template <>
template <>
unsigned int From<std::string>::convert<unsigned int>(std::string value) {
  return std::stoi(value);
}

/// Trivial case: string -> string
template <>
template <>
std::string From<std::string>::convert<std::string>(std::string value) {
  return value;
}
