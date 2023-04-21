//
// Created by Hackman.Lo on 4/11/2023.
//

#ifndef LIBSAHARA_URL_H
#define LIBSAHARA_URL_H
#include <string>
namespace sahara::coder {
  std::string url_encode(const std::string& str);
  std::string url_decode(const std::string& str);
} // sahara::coder

#endif //LIBSAHARA_URL_H
