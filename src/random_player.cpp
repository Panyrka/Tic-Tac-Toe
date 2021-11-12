#include "random_player.h"

coordinate random_player::get_move(const game_field& gf, const size_t number_of_moves, const figure& players_figure) const
{
	coordinate cord{};
	do
	{
		const size_t random_number = rand() % 9;
		cord = { random_number % 3, random_number / 3 };
	} while (!gf.get(cord).is_empty());
	return cord;
}
