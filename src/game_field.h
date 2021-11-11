#pragma once

#include <array>

#include "figure.h"
#include "coordinate.h"

/**
 * \brief Класс для работы с игровым полем
 */
class game_field
{
private:
	/**
	 * \brief Кколичество рядов
	 */
	static constexpr size_t rows = 3;

	/**
	 * \brief Количество столбцов
	 */
	static constexpr size_t columns = 3;

	/**
	 * \brief Массив, содержащий игровое поле
	 * Является статическим, так как задаётся единожды в начале игры.
	 */
	std::array<std::array<figure, rows>, columns> game_field_;

	/**
	 * \brief Вспомогательный метод для получения символьного представления enum figure
	 * \param fig фигура, для которой нужно получить символьное представление
	 * \return символьное представление переданной фигуры
	 */
	static char get_figure_by_int(const figure& fig);

public:
	game_field();

	/**
	 * \brief Метод для заполнения всего поля какой-либо фигурой
	 * \param fig фигура для заполнения
	 */
	void fill(const figure& fig);

	/**
	 * \brief Метод для записи в клетку игрового поля указанного значения
	 * \param cord координата ячейки
	 * \param fig значение фигуры, которое нужно записать
	 */
	void set(const coordinate& cord, const figure& fig);

	/**
	 * \brief Метод для получения фигуры в клетке
	 * \param cord Координата клетки
	 * \return Фигура, находящаяся в данной клетке
	 */
	figure get(const coordinate& cord) const;

	/**
	 * \brief Метод для вывода в консоль игрового поля
	 */
	void print_game_field_to_cmd() const;
};