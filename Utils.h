#pragma once
#include "Dep.h"
#include "Canvas.h"
#include "Stamps.h"

class Utils {
    public:
        static void drawLine(int x0,int y0 ,int x1, int y1,Stamp* s,sf::Color color, Canvas* canvas);
        static void drawEllipe(int xc, int yc, int width, int height, sf::Color color, Canvas* canvas);
        static void drawCircle(int x0, int y0, int radius, sf::Color color, Canvas* canvas);
};