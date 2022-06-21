cmake_minimum_required(VERSION 3.4)	 # Проверка версии CMake.

project(vkmanager)			# Название проекта

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Network)

set(SOURCE_LIB vkmanager.cpp)

add_library(vkmanager ${SOURCE_LIB})

# Линковка программы с библиотекой
target_link_libraries(
	vkmanager
PRIVATE
	Qt5::Core
	Qt5::Network
)