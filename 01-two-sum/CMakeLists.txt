# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.


project(01-two-sum)

set(CMAKE_CXX_STANDARD 11)

add_executable(01-two-sum main.cpp)

project(01-two-sum-2)
add_executable(01-two-sum-2 main2.cpp)