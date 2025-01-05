#include "Tools.h"




Brush::Brush(Stamp* s){
    stamp = s;
}

Brush::~Brush(){
    delete stamp;
}

void Brush::handleEvent(LeftMouse* mouse,sf::Color color,Canvas* canvas){
    if (canvas->isInside(mouse->lastMousePos.x, mouse->lastMousePos.y)) {
        Utils::drawLine(mouse->lastMousePos.x, mouse->lastMousePos.y, mouse->mousePos.x, mouse->mousePos.y,stamp,color,canvas);
        
    }
}

CircleBrush::CircleBrush():Brush(new Circle(5)){}

SquareBrush::SquareBrush():Brush(new Square(5)){}

BackSlashBrush::BackSlashBrush():Brush(new BackSlash(5)){}

ForwardSlashBrush::ForwardSlashBrush():Brush(new ForwardSlash(5)){}

SprayBrush::SprayBrush():Brush(new Spray(5)){}

Eraser::Eraser():Brush(new Square(5)){}