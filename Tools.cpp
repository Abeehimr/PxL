#pragma once
#include "Dep.h"
#include "Canvas.cpp"
#include "Stamps.cpp"
#include "Utility.cpp"

class Tool {
    protected:
        sf::Vector2i startMousePos; // start position when mouse was pressed
        sf::Vector2i lastMousePos; // last known position of mouse
        sf::Vector2i mousePos;
    public:
        Tool(){
            startMousePos = sf::Vector2i(-1, -1);
            lastMousePos = sf::Vector2i(-1, -1);
            mousePos = sf::Vector2i(-1, -1);
        }
        virtual void handleEvent(sf::Event , sf::Vector2i , Canvas* ) = 0;
};



class Pencil : public Tool {
    public:
        void handleEvent(sf::Event event, Canvas* canvas){
            if (event.type == sf::Event::MouseButtonPressed) {
                startMousePos = sf::Mouse::getPosition(canvas->getWindow());
                lastMousePos = startMousePos;
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                lastMousePos = sf::Vector2i(-1, -1);
            }
            if (event.type == sf::Event::MouseMoved) {
                mousePos = sf::Mouse::getPosition(canvas->getWindow());
                if (lastMousePos.x != -1 && lastMousePos.y != -1) {
                    if (canvas->isInside(mousePos.x, mousePos.y)) {
                        canvas->drawLine(lastMousePos.x, lastMousePos.y, mousePos.x, mousePos.y, sf::Color::Black);
                    }
                }
                lastMousePos = mousePos;
            }
        }
};