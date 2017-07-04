//
// Created by Niu Zhaojie on 5/4/17.
//

#ifndef PINK_KV_HASH_TABLE_H
#define PINK_KV_HASH_TABLE_H

#include <string>

using  std::string;

class hash_partition {
public:
    int partition_id;

    hash_partition(int size);

    string get(string key);
    bool put(string key, void* value);
    bool del(string key);
};

#endif //PINK_KV_HASH_TABLE_H
