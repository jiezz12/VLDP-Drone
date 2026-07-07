cmake_minimum_required(VERSION 3.0.2)

project(vldp_msgs)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  std_msgs
)


###################################
## 消息文件
###################################

add_message_files(
  FILES
  ControlCommand.msg
)


###################################
## 生成消息
###################################

generate_messages(
  DEPENDENCIES
  std_msgs
)


###################################
## catkin配置
###################################

catkin_package(
  CATKIN_DEPENDS
    message_runtime
    std_msgs
)


include_directories(
  ${catkin_INCLUDE_DIRS}
)
