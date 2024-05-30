cmake_minimum_required(VERSION 3.0)
project(Week08)

# Automatically include all .cpp files in the current directory
file(GLOB_RECURSE SOURCES *.cpp *.h *.tpp)

# Add all sources to a dummy library for IntelliSense purposes
add_library(${PROJECT_NAME}_lib STATIC ${SOURCES}
        avl_test_from_slides.cpp)

