cmake_minimum_required(VERSION 2.8)

project("PBLoader")

#set (CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

#set(CMAKE_EXE_LINKER_FLAGS "")
#set(CMAKE_C_FLAGS "")
#set(CMAKE_CXX_FLAGS "")

set(source ${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)

set(source ${CMAKE_SOURCE_DIR}/src)
add_library(pbloader SHARED ${source}/main.cpp
                            ${source}/internal.cpp
                            ${source}/launcher.cpp
                            ${source}/api/api.cpp
                            ${source}/hooks/hook.cpp
                            ${source}/hde32/hde32.cpp
                            ${source}/api/render.cpp
                            ${source}/engine/sprite/sprite.cpp)

link_directories(${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(pbloader SDL2 SDL2_image SDL2_mixer)
