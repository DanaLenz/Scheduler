cmake_minimum_required(VERSION 3.15)
project(Scheduler)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS "date_time")

if(Boost_FOUND)
    include_directories(${BOOST_INCLUDE_DIRS})
#    link_directories(${Boost_LIBRARY_DIRS})

    add_executable(
            Scheduler main.cpp
            Core/Tasks/Task.cpp Core/Tasks/Task.h Core/Tasks/Project.cpp Core/Tasks/Project.h
            Core/Tasks/TaskManager.cpp Core/Tasks/TaskManager.h
            Core/Tasks/IDGenerator.cpp Core/Tasks/IDGenerator.h
            Core/Tasks/TaskRule.cpp Core/Tasks/TaskRule.h
            Core/Calendar/Timeslot.cpp Core/Calendar/Timeslot.h
            Core/Calendar/CalendarGenerator.cpp Core/Calendar/CalendarGenerator.h
            Core/Calendar/TimeslotRule.cpp Core/Calendar/TimeslotRule.h
            Core/Definitions.h
            Core/Calendar/Calendar.cpp Core/Calendar/Calendar.h
            Core/Tag.cpp Core/Tag.h)

#    target_link_libraries(progname Boost::filesystem)
else()
    message(FATAL_ERROR "boost libraries not found")
endif()


# Core/PriorityQueue.cpp Core/PriorityQueue.h Core/Tag.cpp Core/Tag.h

# C:\boost_1_72_0 compiler include path
# C:\boost_1_72_0\stage\lib linker library path