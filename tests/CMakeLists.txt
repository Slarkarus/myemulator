cmake_minimum_required(VERSION 3.27)

project(tests)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests

# set(UNIT_TEST_TARGET_NAME my_lib)


#target_sources(${UNIT_TEST_TARGET_NAME}
#        ../include/stack.h ../src/stack.cpp UnitTest.cpp
#)

target_link_libraries(${PROJECT_TEST_NAME}
        gtest
        gtest_main
)


add_executable(tests_run stack_test.cpp
        main.cpp)

target_link_libraries(tests_run gtest gtest_main)

target_link_libraries(tests_run tmp)

enable_testing()