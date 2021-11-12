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
	 * \brief Количество рядов
	 */
	static constexpr size_t rows = 3;

	/**
	 * \brief Количество столбцов
	 */
	static constexpr size_t columns = 3;

	/**
	 * \brief Максимальное количество ходов в игре
	 */
	static constexpr size_t max_number_of_moves = 9;

	/**
	 * \brief Массив игроков
	 */
	std::array<std::shared_ptr<player>, 2> players_;

	/**
	 * \brief Игровое поле
	 */
	game_field game_field_;

	/**
	 * \brief Количество действий, совершенных в игре
	 */
	size_t number_of_moves_ = 0;

	/**
	 * \brief Вспомогательный метод для проверки корректности хода игрока
	 * \param cord Координаты хода игрока
	 * \return Может ли игрок сделать такой ход
	 */
	[[nodiscard]] bool is_correct_move(const coordinate& cord) const;

	/**
	 * \brief Метод для проверки того, не закончилась ли ещё игра
	 * \return Фигуру выигравшего игрока, если победителей нет
	 * или игра не закончена, то возвращает пустую фигуру
	 */
	[[nodiscard]] figure is_game_finished() const;

	/**
	 * \brief Метод для обработки действий игроков
	 * \return Фигура игрока, который победил, если победителей нет, то возвращает пустую фигуру
	 */
	[[nodiscard]] figure do_moves();

	/**
	 * \brief Метод для вывода информации в консоль о об окончании игры
	 * \param fig Фигура игрока, который победил, если победителей нет, то figure::empty
	 */
	void finish_round(const figure& fig) const;

	/**
	 * \brief Метод для получения фигуры игрока на текущем ходу
	 * \return Фигура игрока для текущего хода (number_of_moves_)
	 */
	[[nodiscard]] figure get_current_players_figure() const;

	/**
	 * \brief Метод для получения действия от игрока
	 * \param player Игрок, от которого нужно получить действие
	 * \param players_figure Фигура игрока
	 * \return Координаты, по которым хочет походить игрок
	 */
	[[nodiscard]] coordinate get_move_from_player(const std::shared_ptr<player>& player, const figure& players_figure) const;

	/**
	 * \brief Метод для записи действия игрока
	 * \param player Игрок, совершивший действие
	 * \param players_move Действие, полученное от игрока
	 * \param players_figure Фигура игрока
	 * \return Получилось ли записать действие
	 */
	[[nodiscard]] bool make_players_move(const std::shared_ptr<player>& player, const coordinate& players_move, const figure& players_figure);

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
	[[nodiscard]] size_t play_game();
};
