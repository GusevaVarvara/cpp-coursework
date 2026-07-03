cmake_minimum_required(VERSION 3.0)

project(graph_project)

add_executable(graph_project main.cpp graph_reader.cpp graph_visualization.cpp graph_drawing.cpp graph_reader.h graph_visualization.h graph_drawing.h)


set_property(TARGET graph_project PROPERTY CXX_STANDARD 11)
