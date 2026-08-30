#include "attaque.hpp"

Attaque::Attaque(float spe, joueur& j, sf::RenderWindow& window, vector<Chaser> c) 
:   textureAttaque("assets/attaque.png"), 
    spriteAttaque(textureAttaque),
    pos_xAttaque(j.getXJoueur()),
    pos_yAttaque(j.getYJoueur()),
    win(window)
{
    Attaque::creationSprite(window);

} 

void Attaque::creationSprite(sf::RenderWindow& window) {
    window.draw(spriteAttaque);
}

void Attaque::mouvementAttaque() {
    float elapsed = clockCd.restart().asSeconds();

    if (pos_xAttaque < )
} 