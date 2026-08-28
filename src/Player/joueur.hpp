#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class joueur {
private:
    int vie;

    float pos_x;
    float pos_y;
    float speed;

    float tempsAccumule = 0;

    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock clock;

    bool tire = false;

public: 
    joueur(int v, float x, float y, float spe);

    void Update(sf::RenderWindow& window);
    void afficherJoueur(sf::RenderWindow& window);
    //void Attaquer(float temps, sf::RenderWindow& window);
    int getXJoueur();
    int getYJoueur();
};