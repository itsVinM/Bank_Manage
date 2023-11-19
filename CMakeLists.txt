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