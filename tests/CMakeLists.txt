add_executable(tests complex_main.cpp)
# Linking up all libraries (includes the coverage settings set by 'example' library)
target_link_libraries(tests PRIVATE example)

add_test(NAME example_test COMMAND tests)

