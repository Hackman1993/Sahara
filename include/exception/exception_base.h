//
// Created by Hackman.Lo on 4/10/2023.
//

#ifndef LIBSAHARA_EXCEPTION_BASE_H
#define LIBSAHARA_EXCEPTION_BASE_H
#include <string>
#include "../string/string.h"

namespace sahara::exception {
  class exception_base :public std::exception{
  public:
    exception_base(const sahara::string& str_what) : what_(str_what){};

      const char *what() const override {
          return what_.c_str();
      }

  protected:
      std::string what_;
  };
} // sahara::exception

#endif //LIBSAHARA_EXCEPTION_BASE_H
