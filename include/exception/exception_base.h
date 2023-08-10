//
// Created by Hackman.Lo on 4/10/2023.
//

#ifndef LIBSAHARA_EXCEPTION_BASE_H
#define LIBSAHARA_EXCEPTION_BASE_H

#include <string>
#include "../string/string.h"

namespace sahara::exception {
    class exception_base : public std::exception {
    public:
        exception_base(const std::string &str_what, const std::string &file, unsigned int line, const std::string &module = "sahara") : file_(file), line_(line), module_(module) {
            what_ = std::format("[{}:{}, line {}] {}", module, file, line, str_what);
        };

        std::string_view message() const {
            return what_.c_str();
        }

    protected:
        const char *what() const final {
            return "";
        }
        std::string module_;
        std::string what_;
        std::string file_;
        unsigned int line_ = 0;
    };
} // sahara::exception

#endif //LIBSAHARA_EXCEPTION_BASE_H
