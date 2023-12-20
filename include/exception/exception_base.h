//
// Created by Hackman.Lo on 4/10/2023.
//

#ifndef LIBSAHARA_EXCEPTION_BASE_H
#define LIBSAHARA_EXCEPTION_BASE_H

#include <string>
#include <cstring>
#include <exception>

namespace sahara::exception {
    class exception_base : public std::exception {
    public:
        exception_base(const std::string&message) {
            message_ = new char [message.size() + 1];
            memset(message_, 0, message.size() + 1);
            memcpy(message_, message.data(), message.size());
        };

        const char* what() const noexcept override;

        static std::string format_exception(const std::string&what, const std::string&module, const std::string&file,
                                            unsigned int line);

        ~exception_base() {
            if (message_)
                delete []message_;
        }

    protected:
        char* message_ = nullptr;
    };
} // sahara::exception

#define THROW(type,what, module, ...) throw type(sahara::exception::exception_base::format_exception(what, module, __FILE__, __LINE__).c_str(), ##__VA_ARGS__)

#endif //LIBSAHARA_EXCEPTION_BASE_H
