cmake_minimum_required(VERSION 3.19)
project(GeneticClient)

set(CMAKE_CXX_STANDARD 14)

add_executable(GeneticClient main.cpp Image.cpp Image.h Genetics.cpp Genetics.h Sender.cpp Sender.h)