//
// Created by Hackman.Lo on 11/8/2023.
//

#ifndef SAHARA_IOSTREAM_H
#define SAHARA_IOSTREAM_H
#include "basic_istream.h"
#include "basic_ostream.h"

namespace sahara::stream {

    class iostream : public basic_istream, public basic_ostream{
    public:
        ~iostream() override = default;
    };

} // sahara::stream

#endif //SAHARA_IOSTREAM_H
