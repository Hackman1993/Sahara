#ifndef LIBSAHARA_TIMESTAMP_H
#define LIBSAHARA_TIMESTAMP_H

#include <chrono>
#include <string>
#include <fmt/format.h>
#include "time_duration.h"
#include "../exception/conversion_exception.h"
#include "../string/string.h"
#include <date/tz.h>
namespace sahara::time {
    class timestamp {
    public:
        timestamp() : timepoint_(std::chrono::system_clock::now()){};

        timestamp(std::chrono::system_clock::time_point timepoint) : timepoint_(timepoint) {}

        static timestamp from_string(const sahara::string &time, const sahara::string &format = "%F %T");

        unsigned int year();
        unsigned int month();
        unsigned int day();
        unsigned int hour();
        unsigned int minute();
        unsigned int second();
        unsigned long microsecond();

        time_duration operator-(const timestamp &other) const;

        timestamp operator+(const std::chrono::system_clock::duration &duration) const;

        timestamp operator+(const time_duration &duration) const;

        timestamp operator-(const std::chrono::system_clock::duration &duration) const;

        timestamp operator-(const time_duration &duration) const;

        timestamp operator+=(const time_duration &duration);

        timestamp operator+=(const std::chrono::system_clock::duration &duration);

        timestamp operator-=(const time_duration &duration);

        timestamp operator-=(const std::chrono::system_clock::duration &duration);
        sahara::string to_string(sahara::string format = "%F %T", const date::time_zone *zone = date::locate_zone("UTC")) ;

    protected:
        static std::chrono::system_clock::time_point parse_time_(const sahara::string &time_str, const sahara::string &format = "%F %T");

        std::chrono::system_clock::time_point timepoint_;
    };
} // sahara::time

namespace std {
    string to_string(sahara::time::timestamp &timestamp);
}
template<>
struct fmt::formatter<sahara::time::timestamp> {
    constexpr auto parse(format_parse_context &ctx) { return ctx.begin(); }

    template<typename FormatContext>
    auto format(const sahara::time::timestamp &p, FormatContext &ctx) { return format_to(ctx.out(), "{}", p.to_string()); }
};

#endif //LIBSAHARA_TIMESTAMP_H
