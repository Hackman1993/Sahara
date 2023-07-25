//
// Created by Hackman.Lo on 7/25/2023.
//
#include "log/log.h"
#include <iostream>
int main(){
    sahara::log::set_level(spdlog::level::debug);
    sahara::log::set_level("console", spdlog::level::debug);
    LOG_DEBUG("hello world{}", 1);
    LOG_MODULE_DEBUG("console", "hello world{}", 1);
}