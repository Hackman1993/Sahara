//
// Created by Hackman.Lo on 11/8/2023.
//

#ifndef SAHARA_BASIC_ISTREAM_H
#define SAHARA_BASIC_ISTREAM_H
#include <cstdint>

namespace sahara::stream {

    class basic_istream {
    public:
        virtual bool eof() = 0;
        virtual std::uint64_t read(unsigned char* buf, std::uint64_t size) = 0;
        virtual ~basic_istream() = default;
    };

} // sahara::stream

#endif //SAHARA_BASIC_ISTREAM_H
