#pragma once

#include "player.h"

/**
 * \brief Метод игрока, за которого может играть пользователь
 */
class user final : public player
{
public:
	/**
	 * \brief Конструктор для создания экземпляра игрока
	 * \param name Имя игрока
	 */
	explicit user(std::string name) :
		player(std::move(name))
	{}

	/**
	 * \brief Метод для получения хода от игрока
	 * \param gf игровое поле
	 * \param number_of_moves количество совершённых ходов
	 * \param players_figure фигура игрока
	 * \return координату, по которой нужно походить
	 */
	coordinate get_move(const game_field& gf, const size_t number_of_moves, const figure& players_figure) override;
};