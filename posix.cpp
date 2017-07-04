//
// Created by Niu Zhaojie on 13/4/17.
//

#include "posix.h"

template <typename T, typename... Ts>
std::unique_ptr<T> make_unique(Ts&&... params) {
    return std::unique_ptr<T> (new T(std::forward<Ts>(params)...));
};

void* posix_thread::start_routine(void* arg) noexcept {
    auto pfunc = reinterpret_cast<std::function<void ()>*>(arg);
    (*pfunc)();
    return nullptr;
}

posix_thread::posix_thread(std::function<void()> func)
    : _func(make_unique<std::function<void ()>>(std::move(func))) {

    pthread_create(&_pthread, NULL, &posix_thread::start_routine, _func.get());
}