cmake_minimum_required (VERSION 2.6)
project (Example)

option(CODE_COVERAGE "Enable coverage reporting" OFF)

# Code coverage configuration
add_library(coverage_config INTERFACE)

if(CODE_COVERAGE)
  # Set flags for code coverage (GCC & LLVM/Clang)
  target_compile_options(coverage_config INTERFACE
    -O0        # no optimization
    -g         # generate debug info
    --coverage # sets all required flags
  )

  if (CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
    target_link_options(coverage_config INTERFACE
      --coverage # sets all required linker flags
    )
  else()
    target_link_libraries(coverage_config INTERFACE
      --coverage
    )
  endif()
endif(CODE_COVERAGE)

# Setting default folders
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# C++ compile flags
# -std=c++11 -> for c++ standarts
# -Wall for WARNING
# -pedantic -> for warning between c and c++
# -pthread for portability
# -g -O0 -fprofile-arcs -ftest-coverage for code coverage
if(NOT CMAKE_VERSION VERSION_LESS 3.1)
    set(CMAKE_CXX_STANDARD 11)
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

# Include header files
include_directories(src)

include(CTest)
enable_testing()

# Include .cpp files
add_subdirectory(src)
