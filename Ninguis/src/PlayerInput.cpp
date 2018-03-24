//
//  PlayerInput.cpp
//  Ninguis
//
//  Created by Robin Sullivan on 14/03/2018.
//  Copyright © 2018 Robin Sullivan. All rights reserved.
//

#include <PlayerInput.hpp>

PlayerInput::PlayerInput()
{
}
PlayerInput::~PlayerInput()
{
}

std::uint8_t PlayerInput::TakeInputs(sf::RenderWindow & renderWindow)
{
    sf::Event event;
    while (renderWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            renderWindow.close();
        }
    }
    std::uint8_t input{0};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        return sf::Keyboard::Left;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        return sf::Keyboard::Right;
    }
    return 255;
}
