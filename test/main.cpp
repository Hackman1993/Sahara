//
// Created by Hackman.Lo on 7/25/2023.
//
#include "log/log.h"
#include <iostream>
int main(){
    sahara::log::initialize();
    sahara::log::set_level(spdlog::level::trace);
    LOG_TRACE("hello world{}", 1);
    LOG_MODULE_DEBUG("console", "hello world{}", 1);
}