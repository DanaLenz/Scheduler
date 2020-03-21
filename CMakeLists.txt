cmake_minimum_required(VERSION 3.15)
project(Scheduler)

set(CMAKE_CXX_STANDARD 17)

#find_package(Boost COMPONENTS filesystem date_time)
#if(Boost_FOUND)
#    target_link_libraries(progname Boost::filesystem Boost::date_time)
#else()
#    message(FATAL_ERROR "boost date_time and filesystem libraries not found")
#endif()

add_executable(Scheduler main.cpp Core/Tasks/Task.cpp Core/Tasks/Task.h Core/Tasks/Project.cpp Core/Tasks/Project.h Core/Tasks/TaskManager.cpp Core/Tasks/TaskManager.h UI/consoleUI.cpp UI/consoleUI.h Core/Tasks/IDGenerator.cpp Core/Tasks/IDGenerator.h)

# Core/PriorityQueue.cpp Core/PriorityQueue.h Core/Timeslot.cpp Core/Timeslot.h Core/Calendar.cpp Core/Calendar.h Core/Tag.cpp Core/Tag.h

# C:\boost_1_72_0 compiler include path
# C:\boost_1_72_0\stage\lib linker library path