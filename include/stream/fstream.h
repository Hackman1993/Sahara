//
// Created by Hackman.Lo on 2023/11/13.
//

#ifndef SAHARA_FSTREAM_H
#define SAHARA_FSTREAM_H

#include <fstream>
#include <filesystem>

namespace sahara::stream {

    class fstream : public std::fstream {
    public:
        template<typename ...Args>
        fstream(std::filesystem::path path, Args... args): std::fstream(path,std::forward<Args>(args)...), path_(std::move(path)){}
        std::filesystem::path path() { return path_; };
    private:
        std::filesystem::path path_;
    };

} // sahara::stream

#endif //SAHARA_FSTREAM_H
