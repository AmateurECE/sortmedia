#include <regex>
#include <stdexcept>
#include <string>

#include "convert.h"
#include "metadata.h"

using namespace std;
using namespace metadata;

template <>
template <>
string From<NonStandardTags::Quantity>::convert<string>(
    NonStandardTags::Quantity quantity) {
  switch (quantity) {
  case NonStandardTags::Quantity::Track:
    return "TRACK";
  case NonStandardTags::Quantity::Disc:
    return "DISC";
  default:
    throw std::runtime_error{"non-exhaustive conversion"};
  }
}

std::string metadata::sanitize_token(const std::string& input) {
  static const std::regex disallowed_characters{"[^A-Za-z0-9 ()\\[\\]]+"};
  return std::regex_replace(input, disallowed_characters, "_");
}
