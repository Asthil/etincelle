#pragma once

#include <SFML/Graphics.hpp>
#include "Handler.hpp"
#include "Player/joueur.hpp"

using namespace std;
using namespace sf;

void Game() {
    RenderWindow window(VideoMode({1200, 1200}), "SFML video");


    joueur j(550, 550, 500);
    

    while (window.isOpen()) {

        j.Update();

        while (const optional event = window.pollEvent()) {
            handler(*event, window);
        }

        window.clear(Color(50, 50, 50));
        
        j.afficherJoueur(window);

        window.display();
    }
}