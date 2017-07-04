cmake_minimum_required(VERSION 3.6)
project(pink_kv)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES library.cpp library.h db_server.h spsc_queue.h hash_partition.h config.h command.h redis_proto.h config.cpp posix.h key_mapper.h pink_kv.h reactor.h kv_store.h sds.h reactor.cpp posix.cpp)
add_library(pink_kv ${SOURCE_FILES})