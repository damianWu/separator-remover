project(${project_name}_exception VERSION 1.0.0)

add_library(
        ${project_name}_exception
        source/exception.cpp
)

target_include_directories(
        ${project_name}_exception
        PUBLIC
        include
)
