cmake_minimum_required(VERSION 3.21)
project(Plan_Track_cpp)

set(CMAKE_CXX_STANDARD 14)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

#include(GNUInstallDirs)
set(PACKAGE_NAME Plan_Track_cpp)


# Library target
add_library(Plan_Track_cpp INTERFACE)


# TODO: Use `Development.Embed` component when requiring cmake >= 3.18
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
target_link_libraries(Plan_Track_cpp INTERFACE
        Python3::Python
        Python3::Module
        )
find_package(Python3 COMPONENTS NumPy)
if(Python3_NumPy_FOUND)
    target_link_libraries(Plan_Track_cpp INTERFACE
            Python3::NumPy
            )
else()
    target_compile_definitions(Plan_Track_cpp INTERFACE WITHOUT_NUMPY)
endif()
install(
        TARGETS Plan_Track_cpp
        EXPORT install_targets
)



add_executable(main main.cpp)
target_link_libraries(main PRIVATE Plan_Track_cpp)


add_subdirectory(PathTracking bin)

add_subdirectory(PathPlanning bin_planning)

