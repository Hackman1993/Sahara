//
// Created by Hackman.Lo on 2023/11/10.
//
#include "stream/string_stream.h"

namespace sahara::stream {
    bool string_stream::eof() {
        return str_.eof();
    }

    uint64_t string_stream::read(unsigned char *buf, std::uint64_t size) {
        str_.read((char*)buf, (std::streamsize)size);
        return str_.gcount();
    }

    uint64_t string_stream::write(unsigned char *data, std::uint64_t size) {
        auto p1 = str_.tellp();
        str_.write((char*)data, (std::streamsize)size);
        return str_.tellp() - p1;
    }


} // sahara::stream