set(REACT_NATIVE_DESKTOP_EXTERNAL_MODULES_TYPE_NAMES ${REACT_NATIVE_DESKTOP_EXTERNAL_MODULES_TYPE_NAMES}
                                                     \"RNCM\" PARENT_SCOPE)

set(REACT_NATIVE_DESKTOP_EXTERNAL_MODULES_SRC ${REACT_NATIVE_DESKTOP_EXTERNAL_MODULES_SRC}
                                              ${CMAKE_CURRENT_SOURCE_DIR}/rncmdesktop.cpp PARENT_SCOPE)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
set(FONTS_RESOURCE "")

find_package(Qt5Core REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5WebSockets REQUIRED)
find_package(Qt5Svg REQUIRED)

set(
  QML
  MyMessageBox.qml
)

add_library(
  ${QML}
  resources.qrc
)

set(USED_QT_MODULES Core Qml Quick WebSockets Svg Concurrent)

target_link_libraries(RNCM Qt5::Core Qt5::Widgets)