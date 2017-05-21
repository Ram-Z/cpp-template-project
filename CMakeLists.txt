cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME TemplateProjectCpp)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

include(GitDescribe)
git_describe(PREFIX ${PROJECT_NAME})

project(${PROJECT_NAME}
  VERSION ${${PROJECT_NAME}_VERSION}
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(Catch)
include(Trompeloeil)
get_catch(VERSION 1.9.3)
get_trompeloeil(VERSION 25)

if(TARGET Catch::Catch)
  message(STATUS "Found Catch")
endif()

if(TARGET Trompeloeil::Trompeloeil)
  message(STATUS "Found Trompeloeil")
endif()

add_subdirectory(lib)
