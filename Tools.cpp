#include "Tools.h"


Tool::Tool(int c){
    useColor = c;
}

sf::Color Tool::getColor(Pallete* pallete){
    if (useColor){
        return pallete->getSecondaryColor();
    }
    else{
        return pallete->getPrimaryColor();
    }
}


Bucket::Bucket():Tool(0){

}

void Bucket::handleEvent(LeftMouse* mouse, Pallete* pallete, Canvas* canvas) {
    // if not inside canvas return (if mouse is not pressed)
    if (!canvas->isInside(mouse->mousePos.x, mouse->mousePos.y)) return;

    // get color

    sf::Color color = getColor(pallete);
    // if the color is same as the color of the pixel return
    if (canvas->getPixel(mouse->mousePos.x, mouse->mousePos.y) == color) return;
    // get the color of the pixel
    auto oldColor = canvas->getPixel(mouse->mousePos.x, mouse->mousePos.y);

    std::stack<std::pair<int, int>> stack;
    stack.push({mouse->mousePos.x, mouse->mousePos.y});

    while (!stack.empty()) {
        auto [x, y] = stack.top();
        stack.pop();

        int y1 = y;
        while (canvas->isInside(x, y1) && canvas->getPixel(x, y1) == oldColor) y1--;
        y1++;
        bool spanLeft = false;
        bool spanRight = false;

        while (canvas->isInside(x, y1) && canvas->getPixel(x, y1) == oldColor) {
            canvas->setPixel(x, y1, color);

            if (!spanLeft && canvas->isInside(x - 1, y1) && canvas->getPixel(x - 1, y1) == oldColor) {
                stack.push({x - 1, y1});
                spanLeft = true;
            } else if (spanLeft && canvas->isInside(x - 1, y1) && canvas->getPixel(x - 1, y1) != oldColor) {
                spanLeft = false;
            }

            if (!spanRight && canvas->isInside(x + 1, y1) && canvas->getPixel(x + 1, y1) == oldColor) {
                stack.push({x + 1, y1});
                spanRight = true;
            } else if (spanRight && canvas->isInside(x + 1, y1) && canvas->getPixel(x + 1, y1) != oldColor) {
                spanRight = false;
            }
            y1++;
        }
    }
}



Brush::Brush(Stamp* s,int c):Tool(c){
    stamp = s;
}

Brush::~Brush(){
    delete stamp;
}

void Brush::handleEvent(LeftMouse* mouse,Pallete* pallete,Canvas* canvas){
    if (canvas->isInside(mouse->lastMousePos.x, mouse->lastMousePos.y)) {
        sf::Color color = getColor(pallete);
        Utils::drawLine(mouse->lastMousePos.x, mouse->lastMousePos.y, mouse->mousePos.x, mouse->mousePos.y,stamp,color,canvas);        
    }
}

Pencil::Pencil():Brush(new Square(1),0){}

CircleBrush::CircleBrush():Brush(new Circle(5),0){}

SquareBrush::SquareBrush():Brush(new Square(5),0){}

BackSlashBrush::BackSlashBrush():Brush(new BackSlash(5),0){}

ForwardSlashBrush::ForwardSlashBrush():Brush(new ForwardSlash(5),0){}

SprayBrush::SprayBrush():Brush(new Spray(5),0){}

Eraser::Eraser():Brush(new Square(5),1){}