#pragma once

#include <array>

#include "figure.h"
#include "coordinate.h"

/**
 * \brief ����� ��� ������ � ������� �����
 */
class game_field
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
	 * \brief ������, ���������� ������� ����
	 * �������� �����������, ��� ��� ������� �������� � ������ ����.
	 */
	std::array<std::array<figure, rows>, columns> game_field_;

	/**
	 * \brief ��������������� ����� ��� ��������� ����������� ������������� enum figure
	 * \param fig ������, ��� ������� ����� �������� ���������� �������������
	 * \return ���������� ������������� ���������� ������
	 */
	static char get_figure_by_int(const figure& fig);

public:
	game_field();

	/**
	 * \brief ����� ��� ���������� ����� ���� �����-���� �������
	 * \param fig ������ ��� ����������
	 */
	void fill(const figure& fig);

	/**
	 * \brief ����� ��� ������ � ������ �������� ���� ���������� ��������
	 * \param cord ���������� ������
	 * \param fig �������� ������, ������� ����� ��������
	 */
	void set(const coordinate& cord, const figure& fig);

	/**
	 * \brief ����� ��� ��������� ������ � ������
	 * \param cord ���������� ������
	 * \return ������, ����������� � ������ ������
	 */
	figure get(const coordinate& cord) const;

	/**
	 * \brief ����� ��� ������ � ������� �������� ����
	 */
	void print_game_field_to_cmd() const;
};