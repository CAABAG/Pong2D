cmake_minimum_required(VERSION 3.16)

project(Pong2D)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(vendor/SFML/include)

set(LINUX_SFML_LIB_PATH vendor/SFML/Linux/lib)

find_library(SFMLGraphics libsfml-graphics.so PATHS ${LINUX_SFML_LIB_PATH})
find_library(SFMLWindow libsfml-window.so PATHS ${LINUX_SFML_LIB_PATH})
find_library(SFMLSystem libsfml-system.so PATHS ${LINUX_SFML_LIB_PATH})

set(HEADERS
    src/Ball.h
    src/Paddle.h
    src/Pong.h
    src/WindowManager.h
)

set(SOURCES
    src/Ball.cpp
    src/main.cpp
    src/Paddle.cpp
    src/Pong.cpp
)

add_executable(Pong2D ${SOURCES})
target_link_libraries(Pong2D PUBLIC ${SFMLGraphics} ${SFMLWindow} ${SFMLSystem})
