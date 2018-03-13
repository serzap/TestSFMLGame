cmake_minimum_required(VERSION 3.8)
project(Test)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES main.cpp Game.cpp Game.h)
add_executable(Test ${SOURCE_FILES})


set(EXECUTABLE_NAME "MySFML")
add_executable(${EXECUTABLE_NAME} main.cpp Game.cpp Game.h)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()