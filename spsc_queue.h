//
// Created by Niu Zhaojie on 5/4/17.
//

#ifndef PINK_KV_SPSC_QUEUE_BASE_H
#define PINK_KV_SPSC_QUEUE_BASE_H

#include <boost/lockfree/spsc_queue.hpp>
#include <cstddef>

template<typename T, size_t size>
class spsc_queue {

public:
    //public member function
    bool push(T const &);
    bool pop(T &);

private:
    boost::lockfree::spsc_queue<T, boost::lockfree::capacity<size> > boost_spsc_queue;

};

#endif //PINK_KV_SPSC_QUEUE_BASE_H
