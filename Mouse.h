#pragma once
#include "Dep.h"

class LeftMouse {
public:
    sf::Vector2i startMousePos; // start position when mouse was pressed
    sf::Vector2i lastMousePos; // last known position of mouse
    sf::Vector2i mousePos;

    LeftMouse();
    void Update(sf::RenderWindow* window);
};