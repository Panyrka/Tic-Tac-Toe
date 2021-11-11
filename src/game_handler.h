#pragma once

#include <iostream>

#include "player.h"
#include "game_field.h"

/**
 * \brief Класс для обработки отдельной игры в крестики-нолики
 */
class game_handler
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
	 * \brief Массив игроков
	 */
	std::array<std::shared_ptr<player>, 2> players_;

	/**
	 * \brief Игровое поле
	 */
	game_field game_field_;

	/**
	 * \brief Количество действий, совершённых в игре
	 */
	size_t number_of_moves_ = 0;

	/**
	 * \brief Вспомогательный метод для проверки корректности хода игрока
	 * \param cord Координаты хода игрока
	 * \return Может ли игрок сделать такой ход
	 */
	bool is_correct_move(const coordinate& cord) const;

	/**
	 * \brief Метод для проверки того, не зкончилась ли ещё игра
	 * \return Фигуру выигравшего игрока, если победителей нет, то возвращает figure::empty
	 */
	figure is_game_finished() const;

	/**
	 * \brief Метод для обработки действий игроков
	 * \return Фигура игрока, который победил, если победителей нет, то возвращает figure::empty
	 */
	figure do_moves();

	/**
	 * \brief Метод для вывода информации в консоль о об окончании игры
	 * \param fig Фигура игрока, который победил, если победителей нет, то figure::empty
	 */
	static void finish_round(const figure& fig);

	/**
	 * \brief Вспомогательный метод для определения номера игрока по фигуре. Для empty результат = 0
	 * \param fig Фигура игрока
	 * \return Номер игрока
	 */
	static size_t get_players_number_by_enum(const figure& fig);

public:
	/**
	 * \brief Конструктор для создания экземпляра класса
	 * \param players Массив с игроками
	 */
	game_handler(std::array<std::shared_ptr<player>, 2> players)
	: players_(std::move(players))
	{}

	/**
	 * \brief Основной метод для проведения игры
	 * \return Номер победившего игрока
	 * 0 - победил первый игрок
	 * 1 - победил второй игрок
	 * 2 - ничья
	 */
	size_t play_game();
};