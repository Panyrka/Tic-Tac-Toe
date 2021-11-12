#include <iostream>

#include "user.h"

coordinate user::get_move(const game_field& gf, const size_t number_of_moves, const figure& players_figure) const
{
	std::cout << "Please enter your turn (1-9): ";
	size_t user_input;
	std::cin >> user_input;
	--user_input;
	coordinate cord{ user_input / 3, user_input % 3 };

	while (gf.get(cord).is_empty())
	{
		std::cout << "Incorrect position, please, try again: ";
		std::cin >> user_input;
		--user_input;
		cord = { user_input / 3, user_input % 3 };
	}

	return cord;
}