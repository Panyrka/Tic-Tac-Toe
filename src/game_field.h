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
	 * \brief ���������� �����
	 */
	static constexpr size_t rows = 3;

	/**
	 * \brief ���������� ��������
	 */
	static constexpr size_t columns = 3;

	/**
	 * \brief ������, ���������� ������� ����
	 * �������� �����������, ��� ��� �������� �������� � ������ ����.
	 */
	std::array<figure, rows * columns> game_field_;

public:
	game_field() : game_field_(std::array<figure, rows * columns>()) {}

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
	[[nodiscard]] figure get(const coordinate& cord) const;

	/**
	 * \brief ����� ��� ������ � ������� �������� ����
	 */
	void print_game_field_to_cmd() const;
};