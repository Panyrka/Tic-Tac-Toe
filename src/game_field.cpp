#include <iostream>

#include "game_field.h"

void game_field::fill(const figure& fig)
{
	game_field_.fill(fig);
}

void game_field::set(const coordinate& cord, const figure& fig)
{
	if (cord.column < columns && cord.row < rows)
	{
		game_field_[cord.row * rows + cord.column] = fig;
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
		return game_field_[cord.row * rows + cord.column];
	}
	throw std::exception("Can't resolver coordinates");
}

void game_field::print_game_field_to_cmd() const
{
	for (size_t row_number = 0; row_number < rows; ++row_number)
	{
		for (size_t column_number = 0; column_number < columns; ++column_number)
		{
			std::cout << game_field_[row_number * rows + column_number].get_char() << " ";
		}
		std::cout << std::endl;
	}
}