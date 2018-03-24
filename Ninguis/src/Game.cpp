//
//  Game.cpp
//  Ninguis
//
//  Created by Robin Sullivan on 05/03/2018.
//  Copyright © 2018 Robin Sullivan. All rights reserved.
//

#include <Game.hpp>


void Game::Initialize()
{
    this -> dt = 1.f/60.f;
    this -> accumulator = 0.f;
    
    //this if is here if we decide to change this class to static
    if(gameState != GameState::Uninitialized)
    {
        return;
    }
    mainWindow.create(sf::VideoMode(sf::VideoMode::getDesktopMode()), "Ninguis");
    gameState = GameState::Playing;
    
    
    //TODO: implement resource path builder
    player.Load("/users/theivoz/Documents/Ninguis Project/Ninguis/Ninguis/Resources/VG_Circle.png");
    player.setPosition(mainWindow.getSize().x / 4.0f, mainWindow.getSize().y / 4.0f);
    player.setScale(4, 4);
    
    
    while(!IsExiting())
    {
        GameLoop();
    }
    
    mainWindow.close();
}

bool Game::IsExiting()
{
    return (gameState == GameState::Exiting) ? true : false;
}

void Game::GameLoop()
{
    sf::Event currentEvent;
    while(mainWindow.pollEvent(currentEvent))
    {
        mainWindow.clear(sf::Color(72,163,242));
        mainWindow.display();

        //TODO: switch for all game states
        if (gameState == GameState::Playing)
        {
            this -> accumulator += this -> clock.restart().asSeconds();
            this -> keyCodePressed = input.TakeInputs(mainWindow);
            
            while (this -> accumulator >= this -> dt)
            {
                this -> runPhysics.MoveSprites(this -> keyCodePressed);
                
                this -> accumulator -= this -> dt;
            }
            player.Draw(mainWindow);
            std::cout << "Window width: "<< mainWindow.getSize().x << "\n";
            std::cout << "Window height: "<< mainWindow.getSize().y << "\n";
            std::cout << "Player x: "<< mainWindow.getSize().x / 4.0f << "\n";
            std::cout << "Player y: "<< mainWindow.getSize().y / 4.0f << "\n";
            //Render();
            
        }
        if ((currentEvent.type == sf::Event::KeyPressed && currentEvent.key.code == sf::Keyboard::Escape) || currentEvent.type == sf::Event::Closed)
        {
            gameState = GameState::Exiting;
        }
    }
    
    
}
