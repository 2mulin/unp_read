cmake_minimum_required(VERSION 3.22.1)

include_directories(
    #${PROJECT_SOURCE_DIR}/include  # 多余的, 父目录的CMakeLists已经包含该目录
    ${CMAKE_CURRENT_SOURCE_DIR}/daytime
)

message(${PROJECT_SOURCE_DIR}/include)

add_executable(client client.cpp ${SRC_DIR})
set_target_properties(client PROPERTIES COMPILE_FLAGS "-Wall -g")

add_executable(server server.cpp ${SRC_DIR})
set_target_properties(server PROPERTIES COMPILE_FLAGS "-Wall -g")
