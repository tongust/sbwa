# Program test for SBWT  Blockwise.
cmake_minimum_required(VERSION 3.5)
project(BuildIndexBlockwise) 
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/ ${CMAKE_SOURCE_DIR}/../../) # -I flags for compiler include file
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11") # complier flag


#####################################
#                                   #
#  Include all xx.h and xx.cpp file #
#                                   #
#####################################
# option one
set(SRC ${CMAKE_SOURCE_DIR}/src/sbwtBlockwise.cpp ) # 

# option two
# file (
# GLOB hSRC
# ${CMAKE_SOURCE_DIR}/src/*.cpp
#)
# set(SRC ${hSRC} )


add_executable(BuildIndexBlockwise test.cpp ${SRC} )

# add_library(sbwtBlockwiselib STATIC ${SRC})
#target_link_libraries(prog sbwtBlockwise)
