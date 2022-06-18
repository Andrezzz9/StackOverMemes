cmake_minimum_required(VERSION 3.4)	 # Проверка версии CMake.

project(memevisor)			# Название проекта

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

#find_package(Qt5 COMPONENTS Core)

set(SOURCE_LIB memevisor.cpp)

add_library(memevisor STATIC ${SOURCE_LIB})

link_directories( ${OPENCV_LIBRARY_DIRS} )

target_include_directories(
		memevisor
    PRIVATE
        ${OPENCV_INCLUDE_DIRS}
)

# Линковка программы с библиотекой
target_link_libraries(
		memevisor
	PRIVATE
		Qt5::Core
		${OpenCV_LIBS}
)