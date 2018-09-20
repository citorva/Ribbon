cmake_minimum_required(VERSION 3.6)

set(PROJECT_NAME QtRibbon)
project(${PROJECT_NAME})

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/third-party/CustomWindow)

if(WIN32)
    set (CMAKE_PREFIX_PATH "C:\\Qt\\5.11.2\\msvc2017_64\\")
endif()

set(
    SOURCE_FILES
    include/RibbonMenu.hh
    src/RibbonMenu.cc
	third-party/CustomWindow/CustomWindow.hh
	third-party/CustomWindow/CustomWindow.cc
)

set(QRC_FILES)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Widgets CONFIG REQUIRED)

if (WIN32)
    add_library(${PROJECT_NAME} ${SOURCE_FILES} ${QRC_FILES})
    set_property (DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

    # deploy
    get_target_property(QT5_QMAKE_EXECUTABLE Qt5::qmake IMPORTED_LOCATION)
    set(EXAMPLE_LIBS Qt5::Widgets dwmapi uxtheme)

    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:Qt5::Widgets>
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:Qt5::Core>
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:Qt5::Gui>
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )

else()
    set(EXAMPLE_LIBS Qt5::Widgets)
endif()

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${EXAMPLE_LIBS})