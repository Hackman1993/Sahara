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
        static void set_level(spdlog::level::level_enum level);
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

        template<typename... Args>
        static void critical(format_string_t<Args...> fmt, Args &&... args)
        {
            spdlog::log(spdlog::level::critical, fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        static void error(format_string_t<Args...> fmt, Args &&... args)
        {
            spdlog::log(spdlog::level::err, fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        static void info(format_string_t<Args...> fmt, Args &&... args)
        {
            spdlog::log(spdlog::level::info, fmt, std::forward<Args>(args)...);
        }
        template<typename... Args>
        static void trace(format_string_t<Args...> fmt, Args &&... args)
        {
            spdlog::log(spdlog::level::trace, fmt, std::forward<Args>(args)...);
        }
        template<typename... Args>
        static void warn(format_string_t<Args...> fmt, Args &&... args)
        {
            spdlog::log(spdlog::level::warn, fmt, std::forward<Args>(args)...);
        }
    };

#define LOG_DEBUG(fmt, ...) sahara::log::debug(fmt " [file:{}]" , __VA_ARGS__, __FILE__);
#define LOG_CRITICAL(fmt, ...) sahara::log::critical(fmt " [file:{}]" , __VA_ARGS__, __FILE__);
#define LOG_ERROR(fmt, ...) sahara::log::error(fmt " [file:{}]" , __VA_ARGS__, __FILE__);
#define LOG_INFO(fmt, ...) sahara::log::info(fmt " [file:{}]" , __VA_ARGS__, __FILE__);
#define LOG_TRACE(fmt, ...) sahara::log::trace(fmt " [file:{}]" , __VA_ARGS__, __FILE__);
#define LOG_WARN(fmt, ...) sahara::log::warn(fmt " [file:{}]" , __VA_ARGS__, __FILE__);
} // sahara

#endif //SAHARA_LOG_H
