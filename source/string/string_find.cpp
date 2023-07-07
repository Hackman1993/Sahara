#include "../../include/string/string.h"
#include <boost/algorithm/string.hpp>
namespace sahara{
  bool string::start_with(const string &other) const {
    return boost::algorithm::starts_with(string_, other.string_);
  }

  bool string::istart_with(const string &other) const {
    return boost::algorithm::istarts_with(string_, other.string_);
  }

  bool string::ends_with(const string &other) const {
    return boost::algorithm::ends_with(string_, other.string_);
  }

  bool string::iends_with(const string &other) const {
    return boost::algorithm::iends_with(string_, other.string_);
  }

  bool string::contains(const string &other) const {
    return boost::algorithm::contains(string_, other.string_);
  }

  bool string::icontains(const string &other) const {
    return boost::algorithm::icontains(string_, other.string_);
  }

  std::size_t string::find_first(const string &other) const {
    return boost::find_first(string_, other.string_).begin() - string_.begin();
  }

  std::size_t string::ifind_first(const string &other) const {
    return boost::ifind_first(string_, other.string_).begin() - string_.begin();
  }



}