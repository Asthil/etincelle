#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class joueur {
private:
    float pos_x;
    float pos_y;
    float speed;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock clock;

public:
    joueur(float x, float y, float spe);

    void Update();
    void afficherJoueur(sf::RenderWindow& window);
};