//
// Created by Hackman.Lo on 7/25/2023.
//
#include "include/exception/database_exception.h"
#include "include/exception/conversion_exception.h"
#include "include/container/unordered_smap_u.h"
#include <iostream>
#include <fstream>
#include <filesystem>

#include "include/hash/bcrypt.h"
#include "include/hash/bcrypt/node_blf.h"

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
        auto result  = sahara::hash::bcrypt::validatePassword(std::string("Crown@1188"), std::string("$2y$10$F3s9WvsW27KXEbuCoKWGDu/ULHYlJRALXo/tfUbkkR/jMn7NK4aKi"));
        result = false;

    }catch (sahara::exception::exception_base& e){
        std::cout << e.what() << std::endl;
    }
}