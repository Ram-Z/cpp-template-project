add_library(libfactorial INTERFACE)

target_include_directories(libfactorial
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_test_executable(libfactorial_test
  test/tests.cpp
  test/factorial.test.cpp
)

target_link_libraries(libfactorial_test
  PRIVATE libfactorial
  PRIVATE Catch::Catch
  PRIVATE Trompeloeil::Trompeloeil
)
