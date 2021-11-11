#pragma once

#include "player.h"

/**
 * \brief ����� ������, ������� ����� ������ ��������� �������
 */
class random_player final : public player
{
public:
	/**
	 * \brief ����������� ��� �������� ���������� ���������� ������
	 * \param name ��� ������
	 */
	explicit random_player(std::string name) :
		player(std::move(name))
	{}

	/**
	 * \brief ����� ��� ��������� ���� �� ������
	 * \param gf ������� ����
	 * \param number_of_moves ���������� ����������� �����
	 * \param players_figure ������ ������
	 * \return ����������, �� ������� ����� ��������
	 */
	coordinate get_move(const game_field& gf, const size_t number_of_moves, const figure& players_figure) override;
};