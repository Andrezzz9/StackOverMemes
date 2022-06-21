cmake_minimum_required(VERSION 3.4)	 # Проверка версии CMake.

project(logmanager)			# Название проекта

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core)

set(SOURCE_LIB logmanager.cpp)

add_library(logmanager ${SOURCE_LIB})

# Линковка программы с библиотекой
target_link_libraries(
	logmanager
PRIVATE
	Qt5::Core
)