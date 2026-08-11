#include "chaser.hpp"

Chaser::Chaser(const std::string& texturePath, sf::Vector2f startPosition) 
    : texture(texturePath), sprite(texture) {
        
        vitesse = 5.f;

        sprite.setPosition(startPosition);
}


void Chaser::draw(sf::RenderWindow& window)
{
    window.draw(sprite);

}