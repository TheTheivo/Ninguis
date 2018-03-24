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
    isLoaded = false;
}

GameObject::~GameObject()
{
}

void GameObject::Load(std::string filename)
{
    //TODO: try/catch block
    if(image.loadFromFile(filename) == false)
    {
        filename = "";
        isLoaded = false;
        
    }
    else
    {
        filename = filename;
        sprite.setTexture(image);
        isLoaded = true;
    }
}

void GameObject::Draw(sf::RenderWindow & render)
{
    if(isLoaded)
    {
        render.draw(sprite);
    }
}

void GameObject::setPosition(float x, float y)
{
    if(isLoaded)
    {
        sprite.setPosition(x,y);
    }
}

void GameObject::setScale(float x, float y)
{
    sprite.setScale(x, y);
}
