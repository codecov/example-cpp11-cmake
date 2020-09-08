add_library(example complex.cpp)
target_include_directories(example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# Setting this to the library only avoids errors in 3rd party dependencies which are compile with e.g. -Werror
if(NOT MSVC)
    target_compile_options(example PUBLIC -Wall -pedantic)
endif(NOT MSVC)
# Include code-coverage settings:
target_link_libraries(example PUBLIC coverage_config)

