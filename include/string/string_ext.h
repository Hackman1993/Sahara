//
// Created by Hackman.Lo on 11/3/2023.
//

#ifndef SAHARA_STRING_EXT_H
#define SAHARA_STRING_EXT_H
#include <string>
namespace sahara {
    class string_ext{
    public:
        static void to_upper(std::string& str);
        static std::string to_upper_copy(const std::string& str);
        static void to_lower(std::string& str);
        static std::string to_lower_copy(const std::string& str);
        static bool iequals(const std::string& s1, const std::string& s2);
    };

} // sahara::string

#endif //SAHARA_STRING_EXT_H
