cmake_minimum_required(VERSION 3.21)
project(Plan_Track_cpp)

set(CMAKE_CXX_STANDARD 14)

#include(GNUInstallDirs)
set(PACKAGE_NAME Plan_Track_cpp)


# Library target
# add_library(Plan_Track_cpp INTERFACE)

include_directories(/usr/include/python3.10)
include_directories(/usr/local/lib/python3.10/dist-packages/numpy/core/include)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

find_package(OsqpEigen REQUIRED)

#PID
add_executable(pid_demo PID/main.cpp PID/PID_controller.cpp utils/KinematicModel.cpp)
target_link_libraries(pid_demo PRIVATE Plan_Track_cpp)

#pure pursuit
add_executable(pure_pursuit_demo Pure_Pursuit/main.cpp  Pure_Pursuit/PurePursuit.cpp utils/KinematicModel.cpp)
target_link_libraries(pure_pursuit_demo PRIVATE Plan_Track_cpp)

#stanley
add_executable(stanley_demo Stanley/main.cpp  Stanley/Stanley.cpp utils/KinematicModel.cpp)
target_link_libraries(stanley_demo PRIVATE Plan_Track_cpp)


# 后轮位置反馈控制
add_executable(rear_wheel_feedback_demo Rear_Wheel_Feedback/main.cpp  Rear_Wheel_Feedback/RearWheelFeedback.cpp utils/MyReferencePath.cpp utils/KinematicModel.cpp)
target_link_libraries(rear_wheel_feedback_demo PRIVATE Plan_Track_cpp)

# lqr控制
add_executable(lqr_demo LQR/main.cpp  LQR/LQRControl.cpp utils/MyReferencePath.cpp utils/KinematicModel.cpp)
target_link_libraries(lqr_demo PRIVATE Plan_Track_cpp)

## mpc控制 osqp待实现
add_executable(mpc_demo MPC/main.cpp  MPC/MPCControl.cpp utils/KinematicModel.cpp utils/MyReferencePath.cpp )
target_link_libraries(mpc_demo PRIVATE Plan_Track_cpp OsqpEigen::OsqpEigen)

# MPC实现轨迹跟踪，cppad/ipopt 实现
add_executable(mpc_speed_steel_demo Model_Predictive_Speed_Steel_Control/main.cpp Model_Predictive_Speed_Steel_Control/ModelPredictiveControl.cpp)
target_link_libraries(mpc_speed_steel_demo PRIVATE ipopt Plan_Track_cpp)


