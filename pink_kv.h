//
// Created by Niu Zhaojie on 12/4/17.
//

#ifndef PINK_KV_PINK_KV_H
#define PINK_KV_PINK_KV_H


// this class is the main thread;
// uses db_server to management the connections;
// use reactor smp to build the multi-threads kv store;
// db_server parse the requests from the clients and route the command to the multi-threads kv store;
// the routing is handled by the key_mapper and the command is sent to the corresponding reactor thread pinned in specific core;
class pink_kv {

};


/*
 * // each cpu corresponds to one kv_store which is responsible for a part of hash table partitions
    // num_cpus - 1 kv stores in total
    // build the bridge between the dbserver and the kv store belongs to each core
    // num_cpus - 1 message queues in total

    static void start_all_message_queues();
    static void pin(unsigned cpu_id);
    static void allocate_kv_store(unsigned id);
    static void create_thread(std::function<void ()> thread_loop);
 */


#endif //PINK_KV_PINK_KV_H
