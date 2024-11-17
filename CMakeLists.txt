cmake_minimum_required(VERSION 3.12)

project(OPENGL_Lecture)

set(CMAKE_CXX_STANDARD 17)

#add_definitions (-DDEBUG)

include_directories(
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/include 
)

link_directories(
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/Thirdparty/lib
)

add_subdirectory(wrapper)
add_subdirectory(application)

add_executable(openglStudy "main.cpp" "glad.c" "wrapper/checkError.cpp" "application/Application.cpp")

target_link_libraries(openglStudy
	glfw3.lib
	wrapper
)