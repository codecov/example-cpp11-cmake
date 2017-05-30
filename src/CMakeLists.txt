set(SOURCE_FILES
    complex.cpp
)
add_library(complex ${SOURCE_FILES})

set(TEST_FILES
    complex_main.cpp
)

add_executable(tests ${TEST_FILES})
# Linking up all libraries
target_link_libraries(tests complex)

add_test(NAME example_test COMMAND tests)
