//
// Created by Niu Zhaojie on 5/4/17.
//

#ifndef PINK_KV_CONFIG_H
#define PINK_KV_CONFIG_H


namespace config {
    extern int MAX_CONNECTIONS = 1024;
    extern int DB_SERVER_PORT = 9090;
    extern int NUM_CPUS = 12;

    extern int NUM_HASH_PARTITIONS = 1024;

    bool load_config_file();

}

#endif //PINK_KV_CONFIG_H
