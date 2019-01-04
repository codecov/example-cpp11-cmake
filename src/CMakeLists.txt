cmake_minimum_required(VERSION 3.0)

project(Example_complex LANGUAGES CXX)

# The library
add_library(example
  complex.cpp
)

target_include_directories(example
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(example
  PUBLIC
    coverage_config
)


# The library consumer/tests
add_executable(tests
  complex_main.cpp
)

target_link_libraries(tests
  PRIVATE
    example
)

# CTest
add_test(NAME example_test COMMAND tests)
