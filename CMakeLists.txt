cmake_minimum_required(VERSION 3.5)
project(editor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-deprecated-declarations")

# Add GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(lib/glfw)
include_directories(lib/glfw/include)
set(EXTRA_LIBS ${EXTRA_LIBS} glfw ${GLFW_LIBRARIES})

include_directories(lib/fontstash/src)

include_directories(src)
add_subdirectory(src)
set(EXTRA_LIBS ${EXTRA_LIBS} Renderer)

set(FONT_PATH res/DroidSansMono.ttf)
#file(COPY ${FONT_PATH} DESTINATION DroidSansMono.ttf)


set(SOURCE_FILES main.cpp ${Resources})
add_executable(editor ${SOURCE_FILES})
target_link_libraries(editor ${EXTRA_LIBS})
