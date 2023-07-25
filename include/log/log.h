//
// Created by Hackman.Lo on 7/25/2023.
//

#ifndef SAHARA_LOG_H
#define SAHARA_LOG_H

#include <spdlog/sinks/sink.h>
#include <spdlog/logger.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
namespace sahara {

    template<typename... Args>
    using format_string_t = fmt::format_string<Args...>;

    class log {
    public:
        static void set_level(spdlog::level::level_enum level){
            spdlog::set_level(level);
        };
        static void set_level(const std::string& mod, spdlog::level::level_enum level){
            auto logger = spdlog::get(mod);
            if(!logger)
            {
                logger = spdlog::stdout_color_mt(mod);
            }
            logger->set_level(level);
        };
        static void add_logger(const std::shared_ptr<spdlog::logger>& logger){
            spdlog::register_logger(logger);
        };
        static void add_sink(const std::string& mod, const std::shared_ptr<spdlog::sinks::sink>& sink){
            auto logger = spdlog::get(mod);
            if(logger) logger->sinks().push_back(sink);
        };
        static void add_sink(const std::shared_ptr<spdlog::sinks::sink>& sink){
            spdlog::default_logger()->sinks().push_back(sink);
        };

        template<typename... Args>
        static void write(spdlog::level::level_enum level, format_string_t<Args...> fmt, Args &&... args) {
            spdlog::log(level, fmt, std::forward<Args>(args)...);
        }

        template<typename... Args>
        static void write(const std::string& mod, spdlog::level::level_enum level, format_string_t<Args...> fmt, Args &&... args) {
            auto logger = spdlog::get(mod);
            if(!logger)
            {
                logger = spdlog::stdout_color_mt(mod);
            }
            logger->log(level, fmt, std::forward<Args>(args)...);
        }
    };

#define LOG_DEBUG(fmt, ...) sahara::log::write(spdlog::level::debug, fmt " [file:{}]", __VA_ARGS__ , __FILE__);
#define LOG_CRITICAL(fmt, ...) sahara::log::write(spdlog::level::critical, fmt " [file:{}]", __VA_ARGS__ , __FILE__);
#define LOG_ERROR(fmt, ...) sahara::log::write(spdlog::level::err, fmt " [file:{}]", __VA_ARGS__ , __FILE__);
#define LOG_INFO(fmt, ...) sahara::log::write(spdlog::level::info, fmt " [file:{}]", __VA_ARGS__ , __FILE__);
#define LOG_TRACE(fmt, ...) sahara::log::write(spdlog::level::trace, fmt " [file:{}]", __VA_ARGS__ , __FILE__);
#define LOG_WARN(fmt, ...) sahara::log::write(spdlog::level::warn, fmt " [file:{}]", __VA_ARGS__ , __FILE__);

#define LOG_MODULE_DEBUG(module, fmt, ...) sahara::log::write(module, spdlog::level::debug, fmt " [file:{}]", __VA_ARGS__ , __FILE__);
#define LOG_MODULE_CRITICAL(module, fmt, ...) sahara::log::write(module, spdlog::level::critical, fmt " [file:{}]", __VA_ARGS__ , __FILE__);
#define LOG_MODULE_ERROR(module, fmt, ...) sahara::log::write(module, spdlog::level::err, fmt " [file:{}]", __VA_ARGS__ , __FILE__);
#define LOG_MODULE_INFO(module, fmt, ...) sahara::log::write(module, spdlog::level::info, fmt " [file:{}]", __VA_ARGS__ , __FILE__);
#define LOG_MODULE_TRACE(module, fmt, ...) sahara::log::write(module, spdlog::level::trace, fmt " [file:{}]", __VA_ARGS__ , __FILE__);
#define LOG_MODULE_WARN(module, fmt, ...) sahara::log::write(module, spdlog::level::warn, fmt " [file:{}]", __VA_ARGS__ , __FILE__);
} // sahara

#endif //SAHARA_LOG_H
