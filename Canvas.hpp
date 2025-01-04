#pragma once
#include "Dep.h"
class Canvas {
private:
    sf::Image canvasImage;
    sf::Texture canvasTexture;
    sf::Sprite canvasSprite;
public:
    Canvas(int width,int height){
        canvasImage.create(800, 600, sf::Color::White);
        canvasTexture.loadFromImage(canvasImage);
    }

    void UpdateTexture(){
        canvasTexture.update(canvasImage);
    }

    void updatePosition(float x, float y){
        canvasSprite.setPosition(x,y);
    }

    void updateSize(){
    }

    void UpdateSprite(long left,long top, long width, long height){
        canvasSprite.setTexture(canvasTexture);
        canvasSprite.setTextureRect(sf::IntRect(left,top,width,height));
    }


};
