cmake_minimum_required(VERSION 3.16)

set(TARGET_NAME "Pong2D")
project(${TARGET_NAME})

include_directories(vendor/SFML/include)
link_directories(vendor/SFML/Linux/lib)

set(HEADERS
    src/Ball.h
    src/Paddle.h
    src/Pong.h
    WindowManager.h
)

set(SOURCES
    src/Ball.cpp
    src/main.cpp
    src/Paddle.cpp
    src/Pong.cpp
)

add_executable(${TARGET_NAME} ${SOURCES})

set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD 20)
target_link_libraries(${TARGET_NAME} PUBLIC sfml-graphics sfml-window sfml-system)
