cmake_minimum_required(VERSION 3.22.1)

include_directories(
    #${PROJECT_SOURCE_DIR}/include  # 父目录的CMakeLists已经包含过, 不需要重复包含
    ${CMAKE_CURRENT_SOURCE_DIR}     # 包含当前CMakeLists.txt所在目录的头文件
)

add_executable(byteorder main.cpp ${SRC_DIR})
set_target_properties(byteorder PROPERTIES COMPILE_FLAGS "-Wall -g")
