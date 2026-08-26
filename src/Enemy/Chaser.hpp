#pragma once

#include "Enemy.hpp"

using namespace std;

class Chaser : public Enemy {
private:
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Chaser() : Enemy("Chaser", 20, 10, 10, 10, 200),
    texture("assets/enemy1_sprite.png"),
    sprite(texture) 
    {
    }

    void mouvement(joueur j) override {
        float elapsed = clock.restart().asSeconds();

        int pos_xJoueur = j.getXJoueur();
        int pos_yJoueur = j.getYJoueur();

        int pos_xChaser = pos_x;
        int pos_yChaser = pos_y;

        if (pos_x < pos_xJoueur) {
            pos_x += speed * elapsed;
        }
        if (pos_x > pos_xJoueur) {
            pos_x -= speed * elapsed;
        }
        if (pos_y < pos_yJoueur) {
            pos_y += speed * elapsed;
        }
        if (pos_y > pos_yJoueur) {
            pos_y -= speed * elapsed;
        }

        sprite.setPosition(Vector2f(pos_x, pos_y));

    }

    void draw(sf::RenderWindow& window) override {
        window.draw(sprite);
    }

    

};