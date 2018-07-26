cmake_minimum_required(VERSION 2.8)
project(uno)

configure_file(Assets.h.cmake ${CMAKE_SOURCE_DIR}/include/Assets.h)
include_directories(${CMAKE_SOURCE_DIR}/include)
set(SRC src/main.cpp
		src/MainMenu.cpp
		src/ColorSelectorEntity.cpp
		src/ConfigMenu.cpp
		src/GameScene.cpp
		src/Deck.cpp
		src/Card.cpp
		src/CardEntity.cpp
		src/Player.cpp
		src/AI.cpp
		src/Controller.cpp)

add_executable(uno ${SRC})
target_link_libraries(uno -llittle-knight -lsfml-window -lsfml-graphics -lsfml-system)
