#include "game_handler.h"

bool game_handler::is_correct_move(const coordinate& cord) const
{
	if (game_field_.get(cord).is_empty())
	{
		return true;
	}
	return false;
}

figure game_handler::is_game_finished() const
{
	for (size_t i = 0; i < rows; ++i)
	{
		if (game_field_.get({ i, 0 }) == game_field_.get({ i, 1 })
			&& game_field_.get({ i, 1 }) == game_field_.get({ i, 2 }))
		{
			return game_field_.get({ i, 0 });
		}

		if (game_field_.get({ 0, i }) == game_field_.get({ 1, i })
			&& game_field_.get({ 1, i }) == game_field_.get({ 2, i }))
		{
			return game_field_.get({ 0, i });
		}
	}

	if ((game_field_.get({ 0, 0 }) == game_field_.get({ 1, 1 })
		&& game_field_.get({ 1, 1 }) == game_field_.get({ 2, 2 }))
		|| (game_field_.get({ 0, 2 }) == game_field_.get({ 1, 1 })
			&& game_field_.get({ 1, 1 }) == game_field_.get({ 2, 0 })))
	{
		return game_field_.get({ 1, 1 });
	}

	return figure::get_empty_figure();
}

figure game_handler::do_moves()
{
	while (number_of_moves_ < max_number_of_moves)
	{
		const size_t player_number = number_of_moves_ % 2;
		const auto& current_player = players_[player_number];
		const auto current_figure = get_current_players_figure();

		std::cout << "Move #" << number_of_moves_ << ", " << current_player->get_name()
			<< " move" << std::endl << "Game field: " << std::endl;

		game_field_.print_game_field_to_cmd();

		const coordinate players_move = get_move_from_player(current_player, current_figure);

		if (!make_players_move(current_player, players_move, current_figure))
		{
			return current_figure.get_opposite_figure();
		}

		const auto win_figure = is_game_finished();
		if (!win_figure.is_empty())
		{
			std::cout << "Player " << current_player->get_name()
				<< " won the game!" << std::endl;
			return win_figure;
		}

		number_of_moves_++;
	}

	return figure::get_empty_figure();
}

void game_handler::finish_round(const figure& fig) const
{
	game_field_.print_game_field_to_cmd();
	if (fig.is_empty())
	{
		std::cout << "Game over! The game is a draw." << std::endl << std::endl;
	}
	else
	{
		std::cout << "Player " << fig.get_int() << " won!" << std::endl << std::endl;
	}
}

figure game_handler::get_current_players_figure() const
{
	if (number_of_moves_ % 2 == 0)
	{
		return figure(figure_enum::cross);
	}
	return figure(figure_enum::nought);
}

coordinate game_handler::get_move_from_player(const std::shared_ptr<player>& player, const figure& players_figure) const
{
	return player->get_move(game_field_, number_of_moves_, players_figure);
}

bool game_handler::make_players_move(const std::shared_ptr<player>& player, const coordinate& players_move, const figure& players_figure)
{
	if (!is_correct_move(players_move))
	{
		std::cout << "Incorrect move from player " + player->get_name()
			<< std::endl << "Technical lose for this player." << std::endl;
		return false;
	}

	game_field_.set(players_move, players_figure);

	std::cout << "Player " << player->get_name()
		<< " made move on [" << players_move.column << ", " << players_move.row << "]"
		<< std::endl << std::endl;

	return true;
}

size_t game_handler::play_game()
{
	std::cout << "Started game Tic-Tac-Toe with two players: "
		<< players_[0]->get_name() << " and "
		<< players_[1]->get_name() << std::endl;

	const auto win_figure = do_moves();

	finish_round(win_figure);

	return win_figure.get_int();
}
