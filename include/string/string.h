//
// Created by Hackman.Lo on 4/17/2023.
//

#ifndef LIBSAHARA_STRING_H
#define LIBSAHARA_STRING_H

#include <string>
#include <fmt/format.h>
#include <fmt/xchar.h>

#include <vector>

namespace sahara {
  class string {
  public:
    string() = default;
    string(const char *other);
    string(const string &other);
    string(std::string_view other);
    string(string &&other) noexcept;
    string(const std::string &other);

    operator std::string &();
    operator std::string_view();
    string &operator=(const string &other);
    string &operator=(const std::string& other);
    bool operator==(string &&other) const;
    string operator+(const char *other) const;
    bool operator==(const string &other) const;

    friend string operator+(const char *lhs, const string &rhs);


    static string make_from(std::uint64_t value);
    bool empty() const;
    bool equals(const string &other) const;
    bool iequals(const string &other) const;
    string substr(std::size_t pos = 0, std::size_t len = std::string::npos) const;

    template<typename... Args>
    string &format(std::string_view format, Args &&... args) {
      operator=(fmt::vformat(format, fmt::make_format_args(args...)));
      return *this;
    }

    template<typename... Args>
    static string static_format(string fmt, Args &&... args) {
      return string().format(fmt.to_std(), args...);
    }

    std::size_t size() const noexcept;

    bool contains(const string &other) const;

    bool icontains(const string &other) const;

    bool start_with(const string &other) const;

    bool istart_with(const string &other) const;

    bool ends_with(const string &other) const;

    bool iends_with(const string &other) const;

    std::size_t find_first(const string &other) const;

    std::size_t ifind_first(const string &other) const;

    std::vector<string> split(const string &delimeter, bool token_compress = true, bool drop_empty = true) const;



    std::string to_std() const;
    void url_encode();
    string url_encode_copy() const;
    static string url_encode(string str);

    void url_decode();
    string url_decode_copy() const;
    static string url_decode(string str);

  protected:
    std::string string_;
  };
}
template<>
struct fmt::formatter<sahara::string> {
  constexpr auto parse(format_parse_context &ctx) { return ctx.begin(); }

  template<typename FormatContext>
  auto format(const sahara::string &p, FormatContext &ctx) {
    return fmt::format_to(ctx.out(), "{}", p.to_std());
  }
};

namespace std {
  template<>
  struct hash<sahara::string> {
    std::size_t operator()(const sahara::string &str) const noexcept {
      return std::hash<std::string>()(str.to_std());
    }
  };
}
#endif //LIBSAHARA_STRING_H
