#ifndef CONVERT_H
#define CONVERT_H

#include <concepts>

/// This struct template provides a mechanism for easy type conversion
/// based on user-defined functions. Similar to the From trait in the
/// Rust standard library.
template <typename F> struct From {
  template <typename T> static T convert(F);
};

/// The opposite of From. This allows for partial specialization in some
/// cases not allowed by From. The default implementation of convert
/// relies on the implementation of Into::convert.
template <typename T> struct Into {
  template <typename F> static T convert(F f) {
    return From<F>::template convert<T>(f);
  }
};

/// This concept can be used by consumers who must receive a type for which
/// there is a full template specialization of Into with T and F.
template <typename T, typename F>
concept ConvertibleFrom = requires(T, F f) {
  { Into<T>::template convert<F>(f) } -> std::convertible_to<T>;
};

#endif // CONVERT_H
