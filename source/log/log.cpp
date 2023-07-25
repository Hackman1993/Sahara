#include "log/log.h"
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/support/date_time.hpp>

namespace sahara::log {
    log &log::instance() {
        static log instance;
        return instance;
    }

    bool log::init(std::string fileName, int type, int level, int maxFileSize, int maxBackupIndex) {
        boost::log::formatter formatter = boost::log::expressions::stream
                << "[" << boost::log::expressions::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S.%f")
                << "|" << boost::log::expressions::attr<boost::log::attributes::current_thread_id::value_type>("ThreadID") << "]["
                << boost::log::expressions::attr<boost::log::trivial::severity_level>("Severity") << "]" << boost::log::expressions::smessage
                << "    " << boost::log::expressions::format_named_scope("Scope", boost::log::keywords::format = "(%f:%l)",
                boost::log::keywords::iteration = boost::log::expressions::reverse, boost::log::keywords::depth = 1);

        if(type == LoggerType::file) {
            boost::shared_ptr<file_sink> sink(new file_sink(
                    boost::log::keywords::file_name = fileName,
                    boost::log::keywords::target_file_name = "%Y%m%d_%H%M%S_%5N.log",
                    boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
                    boost::log::keywords::rotation_size = maxFileSize * 1024 * 1024,
                    boost::log::keywords::open_mode = std::ios::out | std::ios::app
                    ));
            sink->locked_backend()->set_file_collector(boost::log::sinks::file::make_collector(
                    boost::log::keywords::target = "logs",
                    boost::log::keywords::max_size = maxFileSize* maxBackupIndex * 1024 * 1024,
                    boost::log::keywords::min_free_space = 30 * 1024 * 1024,
                    boost::log::keywords::max_files = 512));
            sink->set_formatter(formatter);
            sink->locked_backend()->scan_for_files();
            sink->locked_backend()->auto_flush();
            boost::log::core::get()->add_sink(sink);
        } else{
            auto sink = boost::log::add_console_log();
            sink->set_formatter(formatter);
            boost::log::core::get()->add_sink(sink);
        }

        boost::log::add_common_attributes();
        boost::log::core::get()->add_global_attribute("Scope", boost::log::attributes::named_scope());
        boost::log::core::get()->set_filter(boost::log::trivial::severity >= level);
        return true;
    }
}