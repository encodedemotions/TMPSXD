# cmake_minimum_required(VERSION <specify CMake version here>)
project(TMPS)

set(CMAKE_CXX_STANDARD 20)

add_executable(TMPS
        main.cpp ibuilder.h data.h network.h iobject.h softmax_singleton.h dnetwork.h neuron_builder.h fsoftmax.h)
