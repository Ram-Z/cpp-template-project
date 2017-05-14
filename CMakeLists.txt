cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME TemplateProjectCpp)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

include(GitDescribe)
git_describe(PREFIX ${PROJECT_NAME})

project(${PROJECT_NAME}
  VERSION ${${PROJECT_NAME}_VERSION}
  LANGUAGES CXX
)

include(Catch)
get_catch(VERSION 1.9.3)

if(TARGET Catch::Catch)
  message(STATUS "Found Catch")
endif()
