#include "attaque.hpp"

Attaque::Attaque(float spe, joueur& j, sf::RenderWindow& window, vector<Chaser>& c) 
:   textureAttaque("assets/attaque.png"), 
    spriteAttaque(textureAttaque),
    pos_xAttaque(j.getXJoueur()),
    pos_yAttaque(j.getYJoueur()),
    win(window),
    c(c)
{


} 

void Attaque::creationSprite(sf::RenderWindow& window) {
    window.draw(spriteAttaque);
}

void Attaque::mouvementAttaque() {
    float elapsed = clockCd.restart().asSeconds();
    if (c.size() >= 1) {
        float pos_XChaser = c[0].getX();
        float pos_YChaser = c[0].getY();
        
        spriteAttaque.setPosition(sf::Vector2f(pos_xAttaque, pos_yAttaque));

    }


} 