#pragma once
#include "Dep.h"
#include "Mouse.h"
// color pallete of old ms paint
struct ColorBox {
    sf::RectangleShape shape; // Color box shape
    sf::Color color;          // Color of the box
};


// pallete class that stores colors and give 2 colors 1. primary and 2. seconadary
class Pallete {
    private:
        vector<ColorBox> palette;
        vector<sf::Color> colors;

        sf::RectangleShape primaryColorBox;
        sf::RectangleShape secondaryColorBox;

        int posX;
        int posY;
        int buttonSize;
        int spacing;
        int xStart;
        int yStart;
    public:
        Pallete(int,int);
        sf::Color getPrimaryColor();
        sf::Color getSecondaryColor();
        void swapColors();
        void changePrimaryColor(sf::Color color);
        
        void draw(sf::RenderWindow& window);
        void handleEvent(LeftMouse* mouse);
};
