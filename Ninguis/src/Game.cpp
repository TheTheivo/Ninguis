//
//  Game.cpp
//  Ninguis
//
//  Created by Robin Sullivan on 05/03/2018.
//  Copyright © 2018 Robin Sullivan. All rights reserved.
//
#include <iostream>
#include <Game.hpp>

void Game::Initialize()
{
    //this if is here if we decide to change this class to static
    if(_gameState != GameState::Uninitialized)
    {
        return;
    }
    _mainWindow.create(sf::VideoMode(sf::VideoMode::getDesktopMode()), "Ninguis");
    _gameState = GameState::Playing;
    
    
    //TODO: implement resource path builder
    _player.Load("/users/theivoz/Documents/Ninguis Project/Ninguis/Ninguis/Resources/VG_Circle.png");
    _player.setPosition(_mainWindow.getSize().x / 4.0f, _mainWindow.getSize().y / 4.0f);
    _player.setScale(5, 5);
    
    
    while(!IsExiting())
    {
        GameLoop();
    }
    
    _mainWindow.close();
}

bool Game::IsExiting()
{
    return (_gameState == GameState::Exiting) ? true : false;
}

void Game::GameLoop()
{
    sf::Event currentEvent;
    while(_mainWindow.pollEvent(currentEvent))
    {
        //TODO: switch for all game states
        if (_gameState == GameState::Playing)
        {
            _mainWindow.clear(sf::Color(255,255,255));
            _player.Draw(_mainWindow);
            _mainWindow.display();
            
        }
        if ((currentEvent.type == sf::Event::KeyPressed && currentEvent.key.code == sf::Keyboard::Escape) || currentEvent.type == sf::Event::Closed)
        {
            _gameState = GameState::Exiting;
        }
    }
}
