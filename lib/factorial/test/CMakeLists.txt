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

add_custom_target(${_test_target}_check
  COMMAND ${_test_target}_tests
)

add_dependencies(check ${_test_target}_check)
