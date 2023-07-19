//
// Created by Hackman.Lo on 4/10/2023.
//

#include "../../include/time/timestamp.h"
#include "../../include/string/string.h"
#include <iomanip>
#include <sstream>
#include <date/date.h>
#include <date/tz.h>

namespace sahara::time {
    timestamp timestamp::from_string(const sahara::string &time, const sahara::string &format) {
        return timestamp{parse_time_(time, format)};
    }

    time_duration timestamp::operator-(const timestamp &other) const {
        return time_duration(timepoint_ - other.timepoint_);
    }

    timestamp timestamp::operator+(const std::chrono::system_clock::duration &duration) const {
        return timestamp(timepoint_ + duration);
    }

    timestamp timestamp::operator+(const time_duration &duration) const {
        return timestamp(timepoint_ + duration.duration_);
    }

    timestamp timestamp::operator-(const std::chrono::system_clock::duration &duration) const {
        return timestamp(timepoint_ - duration);
    }

    timestamp timestamp::operator-(const time_duration &duration) const {
        return timestamp(timepoint_ - duration.duration_);
    }

    timestamp timestamp::operator+=(const time_duration &duration) {
        timepoint_ += duration.duration_;
        return *this;
    }

    timestamp timestamp::operator+=(const std::chrono::system_clock::duration &duration) {
        timepoint_ += duration;
        return *this;
    }

    timestamp timestamp::operator-=(const time_duration &duration) {
        timepoint_ -= duration.duration_;
        return *this;
    }

    timestamp timestamp::operator-=(const std::chrono::system_clock::duration &duration) {
        timepoint_ -= duration;
        return *this;
    }

    sahara::string timestamp::to_string(sahara::string format) {
        date::make_zoned(date::current_zone(), timepoint_);
        std::string result = date::format(format.std_ref(), timepoint_);
//    std::stringstream ss;
//    ss << std::put_time(std::localtime(&time), format.to_std().c_str());
        return result;
    }

#include <stdio.h>
#include <time.h>

    std::chrono::system_clock::time_point timestamp::parse_time_(const sahara::string &time_str, const sahara::string &format) {
        struct timespec ts;
        timespec_get(&ts, TIME_UTC);
        std::istringstream ss(time_str.to_std());
        std::tm tm_time{};
        ss >> std::get_time(&tm_time, format.to_std().c_str());
        if (ss.fail()) {
            throw exception::conversion_exception("Failed to parse time string.");
        }
        return std::chrono::system_clock::from_time_t(std::mktime(&tm_time));
    }

    unsigned int timestamp::year() {
        auto time = std::chrono::system_clock::to_time_t(timepoint_);
        tm *tm = gmtime(&time);
        return tm->tm_year + 1900;
    }

    unsigned int timestamp::month() {
        auto time = std::chrono::system_clock::to_time_t(timepoint_);
        tm *tm = gmtime(&time);
        return tm->tm_mon + 1;
    }

    unsigned int timestamp::day() {
        auto time = std::chrono::system_clock::to_time_t(timepoint_);
        tm *tm = gmtime(&time);
        return tm->tm_mday;
    }

    unsigned int timestamp::hour() {
        auto time = std::chrono::system_clock::to_time_t(timepoint_);
        tm *tm = gmtime(&time);
        return tm->tm_hour;
    }

    unsigned int timestamp::minute() {
        auto time = std::chrono::system_clock::to_time_t(timepoint_);
        tm *tm = gmtime(&time);
        return tm->tm_min;
    }

    unsigned int timestamp::second() {
        auto time = std::chrono::system_clock::to_time_t(timepoint_);
        tm *tm = gmtime(&time);
        return tm->tm_sec;
    }

    unsigned long timestamp::microsecond() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(timepoint_.time_since_epoch()).count();
    }

    timestamp::timestamp(const date::time_zone *zone) {
        date::make_zoned(zone, timepoint_);
    }} // sahara::time



namespace std {
    string to_string(sahara::time::timestamp &timestamp) {
        return timestamp.to_string().to_std();
    }
}