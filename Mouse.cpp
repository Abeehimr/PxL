#include "Mouse.h"

LeftMouse::LeftMouse(){
    startMousePos = INVALID_POS_f;
    lastMousePos = INVALID_POS_f;
    mousePos = INVALID_POS_f;
}

void LeftMouse::Update(sf::RenderWindow* window){
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        lastMousePos = mousePos;
        mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
        // cout << mousePos.x << " " << mousePos.y << endl;
        if (startMousePos == INVALID_POS_f) {
            startMousePos = mousePos;
        }
    } else {
        startMousePos = INVALID_POS_f;
        lastMousePos = INVALID_POS_f;
        mousePos = INVALID_POS_f;
    }
    // cout << mousePos.x << " " << mousePos.y << " " << startMousePos.x << " " << startMousePos.y << " " << lastMousePos.x << " " << lastMousePos.y << endl;
}