#pragma once

#include "player.h"

/**
 * \brief Класс игрока, который будет ходить случайным образом
 */
class random_player final : public player
{
public:
	/**
	 * \brief Конструктор для создания экземпляра случайного игрока
	 * \param name Имя игрока
	 */
	explicit random_player(std::string name) :
		player(std::move(name))
	{}

	/**
	 * \brief Метод для получения хода от игрока
	 * \param gf игровое поле
	 * \param number_of_moves количество совершенных ходов
	 * \param players_figure фигура игрока
	 * \return координату, по которой нужно походить
	 */
	[[nodiscard]] coordinate get_move(const game_field& gf, const size_t number_of_moves, const figure& players_figure) const override;
};