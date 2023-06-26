#include "string/string.h"
#include <boost/locale.hpp>
#include <boost/locale/encoding_utf.hpp>
#include <utility>

namespace sahara {

  string::string(const std::string &other) : string_(other) {}

  string::string(const char *other) : string_(other) {}

  string::string(const string &other) : string_(other.string_) {}

  string::string(string &&other) noexcept: string_(std::move(other.string_)) {}

  string::string(std::string_view other) : string_(other) {}
}