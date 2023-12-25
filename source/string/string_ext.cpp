//
// Created by Hackman.Lo on 11/3/2023.
//

#include "string/string_ext.h"

#include <iomanip>
#include <sstream>
#include <boost/algorithm/hex.hpp>
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

    bool string_ext::icontains(const std::string_view &s, const std::string_view &find) {
        return boost::algorithm::icontains(s, find);
    }

    std::string string_ext::url_decode(const std::string& str) {
        return url_decode(std::string_view(str.data(), str.length()));
    }

    std::string string_ext::url_decode(const std::string_view str) {
        std::ostringstream ostream;
        for(auto i = 0;i < str.length(); ++i){
            if(i+2 >= str.length()) {
                ostream << str[i];
            }
            else if(str[i] == '%'){
                ostream << boost::algorithm::unhex(std::string(str.substr(i+1, 2)));
                i+= 2;
            }else{
                ostream << str[i];
            }
        }
        return ostream.str();
    }

    std::string string_ext::url_encode(const std::string& str) {
        return url_encode(std::string_view(str.data(), str.length()));
    }

    std::string string_ext::url_encode(const std::string_view str) {
        std::ostringstream encoded;
        encoded.fill('0');
        encoded << std::hex << std::uppercase;

        for (const char c : str) {
            if (std::isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
                encoded << c;
            } else {
                encoded << '%' << std::setw(2) << static_cast<unsigned int>(static_cast<unsigned char>(c));
            }
        }
        return encoded.str();
    }
} // sahara