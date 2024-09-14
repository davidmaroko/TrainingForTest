#include <iostream>
#include <thread>
#include <condition_variable>

static std::mutex mtx;
static std::condition_variable cv;
static bool semaphore = true;
static const int TARGET = 10000000;
static int value = 0;

static void wait() {
    std::unique_lock<std::mutex> lock(mtx);
    while (!semaphore) {
        cv.wait(lock);
    }
    semaphore = false;
}

static void signal() {
    std::lock_guard<std::mutex> lock(mtx);
    semaphore = true;
    cv.notify_one();
}

static void increment() {
    for (int i = 0; i < TARGET / 2; ++i) {
        wait();
        ++value;
        signal();
    }
}

void run_semaphore_increment() {
    value = 0; // Reset value
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final value (with semaphore): " << value << std::endl;
}
