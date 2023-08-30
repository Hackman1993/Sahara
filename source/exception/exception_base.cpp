#include "exception/exception_base.h"
#include <fmt/format.h>

namespace sahara::exception{
    std::string exception_base::format_exception(const std::string &what, const std::string &module, const std::string &file, unsigned int line) {
        return fmt::format("[{}:{}, line {}] {}", module, file,  line, what);
    }

    const char *exception_base::what() const noexcept {
        return message_;
    }
}