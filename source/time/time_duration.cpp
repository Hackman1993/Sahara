//
// Created by Hackman.Lo on 6/14/2023.
//
#include "time/time_duration.h"
namespace sahara::time {
  std::size_t time_duration::to_ms() const {
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration_).count();
  }
}