//
// Created by Hackman.Lo on 7/24/2023.
//

#ifndef SAHARA_LOG_H
#define SAHARA_LOG_H

#include <boost/log/common.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/attributes/named_scope.hpp>

namespace sahara::log {

    class log {
        enum LoggerType {
            console = 0, file,
        };
        typedef boost::log::sinks::synchronous_sink<boost::log::sinks::text_file_backend> file_sink;

        log() {}

        ~log() {}

        static log &instance();

        static bool init(std::string fileName, int type, int level, int maxFileSize, int maxBackupIndex);

        boost::log::sources::severity_logger<boost::log::trivial::severity_level> _logger;

    };
} // log
#define LOG_TRACE(logEvent)  BOOST_LOG_FUNCTION(); BOOST_LOG_SEV(sahara::log::instance()._logger, boost::log::trivial::trace) << logEvent;
#define LOG_DEBUG(logEvent)  BOOST_LOG_FUNCTION(); BOOST_LOG_SEV(sahara::log::instance()._logger, boost::log::trivial::debug) << logEvent;
#define LOG_INFO(logEvent)   BOOST_LOG_FUNCTION(); BOOST_LOG_SEV(sahara::log::instance()._logger, boost::log::trivial::info) << logEvent;
#define LOG_WARN(logEvent)   BOOST_LOG_FUNCTION(); BOOST_LOG_SEV(sahara::log::instance()._logger, boost::log::trivial::warning) << logEvent;
#define LOG_ERROR(logEvent)  BOOST_LOG_FUNCTION(); BOOST_LOG_SEV(sahara::log::instance()._logger, boost::log::trivial::error) << logEvent;
#define LOG_FATAL(logEvent)  BOOST_LOG_FUNCTION(); BOOST_LOG_SEV(sahara::log::instance()._logger, boost::log::trivial::fatal) << logEvent;
#endif //SAHARA_LOG_H
