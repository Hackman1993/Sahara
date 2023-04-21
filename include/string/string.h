//
// Created by Hackman.Lo on 4/17/2023.
//

#ifndef LIBSAHARA_STRING_H
#define LIBSAHARA_STRING_H
#include <string>
#include <cstdarg>
#include <format>
#include <vector>
#include <codecvt>
#include <format>
#include <iostream>

namespace sahara{
  class string{
  public:
    string() = default;
    string(const std::string& other) ;
    string(const std::wstring& other) ;
    string(const char* other) ;
    string(const wchar_t* other) ;
    string(const string& other);
    string(string&& other) noexcept;
    string(std::wstring_view other);
    string(std::string_view other);
    string& operator=(const string& other);
    string& operator=(std::string other);

    bool compare(const string& other) const;
    bool operator==(const string& other) const;
    bool operator==(string&& other) const;

    template<typename... Args>
    string& format(std::wstring_view format, Args&&... args) {
      string_ = std::vformat(format, std::make_wformat_args(args...));
      return *this;
    }
    template<typename... Args>
    string& format(std::string_view format, Args&&... args) {
      operator=(std::vformat(format, std::make_format_args(args...)));
      return *this;
    }
    std::vector<string> split(const string& delimeter);
  protected:
    std::wstring string_;
  };
}

#endif //LIBSAHARA_STRING_H
