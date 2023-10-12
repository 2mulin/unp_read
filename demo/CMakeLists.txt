cmake_minimum_required(VERSION 3.22.1)

# project(demo)
# PROJECT_SOURCE_DIR 是父目录第一次调用project指令时的当前目录; 子目录调用project指令后, 子目录以下的PROJECT_SOURCE_DIR就会被更新为子目录, 所以demo子目录不能再调用project()
include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_DIR)


# 再开其它子项目, 放在demo目录下
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/daytime)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/byteorder)
