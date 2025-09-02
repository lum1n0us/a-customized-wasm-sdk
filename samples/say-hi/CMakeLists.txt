cmake_minimum_required(VERSION 3.14)

project(sample-say-hi)

add_executable(say_hi ./main.c)
set_target_properties(say_hi PROPERTIES SUFFIX .wasm)

include(CTest)
add_test(
  NAME say_hi
  COMMAND ${CMAKE_CURRENT_LIST_DIR}/../../bin/iwasm say_hi.wasm
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
