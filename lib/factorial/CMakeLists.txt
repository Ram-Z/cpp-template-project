add_library(libfactorial INTERFACE)

target_include_directories(libfactorial
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()
