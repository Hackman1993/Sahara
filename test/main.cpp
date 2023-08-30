//
// Created by Hackman.Lo on 7/25/2023.
//
#include "include/exception/database_exception.h"
#include "include/exception/conversion_exception.h"
#include <iostream>
int main(){
    try{
        THROW(sahara::exception::conversion_exception,"message", "module");
    }catch (sahara::exception::exception_base& e){
        std::cout << e.what() << std::endl;
    }
}