#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Handler.hpp"
#include "Player/joueur.hpp"
#include "Player/Attaque/attaque.hpp"
#include "Enemy/Chaser.hpp"

using namespace std;
using namespace sf;

void Game() {
    RenderWindow window(VideoMode({1200, 1200}), "SFML video");


    joueur j(1000, 550, 550, 500);

    Clock clock;
    float tempsAccumule = 9.f;

    vector<Chaser> monstre;
    monstre.reserve(51);

    while (window.isOpen()) {


        float elapsed = clock.restart().asSeconds();
        tempsAccumule += elapsed;

        if (tempsAccumule >= 10.f && monstre.size() < 50) {
            monstre.emplace_back();
            cout << "Nouveau monstre"<< endl;
            tempsAccumule -= 10.f;
        }

        for (auto& m : monstre) {
            m.mouvement(j);
        }


        while (const optional event = window.pollEvent()) {
            handler(*event, window);
        }

        window.clear(Color(50, 50, 50));
        
        j.Update(window);

        Attaque a(100, j, window, monstre);


        j.afficherJoueur(window);

        for (auto& m : monstre) {
            m.draw(window);
        }

        window.display();
    }
}