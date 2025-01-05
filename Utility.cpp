#include "Dep.h"
#include "Canvas.cpp"

// bresenham's line algorithm
void drawLine(int x0,int y0 ,int x1, int y1, sf::Color color, Canvas* canvas){
    int dx = abs(x1-x0);
    int dy = abs(y1-y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx-dy;
    while(true){
        canvas->setPixel(x0,y0,color);
        if(x0 == x1 && y0 == y1) break;
        int e2 = 2*err;
        if(e2 > -dy){
            err -= dy;
            x0 += sx;
        }
        if(e2 < dx){
            err += dx;
            y0 += sy;
        }
    }
}

// mid point ellipes algorithm
void drawEllipe(int xc, int yc, int width, int height, sf::Color color, Canvas* canvas) {
    // Calculate semi-major and semi-minor axes
    int a = width / 2;  // Semi-major axis
    int b = height / 2; // Semi-minor axis

    int x = 0, y = b; // Start at the top of the ellipse
    int a2 = a * a, b2 = b * b;
    int two_a2 = 2 * a2, two_b2 = 2 * b2;
    int dx = 0, dy = two_a2 * y;
    int err = b2 - (a2 * b) + (0.25 * a2); // Initial error term

    // Region 1: Slope < 1
    while (dx < dy) {
        canvas->setPixel(xc + x, yc + y, color);
        canvas->setPixel(xc - x, yc + y, color);
        canvas->setPixel(xc + x, yc - y, color);
        canvas->setPixel(xc - x, yc - y, color);

        x++;
        dx += two_b2;

        // Update error term and adjust y when necessary
        if (err >= 0) {
            y--;
            dy -= two_a2;
            err -= dy;
        }
        err += dx + b2;

        // Check for the condition where the ellipse starts becoming too flat
        if (x > a) break; // Prevent excessive steps in the x direction
    }

    // Region 2: Slope > 1
    err = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;
    while (y >= 0) {
        canvas->setPixel(xc + x, yc + y, color);
        canvas->setPixel(xc - x, yc + y, color);
        canvas->setPixel(xc + x, yc - y, color);
        canvas->setPixel(xc - x, yc - y, color);

        y--;
        dy -= two_a2;

        // Update error term and adjust x when necessary
        if (err <= 0) {
            x++;
            dx += two_b2;
            err += dx;
        }
        err += a2 - dy;

        // Check for the condition where the ellipse starts becoming too flat
        if (y < 0) break; // Prevent excessive steps in the y direction
    }
}


void drawCircle(int x0, int y0, int radius, sf::Color color, Canvas* canvas){
    int x = radius;
    int y = 0;
    int dx = 1 - (radius << 1);
    int dy = 1;
    int err = 0;
    while(x >= y){
        canvas->setPixel(x0 + x, y0 + y, color);
        canvas->setPixel(x0 + y, y0 + x, color);
        canvas->setPixel(x0 - y, y0 + x, color);
        canvas->setPixel(x0 - x, y0 + y, color);
        canvas->setPixel(x0 - x, y0 - y, color);
        canvas->setPixel(x0 - y, y0 - x, color);
        canvas->setPixel(x0 + y, y0 - x, color);
        canvas->setPixel(x0 + x, y0 - y, color);
        if(err <= 0){
            y++;
            err += dy;
            dy += 2;
        }
        if(err > 0){
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}