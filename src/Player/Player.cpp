#include <SFML/Graphics.hpp>
#include "en-tete/Player.hpp"
#include <iostream>

Player::Player(const std::string& texturePath, sf::Vector2f startPosition)
    : texture(texturePath), sprite(texture)
{
    vitesse = 10.f;

    sprite.setPosition(startPosition);

    sf::Vector2u tailleTexture = texture.getSize();
    sf::Vector2f tailleHitbox{ 50.f, 90.f };

    sf::Vector2f offset{
        (static_cast<float>(tailleTexture.x) - tailleHitbox.x) / 2.2f,
        (static_cast<float>(tailleTexture.y) - tailleHitbox.y) / 2.f
    };

    hitbox.setSize(tailleHitbox);
    hitbox.setPosition(startPosition + offset);
}

void Player::update(sf::RenderWindow& window)
{
    sf::Vector2f deplacement{0.f, 0.f};
    timerAttack.start();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && timerAttack.getElapsedTime() >= sf::seconds(2.f)) 
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::RectangleShape rectangle;
        rectangle.setSize(sf::Vector2f(100, 100));
        rectangle.setPosition({static_cast<float>(mousePos.x - 50), static_cast<float>(mousePos.y - 50)});

        marques.push_back(rectangle);
        timerAttack.restart();

    }


    if (isBoosting && boostClock.getElapsedTime() >= sf::seconds(0.01f)) {
        vitesse = 10.f;
        isBoosting = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !isBoosting) {
        vitesse = 50.f;
        isBoosting = true;
        boostClock.restart();
    }

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

    for (const auto& marque : marques) {
        window.draw(marque);
    }
}