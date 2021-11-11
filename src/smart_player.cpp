#include "smart_player.h"

coordinate smart_player::find_opp_under_win_combination(const game_field& gf, const figure& figure)
{
    for (size_t i = 0; i < number_of_rows; ++i)
    {
        if (gf.get({ i, 0 }) == figure 
            && gf.get({ i, 0 }) == gf.get({ i, 1 }) 
            && gf.get({ i, 2 }) == figure::empty)
        {
            return {i, 2};
        }
        if (gf.get({ i, 0 }) == figure 
            && gf.get({ i, 0 }) == gf.get({ i, 2 }) 
            && gf.get({ i, 1 }) == figure::empty)
        {
            return { i, 1 };
        }
        if (gf.get({ i, 1 }) == figure 
            && gf.get({ i, 1 }) == gf.get({ i, 2 }) 
            && gf.get({ i, 0 }) == figure::empty)
        {
            return {i, 0};
        }
        if (gf.get({ 0, i }) == figure 
            && gf.get({ 0, i }) == gf.get({ 1, i }) 
            && gf.get({ 2, i }) == figure::empty)
        {
            return { 2, i };
        }
        if (gf.get({ 0, i }) == figure 
            && gf.get({ 0, i }) == gf.get({ 2, i }) 
            && gf.get({ 1, i }) == figure::empty)
        {
            return { 1, i };
        }
        if (gf.get({ 1, i }) == figure 
            && gf.get({ 1, i }) == gf.get({ 2, i }) 
            && gf.get({ 0, i }) == figure::empty)
        {
            return { 0, i };
        }
    }

    if (gf.get({0, 0}) == figure 
        && gf.get({ 0, 0 }) == gf.get({ 1, 1 }) 
        && gf.get({ 2, 2 }) == figure::empty)
    {
        return { 2, 2 };
    }
    if (gf.get({ 0, 0 }) == figure 
        && gf.get({ 0, 0 }) == gf.get({ 2, 2 }) 
        && gf.get({ 1, 1 }) == figure::empty)
    {
        return { 1, 1 };
    }
    if (gf.get({ 1, 1 }) == figure 
        && gf.get({ 1, 1 }) == gf.get({ 2, 2 })
        && gf.get({ 0, 0 }) == figure::empty)
    {
        return { 0, 0 };
    }
	if (gf.get({ 0, 2 }) == figure 
        && gf.get({ 0, 2 }) == gf.get({ 1, 1 }) 
        && gf.get({ 2, 0 }) == figure::empty)
	{
        return { 2, 0 };
	}
    if (gf.get({ 0, 0 }) == figure 
        && gf.get({ 0, 2 }) == gf.get({ 2, 0 }) 
        && gf.get({ 1, 1 }) == figure::empty)
    {
        return { 1, 1 };
    }
    if (gf.get({ 2, 0 }) == figure 
        && gf.get({ 2, 0 }) == gf.get({ 1, 1 }) 
        && gf.get({ 0, 2 }) == figure::empty)
    {
        return {0, 2};
    }

    return {number_of_rows, number_of_columns};
}

coordinate smart_player::get_move(const game_field& gf, const size_t number_of_moves, const figure& players_figure)
{
    /*
     * Алгоритм действий умного игрока:
     * В начале игрок пытается ставить свою фигуру в середине поля, если оно занято, то сверху слева или сверху справа.
     * На последующих ходах игрок проверят, есть ли такие ходы, после которых он может выиграть, и если они есть, то делает их.
     * Если таких ходов нет, то проверяет, есть ли такие ходы, которые может сделать оппонент и выиграть, и пыатесят их предотварить.
     * Если таких ходов тоже нет, то действует случайным образом.
     */

    if (number_of_moves == 0)
    {
        return { 1, 1 };
    }
    else if (number_of_moves == 1)
    {
        if (gf.get({ 1, 1 }) == figure::empty)
        {
            return { 1, 1 };
        }
        return { 0, 0 };
    }
    else if (number_of_moves == 2)
    {
        if (gf.get({ 0, 0 }) == figure::empty)
        {
            return { 0, 0 };
        }
        return { 2, 0 };
    }

    const coordinate player_under_win_combination =  find_opp_under_win_combination(gf, players_figure);
    if (player_under_win_combination.column != number_of_rows)
    {
        return player_under_win_combination;
    }

    const figure opponent_figure = players_figure == figure::cross ? figure::nought : figure::cross;
    const coordinate opponent_win_combination = find_opp_under_win_combination(gf, opponent_figure);
    if (opponent_win_combination.column != number_of_rows)
    {
        return opponent_win_combination;
    }

    coordinate cord{};
    do
    {
        const size_t random_number = rand() % 9;
        cord = { random_number / 3, random_number % 3 };
    } while (gf.get(cord) != figure::empty);
    return cord;
}
