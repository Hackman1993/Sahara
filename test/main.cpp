//
// Created by Hackman.Lo on 7/25/2023.
//
#include "include/exception/database_exception.h"
#include "include/exception/conversion_exception.h"
#include "include/container/unordered_smap_u.h"
#include <iostream>
#include "include/stream/multipart_istream.h"
int main(){
    try{
        sahara::stream::multipart_istream stream;
        stream.size();

    }catch (sahara::exception::exception_base& e){
        std::cout << e.what() << std::endl;
    }
}