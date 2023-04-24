//
// Created by Hackman.Lo on 4/11/2023.
//

#ifndef LIBSAHARA_URL_H
#define LIBSAHARA_URL_H
#include <string>
namespace sahara::coder {
    sahara::string url_encode(const sahara::string& str);
    sahara::string url_decode(const sahara::string& str);
} // sahara::coder

#endif //LIBSAHARA_URL_H
