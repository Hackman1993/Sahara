//
// Created by Hackman.Lo on 7/25/2023.
//
#include "include/exception/database_exception.h"
#include "include/exception/conversion_exception.h"
#include "include/container/unordered_smap_u.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include "include/stream/fstream.h"
//#include "include/stream/stl_stream_wrapper.h"

class base{
public:
    explicit base(int a):a_(a){};
    virtual ~base() = default;
protected:
    int a_ = 0;
};
class A: public base{
public:
    int a(){return a_;}
    explicit A(int a) : base(a){}

};
class B: public base{
public:
    int b(){return a_;}
    explicit B(int a) : base(a){}
};
class C: public A, public B{
public:
    explicit C(int a) : A(1), B(2){}
};
int main(){
    try{
        sahara::stream::fstream stream(R"(D:/Workspace/Cpp/LibraryOrganized/libraries/sahara/include/stream/fstream.h)", std::ios::in|std::ios::binary);
        C c(10);
        std::cout << c.a() << c.b()<< std::endl;
//        stream.size();
//        std::ifstream t("./test");
//        sahara::stream::stl_stream_wrapper<std::ifstream> wrapper(std::filesystem::path("./test"));

    }catch (sahara::exception::exception_base& e){
        std::cout << e.what() << std::endl;
    }
}