//
// Created by Hackman.Lo on 7/25/2023.
//
#include "include/exception/database_exception.h"
#include "include/exception/conversion_exception.h"
#include "include/container/unordered_smap_u.h"
#include <iostream>
int main(){
    try{
        std::unordered_map<std::string, std::string> umap2({
                                                                   {"BCQQA", "CDCEF"},
                                                                   {"BCQBA", "CDCEF"},
                                                           });
        sahara::container::unordered_smap_u<std::string> umap({
                                                                      {"BCQQA", "CDCEF"},
                                                                      {"BCQBA", "CDCEF"},
        });
        auto a = umap.contains("bcqqa");
        auto b = umap.contains("BCQBA");
    }catch (sahara::exception::exception_base& e){
        std::cout << e.what() << std::endl;
    }
}