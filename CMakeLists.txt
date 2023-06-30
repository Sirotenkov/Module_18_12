cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(18_12 VERSION 1.0)

# add the executable
add_executable(18_12 main.cpp)
target_sources(18_12 PRIVATE users.cpp messages.cpp)
target_compile_features(18_12 PRIVATE cxx_std_17)