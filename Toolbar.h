#pragma once
#include "Dep.h"
#include "Tools.h"


struct Button {
    int index;
    sf::RectangleShape shape; // Button background
    sf::Sprite icon;          // Button icon
    bool isPressed = false;   // Track button state
};


class Toolbar {
    private:
        vector<Tool*> tools;
        vector<Button> buttons;
        sf::Texture texture; // temp
        int currentTool;
        int posX;
        int posY;
        int buttonSize;
        int spacing;
        int xStart;
        int yStart;
    public:
        Toolbar(int,int);
        ~Toolbar();
        void pressButton(int);
        void releaseButton(int);
        void draw(sf::RenderWindow& window);
        void handleEvent(LeftMouse* mouse,Pallete* pallete, Canvas* canvas);
        Tool* getTool(int);
};