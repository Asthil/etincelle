#pragma once

#include "Player/joueur.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

class Enemy {
protected:
    string name;

    int hp;
    int attack;

    float pos_x;
    float pos_y;
    float speed;

    sf::Clock clock;

public:
    Enemy(string n, int h, int a, float x, float y, float spe);

    virtual void mouvement(joueur j) = 0;
    virtual void draw(sf::RenderWindow& window);

    int getX();
    int getY();
};