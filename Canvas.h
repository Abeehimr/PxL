#pragma once
#include "Dep.h"

class Canvas {
private:
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Canvas(int, int);
    void UpdateImage(int, int);
    bool isInside(int, int);
    void setPixel(float, float, sf::Color);
    void clear();
    sf::Image& getImage();
    void UpdateTexture();
    void updatePosition(float, float);
    void updateSize(int, int);
    void UpdateSprite(long, long, long, long);
    void draw(sf::RenderWindow&);
    sf::Sprite& getSprite();
};