#include "Tools.h"

void Pencil::handleEvent(LeftMouse* mouse, Canvas* canvas){
    if (canvas->isInside(mouse->mousePos.x, mouse->mousePos.y) 
    && canvas->isInside(mouse->lastMousePos.x, mouse->lastMousePos.y)) {
        Utility::drawLine(mouse->lastMousePos.x, mouse->lastMousePos.y, mouse->mousePos.x, mouse->mousePos.y,sf::Color::Black, canvas);
    }
}