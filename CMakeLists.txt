# For a general introduction to CMake, see:
# https://cmake.org/cmake/help/latest/guide/tutorial/

cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
cmake_policy(VERSION 3.14)

# Use the C++20 standard; fail if the compiler does not support it
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Name used to reference the framework library throughout this file
set(FRAMEWORK_NAME framework)

project(raytracer)

# Prevent in-source builds (building inside the source directory would
# clutter it with generated files and make cleanup difficult)
if(CMAKE_CURRENT_SOURCE_DIR EQUAL CMAKE_CURRENT_BINARY_DIR)
  message(FATAL_ERROR "Source and binary directories must be different")
endif(CMAKE_CURRENT_SOURCE_DIR EQUAL CMAKE_CURRENT_BINARY_DIR)

# ---------------------------------------------------------------------------
# External dependencies
# ---------------------------------------------------------------------------

# OpenGL - the graphics API used for rendering
find_package(OpenGL REQUIRED)

# Make headers in external/ available via #include
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external)

# GLEW - OpenGL extension loader, compiled statically into our project
add_definitions(-DGLEW_STATIC)

# GLFW - library for creating windows and handling keyboard/mouse input
set(GLFW_DIRECTORY glfw-3.4)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/${GLFW_DIRECTORY}/include)

# Disable building GLFW's own examples and tests (we only need the library)
set(GLFW_INSTALL OFF CACHE STRING "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE STRING "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE STRING "" FORCE)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/${GLFW_DIRECTORY})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/${GLFW_DIRECTORY}/include)

# NanoVG - small vector graphics library for 2D drawing
set(NANOVG_DIRECTORY nanovg)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/${NANOVG_DIRECTORY}/src)

add_library(nanovg STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/external/${NANOVG_DIRECTORY}/src/nanovg.c
)

# Suppress compiler warnings in third-party code that we do not maintain
if (CMAKE_COMPILER_IS_GNUCC)
  set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/external/${NANOVG_DIRECTORY}/src/nanovg.c PROPERTIES COMPILE_FLAGS -Wno-unused-result)
elseif(MSVC)
  set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/external/${NANOVG_DIRECTORY}/src/nanovg.c PROPERTIES COMPILE_FLAGS "/wd4005 /wd4456 /wd4457")
endif()

# Doctest - single-header unit testing framework (https://github.com/doctest/doctest)
set(DOCTEST_DIRECTORY doctest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/${DOCTEST_DIRECTORY})

# GLM - a header-only math library for graphics (vectors, matrices, etc.)
set(GLM_DIRECTORY glm-1.0.1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external/${GLM_DIRECTORY})

# Collect all graphics libraries into a single variable for convenience
set(LIBRARIES glfw ${GLFW_LIBRARIES})

# Suppress deprecation warnings on Windows
if(MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

# ---------------------------------------------------------------------------
# Testing and subdirectories
# ---------------------------------------------------------------------------

# Activate CMake's test runner (ctest)
enable_testing()

# framework/ - reusable library code (geometry, materials, rendering)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/framework)
add_subdirectory(framework)

# source/ - the programs you build and run (raytracer, example, tests)
add_subdirectory(source)
