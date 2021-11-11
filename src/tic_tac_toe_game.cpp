#include "tic_tac_toe_game.h"
#include "smart_player.h"
#include "user.h"
#include "random_player.h"

void tic_tac_toe_game::setup_parameters()
{
	size_t type;
	std::string player_name;
	std::cout << "Choose type of first player(0 - user, 1 - random player, 2 - smart player): ";
	std::cin >> type;
	std::cout << "Enter name for the first player: ";
	std::cin >> player_name;

	switch (type)
	{
	case 0:
		players_[0] = std::make_shared<user>(player_name);
		break;
	case 1:
		players_[0] = std::make_shared<random_player>(player_name);
		break;
	case 2:
		players_[0] = std::make_shared<smart_player>(player_name);
		break;
	default:
		players_[0] = std::make_shared<random_player>(player_name);
	}

	std::cout << "Choose type of second player(0 - user, 1 - random player, 2 - smart player): ";
	std::cin >> type;
	std::cout << "Enter name for the second player: ";
	std::cin >> player_name;

	switch (type)
	{
	case 0:
		players_[1] = std::make_shared<user>(player_name);
		break;
	case 1:
		players_[1] = std::make_shared<random_player>(player_name);
		break;
	case 2:
		players_[1] = std::make_shared<smart_player>(player_name);
		break;
	default:
		players_[1] = std::make_shared<random_player>(player_name);
	}

	std::cout << "Please enter number of games: ";
	std::cin >> number_of_games_;
}

void tic_tac_toe_game::play_games() const
{
	size_t number_of_first_player_wins = 0;
	size_t number_of_second_player_wins = 0;
	size_t number_of_draws = 0;

	for (size_t i = 0; i < number_of_games_; i++)
	{
		game_handler gm(players_);
		const size_t result = gm.play_game();
		switch (result)
		{
		case 0:
			++number_of_first_player_wins;
			break;
		case 1:
			++number_of_second_player_wins;
			break;
		case 2:
		default:
			++number_of_draws;
		}
	}

	std::cout << "First player " << players_[0]->get_name() << " wins: " << number_of_first_player_wins << std::endl
		<< "Second player " << players_[1]->get_name() << " wins: " << number_of_second_player_wins << std::endl
		<< "Draws: " << number_of_draws << std::endl;
}
