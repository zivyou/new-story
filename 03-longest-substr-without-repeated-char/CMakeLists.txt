# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.


project(03)

set(CMAKE_CXX_STANDARD 11)


add_executable(03 main.cpp)