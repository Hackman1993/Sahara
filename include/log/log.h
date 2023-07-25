//
// Created by Hackman.Lo on 7/25/2023.
//

#ifndef SAHARA_LOG_H
#define SAHARA_LOG_H

#include <spdlog/sinks/sink.h>
#include <spdlog/logger.h>
#include <spdlog/spdlog.h>

namespace sahara {

    template<typename... Args>
    using format_string_t = fmt::format_string<Args...>;

    class log {
    public:
        static void add_logger(const std::shared_ptr<spdlog::logger>& logger);
        static void add_sink(const std::shared_ptr<spdlog::sinks::sink>& sink);
        template<typename... Args>
        static void debug(format_string_t<Args...> fmt, Args &&... args)
        {
            spdlog::log(spdlog::level::debug, fmt, std::forward<Args>(args)...);
        }

        template<typename T>
        static void debug(const T &msg)
        {
            spdlog::log(spdlog::level::debug, msg);
        }
    };

#define LOG_DEBUG(fmt, ...) log::debug(fmt, __VA_ARGS__);
} // sahara

#endif //SAHARA_LOG_H
