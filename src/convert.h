#ifndef CONVERT_H
#define CONVERT_H

#include <concepts>

/// This struct template provides a mechanism for easy type conversion
/// based on user-defined functions. Similar to the From and Into traits
/// in the Rust standard library.
template <typename T> struct Into {
  template <typename F> static T convert(F);
};

/// This concept can be used by consumers who must receive a type for which
/// there is a full template specialization of Into with T and F.
template <typename T, typename F>
concept ConvertibleFrom = requires(T, F f) {
  { Into<T>::template convert<F>(f) } -> std::convertible_to<T>;
};

#endif // CONVERT_H
