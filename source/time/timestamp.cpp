//
// Created by Hackman.Lo on 4/10/2023.
//

#include "time/timestamp.h"

namespace sahara::time {
  timestamp timestamp::from_string(const std::string& time, const std::string& format){
    return timestamp{parse_time_(time, format)};
  }

  time_duration timestamp::operator-(const timestamp &other) const {
    return time_duration(timepoint_ - other.timepoint_);
  }

  timestamp timestamp::operator+(const std::chrono::system_clock::duration &duration) const  {
    return timestamp(timepoint_ + duration);
  }

  timestamp timestamp::operator+(const time_duration &duration) const  {
    return timestamp(timepoint_ + duration.duration_);
  }

  timestamp timestamp::operator-(const std::chrono::system_clock::duration &duration) const {
    return timestamp(timepoint_ - duration);
  }

  timestamp timestamp::operator-(const time_duration &duration) const  {
    return timestamp(timepoint_ - duration.duration_);
  }

  timestamp timestamp::operator+=(const time_duration &duration)  {
    timepoint_ += duration.duration_;
    return *this;
  }

  timestamp timestamp::operator+=(const std::chrono::system_clock::duration &duration)  {
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

  std::string timestamp::to_string(const std::string &format) const  {
    std::time_t time = std::chrono::system_clock::to_time_t(timepoint_);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time), format.c_str());
    return ss.str();
  }

  std::chrono::system_clock::time_point timestamp::parse_time_(const std::string &time_str, const std::string &format) {
    std::istringstream ss(time_str);
    std::tm tm_time{};
    ss >> std::get_time(&tm_time, format.c_str());
    if(ss.fail()){
      throw exception::conversion_exception("Failed to parse time string.");
    }
    return std::chrono::system_clock::from_time_t(std::mktime(&tm_time));
  }
} // sahara::time