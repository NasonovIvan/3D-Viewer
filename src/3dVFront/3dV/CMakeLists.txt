cmake_minimum_required(VERSION 3.5)

project(3dV VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)

# target_link_libraries(mytarget PRIVATE Qt6::OpenGLWidgets)
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    myopenglwidget.h 
    myopenglwidget.cpp

    # ../viewer.h
    # ../Functions/parser.c
    # ../Functions/affine.c
    # ../Functions/affine.h
    ../../viewer.h
    ../../Functions/parser.c
    ../../Functions/affine.c
    ../../Functions/affine.h

    ../../giflib/dgif_lib.c
    ../../giflib/egif_lib.c
    ../../giflib/gif_err.c
    ../../giflib/gif_font.c
    ../../giflib/gif_hash.c
    ../../giflib/gifalloc.c
    ../../giflib/quantize.c

    ../../giflib/gif_lib_private.h
    ../../giflib/gif_lib.h
    ../../giflib/gif_hash.h

    ../../gifimage/qgifglobal.h
    ../../gifimage/qgifimage_p.h
    ../../gifimage/qgifimage.cpp
    ../../gifimage/qgifimage.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(3dV
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

# Define target properties for Android with Qt 6 as:
# set_property(TARGET 3dV APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
# ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(3dV SHARED
            ${PROJECT_SOURCES}
        )

    # Define properties for Android with Qt 5 after find_package() calls as:
    # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(3dV
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(3dV PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(3dV PRIVATE Qt${QT_VERSION_MAJOR}::OpenGL)
target_link_libraries(3dV PRIVATE Qt${QT_VERSION_MAJOR}::OpenGLWidgets)

set_target_properties(3dV PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(3dV)
endif()