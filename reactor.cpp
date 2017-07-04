//
// Created by Niu Zhaojie on 12/4/17.
//


#include "reactor.h"
#include "posix.h"


void smp::configure() {

    int num_cpus;

    unsigned i;
    // core 0 is main threads
    // create num_cpus - 1 reactor thread, each reactor is a kv_store proxy
    for (i = 1; i < num_cpus; i++) {
        // create_thread here
    }

}


void smp::create_thread(std::function<void ()> thread_loop) {

    _threads.emplace_back(std::move(thread_loop));
}
