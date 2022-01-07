cmake_minimum_required(VERSION 3.14)

project(untitled_lib1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)


find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

add_library(untitled_lib1 SHARED
  untitled_lib1.cpp
  untitled_lib1.h
)
set_target_properties(untitled_lib1 PROPERTIES DEBUG_POSTFIX "d")

target_link_libraries(untitled_lib1 PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(untitled_lib1 PRIVATE UNTITLED_LIB1_LIBRARY)

target_include_directories(untitled_lib1 PUBLIC ${PROJECT_SOURCE_DIR})

install(TARGETS untitled_lib1
    LIBRARY DESTINATION lib)


message("CMAKE_SOURCE_DIR"  ${PROJECT_BINARY_DIR} ${CMAKE_BUILD_TYPE})
message("CMAKE_SOURCE_DIR"  ${DEBUG_POSTFIX} ${RELEASE_POSTFIX})
