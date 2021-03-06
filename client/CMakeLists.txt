cmake_minimum_required(VERSION 3.21)
project(Client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/5.12.12/mingw73_64/lib/cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Network
        REQUIRED)

add_executable(Client main.cpp
        ui-components/startingwindow.cpp
        ui-components/startingwindow.h
        ui-components/startingwindow.ui
        Client.cpp
        Client.h
        ApplicationCore.cpp
        ApplicationCore.h
        ui-components/statusdialog.cpp
        ui-components/statusdialog.h
        ui-components/statusdialog.ui
        data/AbstractData.h
        data/AbstractData.cpp
        data/Message.h
        data/Message.cpp
        data/User.h
        data/User.cpp
        data/AuthAnswer.cpp
        data/AuthAnswer.h
        data/FriendList.cpp
        data/FriendList.h
        data/MessageList.cpp
        data/MessageList.h
        data/Friend.h
        data/Friend.cpp
        ui-components/mainapplicationwindow.cpp
        ui-components/mainapplicationwindow.h
        ui-components/mainapplicationwindow.ui
        ui-components/privatemessagepanel.cpp
        ui-components/privatemessagepanel.h
        ui-components/privatemessagepanel.ui)
target_link_libraries(Client
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Network
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
