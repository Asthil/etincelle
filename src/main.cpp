#include "en-tete/main.hpp"
#include "en-tete/InputHandler.hpp"
#include "en-tete/Player.hpp"

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode({ WIN_WIDTH, WIN_HEIGHT }), "Titre");

    //window.setVerticalSyncEnabled(true); vsync
    window.setFramerateLimit(60);

    Player joueur("Image/player_sprite.png", {400.f, 400.f});


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

        window.display(); //affichage
    }
}

// - 40 - 10