#include "Stamps.h"


Stamp::Stamp(int r){
    radius = r;
}

void Stamp::setRadius(int r){
    radius = max(0,r);
}

int Stamp::getRadius(){
    return radius;
}

Point::Point():Stamp(0){
    radius = 0;
}

void Point::draw(sf::Vector2i pos,sf::Color color,Canvas* canvas){
    canvas->setPixel(pos.x,pos.y,color);
}

Circle::Circle(int radius):Stamp(radius){}

void Circle::draw(sf::Vector2i pos,sf::Color color,Canvas* canvas){
    for(int i = -radius; i <= radius; i++){
        for(int j = -radius; j <= radius; j++){
            if(i*i + j*j <= radius*radius){
                canvas->setPixel(pos.x+i,pos.y+j,color);
            }
        }
    }
}

Square::Square(int radius):Stamp(radius){}

void Square::draw(sf::Vector2i pos,sf::Color color,Canvas* canvas){
    for(int i = -radius; i <= radius; i++){
        for(int j = -radius; j <= radius; j++){
            canvas->setPixel(pos.x+i,pos.y+j,color);
        }
    }
}

BackSlash::BackSlash(int radius):Stamp(radius){}

void BackSlash::draw(sf::Vector2i pos,sf::Color color,Canvas* canvas){
    for(int i = -radius; i <= radius; i++){
        canvas->setPixel(pos.x+i,pos.y+i,color);       
    }
}

ForwardSlash::ForwardSlash(int radius):Stamp(radius){}

void ForwardSlash::draw(sf::Vector2i pos,sf::Color color,Canvas* canvas){
    for(int i = -radius; i <= radius; i++){
        canvas->setPixel(pos.x+i,pos.y-i,color);       
    }
}
