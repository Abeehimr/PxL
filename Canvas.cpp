#pragma once
#include "Dep.h"
class Canvas {
private:
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Canvas(int width,int height){
        UpdateImage(width,height);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
    }

    void UpdateImage(int width, int height){
        image.create(width, height, sf::Color::White);
    }

    bool isInside(int x, int y){
        // take offset of the sprite
        // sub from x,y
        // check if x and y are inside the image
        auto offset = sprite.getPosition();
        x -= offset.x;
        y -= offset.y;
        return x >= 0 && x < image.getSize().x && y >= 0 && y < image.getSize().y;
    }

    void setPixel(float x, float y, sf::Color color){
        auto offset = sprite.getPosition();
        x -= offset.x;
        y -= offset.y;
        image.setPixel(x,y,color);
    }

    void clear(){
        UpdateImage(image.getSize().x, image.getSize().y);
    }

    sf::Image& getImage(){
        return image;
    }

    void UpdateTexture(){
        texture.update(image);
    }

    void updatePosition(float x, float y){
        sprite.setPosition(x,y);
    }

    void updateSize(int height, int width){
        sf::IntRect rect = sprite.getTextureRect();
        auto xscale = width/rect.width;
        auto yscale = height/rect.height;
        sprite.setScale(xscale,yscale);
    }

    void UpdateSprite(long left,long top, long width, long height){
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(left,top,width,height));
    }

    void draw(sf::RenderWindow& window){
        UpdateTexture();
        window.draw(sprite);
    }

    sf::Sprite& getSprite(){
        return sprite;
    }
};
