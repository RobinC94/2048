cmake_minimum_required(VERSION 3.3)

set(REPO ~/ClionProjects/.repo)

project(Test)

project(Example)

include(CTest)
enable_testing()

#INCLUDE_DIRECTORIES(
#        ../include
#)

#set(gtest_disable_pthreads on) #needed in MinGW
include(${REPO}/DownloadProject/DownloadProject.cmake)
download_project(
        PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)

set(test_SRCS ../src/BaseUI.cpp ../src/PrintfUI.cpp ../src/2048.cpp)

add_executable(runUnitTests ${test_SRCS} test.cpp)
target_link_libraries(runUnitTests gtest)
