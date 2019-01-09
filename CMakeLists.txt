cmake_minimum_required (VERSION 3.0)
project(Example LANGUAGES CXX)

option(CODE_COVERAGE "Enable coverage reporting" OFF)

# Common configuration and force C++ standard
add_compile_options(-Wall -pedantic)
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.1)
  set(CMAKE_CXX_STANDARD 11)
else()
  add_compile_options(-std=c++11)
endif()


# Code Coverage Configuration
add_library(coverage_config INTERFACE)

if(CODE_COVERAGE)
  # Add required flags (GCC & LLVM/Clang)
  target_compile_options(coverage_config INTERFACE
    -O0        # no optimization
    -g         # generate debug info
    --coverage # sets all required flags
  )
  if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
    target_link_options(coverage_config INTERFACE --coverage)
  else()
    target_link_libraries(coverage_config INTERFACE --coverage)
  endif()
endif(CODE_COVERAGE)


enable_testing() # CTest
add_subdirectory(src)
