//
// Created by Hackman.Lo on 4/10/2023.
//

#ifndef LIBSAHARA_NULLABLE_H
#define LIBSAHARA_NULLABLE_H
#include <string>
#include <fmt/format.h>
#include <variant>
#include "dirtyable.h"
#include "../time/timestamp.h"
#include "../string/string.h"
#include <boost/format.hpp>
namespace sahara::types{
  template <typename BaseType>
  class nullable : public std::variant<BaseType, std::nullptr_t>, public dirtyable{
  public:
//    nullable &operator=(BaseType value){
//      std::variant<BaseType, std::nullptr_t>::operator=(value);
//      dirty_ = true;
//      return *this;
//    }
    using std::variant<BaseType, std::nullptr_t>::operator=;
//    nullable &operator=(std::nullptr_t value){
//      std::variant<BaseType, std::nullptr_t>::operator=(value);
//      dirty_ = true;
//      return *this;
//    }

    template <typename U = BaseType>
    nullable(typename std::enable_if<!std::is_same_v<bool, U>, bool>::type dirty = false): dirtyable(false){
      std::variant<BaseType, std::nullptr_t>::operator=(std::nullptr_t());
    }
    nullable(BaseType value, bool dirty = true): std::variant<BaseType, std::nullptr_t>(value), dirtyable(dirty){

    }
    nullable(std::nullptr_t value, bool dirty = false): std::variant<BaseType, std::nullptr_t>(value), dirtyable(dirty){

    }

    virtual bool is_null() const{
      return std::variant<BaseType, std::nullptr_t>::index() == 1;
    }
    operator BaseType(){
      if(!is_null()) return std::get<BaseType>(*this);
      return BaseType();
    }

    template<typename Type = BaseType>
    std::enable_if_t<(std::is_same_v<Type, sahara::string> || std::is_same_v<Type,sahara::time::timestamp>) , sahara::string> json(){
      if(is_null()) return "null";
      return sahara::string::static_format(("\"{}\"", std::get<BaseType>(*this)));
    }

    template<typename Type = BaseType>
     std::enable_if_t<(!std::is_same_v<Type,sahara::string>&& !std::is_same_v<Type,sahara::time::timestamp>), sahara::string> json(){
      if(is_null()) return "null";
        return sahara::string::static_format(("{}", std::get<BaseType>(*this)));
    }



  };
}


#endif //LIBSAHARA_NULLABLE_H
