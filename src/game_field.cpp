#include <iostream>

#include "game_field.h"

char game_field::get_figure_by_int(const figure& fig)
{
	switch (fig)
	{
	case figure::nought:
		return '0';
	case figure::cross:
		return 'X';
	case figure::empty:
		return '_';
	}
	return '_';
}

game_field::game_field(): game_field_(std::array<std::array<figure, rows>, columns>())
{
	fill(figure::empty);
}

void game_field::fill(const figure& fig)
{
	for (auto& column : game_field_)
	{
		column.fill(fig);
	}
}

void game_field::set(const coordinate& cord, const figure& fig)
{
	if (cord.column < columns && cord.row < rows)
	{
		game_field_[cord.column][cord.row] = fig;
	}
	else
	{
		throw std::exception("Can't resolver coordinates");
	}
}

figure game_field::get(const coordinate& cord) const
{
	if (cord.column < columns && cord.row < rows)
	{
		return game_field_[cord.column][cord.row];
	}
	throw std::exception("Can't resolver coordinates");
}

void game_field::print_game_field_to_cmd() const
{
	for (const auto& column : game_field_)
	{
		for (const auto& cell : column)
		{
			std::cout << get_figure_by_int(cell) << " ";
		}
		std::cout << std::endl;
	}
}