//
// Created by Hackman.Lo on 6/14/2023.
//

#include "../../include/utils/uuid.h"
#include "boost/uuid/uuid_io.hpp"
#include "boost/uuid/random_generator.hpp"

namespace sahara::utils {
  std::string uuid::generate() {
    return to_string(boost::uuids::random_generator()());
  }
} // utils