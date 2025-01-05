#pragma once
#include "Dep.h"
#include "Canvas.cpp"

class Utility {
    public:
        static void drawLine(int x0,int y0 ,int x1, int y1, sf::Color color, Canvas* canvas);
        static void drawEllipe(int xc, int yc, int width, int height, sf::Color color, Canvas* canvas);
        static void drawCircle(int x0, int y0, int radius, sf::Color color, Canvas* canvas);
};