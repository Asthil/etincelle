#include "InputHandler.hpp"

void InputHandler(const sf::Event& event, sf::RenderWindow& window)
{
    if (event.is<sf::Event::Closed>())
    {
        window.close();
    }
    else if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
        {
            window.close();

            std::cout << "La touche echappe a ete appuyee\n";
        }
    }
}