#include <iostream>
#include <thread>
#include <mutex>

static std::mutex mtx;
static const int TARGET = 10000000;
static int value = 0;

static void increment() {
    for (int i = 0; i < TARGET / 2; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++value;
    }
}

void run_mutex_increment() {
    value = 0; 
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final value (with mutex): " << value << std::endl;
}
