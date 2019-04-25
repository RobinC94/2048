cmake_minimum_required(VERSION 3.10)
project(2048)


set(CMAKE_CXX_STANDARD 11)

AUX_SOURCE_DIRECTORY(src DIR_SRCS)

SET(SOURCE_FILES
        ${DIR_SRCS}
        )

INCLUDE_DIRECTORIES(
        include
)

add_subdirectory(test)

add_executable(2048 ${SOURCE_FILES} rungame.cpp)










