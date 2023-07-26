//
// Created by Hackman.Lo on 7/26/2023.
//
#include "log/log.h"
namespace sahara{
    std::shared_ptr<spdlog::logger> log::logger_ = spdlog::stdout_color_mt("console");
    void log::set_level(spdlog::level::level_enum level) {
        spdlog::set_level(level);
    }

    void log::set_level(const std::string &mod, spdlog::level::level_enum level) {
        auto logger = spdlog::get(mod);
        if(!logger)
        {
            logger = spdlog::stdout_color_mt(mod);
        }
        logger->set_level(level);
    }

    void log::initialize() {
        spdlog::set_default_logger(logger_);
        set_level(spdlog::level::trace);
    }
}