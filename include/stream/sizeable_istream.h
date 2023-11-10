//
// Created by Hackman.Lo on 2023/11/9.
//

#ifndef SAHARA_SIZEABLE_ISTREAM_H
#define SAHARA_SIZEABLE_ISTREAM_H

#include <ios>
#include "basic_istream.h"
namespace sahara::stream {

    class sizeable_istream : public basic_istream{
    public:
        virtual std::uint64_t size() = 0;

    };

} // sahara::stream

#endif //SAHARA_SIZEABLE_ISTREAM_H
