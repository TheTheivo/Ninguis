//
//  main.cpp
//  Ninguis
//
//  Created by Robin Sullivan on 02/03/2018.
//  Copyright © 2018 Robin Sullivan. All rights reserved.
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Game.hpp>

int main(int, char const**)
{
    Game *game = new Game();
    game->Initialize();
    return EXIT_SUCCESS;
}
