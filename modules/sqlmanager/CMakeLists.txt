cmake_minimum_required(VERSION 3.4)	 # Проверка версии CMake.

project(sqlmanager)			# Название проекта

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core)

set(SOURCE_LIB sqlmanager.cpp)

add_library(sqlmanager STATIC ${SOURCE_LIB})

# Линковка программы с библиотекой
target_link_libraries(
	sqlmanager
PRIVATE
	Qt5::Core
)