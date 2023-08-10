//
// Created by Hackman.Lo on 8/10/2023.
//

#ifndef SAHARA_EXCEPTION_H
#define SAHARA_EXCEPTION_H
#include "conversion_exception.h"
#include "database_exception.h"
#define THROW(type, module, what, ...) throw type(sahara::exception::exception_base::format_exception(what, module, __FILE__, __LINE__).c_str(), __VA_ARGS__)
#endif //SAHARA_EXCEPTION_H
