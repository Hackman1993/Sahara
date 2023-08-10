#include "exception/exception_base.h"
#include <format>
namespace sahara::exception{
    std::string exception_base::format_exception(const std::string &what, const std::string &module, const std::string &file, unsigned int line) {
        return std::format("[{}:{}, line {}] {}", module, file,  line, what);
    }
}