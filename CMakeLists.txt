cmake_minimum_required(VERSION 2.8)

project("PBLoader")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(source ${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)

set(source ${CMAKE_SOURCE_DIR}/src)
add_library(pbloader SHARED ${source}/main.cpp
                            ${source}/internal.cpp
                            ${source}/api/api.cpp
                            ${source}/hooks/hook.cpp
                            ${source}/hde32/hde32.cpp
                            ${source}/api/render.cpp
                            ${source}/engine/sprite/sprite.cpp
                            ${source}/engine/player/player.cpp
                            ${source}/engine/mapmanager/location.cpp
                            ${source}/engine/gamemanager/gamemanager.cpp)

IF(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
ENDIF(CMAKE_COMPILER_IS_GNUCC)

link_directories(${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(pbloader SDL2 SDL2_image SDL2_mixer)
