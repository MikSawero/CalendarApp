cmake_minimum_required(VERSION 3.19)
project(CalendarApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Sql)

qt_standard_project_setup()

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/forms)

qt_add_executable(CalendarApp
    WIN32 MACOSX_BUNDLE
    src/main.cpp
    src/models/CalendarEngine.cpp
    src/models/DatabaseManager.cpp
    src/ui/Calendar.cpp
    src/ui/DayWindow.cpp
    src/ui/EventEditorDialog.cpp

    include/models/CalendarEngine.h
    include/models/CalendarEvent.h
    include/models/DatabaseManager.h

    include/ui/Calendar.h
    include/ui/DayWindow.h
    include/ui/EventEditorDialog.h
    
    forms/Calendar.ui
    forms/DayWindow.ui
    forms/EventEditorDialog.ui
)

target_include_directories(CalendarApp
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ui
        ${CMAKE_CURRENT_SOURCE_DIR}/include/models
)

target_link_libraries(CalendarApp
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Sql
)

include(GNUInstallDirs)

install(TARGETS CalendarApp
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET CalendarApp
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
