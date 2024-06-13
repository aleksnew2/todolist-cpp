cmake_minimum_required(VERSION 3.29.5)
project(todolist)

set(CMAKE_CXX_STANDARD 26)
set(SOURCES
  src/todolist.c++
  src/todolist.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES})