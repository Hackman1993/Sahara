//
// Created by Hackman.Lo on 4/11/2023.
//

#include "coder/url.h"
#include <sstream>
namespace sahara::coder {
  std::string url_encode(const std::string &str) {
    std::stringstream ss;
    for (char ch: str) {
      if (std::isalnum(ch) || ch == '-' || ch == '_' || ch == '.' || ch == '~') {
        ss << ch;
      } else {
        ss << '%' << std::uppercase << std::hex << static_cast<int>(ch);
      }
    }
    return ss.str();
  }

  std::string url_decode(const std::string& str){
    std::stringstream ss;
    for (std::size_t i = 0; i < str.size(); ++i) {
      if (str[i] == '%') {
        if (i + 2 < str.size() && std::isxdigit(str[i + 1]) && std::isxdigit(str[i + 2])) {
          std::string hex = str.substr(i + 1, 2);
          ss << static_cast<char>(std::stoul(hex, nullptr, 16));
          i += 2;
        } else {
          ss << str[i];
        }
      } else if (str[i] == '+') {
        ss << ' ';
      } else {
        ss << str[i];
      }
    }
    return ss.str();
  }
} // sahara::coder