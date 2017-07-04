//
// Created by Niu Zhaojie on 12/4/17.
//

#ifndef PINK_KV_KEY_MAPPER_H
#define PINK_KV_KEY_MAPPER_H

#include <string>

using std::string

class key_mapper {
public:
    static int get_kv_store_id(string key);

private:
    static int build_key_mapping();
};


/*
 * int num_cpus;

    // map key to hash partition
    // index of the array is the hashed key value, its value is the hash partition id
    int key_to_partition[];

    // map partition to kv_store
    // one kv_store has multiple partitions
    std::map<int, int> partition_to_kv_store;

    int get_kv_store_id(command* cmd);

    static std::vector<posix_thread> _threads;
    static message_queue _qs[num_cpus - 1];
    static std::vector<kv_store*> _kv_stores;
 */

#endif //PINK_KV_KEY_MAPPER_H
