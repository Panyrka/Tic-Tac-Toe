#pragma once

#include "player.h"
#include "game_handler.h"

/**
 * \brief ����� ��� ���������� ��� � �������� ������
 */
class tic_tac_toe_game
{
private:
	/**
	 * \brief ������ � ��������
	 */
	std::array<std::shared_ptr<player>, 2> players_;

	/**
	 * \brief ���������� ���, ������� ����� ��������
	 */
	size_t number_of_games_;

public:
	tic_tac_toe_game() : number_of_games_(0) {}

	/**
	 * \brief ����� ��� ��������� ���������� (������, ���������� ���) � ����
	 */
	void setup_parameters();

	/**
	 * \brief ����� ��� ������� ��� � ������ ���������� � �������
	 */
	void play_games() const;
};