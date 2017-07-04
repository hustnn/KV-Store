//
// Created by Niu Zhaojie on 12/4/17.
//

#ifndef PINK_KV_KV_STORE_H
#define PINK_KV_KV_STORE_H

#include "hash_partition.h"
#include "command.h"

// each cpu has one corresponding kv store
class kv_store {
private:

    int cpu_id;

    // each cpu corresponds to one kv_store
    // each kv_store has multiple partitions
    int kv_store_id;

    hash_partition* partitions;

public:

    bool execute(command* cmd, response* result);

};

#endif //PINK_KV_KV_STORE_H
