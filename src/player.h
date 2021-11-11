#pragma once
#include <string>

#include "game_field.h"
#include "coordinate.h"

/**
 * \brief ����� ��� �������� �������� ������
 */
class player
{
private:
	/**
	 * \brief ��� ������
	 */
	std::string name_;
	
public:
	/**
	 * \brief ����������� ��� �������� ���������� ������
	 * \param name ��� ������
	 */
	explicit player(std::string name) : name_(std::move(name))
	{}

	virtual ~player() = default;

	/**
	 * \brief ����� ��� ��������� ���� �� ������
	 * \param gf ������� ����
	 * \param number_of_moves ���������� ����������� ����� 
	 * \param players_figure ������ ������
	 * \return ����������, �� ������� ����� ��������
	 */
	virtual coordinate get_move(const game_field& gf, const size_t number_of_moves, const figure& players_figure) = 0;

	/**
	 * \brief ����� ��� ��������� ����� ������
	 * \return ��� ������
	 */
	std::string get_name() const;
};