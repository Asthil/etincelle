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


public:
    Attaque(float speed, joueur jou);
    void creationSprite();
    void mouvementAttaque();

};