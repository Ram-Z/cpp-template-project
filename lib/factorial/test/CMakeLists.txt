set(_test_target libfactorial)

add_executable(${_test_target}_tests
  tests.cpp  # main
  factorial.test.cpp
)

target_link_libraries(${_test_target}_tests
  PRIVATE libfactorial
  PRIVATE Catch::Catch
  PRIVATE Trompeloeil::Trompeloeil
)
