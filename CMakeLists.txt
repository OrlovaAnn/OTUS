cmake_minimum_required(VERSION 3.4)
project(multi_file)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")

enable_testing()

add_custom_target(doc DEPENDS helloworld ip_filter googletest)

add_subdirectory(Week1)
add_subdirectory(Week2)
add_subdirectory(googletest EXCLUDE_FROM_ALL)