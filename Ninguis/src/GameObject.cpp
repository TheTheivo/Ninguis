//
//  GameObject.cpp
//  Ninguis
//
//  Created by Robin Sullivan on 05/03/2018.
//  Copyright © 2018 Robin Sullivan. All rights reserved.
//

#include <GameObject.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

GameObject::GameObject()
{
    _isLoaded = false;
}

GameObject::~GameObject()
{
}

void GameObject::Load(std::string filename)
{
    //TODO: try/catch block
    if(_image.loadFromFile(filename) == false)
    {
        _filename = "";
        _isLoaded = false;
        
    }
    else
    {
        _filename = filename;
        _sprite.setTexture(_image);
        _isLoaded = true;
    }
}

void GameObject::Draw(sf::RenderWindow & render)
{
    if(_isLoaded)
    {
        render.draw(_sprite);
    }
}

void GameObject::setPosition(float x, float y)
{
    if(_isLoaded)
    {
        _sprite.setPosition(x,y);
    }
}

void GameObject::setScale(float x, float y)
{
    _sprite.setScale(x, y);
}
