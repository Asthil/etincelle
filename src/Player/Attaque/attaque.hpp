#pragma once

#include <vector>

#include "Player/joueur.hpp"
#include "Enemy/Chaser.hpp"
#include <SFML/Graphics.hpp>

class Attaque {
private:

    float speedAttaque;
    float pos_xAttaque;
    float pos_yAttaque;

    float pos_xChaser;
    float pos_yChaser;

    sf::Texture textureAttaque;
    sf::Sprite spriteAttaque;
    sf::Clock clockCd;
    sf::RenderWindow& win;

    vector<Chaser> c


public:
    Attaque(float speed, joueur& jou, sf::RenderWindow& win, vector<Chaser> cha);
    void creationSprite(sf::RenderWindow& window);
    void mouvementAttaque();

};