#include "string/string.h"
#include <boost/locale/encoding.hpp>

namespace sahara{
  string::operator std::string &() {
    return string_;
  }

  string::operator std::string_view() {
    return string_;
  }

  string &string::operator=(const string &other) {
    this->string_ = other.string_;
    return *this;
  }

  bool string::operator==(const string &other) const {
    return equals(other);
  }

  string &string::operator=(const std::string& other) {
    operator=(string(other));
    return *this;
  }

  bool string::operator==(string &&other) const {
    return equals(other);
  }

  string string::operator+(const char *other) const {
    return string_ + other;
  }

  string operator+(const char *lhs, const string &rhs) {
    return lhs + rhs.string_;
  }
}