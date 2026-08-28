#include "joueur.hpp"

using namespace std;
using namespace sf;



joueur::joueur(int v, float x, float y, float spe) 
    : texture("assets/player_sprite.png"), sprite(texture)
    {
    vie = v;
    pos_x = x;
    pos_y = y;
    speed = spe;
    
}


void joueur::Update(sf::RenderWindow& window)
{
    float elapsed = clock.restart().asSeconds();
    tempsAccumule += elapsed;

    if (Keyboard::isKeyPressed(Keyboard::Key::Q) && pos_x >= -40) {
        pos_x -= speed * elapsed;
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::D) && pos_x <= 1090) {
        pos_x += speed * elapsed;
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::Z ) && pos_y >= 10) {
        pos_y -= speed * elapsed;
    }
        if (Keyboard::isKeyPressed(Keyboard::Key::S) && pos_y <= 1060) {
        pos_y += speed * elapsed;
    }

    sprite.setPosition(Vector2f(pos_x, pos_y));
}

void joueur::afficherJoueur(sf::RenderWindow& window) 
{
    window.draw(sprite);
}

int joueur::getXJoueur() {return pos_x;}
int joueur::getYJoueur() {return pos_y;}

