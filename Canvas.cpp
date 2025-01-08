#include "Canvas.h"

Canvas::Canvas(int width,int height){
    UpdateImage(width,height);
    texture.loadFromImage(image);
    sprite.setTexture(texture);

    tempTexture.loadFromImage(tempImage);
    tempSprite.setTexture(tempTexture);
}



void Canvas::UpdateImage(int width, int height){
    image.create(width, height, sf::Color::White);
    tempImage.create(width, height, sf::Color::Transparent);
}

bool Canvas::isInside(int x, int y){
    auto [nx,ny] = getCoords(x,y);
    return sprite.getTextureRect().contains(nx,ny);
}

void Canvas::setPixel(float x, float y, sf::Color color){
    if (!isInside(x,y)) return;
    auto [nx,ny] = getCoords(x,y);
    image.setPixel(nx,ny,color);
}

sf::Color Canvas::getPixel(float x, float y){
    if (!isInside(x,y)) return INVALID_COLOR;
    auto [nx,ny] = getCoords(x,y);
    return image.getPixel(nx,ny);
}



void Canvas::clear(){
    UpdateImage(image.getSize().x, image.getSize().y);
}

sf::Image& Canvas::getImage(){
    return image;
}

void Canvas::UpdateTexture(){
    texture.update(image);
}

void Canvas::updatePosition(float x, float y){
    sprite.setPosition(x,y);
}

void Canvas::updateSize(int height, int width){
    sf::IntRect rect = sprite.getTextureRect();
    auto xscale = width/rect.width;
    auto yscale = height/rect.height;
    sprite.setScale(xscale,yscale);
}

void Canvas::UpdateSprite(long left,long top, long width, long height){
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(left,top,width,height));
}

void Canvas::draw(sf::RenderWindow& window){
    UpdateTexture();
    window.draw(sprite);
}

sf::Sprite& Canvas::getSprite(){
    return sprite;
}

// assume it get world coords
sf::Vector2i Canvas::getCoords(float x, float y){
    auto [nx,ny] = sprite.getInverseTransform().transformPoint(sf::Vector2f(x,y));
    auto rect = sprite.getTextureRect();
    nx += rect.left;
    ny += rect.top;
    return sf::Vector2i(static_cast<int>(nx),static_cast<int>(ny));
}