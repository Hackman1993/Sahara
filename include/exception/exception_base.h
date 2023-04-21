//
// Created by Hackman.Lo on 4/10/2023.
//

#ifndef LIBSAHARA_EXCEPTION_BASE_H
#define LIBSAHARA_EXCEPTION_BASE_H
#include <string>
namespace sahara::exception {
  class exception_base :public std::exception{
  public:
    exception_base(const std::string& str_what) : what_(str_what){};
    [[nodiscard]] const char *what() const override {
      return what_.c_str();
    }

  protected:
    std::string what_;
  };
} // sahara::exception

#endif //LIBSAHARA_EXCEPTION_BASE_H
