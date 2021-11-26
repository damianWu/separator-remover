set(lib_name ${project_name}_punct_stream)

project(${lib_name} VERSION 1.0.0)

add_library(
        ${lib_name}
        source/punct_stream.cpp
)

target_link_libraries(
        ${lib_name}
#        ${project_name}_exception
)

target_include_directories(
        ${lib_name}
        PUBLIC
        include
)
