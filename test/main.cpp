//
// Created by Hackman.Lo on 7/25/2023.
//
#include "log/log.h"
#include "string/string.h"
#include <iostream>
int main(){
    sahara::string str = "/api/user/login?account=admin&password=123123";
    std::cout << str.substr(0, str.find_first("?")) << std::endl;
}