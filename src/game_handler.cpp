#include "game_handler.h"

bool game_handler::is_correct_move(const coordinate& cord) const
{
	if (game_field_.get(cord) == figure::empty)
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

	return figure::empty;
}

figure game_handler::do_moves()
{
	while (number_of_moves_ < 9)
	{
		const size_t player_number = number_of_moves_ % 2;
		const auto current_figure = static_cast<const figure>(player_number);

		std::cout << "Move #" << number_of_moves_ << ", "
			<< players_[player_number]->get_name() << " move" << std::endl
			<< "Game field: " << std::endl;

		game_field_.print_game_field_to_cmd();

		const coordinate player_move = players_[player_number]->get_move(game_field_, number_of_moves_, current_figure);
		if (!is_correct_move(player_move))
		{
			std::cout << "Incorrect move from player " + players_[player_number]->get_name()
				<< std::endl << "Technical lose for this player." << std::endl;
			return static_cast<const figure>(!player_number);
		}
		game_field_.set(player_move, current_figure);

		std::cout << "Player " << players_[player_number]->get_name()
			<< " made move on [" << player_move.column << ", " << player_move.row << "]"
			<< std::endl << std::endl << std::endl;

		const auto win_figure = is_game_finished();
		if (win_figure != figure::empty)
		{
			std::cout << "Player " << players_[player_number]->get_name()
				<< " won the game!!!!" << std::endl;
			return win_figure;
		}

		number_of_moves_++;
	}
	return figure::empty;
}

void game_handler::finish_round(const figure& fig)
{
	if (fig == figure::empty)
	{
		std::cout << "Game over! The game is a draw." << std::endl << std::endl;
	}
	else
	{
		std::cout << "Player " << get_players_number_by_enum(fig) << " won!" << std::endl << std::endl;
	}
}

size_t game_handler::get_players_number_by_enum(const figure& fig)
{
	switch (fig)
	{
	case figure::cross:
		return 0;
	case figure::nought:
		return 1;
	case figure::empty:
	default:
		return 2;
	}
}

size_t game_handler::play_game()
{
	std::cout << "Started game Tic-Tac-Toe with two players: "
		<< players_[0]->get_name() << " and "
		<< players_[1]->get_name() << std::endl;

	const auto win_figure = do_moves();
	finish_round(win_figure);

	switch (win_figure)
	{
	case figure::cross:
		return 0;
	case figure::nought:
		return 1;
	case figure::empty:
	default:
		return 2;
	}
}
