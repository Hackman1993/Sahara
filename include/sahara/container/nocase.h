//
// Created by Hackman.Lo on 11/3/2023.
//

#ifndef SAHARA_NOCASE_H
#define SAHARA_NOCASE_H
#include <string>
#include <algorithm>
#include "../string/string_ext.h"
namespace sahara::container {

    struct nocase_hash {
        std::size_t operator()(const std::string& key) const;
    };

    struct nocase_equal {
        bool operator()(const std::string& left, const std::string& right) const;
    };


} // sahara::container

#endif //SAHARA_NOCASE_H
