#include <iostream>
#include <thread>

static const int TARGET = 10000000;
static int value = 0;

static void increment() {
    for (int i = 0; i < TARGET / 2; ++i) {
        ++value;
    }
}

void run_unsafe_increment() {
    value = 0;
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final value (unsafe): " << value << std::endl;
}
