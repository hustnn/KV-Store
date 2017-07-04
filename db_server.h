//
// Created by Niu Zhaojie on 5/4/17.
//

#ifndef PINK_KV_DB_SERVER_H
#define PINK_KV_DB_SERVER_H

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

// the redis server
class db_server {
private:

    int server_port;

    // client connections
    struct pollfd clients_fds[config::MAX_CONNECTIONS];

    // redis commands queue for redis clients
    std::vector<redis_req> redis_client_requests;
    std::vector<redis_res> redis_client_responses;

    // wait for new connection to connect
    int listen();

    // poll the requests from the redis clients
    int poll();

    // process the command from the clients
    int process_request();

    // response the clients requests
    int process_response();

public:

    db_server(int port);

    bool configure();

    bool start();

    bool stop();
};




#endif //PINK_KV_DB_SERVER_H
