#pragma once

#include "player.h"
#include "game_handler.h"

/**
 * \brief Класс для проведения игр в крестики нолики
 */
class tic_tac_toe_game
{
private:
	/**
	 * \brief Массив с игроками
	 */
	std::array<std::shared_ptr<player>, 2> players_;

	/**
	 * \brief Количество игр, которые нужно провести
	 */
	size_t number_of_games_;

public:
	tic_tac_toe_game() : number_of_games_(0) {}

	/**
	 * \brief Метод для установки параметров (игроки, количество игр) в игре
	 */
	void setup_parameters();

	/**
	 * \brief Метод для запуска игр и вывода результата в консоль
	 */
	void play_games() const;
};