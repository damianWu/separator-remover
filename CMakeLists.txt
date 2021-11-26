cmake_minimum_required(VERSION 3.16)

set(project_name separator_remover)

project(${project_name})


# ----------------------
# Debugging
# ----------------------
# set(DEBUG_MODE TRUE)


# ----------------------
# Build type
# ----------------------
if (NOT CMAKE_BUILD_TYPE AND DEBUG_MODE)
	set(CMAKE_BUILD_TYPE Debug)
elseif(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif ()


# ----------------------
# CXX settings
# ----------------------
set(CPP_COMPILER_STANDARD "-std=c++2a")
# set(CPP_STANDARD "20")
# set(CMAKE_CXX_STANDARD ${CPP_STANDARD})
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ----------------------
# Compiler flags
# ----------------------
# Rejected: -Wmissing-prototypes
set(EXTRA_COMPILER_FLAGS "-Wall -Wextra -Werror -Wpedantic -Wconversion -Wshadow -Wold-style-cast -Wpointer-arith -Wcast-qual -Wno-unused-function")

if(${DEBUG_MODE})
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG -g -O0")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CPP_COMPILER_STANDARD} ${EXTRA_COMPILER_FLAGS}")
	message(WARNING "Project is now in debug mode!")
else()
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CPP_COMPILER_STANDARD} ${EXTRA_COMPILER_FLAGS}")
endif()


# ----------------------
# Tests
# ----------------------
# Must be defined in top-most CMakeLists.txt file.
#enable_testing()


# ----------------------
# Libraries / Subdirectories
# ----------------------
# Outsource tests to another folder.
add_subdirectory(source/utils/exception)
add_subdirectory(source/punct_stream)
# add_subdirectory(tests)


# ----------------------
# Create executable target
# ----------------------
add_executable(
        ${project_name}
        main.cpp
)


# ----------------------
# Search header file in <dir>
# ----------------------
# include_directories(${CMAKE_SOURCE_DIR}/<dir>)


# ----------------------
# Link libraries with executable target
# ----------------------
target_link_libraries(
        ${project_name}
        ${project_name}_exception
        ${project_name}_punct_stream
)
