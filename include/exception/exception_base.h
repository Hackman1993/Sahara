//
// Created by Hackman.Lo on 4/10/2023.
//

#ifndef LIBSAHARA_EXCEPTION_BASE_H
#define LIBSAHARA_EXCEPTION_BASE_H

#include <string>
#include <exception>

namespace sahara::exception {
    class exception_base : public std::exception {
    public:
        exception_base(const std::string& message) : std::exception(message.c_str()) {};
        static std::string format_exception(const std::string& what, const std::string& module, const std::string& file, unsigned int line);
    };
} // sahara::exception

#define THROW(type, module, what, ...) throw type(sahara::exception::exception_base::format_exception(what, module, __FILE__, __LINE__).c_str(), __VA_ARGS__)

#endif //LIBSAHARA_EXCEPTION_BASE_H
