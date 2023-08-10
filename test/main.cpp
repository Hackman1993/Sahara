//
// Created by Hackman.Lo on 7/25/2023.
//
#include "include/exception/exception.h"
#include <iostream>
int main(){
    try{
        THROW(sahara::exception::database_exception,"sahara", "Wired", 200);
    }catch (sahara::exception::exception_base& e){
        std::cout << e.what() << std::endl;
    }
}