cmake_minimum_required(VERSION 3.22.1) 
project(VectorExercise)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -pedantic")

# add_compile_options(-DVECTOR_DEBUG)
add_executable(${PROJECT_NAME} VectorTest.cpp Vector.cpp)
