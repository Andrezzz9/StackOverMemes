cmake_minimum_required(VERSION 3.4)	 # Проверка версии CMake.

set(PRJ_NAME stackovermemes)
project(${PRJ_NAME})			# Название проекта

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_COLOR_MAKEFILE ON)
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY AUTOGEN_TARGETS_FOLDER AutoMoc)


list(APPEND CMAKE_PREFIX_PATH "C:/Qt/5.15.2/msvc2019_64/lib/cmake/")
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/build/3rdparty/opencv/)
#list(APPEND CMAKE_PREFIX_PATH C:/Hobby/StackOverMemes/build/3rdparty/opencv/install/x64/vc17/staticlib)

find_package(Qt5 COMPONENTS Core Network REQUIRED)
if (${Qt5_FOUND})
    message("Found Qt " ${Qt5_VERSION})
else()
    message("Couldn't find Qt")
endif()

find_package( OpenCV REQUIRED)

set(SOURCE_EXE ./modules/core/main.cpp)		# Установка переменной со списком исходников для исполняемого файла

include_directories(./modules/vkmanager)
include_directories(./modules/logmanager)
include_directories(./modules/sqlmanager)
include_directories(./modules/memevisor)

add_executable(${PRJ_NAME} ${SOURCE_EXE})	# Создает исполняемый файл с именем main

include_directories(${Qt5Core_INCLUDES})
add_definitions(${Qt5Core_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${Qt5Core_EXECUTABLE_COMPILE_FLAGS}")

add_subdirectory(./modules/vkmanager)
add_subdirectory(./modules/logmanager)
add_subdirectory(./modules/sqlmanager)
add_subdirectory(./modules/memevisor)

# Линковка программы с библиотекой
target_link_libraries(
	${PRJ_NAME}
	Qt5::Core
	vkmanager 
	logmanager
	sqlmanager
	memevisor
)


# Получение и подключение пред-собранных библиотек.
if(MSVC)
    set(CMAKE_INSTALL_UCRT_LIBRARIES TRUE)
    if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
        set(CMAKE_INSTALL_DEBUG_LIBRARIES TRUE)
        include(InstallRequiredSystemLibraries)
        FILE(COPY ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION "${CMAKE_SOURCE_DIR}/build/bin")
        set(QtLibraries Qt5::Core Qt5::Network)
        foreach(module ${QtLibraries})
            message(${module})
            get_target_property(dllfile ${module} IMPORTED_LOCATION_DEBUG)
            FILE(COPY ${dllfile} DESTINATION "${CMAKE_SOURCE_DIR}/build/bin")
        endforeach()
        # #
        # set(plugins ${Qt5Gui_PLUGINS} ${Qt5Widgets_PLUGINS} ${Qt5Sql_PLUGINS})
        # foreach(plugin ${plugins})
            # get_target_property(pluginDll ${plugin} IMPORTED_LOCATION_DEBUG)
            # file(RELATIVE_PATH file ${_qt5Gui_install_prefix}/plugins ${pluginDll})
            # get_filename_component(ptype ${file} DIRECTORY)
            # FILE(COPY ${pluginDll} DESTINATION ${GEODEV_INSTALL_PATH}/${ptype})
        # endforeach()
    else()
        # include(InstallRequiredSystemLibraries)
        # FILE(COPY ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION ${GEODEV_INSTALL_PATH})
        # INSTALL(FILES ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION bin)
        # set(QtLibraries Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Xml Qt5::Sql Qt5::OpenGL Qt5::Network Qt5::Svg Qt5::PrintSupport Qt5::Test)
        # foreach(module ${QtLibraries})
            # message(${module})
            # get_target_property(dllfile ${module} IMPORTED_LOCATION_RELEASE)
            # FILE(COPY ${dllfile} DESTINATION ${GEODEV_INSTALL_PATH})
            # INSTALL(FILES ${dllfile} DESTINATION bin)
        # endforeach()
        # #
        # set(plugins ${Qt5Gui_PLUGINS} ${Qt5Widgets_PLUGINS} ${Qt5Sql_PLUGINS} ${Qt5PrintSupport_PLUGINS})
        # foreach(plugin ${plugins})
            # get_target_property(pluginDll ${plugin} IMPORTED_LOCATION_RELEASE)
            # file(RELATIVE_PATH file ${_qt5Gui_install_prefix}/plugins ${pluginDll})
            # get_filename_component(ptype ${file} DIRECTORY)
            # FILE(COPY ${pluginDll} DESTINATION ${GEODEV_INSTALL_PATH}/${ptype})
            # INSTALL(FILES ${pluginDll} DESTINATION bin/${ptype})
        # endforeach()
        # #
    endif()

file(GLOB dll_files_3rd ${PROJECT_BINARY_DIR}/3rdparty/opencv/bin/Debug/*.dll)
  foreach(dll_3rd ${dll_files_3rd})
    message(${dll_3rd})
    FILE(COPY ${dll_3rd} DESTINATION "${CMAKE_SOURCE_DIR}/build/bin")
    INSTALL(FILES ${dll_3rd} DESTINATION bin)
  endforeach()	

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
#message(STATUS "~~~~~~~~~~~~~~~~${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
	
endif()
