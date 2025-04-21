//
// Created by Hackman.Lo on 4/10/2023.
//

#ifndef LIBSAHARA_TIME_DURATION_H
#define LIBSAHARA_TIME_DURATION_H
#include <chrono>
namespace sahara::time {
  class timestamp;
  class time_duration {
  public:
    explicit time_duration(const std::chrono::system_clock::duration& duration): duration_(duration){}
    time_duration(const std::chrono::seconds & duration): duration_(duration){}
    std::size_t to_ms() const;


  protected:
    std::chrono::system_clock::duration duration_;
    friend timestamp;
  };


} // sahara::time

#endif //LIBSAHARA_TIME_DURATION_H
