# Add the test executable
add_executable(test test.cpp)

# Link libraries to the test executable
target_link_libraries(test PRIVATE light_bulb gtest gtest_main pthread)
