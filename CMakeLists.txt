cmake_minimum_required(VERSION 3.8)

set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "")

set(PROJECT_NAME TemplateProjectCpp)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

include(GitDescribe)
git_describe(PREFIX ${PROJECT_NAME})

project(${PROJECT_NAME}
  VERSION ${${PROJECT_NAME}_VERSION}
  LANGUAGES CXX
)

include(ClangTools)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(BUILD_TESTING "Enable testing" ON)

if(BUILD_TESTING)
  include(Catch)
  get_catch(VERSION 1.9.3)

  include(Trompeloeil)
  get_trompeloeil(VERSION 25)
endif()

add_subdirectory(lib/factorial)
add_subdirectory(app/factorial)
