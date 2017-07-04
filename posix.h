//
// Created by Niu Zhaojie on 6/4/17.
//

#ifndef PINK_KV_POSIX_H
#define PINK_KV_POSIX_H


#include <functional>
#include <pthread.h>

void pin_this_thread(unsigned cpu_id);

class posix_thread {
private:
    std::unique_ptr<std::function<void ()>> _func;
    pthread_t _pthread;

private:
    static void* start_routine(void* arg) noexcept;

public:
    posix_thread(std::function<void ()> func);
    ~posix_thread();
    void join();

};

#endif //PINK_KV_POSIX_H
