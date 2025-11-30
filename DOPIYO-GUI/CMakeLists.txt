cmake_minimum_required(VERSION 3.16)

project(Progdas-Final-Project LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets PrintSupport)

# Add include directory
include_directories(include)

add_executable(Progdas-Final-Project
    src/main.cpp

    src/mainwindow.cpp
    include/mainwindow.h
    ui/mainwindow.ui

    src/menuorder.cpp
    include/menuorder.h
    ui/menuorder.ui

    src/cart.cpp
    include/cart.h
    ui/cart.ui

    src/nota.cpp
    include/nota.h
    ui/nota.ui

    src/payment.cpp
    include/payment.h
    ui/payment.ui

    src/customername.cpp
    include/customername.h

    src/ordermanager.cpp
    include/ordermanager.h

    resources/fotoQR.qrc
)

target_link_libraries(Progdas-Final-Project PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::PrintSupport
)

include(GNUInstallDirs)
install(TARGETS Progdas-Final-Project
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
