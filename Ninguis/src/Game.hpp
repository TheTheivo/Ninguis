//
//  Game.hpp
//  Ninguis
//
//  Created by Robin Sullivan on 05/03/2018.
//  Copyright © 2018 Robin Sullivan. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Player.hpp>
//TODO: 'rethink' if the class would not be better as static
class Game
{
public:
    void Initialize();
    
private:
    bool IsExiting();
    void GameLoop();
    
    enum GameState{ Uninitialized, Playing, Exiting, InMenu, InIngameMenu};
    GameState _gameState;
    sf::RenderWindow _mainWindow;
    Player _player;
};

#endif /* Game_hpp */
