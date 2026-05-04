cmake_minimum_required(VERSION 3.5)

project(ScannerApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_TOOLCHAIN_FILE "C:/Users/naird/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)
find_package(Qt6 REQUIRED COMPONENTS OpenGL)
find_package(Qt6 REQUIRED COMPONENTS SerialPort)
find_package(PCL REQUIRED)
find_package(PCL REQUIRED COMPONENTS surface)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        visualizer.cpp
        visualizer.h
        pcdvertices.cpp
        pcdvertices.h
        pointcloudhandler.h
        pointcloudhandler.cpp


)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ScannerApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        visualizer.h visualizer.cpp
        vis_frag.glsl
        vis_vert.glsl
        resources.qrc
        gridvertices.h gridvertices.cpp
        grid_frag.glsl
        grid_vert.glsl
        grid_vert.glsl

        pointcloudhandler.h pointcloudhandler.cpp
        colorutils.h
        propdialog.h propdialog.cpp
        propdialog.ui
        types/position.h
        types/keyframe.h
        helpers/PointCloudIO.h
        PointCloudIO.cpp
        types/pointtypes.h
        utils/position_utils.h
        types/pose.h
        types/node.h
        constants.h
        types/edge.h
        types/posegraph.h
        helpers/TransformHelper.h
        TransformHelper.cpp
        types/registrationresult.h



    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ScannerApp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ScannerApp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ScannerApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ScannerApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(ScannerApp PRIVATE Qt6::OpenGLWidgets)
target_link_libraries(ScannerApp PRIVATE Qt6::OpenGL)
target_link_libraries(ScannerApp PRIVATE Qt6::SerialPort)
target_link_libraries(ScannerApp PRIVATE ${PCL_LIBRARIES})
target_include_directories(ScannerApp PRIVATE ${PCL_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}         # project root
    ${CMAKE_CURRENT_SOURCE_DIR}/types   # types folder
    )
add_definitions(${PCL_DEFINITIONS})

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ScannerApp)
endif()
set_target_properties(ScannerApp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ScannerApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ScannerApp)
endif()
