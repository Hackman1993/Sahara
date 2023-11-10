//
// Created by Hackman.Lo on 2023/11/10.
//

#ifndef SAHARA_STRING_STREAM_H
#define SAHARA_STRING_STREAM_H


#include <sstream>
#include "iostream.h"

namespace sahara::stream {

    class string_stream : public iostream{
    public:
        explicit string_stream(std::stringstream ss) : str_(std::move(ss)){}

        bool eof() override;

        uint64_t read(unsigned char *buf, std::uint64_t size) override;

        uint64_t write(unsigned char *data, std::uint64_t size) override;

    private:
        std::stringstream str_;
    };

} // sahara::stream

#endif //SAHARA_STRING_STREAM_H
