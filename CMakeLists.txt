cmake_minimum_required(VERSION 3.20)
project(loz-ocarina-mq CXX)
set(CMAKE_CXX_STANDARD 20)
add_executable(loz-ocarina-mq
  src/main.cpp
  src/engine_bridge.cpp
)
target_include_directories(loz-ocarina-mq PRIVATE
  ${CMAKE_SOURCE_DIR}/src
  ${CMAKE_SOURCE_DIR}/../twilight-elysium/src
)
