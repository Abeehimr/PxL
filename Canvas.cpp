#pragma once
#include "Dep.h"
class Canvas {
private:
    sf::Image canvasImage;
    sf::Texture canvasTexture;
    sf::Sprite canvasSprite;
public:
    Canvas(int width,int height){
        UpdateImage(width,height);
        canvasTexture.loadFromImage(canvasImage);
    }

    void UpdateImage(int width, int height){
        canvasImage.create(width, height, sf::Color::White);
    }

    void clear(){
        UpdateImage(canvasImage.getSize().x, canvasImage.getSize().y);
    }

    sf::Image& getImage(){
        return canvasImage;
    }

    void UpdateTexture(){
        canvasTexture.update(canvasImage);
    }

    void updatePosition(float x, float y){
        canvasSprite.setPosition(x,y);
    }

    void updateSize(int height, int width){
        sf::IntRect rect = canvasSprite.getTextureRect();
        auto xscale = width/rect.width;
        auto yscale = height/rect.height;
        canvasSprite.setScale(xscale,yscale);
    }

    void UpdateSprite(long left,long top, long width, long height){
        canvasSprite.setTexture(canvasTexture);
        canvasSprite.setTextureRect(sf::IntRect(left,top,width,height));
    }

    void draw(sf::RenderWindow& window){
        cout << "Drawing canvas\n";
        window.draw(canvasSprite);
    }
    sf::Sprite& getSprite(){
        return canvasSprite;
    }
};
