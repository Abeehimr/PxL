#pragma once
#include "Dep.h"
#include "Canvas.cpp"
#include "Stamps.cpp"
#include "Utility.h"
#include "Mouse.cpp"
class Tool {
    public:
        Tool(){}
        virtual void handleEvent(LeftMouse*, Canvas* ) = 0;
};

class Pencil: public Tool {
    public:
        Pencil(){}
        void handleEvent(LeftMouse* mouse, Canvas* canvas){
            if (canvas->isInside(mouse->mousePos.x, mouse->mousePos.y) 
            && canvas->isInside(mouse->lastMousePos.x, mouse->lastMousePos.y)) {
                Utility::drawLine(mouse->lastMousePos.x, mouse->lastMousePos.y, mouse->mousePos.x, mouse->mousePos.y,sf::Color::Black, canvas);
            }
        }
};

