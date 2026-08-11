#include <SFML/Graphics.hpp>
#include "en-tete/Player.hpp"

Player::Player(const std::string& texturePath, sf::Vector2f startPosition)
    : texture(texturePath), sprite(texture)
{
    vitesse = 20.f;

    sprite.setPosition(startPosition);

    sf::Vector2u tailleTexture = texture.getSize();
    sf::Vector2f tailleHitbox{ 50.f, 50.f };

    sf::Vector2f offset{
        (static_cast<float>(tailleTexture.x) - tailleHitbox.x) / 2.f,
        (static_cast<float>(tailleTexture.y) - tailleHitbox.y) / 2.f
    };

    hitbox.setSize(tailleHitbox);
    hitbox.setPosition(startPosition + offset);
}

void Player::update()
{
    sf::Vector2f deplacement{0.f, 0.f};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
        deplacement.y -= vitesse;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        deplacement.y += vitesse;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
        deplacement.x -= vitesse;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        deplacement.x += vitesse;

    sprite.move(deplacement);
    hitbox.move(deplacement);
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(hitbox);
}