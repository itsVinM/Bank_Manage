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
