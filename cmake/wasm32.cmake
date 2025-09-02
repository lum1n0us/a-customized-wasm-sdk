#TODO: COPYRIGHT

# cmake/directory.cmake shall setup WASI_SDK_DIR
if(NOT WASI_SDK_DIR)
  #FIXME: remove me before check-in
  set(WASI_SDK_DIR ${CMAKE_CURRENT_LIST_DIR}/../../wasi-sdk-24.0-x86_64-linux)

  if(NOT EXISTS ${WASI_SDK_DIR})
    message(FATAL_ERROR "The wasi-sdk at ${WASI_SDK_DIR} is not present. Please install it alongside this-wasm-sdk")
  endif()

  #FIXME: enable me before check-in
  # message(FATAL_ERROR "WASI_SDK_DIR is not set")
endif()

# Include the base toolchain
include(${WASI_SDK_DIR}/share/cmake/wasi-sdk.cmake)

#
# Override something

#TODO: new triple

# more paths
include_directories(${CMAKE_CURRENT_LIST_DIR}/../include)
link_directories(${CMAKE_CURRENT_LIST_DIR}/../lib)

# Add compile options globally
add_compile_options(
  -mno-atomics
  -mno-exception-handling
  -mno-extended-const
  -mno-multimemory
  -mno-relaxed-simd
  -mno-simd128
)

add_link_options(
  LINKER:--max-memory=131072
  LINKER:--no-entry
  LINKER:--allow-undefined
)
