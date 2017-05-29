find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(qt_app
  src/main.cpp
  src/Mainwindow.cpp
)

target_include_directories(qt_app
  PRIVATE src
)

set_target_properties(qt_app PROPERTIES
  AUTOMOC ON
  AUTORCC ON
  AUTOUIC ON
)

target_link_libraries(qt_app
  PRIVATE libfactorial
  PRIVATE Qt5::Widgets
)

clang_format(qt_app)
clang_tidy(qt_app)
