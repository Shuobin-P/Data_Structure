cmake_minimum_required(VERSION 3.19)
project(data_structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structure main.cpp src/seq_list/link_storage/single_link_list.h src/seq_list/link_storage/single_link_list.cpp src/seq_list/seq_storage/seq_list.cpp src/seq_list/seq_storage/seq_list.h)