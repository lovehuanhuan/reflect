cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 11)
project(reflection_lib)

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB_RECURSE SRC "src/*.cc")

add_library(lib ${SRC})
set_target_properties(lib PROPERTIES OUTPUT_NAME "reflection")

#set(LIBRARY_OUTPUT_PATH ${HOME}/lib)
