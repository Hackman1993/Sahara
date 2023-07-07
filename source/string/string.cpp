
#include "../../include/string/string.h"
#include <iostream>
#include <iomanip>
#include <codecvt>
#include <boost/url/encode.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/locale/encoding.hpp>
#include <boost/url/grammar.hpp>
#include <boost/algorithm/hex.hpp>
namespace sahara {
    std::vector<string> string::split(const string &delimeter, bool compress_token, bool drop_empty) const{
        std::vector<std::string> result;
        boost::split(result, string_, boost::is_any_of(delimeter.string_),compress_token? boost::token_compress_on:boost::token_compress_off);
        std::vector<sahara::string> result1;
        for(auto& str: result){
          if(drop_empty && str.empty()) continue;
          result1.emplace_back(str);
        }
        return result1;
    }

    std::string string::to_std() const {
        return boost::locale::conv::utf_to_utf<char>(string_);
    }

    bool string::equals(const string &other) const {
        return string_ == other.string_;
    }
    bool string::iequals(const string &other) const {
      return boost::algorithm::iequals(string_, other.string_);
    }

    bool string::empty() const {
        return string_.empty();
    }

    std::size_t string::size() const noexcept {
        return string_.length();
    }
    string string::substr(std::size_t pos, std::size_t len) const {
        return string_.substr(pos, len);
    }

  string string::make_from(std::uint64_t value) {
    return boost::lexical_cast<std::string>(value);
  }

  string string::url_encode_copy() const {
      return url_encode(string_);
  }

  void string::url_encode() {
    string_ = url_encode(string_);
  }

  string string::url_encode(string str) {
    std::ostringstream encoded;
    encoded.fill('0');
    encoded << std::hex << std::uppercase;

    for (char c : str.string_) {
      if (std::isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
        encoded << c;
      } else {
        encoded << '%' << std::setw(2) << static_cast<unsigned int>(static_cast<unsigned char>(c));
      }
    }
    return encoded.str();
  }


  void string::url_decode() {
      string_ = url_decode(string_);
  }

  string string::url_decode_copy() const {
    return url_decode(string_);
  }

  string string::url_decode(string str) {
    std::ostringstream ostream;
    for(auto i = 0;i < str.string_.length(); ++i){
      if(i+2 >= str.string_.length())
        ostream << str.string_[i];

      else if(str.string_[i] == '%'){
        std::string test = str.substr(i+1, 2);
        ostream << boost::algorithm::unhex(test);
        i+= 2;
      }else{
          ostream << str.string_[i];
      }
    }
    return ostream.str();
  }


}