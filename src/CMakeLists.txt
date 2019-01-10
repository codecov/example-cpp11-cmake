cmake_minimum_required(VERSION 3.0)

# The library
add_library(example complex.cpp)
target_include_directories(example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# Include code-coverage settings:
target_link_libraries(example PUBLIC coverage_config)


# Tests for the library
add_executable(tests complex_main.cpp)
target_link_libraries(tests PRIVATE example) # inherits coverage_config
add_test(NAME example_test COMMAND tests)
