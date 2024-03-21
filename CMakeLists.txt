cmake_minimum_required(VERSION 3.27)
project(Emulator)

set(CMAKE_CXX_STANDARD 20)


add_library(Stack STATIC "src/stack.cpp")


add_library(Memory STATIC "src/memory.cpp")
add_library(Commands STATIC "src/commands.cpp")
add_library(Parser STATIC "src/my_parser.cpp")
add_library(Preprocessor STATIC "src/preprocessor.cpp")
add_library(Processor STATIC "src/processor.cpp")
add_library(Emulator STATIC "src/emulator.cpp")


target_include_directories(Stack PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_include_directories(Memory PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_include_directories(Commands PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_include_directories(Parser PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_include_directories(Preprocessor PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_include_directories(Processor PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_include_directories(Emulator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")


add_executable(test_stack "test/stack_test.cpp")
target_link_libraries(test_stack
        Stack
        gtest_main)

add_executable(test_parser "test/parser_test.cpp")
target_link_libraries(test_parser
        Parser
        gtest_main)

add_executable(test_commands "test/commands_test.cpp")
target_link_libraries(test_commands
        Stack
        Memory
        Commands
        gtest_main)

add_executable(test_emulator "test/emulator_test.cpp")
target_link_libraries(test_emulator
        Stack
        Memory
        Commands
        Parser
        Preprocessor
        Processor
        Emulator
        gtest_main
)

add_executable(main "test/main.cpp")
target_link_libraries(main
        Stack
        Memory
        Commands
        Parser
        Preprocessor
        Processor
        Emulator
)

# Google tests
enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)