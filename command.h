//
// Created by Niu Zhaojie on 5/4/17.
//

#ifndef PINK_KV_COMMAND_H
#define PINK_KV_COMMAND_H

#include <string>

#include "sds.h"

using  std::string;


class command {
public:
    int command_id;
    sds redis_command;

};

class response {
public:
    int command_id;
    void* value;
    bool success;
};

#endif //PINK_KV_COMMAND_H
