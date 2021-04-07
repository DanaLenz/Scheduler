cmake_minimum_required(VERSION 3.15)
project(Scheduler)

set(CMAKE_CXX_STANDARD 17)

set(wxWidgets_ROOT_DIR </usr/include/wx-3.0>)
#set(wxWidgets_CXX_FLAGS)
set(wxWidgets_USE_LIBS)
#set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

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
            Core/Tag.cpp Core/Tag.h
            UI/schedulerApp.cpp UI/schedulerApp.h
            UI/TaskFrame.cpp UI/TaskFrame.h
            UI/wxDefs.h
            UI/TaskRuleDialog.cpp UI/TaskRuleDialog.h
            UI/TimeslotFrame.cpp UI/TimeslotFrame.h
            UI/TimeslotDialog.cpp UI/TimeslotDialog.h
            UI/MainFrame.cpp UI/MainFrame.h
            UI/ProjectPanel.cpp UI/ProjectPanel.h
            UI/ProjectDialog.cpp UI/ProjectDialog.h)

#    target_link_libraries(progname Boost::filesystem)
    target_link_libraries(Scheduler ${wxWidgets_LIBRARIES})
    target_link_libraries(Scheduler ${Boost_DATE_TIME_LIBRARY})

else()
    message(FATAL_ERROR "boost libraries not found")
endif()


# C:\boost_1_72_0 compiler include path
# C:\boost_1_72_0\stage\lib linker library path