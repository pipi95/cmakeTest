cmake_minimum_required(VERSION 3.5)

set(target untitled_1 )
project(${target} VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets QuickWidgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets QuickWidgets REQUIRED)

add_subdirectory(untitled_lib1)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        form.cpp
        form.h
        form.ui
        res_qml.qrc
        res_assets.qrc
        )


qt_add_binary_resources(untitled_1_rcc res_qml.qrc
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/${target}.dll
        OPTIONS -no-compress
        )
qt_add_binary_resources(untitled_1_rcc_assets res_assets.qrc
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/${target}_assets.dll
        OPTIONS -no-compress
        )
set(rcc_files
        ${CMAKE_CURRENT_BINARY_DIR}/${target}.dll
        ${CMAKE_CURRENT_BINARY_DIR}/${target}_assets.dll
        )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
        qt_add_executable(${target}
                MANUAL_FINALIZATION
                ${PROJECT_SOURCES}
                )
        # Define target properties for Android with Qt 6 as:
        #    set_property(TARGET untitled_1 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
        #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
        # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
        if(ANDROID)
                add_library(${target} SHARED
                        ${PROJECT_SOURCES}
                        )
                # Define properties for Android with Qt 5 after find_package() calls as:
                #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
        else()
                add_executable(${target}
                        ${PROJECT_SOURCES}
                        )
        endif()
endif()

target_link_libraries(${target}
        PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::QuickWidgets
        PUBLIC
        untitled_lib1)

set_target_properties(${target} PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        )
get_target_property(_qt5_qmake_location
        Qt5::qmake IMPORTED_LOCATION
        )

execute_process(
        COMMAND "${_qt5_qmake_location}" -query QT_INSTALL_PREFIX
        RESULT_VARIABLE return_code
        OUTPUT_VARIABLE qt5_install_prefix
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )
add_custom_command(TARGET ${target}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_CURRENT_BINARY_DIR}/windeployqt"
        COMMAND set PATH=%PATH%$<SEMICOLON>${qt5_install_prefix}/bin
        COMMAND ${qt5_install_prefix}/bin/windeployqt.exe --dir "${CMAKE_CURRENT_BINARY_DIR}/windeployqt" --qmldir "${CMAKE_CURRENT_SOURCE_DIR}/qml" "$<TARGET_FILE_DIR:${target}>/$<TARGET_FILE_NAME:${target}>"
        )
message("${CMAKE_CURRENT_SOURCE_DIR}/qml")
message("${qt5_install_prefix}/bin/windeployqt.exe --dir ${CMAKE_CURRENT_BINARY_DIR}/windeployqt --qmldir ${CMAKE_CURRENT_SOURCE_DIR}/qml $<TARGET_FILE_DIR:${target}>/$<TARGET_FILE_NAME:${target}>")
if(QT_VERSION_MAJOR EQUAL 6)
        qt_finalize_executable(${target})
endif()

set(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP TRUE)

include(InstallRequiredSystemLibraries)

install(
        PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS}
        DESTINATION bin
        )

install(TARGETS ${target}
        LIBRARY DESTINATION lib)

install(FILES  ${rcc_files}
        DESTINATION bin)

install(
        DIRECTORY
        "${CMAKE_CURRENT_BINARY_DIR}/windeployqt/"
        DESTINATION bin
        )
