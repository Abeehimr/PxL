#pragma once
#include "Dep.h"
#include "Canvas.h"


class Stamp {
    protected:
        int radius;
    public:
        Stamp(int);
        void setRadius(int);
        int getRadius();
        // draw on canvas the stamp with centre
        virtual void draw(sf::Vector2i ,sf::Color,Canvas*) = 0;
};

class Point: public Stamp{
    public:
        Point();
        void draw(sf::Vector2i pos,sf::Color color,Canvas* canvas);
};

class Circle: public Stamp{
    private:
        int radius;
    public:
        Circle(int radius);
        void draw(sf::Vector2i pos,sf::Color color,Canvas* canvas);
};

class Square: public Stamp{
    private:
        int radius;
    public:
        Square(int radius);
        void draw(sf::Vector2i pos,sf::Color color,Canvas* canvas);
};

class BackSlash: public Stamp{
    private:
        int radius;
    public:
        BackSlash(int radius);
        void draw(sf::Vector2i pos,sf::Color color,Canvas* canvas);
};

class ForwardSlash: public Stamp{
    private:
        int radius;
    public:
        ForwardSlash(int radius);
        void draw(sf::Vector2i pos,sf::Color color,Canvas* canvas);
};

