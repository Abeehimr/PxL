#include "Mouse.h"

LeftMouse::LeftMouse(){
    startMousePos = sf::Vector2f(-1, -1);
    lastMousePos = sf::Vector2f(-1, -1);
    mousePos = sf::Vector2f(-1, -1);
}

void LeftMouse::Update(sf::RenderWindow* window){
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        lastMousePos = mousePos;
        mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
        if (startMousePos.x == -1 && startMousePos.y == -1) {
            startMousePos = mousePos;
        }
    } else {
        lastMousePos = sf::Vector2f(-1, -1);
        startMousePos = sf::Vector2f(-1, -1);
        mousePos = sf::Vector2f(-1, -1);
    }
    // cout << mousePos.x << " " << mousePos.y << " " << startMousePos.x << " " << startMousePos.y << " " << lastMousePos.x << " " << lastMousePos.y << endl;
}