# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(Bank_Manage)

set(CMAKE_CXX_STANDARD 11)

# Collect all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

# Add main executable and source files
add_executable(Bank_Manage ${SOURCES} ${HEADERS})

# Specify include directories
target_include_directories(Bank_Manage PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# ---- Testing Configuration ----
enable_testing()

# Collect all test source files
file(GLOB_RECURSE TEST_SOURCES "test/*.cpp")

# Add test executable and source files
add_executable(Bank_ManageTests ${TEST_SOURCES} ${HEADERS})

# Specify include directories for tests
target_include_directories(Bank_ManageTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link the main executable and any other libraries needed for tests
target_link_libraries(Bank_ManageTests PRIVATE Bank_Manage)  # Fix the library name

# Add tests
add_test(NAME Bank_ManageTests COMMAND Bank_ManageTests)
