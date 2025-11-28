cmake_minimum_required(VERSION 3.16)

project(Progdas-Final-Project LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets PrintSupport)

add_executable(Progdas-Final-Project
  main.cpp
  mainwindow.h
  mainwindow.cpp
  mainwindow.ui

  menuorder.h
  menuorder.cpp
  menuorder.ui

  cart.h
  cart.cpp
  cart.ui

  nota.h
  nota.cpp
  nota.ui

  payment.h
  payment.cpp
  payment.ui

  fotoQR.qrc
  customername.h customername.cpp
  ordermanager.h ordermanager.cpp
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
