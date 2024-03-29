#include <string>

#include "convert.h"

template <>
template <>
unsigned int Into<unsigned int>::convert<std::string>(std::string value) {
  return std::stoi(value);
}

/// Trivial case: string -> string
template <>
template <>
std::string Into<std::string>::convert<std::string>(std::string value) {
  return value;
}
