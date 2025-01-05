#include "Canvas.h"

Canvas::Canvas(int width,int height){
    UpdateImage(width,height);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

void Canvas::UpdateImage(int width, int height){
    image.create(width, height, sf::Color::White);
}

bool Canvas::isInside(int x, int y){
    // take offset of the sprite
    // sub from x,y
    // check if x and y are inside the image
    auto offset = sprite.getPosition();
    x -= offset.x;
    y -= offset.y;
    return x >= 0 && x < image.getSize().x && y >= 0 && y < image.getSize().y;
}

void Canvas::setPixel(float x, float y, sf::Color color){
    auto offset = sprite.getPosition();
    x -= offset.x;
    y -= offset.y;
    image.setPixel(x,y,color);
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
