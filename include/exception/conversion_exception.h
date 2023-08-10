//
// Created by Hackman.Lo on 4/10/2023.
//

#ifndef LIBSAHARA_CONVERSION_EXCEPTION_H
#define LIBSAHARA_CONVERSION_EXCEPTION_H

#include "exception_base.h"

namespace sahara::exception {

  class conversion_exception : exception_base{
  public:
    explicit conversion_exception(const std::string& message, const std::string &file, unsigned int line): exception_base(message, file, line){}
  };
} // sahara::exception

#endif //LIBSAHARA_CONVERSION_EXCEPTION_H
