cmake_minimum_required(VERSION 3.14)
project(poker-test)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/poker-hand/include/)
include_directories(${PROJECT_SOURCE_DIR}/build/gtest/src/gtest/googletest/include)

##################################
# Download and install GoogleTest
include(ExternalProject)
ExternalProject_Add(gtest
        GIT_REPOSITORY https://github.com/google/googletest.git GIT_TAG release-1.8.1
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        INSTALL_COMMAND ""
        )
ExternalProject_Get_Property(gtest source_dir binary_dir)

################
# Define a test
add_executable(card_test CardTest.cpp ${PROJECT_SOURCE_DIR}/../source/Card.cpp)

######################################
# Configure the test to use GoogleTest
add_dependencies(card_test gtest)
target_link_libraries(card_test ${binary_dir}/googlemock/gtest/libgtest.a)
target_link_libraries(card_test ${binary_dir}/googlemock/gtest/libgtest_main.a)

##################################
enable_testing()
add_test(NAME    card_test
        COMMAND card_test)