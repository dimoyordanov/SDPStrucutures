cmake_minimum_required(VERSION 3.30.5)
project(SDPStructures VERSION 0.1.0 LANGUAGES C CXX)

# Add a library for the example classes
add_library(SDPTest 
    main.cpp
    # structures/Optional/Optional.hpp
    structures/Array/ArrayStatic.hpp
    structures/Pair/Pair.hpp
    structures/List/LinkedList.hpp
    # structures/List/DoublyLinkedList.hpp
    # structures/Trees/Trees.hpp
    # structures/Stack/LinkedStack.hpp
    # structures/Queue/LinkedQueue.hpp
    # structures/Array/DynamicArray.hpp
)

include(CTest)
enable_testing()
#############################################
# Unit tests

# Use FetchContent to get GoogleTest automatically
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2  # You can adjust the version if needed
)

# Make sure GoogleTest is built before tests
FetchContent_MakeAvailable(googletest)
enable_testing()

# Add a testing executable
add_executable(unit_tests 
    unit_tests.cpp 
    # tests/Optional/OptionalTest.cpp 
    tests/Array/ArrayTest.cpp
    tests/Pair/Pair.cpp
    tests/List/ListTest.cpp
    # tests/List/DoublyLinkedList.cpp
    # tests/Tree/Tree.cpp
    # tests/Array/DynamicArrayTest.cpp
)

target_link_libraries(unit_tests
    SDPTest
    gtest_main
)

# Enable GoogleTest testing framework
include(GoogleTest)
gtest_discover_tests(unit_tests)

# Add test for CTest
add_test(NAME test_all COMMAND unit_tests)