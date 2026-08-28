#pragma once

#include "Player/joueur.hpp"
#include "Enemy/Chaser.hpp"
#include <SFML/Graphics.hpp>

class Attaque {
private:

    float speedAttaque;
    float pos_xAttaque;
    float pos_yAttaque;

    sf::Texture textureAttaque;
    sf::Sprite spriteAttaque;
    sf::Clock clockCd;
    sf::RenderWindow& window;


public:
    Attaque(float speed, joueur& jou, sf::RenderWindow& win);
    void creationSprite(sf::RenderWindow& window);
    void mouvementAttaque();

};