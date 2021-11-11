#pragma once

#include "player.h"

/**
 * \brief ����� "������" ������, ������� ������������ ���� ��������
 */
class smart_player final : public player
{
private:
	/**
	 * \brief ����������� �����
	 */
	static constexpr size_t number_of_rows = 3;

	/**
	 * \brief ���������� ��������
	 */
	static constexpr size_t number_of_columns = 3;

	/**
	 * \brief ��������������� �����, �����������, ��� �� ����� ���������� �� ����, ��� ���� �� �������,
	 * ����� � ��������� ������� ����������
	 * \param gf ������� ����
	 * \param figure ������
	 * \return ���������� ����� ����������
	 *	���� �� �������, �� ������������ (3, 3)
	 */
	static coordinate find_opp_under_win_combination(const game_field& gf, const figure& figure);

public:
	/**
	 * \brief ����������� ��� �������� ���������� ���������� ������
	 * \param name ��� ������
	 */
	explicit smart_player(std::string name) :
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