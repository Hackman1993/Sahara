//
// Created by Hackman.Lo on 7/25/2023.
//

#include "log/log.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/daily_file_sink.h>
namespace sahara {
    void log::add_sink(const std::shared_ptr<spdlog::sinks::sink>& sink) {
        spdlog::default_logger()->sinks().push_back(sink);
    }

    void log::add_logger(const std::shared_ptr<spdlog::logger> &logger) {
        spdlog::register_logger(logger);
    }

    void log::set_level(spdlog::level::level_enum level) {
        spdlog::set_level(level);
    }
} // sahara