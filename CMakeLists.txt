cmake_minimum_required(VERSION 3.16.3)

project(unp)
include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_DIR)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(app main.cpp ${SRC_DIR})
set_target_properties(app PROPERTIES COMPILE_FLAGS "-Wall -g -pthread" LINK_FLAGS "-pthread")

