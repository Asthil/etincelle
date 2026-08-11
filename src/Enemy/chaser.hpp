#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Chaser {

public:
    Chaser(const std::string& texturePath, sf::Vector2f startPostion);

    void update(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape hitbox;
    sf::Vector2f position;
    float vitesse = 10.f;
};