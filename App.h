#pragma once
#include "Dep.h"
#include "Canvas.h"
#include "Stamps.h"
#include "Utils.h"
#include "Mouse.h"
#include "Tools.h"
#include "Pallete.h"
#include "Toolbar.h"

class App {
    private:
        sf::RenderWindow window;
        sf::Vector2u size;
        Canvas* canvas;
        Pallete* pallete;
        Toolbar* toolbar;
        LeftMouse* mouse;
    public:
        App();
        ~App();
        void run();
        void keyEvent(sf::Event event);
};