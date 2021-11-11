#include <iostream>

#include "tic_tac_toe_game.h"

int main()
{
    try
    {
        tic_tac_toe_game game;
        game.setup_parameters();
        game.play_games();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error has occurred while playing games. Error message: " << e.what() << std::endl;
    }
    return 0;
}
