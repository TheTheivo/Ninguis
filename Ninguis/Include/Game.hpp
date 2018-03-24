//
//  Game.hpp
//  Ninguis
//
//  Created by Robin Sullivan on 05/03/2018.
//  Copyright © 2018 Robin Sullivan. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp


#include <iostream>
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Player.hpp>
#include <PlayerInput.hpp>
#include <Integrate.hpp>
#include <SFML/System/Clock.hpp>
//TODO: 'rethink' if the class would not be better as static
class Game
{
public:
    void Initialize();
    
private:
    bool IsExiting();
    void GameLoop();

    
    enum GameState{ Uninitialized, Playing, Exiting, InMenu, InIngameMenu};
    GameState gameState;
    sf::RenderWindow mainWindow;
    //Class gameplay memebers
    Player player;
    PlayerInput input;
    Integrate runPhysics;
    //Timestep variables
    float dt;
    float accumulator;
    sf::Clock clock;
    //Key input
    std::uint8_t keyCodePressed;
};

#endif /* Game_hpp */
