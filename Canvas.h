#pragma once
#include "Dep.h"

class Canvas {
private:
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    sf::Image tempImage;
    sf::Texture tempTexture;
    sf::Sprite tempSprite;
public:
    Canvas(int, int);
    void UpdateImage(int, int);
    bool isInside(int, int);
    void setPixel(float, float, sf::Color);
    sf::Color getPixel(float, float);
    void clear();
    sf::Image& getImage();
    void UpdateTexture();
    void updatePosition(float, float);
    void updateSize(int, int);
    void UpdateSprite(long, long, long, long);
    void draw(sf::RenderWindow&);
    sf::Sprite& getSprite();

    sf::Vector2i getCoords(float, float);
};