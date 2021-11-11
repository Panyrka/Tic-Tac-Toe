#pragma once

#include <iostream>

#include "player.h"
#include "game_field.h"

/**
 * \brief ����� ��� ��������� ��������� ���� � ��������-������
 */
class game_handler
{
private:
	/**
	 * \brief ����������� �����
	 */
	static constexpr size_t rows = 3;

	/**
	 * \brief ���������� ��������
	 */
	static constexpr size_t columns = 3;

	/**
	 * \brief ������ �������
	 */
	std::array<std::shared_ptr<player>, 2> players_;

	/**
	 * \brief ������� ����
	 */
	game_field game_field_;

	/**
	 * \brief ���������� ��������, ����������� � ����
	 */
	size_t number_of_moves_ = 0;

	/**
	 * \brief ��������������� ����� ��� �������� ������������ ���� ������
	 * \param cord ���������� ���� ������
	 * \return ����� �� ����� ������� ����� ���
	 */
	bool is_correct_move(const coordinate& cord) const;

	/**
	 * \brief ����� ��� �������� ����, �� ���������� �� ��� ����
	 * \return ������ ����������� ������, ���� ����������� ���, �� ���������� figure::empty
	 */
	figure is_game_finished() const;

	/**
	 * \brief ����� ��� ��������� �������� �������
	 * \return ������ ������, ������� �������, ���� ����������� ���, �� ���������� figure::empty
	 */
	figure do_moves();

	/**
	 * \brief ����� ��� ������ ���������� � ������� � �� ��������� ����
	 * \param fig ������ ������, ������� �������, ���� ����������� ���, �� figure::empty
	 */
	static void finish_round(const figure& fig);

	/**
	 * \brief ��������������� ����� ��� ����������� ������ ������ �� ������. ��� empty ��������� = 0
	 * \param fig ������ ������
	 * \return ����� ������
	 */
	static size_t get_players_number_by_enum(const figure& fig);

public:
	/**
	 * \brief ����������� ��� �������� ���������� ������
	 * \param players ������ � ��������
	 */
	game_handler(std::array<std::shared_ptr<player>, 2> players)
	: players_(std::move(players))
	{}

	/**
	 * \brief �������� ����� ��� ���������� ����
	 * \return ����� ����������� ������
	 * 0 - ������� ������ �����
	 * 1 - ������� ������ �����
	 * 2 - �����
	 */
	size_t play_game();
};