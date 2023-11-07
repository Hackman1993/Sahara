//
// Created by Hackman.Lo on 11/3/2023.
//

#include "string/string_ext.h"
#include <boost/algorithm/string.hpp>
namespace sahara {
    void string_ext::to_upper(std::string &str) {
        boost::algorithm::to_upper(str);
    }

    std::string string_ext::to_upper_copy(const std::string &str) {
        return boost::algorithm::to_upper_copy(str);
    }

    void string_ext::to_lower(std::string &str) {
        boost::algorithm::to_lower(str);
    }

    std::string string_ext::to_lower_copy(const std::string &str) {
        return boost::algorithm::to_lower_copy(str);
    }

    bool string_ext::iequals(const std::string &s1, const std::string &s2) {
        return boost::algorithm::iequals(s1, s2);
    }

    bool string_ext::icontains(const std::string &s, const std::string &find) {
        return boost::algorithm::icontains(s, find);
    }
} // sahara