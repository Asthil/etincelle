#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

void handler(const Event& event, RenderWindow& window) {

    if (event.is<Event::Closed>()) {
        window.close();
    }
}