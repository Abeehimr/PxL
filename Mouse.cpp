#ifndef MOUSE_CPP
#define MOUSE_CPP

#include "Dep.h"

class LeftMouse {
    public:
        sf::Vector2i startMousePos; // start position when mouse was pressed
        sf::Vector2i lastMousePos; // last known position of mouse
        sf::Vector2i mousePos;

        LeftMouse(){
            startMousePos = sf::Vector2i(-1, -1);
            lastMousePos = sf::Vector2i(-1, -1);
            mousePos = sf::Vector2i(-1, -1);
        }

        void Update(sf::RenderWindow* window){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                lastMousePos = mousePos;
                mousePos = sf::Mouse::getPosition(*window);
                if (startMousePos.x == -1 && startMousePos.y == -1) {
                    startMousePos = mousePos;
                }
            } else {
                lastMousePos = sf::Vector2i(-1, -1);
                startMousePos = sf::Vector2i(-1, -1);
                mousePos = sf::Vector2i(-1, -1);
            }
            // cout << mousePos.x << " " << mousePos.y << " " << startMousePos.x << " " << startMousePos.y << " " << lastMousePos.x << " " << lastMousePos.y << endl;
        }
};

// if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {}
#endif