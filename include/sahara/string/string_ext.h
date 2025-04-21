//
// Created by Hackman.Lo on 11/3/2023.
//

#ifndef SAHARA_STRING_EXT_H
#define SAHARA_STRING_EXT_H
#include <chrono>
#include <string>
namespace sahara {
    class string_ext{
    public:
        static void to_upper(std::string& str);
        static std::string to_upper_copy(const std::string& str);
        static void to_lower(std::string& str);
        static std::string to_lower_copy(const std::string& str);
        static bool iequals(const std::string& s1, const std::string& s2);

        static bool icontains(const std::string& s, const std::string &find);
        static bool icontains(const std::string_view& s, const std::string_view& find);

        static std::string url_decode(const std::string& str);
        static std::string url_decode(std::string_view str);
        static std::string url_encode(const std::string& str);
        static std::string url_encode(std::string_view str);

        static std::string time_format(const std::chrono::system_clock::time_point& tp, const std::string& format);
    };

} // sahara::string

#endif //SAHARA_STRING_EXT_H
