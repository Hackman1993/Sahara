//
// Created by Hackman.Lo on 2023/11/10.
//

#ifndef SAHARA_TEMP_FSTREAM_H
#define SAHARA_TEMP_FSTREAM_H

#include "fstream.h"
namespace sahara::stream {
    class temp_fstream : public fstream{
    public:
        template<typename ...Args>
        temp_fstream(std::filesystem::path path, Args... args): fstream(path,std::forward<Args>(args)...){}

        virtual ~temp_fstream(){
            if(std::filesystem::is_regular_file(path())){
                std::filesystem::remove(path());
            }
        }


    };

} // sahara::stream

#endif //SAHARA_TEMP_FSTREAM_H
