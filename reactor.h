//
// Created by Niu Zhaojie on 12/4/17.
//

#ifndef PINK_KV_REACTOR_H
#define PINK_KV_REACTOR_H

#include <map>
#include <cstddef>
#include <vector>
#include <deque>
#include <sys/poll.h>
#include "posix.h"

#include "spsc_queue.h"
#include "command.h"
#include "hash_partition.h"
#include "config.h"
#include "redis_proto.h"
#include "kv_store.h"


// shared place for all reactors
class smp {

    static std::vector<posix_thread> _threads;
    static std::vector<reactor*> _reactors;
    static std::vector<kv_store*> _kv_stores;
    static message_queue** _msg_queues;

public:
    static void join_all();
    static bool poll_queues();
    static void submit_to(unsigned cpu_id, command* cmd);

    // the main interface of build the multi thread environments
    static void configure();

private:
    static void start_all_queues();
    static void pin(unsigned cpu_id);
    static void allocate_reactor(unsigned id);
    static void create_thread();

};

// each compute unit is represented as a reactor thread
class reactor {
private:
    std::vector<command> _pending_tasks;

    bool pool_once();
    void run_tasks(command* cmd);

public:
    // main loop of reactor thread
    int run();
    void add_task(command task);
};

// db_server communicates with kvstore through the messagequeue
class message_queue {
    static size_t queue_length = 128;
    static size_t batch_size = 16;

    spsc_queue<command*, queue_length> _pending;
    spsc_queue<response*, queue_length> _completed;

public:
    message_queue(reactor* from, reactor* to);

    bool submit(command* cmd);
    size_t process_incoming();
    size_t process_completions();

    std::deque<command*> _pending_fifo;
    std::deque<response*> _complete_fifo;

private:
    void flush_request_batch();
    void flush_response_batch();
    bool has_unflushed_responses();
};

#endif //PINK_KV_REACTOR_H
