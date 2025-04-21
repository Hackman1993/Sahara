//
// Created by Hackman.Lo on 4/12/2023.
//

#ifndef LIBSAHARA_DIRTYABLE_H
#define LIBSAHARA_DIRTYABLE_H

namespace sahara::types {
  class dirtyable {
  public:
    explicit dirtyable(bool dirty): dirty_(dirty){}
    virtual bool dirty() { return dirty_; }
    virtual ~dirtyable(){}
  protected:
    bool dirty_ = false;
  };
} // types

#endif //LIBSAHARA_DIRTYABLE_H
