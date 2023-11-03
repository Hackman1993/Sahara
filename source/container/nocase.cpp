//
// Created by Hackman.Lo on 11/3/2023.
//

#include "container/nocase.h"


namespace sahara::container {
    std::size_t nocase_hash::operator()(const std::string &key) const {
        return std::hash<std::string>()(sahara::string_ext::to_lower_copy(key));
    }

    bool nocase_equal::operator()(const std::string &left, const std::string &right) const {
        return sahara::string_ext::iequals(left, right);
    }
} // sahara::container