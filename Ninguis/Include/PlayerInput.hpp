//
//  PlayerInput.hpp
//  Ninguis
//
//  Created by Robin Sullivan on 14/03/2018.
//  Copyright © 2018 Robin Sullivan. All rights reserved.
//

#ifndef PlayerInput_hpp
#define PlayerInput_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <SFML/Window/Keyboard.hpp>

#endif /* PlayerInput_hpp */
class PlayerInput
{
public:
    PlayerInput();
    ~PlayerInput();
    
    std::uint8_t TakeInputs(sf::RenderWindow & renderWindow);
    
private:
    sf::Event currentEvent;
};
