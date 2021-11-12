cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(TicTacToe LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)

set (MAIN src/main.cpp)

set (SOURCE
	src/coordinate.h
	src/figure.h
	src/figure.cpp
	src/game_field.cpp
	src/game_field.h
	src/game_handler.cpp
	src/game_handler.h
	src/player.cpp
	src/player.h
	src/random_player.cpp
	src/random_player.h
	src/smart_player.cpp
	src/smart_player.h
	src/tic_tac_toe_game.cpp
	src/tic_tac_toe_game.h
	src/user.cpp
	src/user.h
	)

add_executable(TicTacToe 
	${MAIN} 
	${SOURCE}
	)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT TicTacToe)