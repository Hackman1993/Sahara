//
// Created by Hackman.Lo on 4/10/2023.
//

#ifndef LIBSAHARA_DATABASE_EXCEPTION_H
#define LIBSAHARA_DATABASE_EXCEPTION_H
#include "exception_base.h"
namespace sahara::exception{
    class database_exception : public exception_base{
    public:
      database_exception(std::size_t code, const sahara::string& message): exception_base(message), code_(code){}
    protected:
      std::size_t code_ = 0;
    };
} // sahara::exception

#endif //LIBSAHARA_DATABASE_EXCEPTION_H
