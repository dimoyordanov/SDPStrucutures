cmake_minimum_required(VERSION 3.30.5)
project(SDPStructures VERSION 0.1.0 LANGUAGES C CXX)

# Add an library for the example classes
add_library(SDPTest 
    main.cpp
)


include(CTest)
enable_testing()

#############################################
# Unit tests

add_subdirectory(google_test)

# enable CTest testing
enable_testing()

# Add a testing executable
add_executable(unit_tests unit_tests.cpp)

target_link_libraries(unit_tests
    SDPTest
    GTest::GTest 
    GTest::Main
)

add_test(test_all unit_tests)