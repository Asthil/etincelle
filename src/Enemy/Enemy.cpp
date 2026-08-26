#include "Enemy.hpp"

Enemy::Enemy(string n, int h, int a, float x, float y, float spe)
{
        name = n;
        hp = h;
        attack = a;
        pos_x = x;
        pos_y = y;
        speed = spe;
}

void Enemy::draw(sf::RenderWindow& window) {}
void Enemy::mouvement(joueur j) {}

int Enemy::getX() {return pos_x;}
int Enemy::getY() {return pos_y;}
