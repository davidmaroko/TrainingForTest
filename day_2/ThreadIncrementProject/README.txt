Exercise 1: Incrementing a Value Using Multiple Threads
Create programs that increment a value from zero to 10 million using two different threads. Implement the following versions:

An unsafe program without protection.

A program with protection of the critical sections using a mutex.

A program with protection of the critical sections using a binary semaphore.

for run: 
mkdir build
cd build
cmake ..
cmake --build .
./thread_increment
