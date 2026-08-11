#include "main.hpp"
#include "Game/InputHandler.hpp"
#include "Player/Player.hpp"
#include "Enemy/chaser.hpp"

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode({ WIN_WIDTH, WIN_HEIGHT }), "Titre");

    //window.setVerticalSyncEnabled(true); vsync
    window.setFramerateLimit(60);

    Player joueur("Image/player_sprite.png", {400.f, 400.f});
    Chaser chase("Image/enemy1_sprite.png", {100.f, 100.f});

    while (window.isOpen())
    {
        while (const optional event = window.pollEvent())
        {
            //gestion des inputs / events
            InputHandler(*event, window);
        }

        window.clear(Color::Blue); //effacer l'écran

        joueur.update(window);
        joueur.draw(window);
        
        chase.draw(window);

        window.display(); //affichage
    }
}

// - 40 - 10