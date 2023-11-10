//
// Created by Hackman.Lo on 11/8/2023.
//

#ifndef SAHARA_BASIC_OSTREAM_H
#define SAHARA_BASIC_OSTREAM_H

#include <cstdint>

namespace sahara::stream {

    class basic_ostream {
    public:
        virtual std::uint64_t write(unsigned char* data, std::uint64_t size) = 0;
        virtual ~basic_ostream() = default;
    };

} // sahara::ostream

#endif //SAHARA_BASIC_OSTREAM_H
