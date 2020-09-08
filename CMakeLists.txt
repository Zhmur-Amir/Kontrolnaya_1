cmake_minimum_required(VERSION 3.1)

project(CcomplexVector)

set (CCOMPLEX_VECTOR_SRC  main.cpp autotest.cpp)
set (CCOMPLEX_VECTOR_HDR klass.h)

add_executable (${PROJECT_NAME} ${CCOMPLEX_VECTOR_SRC} ${CCOMPLEX_VECTOR_HDR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")