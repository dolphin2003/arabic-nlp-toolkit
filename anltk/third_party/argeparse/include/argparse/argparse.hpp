
/*
  __ _ _ __ __ _ _ __   __ _ _ __ ___  ___
 / _` | '__/ _` | '_ \ / _` | '__/ __|/ _ \ Argument Parser for Modern C++
| (_| | | | (_| | |_) | (_| | |  \__ \  __/ http://github.com/p-ranav/argparse
 \__,_|_|  \__, | .__/ \__,_|_|  |___/\___|
           |___/|_|

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2019-2021 Pranav Srinivas Kumar <pranav.srinivas.kumar@gmail.com>
and other contributors.

Permission is hereby  granted, free of charge, to any  person obtaining a copy
of this software and associated  documentation files (the "Software"), to deal
in the Software  without restriction, including without  limitation the rights
to  use, copy,  modify, merge,  publish, distribute,  sublicense, and/or  sell
copies  of  the Software,  and  to  permit persons  to  whom  the Software  is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE  IS PROVIDED "AS  IS", WITHOUT WARRANTY  OF ANY KIND,  EXPRESS OR
IMPLIED,  INCLUDING BUT  NOT  LIMITED TO  THE  WARRANTIES OF  MERCHANTABILITY,
FITNESS FOR  A PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO EVENT  SHALL THE
AUTHORS  OR COPYRIGHT  HOLDERS  BE  LIABLE FOR  ANY  CLAIM,  DAMAGES OR  OTHER
LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE  OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once
#include <algorithm>
#include <any>
#include <cerrno>
#include <charconv>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <variant>
#include <vector>

namespace argparse {

namespace details { // namespace for helper methods

template <typename T, typename = void>
struct is_container : std::false_type {};

template <> struct is_container<std::string> : std::false_type {};

template <typename T>
struct is_container<T, std::void_t<typename T::value_type,
                                   decltype(std::declval<T>().begin()),
                                   decltype(std::declval<T>().end()),
                                   decltype(std::declval<T>().size())>>
  : std::true_type {};

template <typename T>
static constexpr bool is_container_v = is_container<T>::value;

template <typename T, typename = void>
struct is_streamable : std::false_type {};

template <typename T>
struct is_streamable<
    T, std::void_t<decltype(std::declval<std::ostream&>() << std::declval<T>())>>
  : std::true_type {};

template <typename T>
static constexpr bool is_streamable_v = is_streamable<T>::value;

template <typename T>
static constexpr bool is_representable_v =
    is_streamable_v<T> || is_container_v<T>;

constexpr std::size_t repr_max_container_size = 5;

template <typename T> std::string repr(T const &val) {
  if constexpr (std::is_same_v<T, bool>) {
    return val ? "true" : "false";
  } else if constexpr (std::is_convertible_v<T, std::string_view>) {
    return '"' + std::string{std::string_view{val}} + '"';
  } else if constexpr (is_container_v<T>) {
    std::stringstream out;
    out << "{";
    const auto size = val.size();
    if (size > 1) {
      out << repr(*val.begin());
      std::for_each(
          std::next(val.begin()),
          std::next(val.begin(), std::min<std::size_t>(size, repr_max_container_size) - 1),
          [&out](const auto &v) { out << " " << repr(v); });
      if (size <= repr_max_container_size)
        out << " ";
      else
        out << "...";
    }
    if (size > 0)
      out << repr(*std::prev(val.end()));
    out << "}";
    return out.str();
  } else if constexpr (is_streamable_v<T>) {
    std::stringstream out;
    out << val;
    return out.str();
  } else {
    return "<not representable>";
  }
}

namespace {

template <typename T> constexpr bool standard_signed_integer = false;
template <> constexpr bool standard_signed_integer<signed char> = true;
template <> constexpr bool standard_signed_integer<short int> = true;
template <> constexpr bool standard_signed_integer<int> = true;
template <> constexpr bool standard_signed_integer<long int> = true;
template <> constexpr bool standard_signed_integer<long long int> = true;

template <typename T> constexpr bool standard_unsigned_integer = false;
template <> constexpr bool standard_unsigned_integer<unsigned char> = true;
template <> constexpr bool standard_unsigned_integer<unsigned short int> = true;
template <> constexpr bool standard_unsigned_integer<unsigned int> = true;
template <> constexpr bool standard_unsigned_integer<unsigned long int> = true;
template <>
constexpr bool standard_unsigned_integer<unsigned long long int> = true;

} // namespace

template <typename T>
constexpr bool standard_integer =
    standard_signed_integer<T> || standard_unsigned_integer<T>;

template <class F, class Tuple, class Extra, std::size_t... I>
constexpr decltype(auto) apply_plus_one_impl(F &&f, Tuple &&t, Extra &&x,
                                             std::index_sequence<I...>) {
  return std::invoke(std::forward<F>(f), std::get<I>(std::forward<Tuple>(t))...,
                     std::forward<Extra>(x));
}

template <class F, class Tuple, class Extra>
constexpr decltype(auto) apply_plus_one(F &&f, Tuple &&t, Extra &&x) {
  return details::apply_plus_one_impl(
      std::forward<F>(f), std::forward<Tuple>(t), std::forward<Extra>(x),
      std::make_index_sequence<
          std::tuple_size_v<std::remove_reference_t<Tuple>>>{});
}

constexpr auto pointer_range(std::string_view s) noexcept {
  return std::tuple(s.data(), s.data() + s.size());
}

template <class CharT, class Traits>
constexpr bool starts_with(std::basic_string_view<CharT, Traits> prefix,
                           std::basic_string_view<CharT, Traits> s) noexcept {
  return s.substr(0, prefix.size()) == prefix;
}

enum class chars_format {
  scientific = 0x1,
  fixed = 0x2,
  hex = 0x4,
  general = fixed | scientific
};

struct consume_hex_prefix_result {
  bool is_hexadecimal;
  std::string_view rest;
};

using namespace std::literals;

constexpr auto consume_hex_prefix(std::string_view s)
    -> consume_hex_prefix_result {
  if (starts_with("0x"sv, s) || starts_with("0X"sv, s)) {
    s.remove_prefix(2);
    return {true, s};
  } else {
    return {false, s};
  }
}

template <class T, auto Param>
inline auto do_from_chars(std::string_view s) -> T {
  T x;
  auto [first, last] = pointer_range(s);
  auto [ptr, ec] = std::from_chars(first, last, x, Param);
  if (ec == std::errc()) {
    if (ptr == last)
      return x;
    else
      throw std::invalid_argument{"pattern does not match to the end"};
  } else if (ec == std::errc::invalid_argument) {
    throw std::invalid_argument{"pattern not found"};
  } else if (ec == std::errc::result_out_of_range) {
    throw std::range_error{"not representable"};
  } else {
    return x; // unreachable
  }
}

template <class T, auto Param = 0> struct parse_number {
  auto operator()(std::string_view s) -> T {
    return do_from_chars<T, Param>(s);
  }
};

template <class T> struct parse_number<T, 16> {
  auto operator()(std::string_view s) -> T {
    if (auto [ok, rest] = consume_hex_prefix(s); ok)
      return do_from_chars<T, 16>(rest);
    else
      throw std::invalid_argument{"pattern not found"};
  }
};

template <class T> struct parse_number<T> {
  auto operator()(std::string_view s) -> T {
    if (auto [ok, rest] = consume_hex_prefix(s); ok)
      return do_from_chars<T, 16>(rest);
    else if (starts_with("0"sv, s))
      return do_from_chars<T, 8>(rest);
    else
      return do_from_chars<T, 10>(rest);
  }
};

namespace {

template <class T> constexpr auto generic_strtod = nullptr;
template <> constexpr auto generic_strtod<float> = strtof;
template <> constexpr auto generic_strtod<double> = strtod;
template <> constexpr auto generic_strtod<long double> = strtold;

} // namespace

template <class T> inline auto do_strtod(std::string const &s) -> T {
  if (isspace(static_cast<unsigned char>(s[0])) || s[0] == '+')
    throw std::invalid_argument{"pattern not found"};

  auto [first, last] = pointer_range(s);
  char *ptr;

  errno = 0;
  if (auto x = generic_strtod<T>(first, &ptr); errno == 0) {
    if (ptr == last)
      return x;
    else
      throw std::invalid_argument{"pattern does not match to the end"};
  } else if (errno == ERANGE) {
    throw std::range_error{"not representable"};
  } else {
    return x; // unreachable
  }
}

template <class T> struct parse_number<T, chars_format::general> {
  auto operator()(std::string const &s) -> T {
    if (auto r = consume_hex_prefix(s); r.is_hexadecimal)
      throw std::invalid_argument{
          "chars_format::general does not parse hexfloat"};

    return do_strtod<T>(s);
  }
};

template <class T> struct parse_number<T, chars_format::hex> {
  auto operator()(std::string const &s) -> T {
    if (auto r = consume_hex_prefix(s); !r.is_hexadecimal)
      throw std::invalid_argument{"chars_format::hex parses hexfloat"};

    return do_strtod<T>(s);
  }
};

template <class T> struct parse_number<T, chars_format::scientific> {
  auto operator()(std::string const &s) -> T {
    if (auto r = consume_hex_prefix(s); r.is_hexadecimal)
      throw std::invalid_argument{
          "chars_format::scientific does not parse hexfloat"};
    if (s.find_first_of("eE") == s.npos)
      throw std::invalid_argument{