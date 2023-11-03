//
// Created by Hackman.Lo on 11/3/2023.
//

#ifndef SAHARA_UNORDERED_SMAP_U_H
#define SAHARA_UNORDERED_SMAP_U_H

#include <unordered_map>
#include <string>
#include "nocase.h"
namespace sahara::container {

    template<typename T>
    class unordered_smap_u : public std::unordered_map<std::string, T, nocase_hash, nocase_equal> {};

} // sahara::container

#endif //SAHARA_UNORDERED_SMAP_U_H
