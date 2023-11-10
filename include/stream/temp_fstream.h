//
// Created by Hackman.Lo on 2023/11/10.
//

#ifndef SAHARA_TEMP_FSTREAM_H
#define SAHARA_TEMP_FSTREAM_H

#include <filesystem>
#include "iostream.h"
namespace sahara::stream {

    class temp_fstream : sahara::stream::iostream{
    public:
        explicit temp_fstream(const std::string& path) : path_(path){};
        explicit temp_fstream(std::filesystem::path path): path_(std::move(path)){};
    protected:
        std::filesystem::path path_;
    };

} // sahara::stream

#endif //SAHARA_TEMP_FSTREAM_H
