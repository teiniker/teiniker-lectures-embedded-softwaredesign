# Add the test executable
add_executable(test test.cpp)

# Link the 'book' library to the test executable
target_link_libraries(test PRIVATE book gtest gtest_main pthread)
