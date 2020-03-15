cmake_minimum_required(VERSION 3.15)
project(Scheduler)

set(CMAKE_CXX_STANDARD 17)

add_executable(Scheduler main.cpp Core/Task.cpp Core/Task.h Core/Project.cpp Core/Project.h Core/PriorityQueue.cpp Core/PriorityQueue.h Core/Timeslot.cpp Core/Timeslot.h Core/Calendar.cpp Core/Calendar.h)