#include "en-tete/main.hpp"
#include "en-tete/InputHandler.hpp"

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode({ WIN_WIDTH, WIN_HEIGHT }), "Titre");

    //window.setVerticalSyncEnabled(true); vsync
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        while (const optional event = window.pollEvent())
        {
            //gestion des inputs / events
            InputHandler(*event, window);
            
        }

        window.clear(); //effacer l'écran

        window.display(); //affichage
    }
}