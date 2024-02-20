cmake_minimum_required(VERSION 3.19)
project(data_structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structure main.cpp src/linear_list/link_storage/single_link_list/single_link_list.h src/linear_list/link_storage/single_link_list/single_link_list.cpp src/linear_list/seq_storage/seq_list.cpp src/linear_list/seq_storage/seq_list.h src/linear_list/link_storage/double_link_list/double_link_list.h src/linear_list/link_storage/double_link_list/double_link_list.cpp src/linear_list/seq_storage/stack/stack.h src/linear_list/seq_storage/stack/stack.cpp src/linear_list/link_storage/stack/stack.h src/linear_list/link_storage/stack/stack.cpp src/linear_list/seq_storage/queue/queue.cpp src/linear_list/seq_storage/queue/queue.h)