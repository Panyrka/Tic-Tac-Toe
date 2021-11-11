#pragma once
#include <string>

#include "game_field.h"
#include "coordinate.h"

/**
 * \brief Класс для описания базового игрока
 */
class player
{
private:
	/**
	 * \brief Имя игрока
	 */
	std::string name_;
	
public:
	/**
	 * \brief Конструктор для создания экземпляра игрока
	 * \param name Имя игрока
	 */
	explicit player(std::string name) : name_(std::move(name))
	{}

	virtual ~player() = default;

	/**
	 * \brief Метод для получения хода от игрока
	 * \param gf игровое поле
	 * \param number_of_moves количество совершённых ходов 
	 * \param players_figure фигура игрока
	 * \return координату, по которой нужно походить
	 */
	virtual coordinate get_move(const game_field& gf, const size_t number_of_moves, const figure& players_figure) = 0;

	/**
	 * \brief Метод для получения имени игрока
	 * \return Имя игрока
	 */
	std::string get_name() const;
};