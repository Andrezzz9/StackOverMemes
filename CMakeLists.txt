cmake_minimum_required(VERSION 3.4)	 # Проверка версии CMake.

set(PRJ_NAME stackovermemes)
project(${PRJ_NAME})			# Название проекта

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
set(CMAKE_BUILD_TYPE Debug)
#set_property(GLOBAL PROPERTY USE_FOLDERS ON)
#set_property(GLOBAL PROPERTY AUTOGEN_TARGETS_FOLDER AutoMoc)


list(APPEND CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64")
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/build/3rdparty/opencv/)
#list(APPEND CMAKE_PREFIX_PATH C:/Hobby/StackOverMemes/build/3rdparty/opencv/install/x64/vc17/staticlib)

find_package(Qt5 COMPONENTS Core)
find_package( OpenCV REQUIRED )

set(SOURCE_EXE ./modules/core/main.cpp)		# Установка переменной со списком исходников для исполняемого файла

include_directories(./modules/vkmanager)
include_directories(./modules/logmanager)
include_directories(./modules/sqlmanager)
include_directories(./modules/memevisor)

add_executable(${PRJ_NAME} ${SOURCE_EXE})	# Создает исполняемый файл с именем main

add_subdirectory(./modules/vkmanager)
add_subdirectory(./modules/logmanager)
add_subdirectory(./modules/sqlmanager)
add_subdirectory(./modules/memevisor)

# Линковка программы с библиотекой
target_link_libraries(
	${PRJ_NAME}
PRIVATE
	vkmanager 
	logmanager
	sqlmanager
	memevisor
	
	Qt5::Core
)