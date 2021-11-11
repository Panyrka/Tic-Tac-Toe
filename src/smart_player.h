#pragma once

#include "player.h"

/**
 * \brief Класс "умного" игрока, который просчитывает свои действия
 */
class smart_player final : public player
{
private:
	/**
	 * \brief Кколичество рядов
	 */
	static constexpr size_t number_of_rows = 3;

	/**
	 * \brief Количество столбцов
	 */
	static constexpr size_t number_of_columns = 3;

	/**
	 * \brief Вспомогательный метод, проверяющий, нет ли таких комбинаций на поле, при ходе на которые,
	 * игрок с указанной фигурой выигрывает
	 * \param gf игровое поле
	 * \param figure фигура
	 * \return координата такой комбинации
	 *	Если не найдена, то возвращается (3, 3)
	 */
	static coordinate find_opp_under_win_combination(const game_field& gf, const figure& figure);

public:
	/**
	 * \brief Конструктор для создания экземпляра случайного игрока
	 * \param name Имя игрока
	 */
	explicit smart_player(std::string name) :
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