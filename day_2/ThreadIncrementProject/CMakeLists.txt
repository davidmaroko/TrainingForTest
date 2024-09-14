cmake_minimum_required(VERSION 3.10)
project(ThreadIncrementProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(thread_increment main.cpp 
               unsafe_increment.cpp 
               mutex_increment.cpp 
               semaphore_increment.cpp)
