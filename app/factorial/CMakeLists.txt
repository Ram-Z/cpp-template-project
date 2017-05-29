find_package(Qt5 COMPONENTS Widgets REQUIRED)
if(BUILD_TESTING)
  find_package(Qt5 COMPONENTS Test REQUIRED)
endif()

add_library(qt_app_lib STATIC
  src/Mainwindow.cpp
)

target_include_directories(qt_app_lib
  PUBLIC src
)

set_target_properties(qt_app_lib PROPERTIES
  AUTOMOC ON
  AUTORCC ON
  AUTOUIC ON
)

target_link_libraries(qt_app_lib
  PUBLIC Template::Factorial
  PUBLIC Qt5::Widgets
)

add_executable(qt_app
  src/main.cpp
)

target_link_libraries(qt_app
  PRIVATE qt_app_lib
)

add_executable(qt_app_test
  test/tests.cpp
  test/Mainwindow.test.cpp
)

target_link_libraries(qt_app_test
  PRIVATE qt_app_lib
  PRIVATE Catch::Catch
  PRIVATE Qt5::Test
)

add_custom_target(qt_app_check
  COMMAND qt_app_test
)

add_dependencies(check qt_app_check)

clang_format(qt_app)
clang_tidy(qt_app)
