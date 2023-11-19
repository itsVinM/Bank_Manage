# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(BankMng)

set(CMAKE_CXX_STANDARD 11)

# Collect all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

# Add executable and source files
add_executable(BankMng ${SOURCES} ${HEADERS})

# Specify include directories
target_include_directories(BankMng PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# ---- Testing Configuration ----
enable_testing()

# Collect all test source files
file(GLOB_RECURSE TEST_SOURCES "test/*.cpp")

# Add test executable and source files
add_executable(BankMngTests ${TEST_SOURCES} ${HEADERS})

# Specify include directories for tests
target_include_directories(BankMngTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link the main executable and any other libraries needed for tests
target_link_libraries(BankMngTests PRIVATE BankMng)

# Add tests
add_test(NAME BankMngTests COMMAND BankMngTests)
