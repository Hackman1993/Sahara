//
// Created by Hackman.Lo on 2023/11/9.
//

#ifndef SAHARA_MULTIPART_ISTREAM_H
#define SAHARA_MULTIPART_ISTREAM_H

#include "sizeable_istream.h"
#include <type_traits>

namespace sahara::stream {

class multipart_istream : public sahara::stream::sizeable_istream {
    public:
        std::uint64_t size() override{
            std::streamsize s = 0;
            for(auto &i : ptrs_){
                s += i->size();
            }
            return s;
        };

    bool eof() override {
        return std::ranges::all_of(ptrs_.begin(), ptrs_.begin(), [](std::shared_ptr<sizeable_istream>& s){ return s->eof();});
    }

    std::uint64_t read(unsigned char* buffer, std::uint64_t size) override{
            std::uint64_t buffer_remains = size;
            for(auto &stream: ptrs_){
                if(buffer_remains == 0)
                    return size;
                if(stream->eof())
                    continue;
                buffer_remains -= stream->read(&buffer[size - buffer_remains], buffer_remains);
            }
            return size - buffer_remains;

        }
    private:
        std::vector<std::shared_ptr<sizeable_istream>> ptrs_;

    };

} // sahara:stream

#endif //SAHARA_MULTIPART_ISTREAM_H
