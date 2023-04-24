//
// Created by Hackman.Lo on 4/17/2023.
//

#ifndef LIBSAHARA_STRING_H
#define LIBSAHARA_STRING_H
#include <string>
#include <fmt/format.h>
#include <fmt/xchar.h>

#include <vector>

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

    bool equals(const string& other) const;
      bool iequals(const string& other) const;
    bool operator==(const string& other) const;
    bool operator==(string&& other) const;

    friend string operator+(const char* lhs, const string& rhs);

    template<typename... Args>
    string& format(std::wstring_view format, Args&&... args) {
      string_ = fmt::vformat(format, fmt::make_wformat_args(args...));
      return *this;
    }
    template<typename... Args>
    string& format(std::string_view format, Args&&... args) {
      operator=(fmt::vformat(format, fmt::make_format_args(args...)));
      return *this;
    }
    template<typename... Args>
    static string static_format(string fmt, Args&&... args) {
      return string().format(fmt.to_std(), args...);
    }
    bool start_with(const string& other) const;
    bool istart_with(const string& other) const;
    std::vector<string> split(const string& delimeter);
    operator std::wstring& ();
    operator std::string ();
    operator std::wstring_view ();
    std::string to_std() const;
    std::wstring& to_wstd();
  protected:
    std::wstring string_;
  };
}
template <>
struct fmt::formatter<sahara::string> {
    constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }

    template <typename FormatContext>
    auto format(const sahara::string& p, FormatContext& ctx) {
        return fmt::format_to(ctx.out(), "{}", p.to_std());
    }
};
#endif //LIBSAHARA_STRING_H
