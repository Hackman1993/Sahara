#ifndef LIBSAHARA_TIMESTAMP_H
#define LIBSAHARA_TIMESTAMP_H

#include <chrono>
#include <string>
#include <fmt/format.h>
#include "time_duration.h"
#include "../exception/conversion_exception.h"
#include "../string/string.h"

namespace sahara::time {
    class timestamp {
    public:
        timestamp() : timepoint_(std::chrono::system_clock::now()) {}

        timestamp(std::chrono::system_clock::time_point timepoint) : timepoint_(timepoint) {}

        static timestamp from_string(const sahara::string &time, const sahara::string &format = "%Y-%m-%d %H:%M:%S");

        time_duration operator-(const timestamp &other) const;

        timestamp operator+(const std::chrono::system_clock::duration &duration) const;

        timestamp operator+(const time_duration &duration) const;

        timestamp operator-(const std::chrono::system_clock::duration &duration) const;

        timestamp operator-(const time_duration &duration) const;

        timestamp operator+=(const time_duration &duration);

        timestamp operator+=(const std::chrono::system_clock::duration &duration);

        timestamp operator-=(const time_duration &duration);

        timestamp operator-=(const std::chrono::system_clock::duration &duration);

        operator std::string() const;
        sahara::string to_string(const sahara::string &format = "%Y-%m-%d %H:%M:%S") const;

    protected:
        static std::chrono::system_clock::time_point parse_time_(const sahara::string &time_str, const sahara::string &format = "%Y-%m-%d %H:%M:%S");

        std::chrono::system_clock::time_point timepoint_;
    };
} // sahara::time

template<>
struct fmt::formatter<sahara::time::timestamp> {
    constexpr auto parse(format_parse_context &ctx) { return ctx.begin(); }

    template<typename FormatContext>
    auto format(const sahara::time::timestamp &p, FormatContext &ctx) { return format_to(ctx.out(), "{}", p.to_string()); }
};

#endif //LIBSAHARA_TIMESTAMP_H
