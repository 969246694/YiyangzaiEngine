cmake_minimum_required(VERSION 3.15)
project(YiyangzaiEngine VERSION 0.1.0 LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY /lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY /lib)

# 包含目录
include_directories(include)

# 添加内核子目录
add_subdirectory(src)

# 添加示例（可选，通过选项控制）
option(BUILD_EXAMPLES "Build example projects" ON)
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# 添加测试（可选）
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
