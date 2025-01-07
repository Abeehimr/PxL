#pragma once
#include "Dep.h"

class LeftMouse {
public:
    sf::Vector2f startMousePos; // start position when mouse was pressed
    sf::Vector2f lastMousePos; // last known position of mouse
    sf::Vector2f mousePos;

    LeftMouse();
    void Update(sf::RenderWindow* window);
};