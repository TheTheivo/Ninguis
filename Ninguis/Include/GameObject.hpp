//
//  GameObject.hpp
//  Ninguis
//
//  Created by Robin Sullivan on 05/03/2018.
//  Copyright © 2018 Robin Sullivan. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class GameObject
{
public:
    GameObject();
    virtual ~GameObject();
    virtual void Load(std::string filename);
    virtual void Draw(sf::RenderWindow & renderWindow);
    
    virtual void setScale(float x, float y);
    virtual void setPosition(float x, float y);
    //TODO: implement movement
private:
    sf::Sprite sprite;
    sf::Texture image;
    std::string filename;
    bool isLoaded;
};

#endif /* GameObject_hpp */
