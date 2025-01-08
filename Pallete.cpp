#include "Pallete.h"

Pallete::Pallete(int x, int y){
    posX = x;
    posY = y;
    buttonSize = 20;
    spacing = 5;
    xStart = 50;
    yStart = 20;

    std::vector<sf::Color> colors = {
        sf::Color(0,0,0),
        sf::Color(120,120,120),
        sf::Color(121,3,0),
        sf::Color(117,122,1),
        sf::Color(0,121,2),
        sf::Color(0,119,120),
        sf::Color(10,0,120),
        sf::Color(123,0,119),
        sf::Color(118,122,56),
        sf::Color(0,54,55),
        sf::Color(40,111,254),
        sf::Color(8,49,120),
        sf::Color(76,0,254),
        sf::Color(120,59,0),

        sf::Color(255,255,255),
        sf::Color(187,187,187),
        sf::Color(255,14,0),
        sf::Color(250,255,8),
        sf::Color(0,255,11),
        sf::Color(0,254,255),
        sf::Color(52,0,254),
        sf::Color(255,0,254),
        sf::Color(251,255,122),
        sf::Color(0,255,123),
        sf::Color(118,254,255),
        sf::Color(130,112,254),
        sf::Color(255,6,119),
        sf::Color(255,125,54)    
    };

        // Create color boxes for the palette
    int colorIndex = 0;
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < colors.size()/2; col++) {
            if (colorIndex >= colors.size()) break;
            ColorBox box;
            box.color = colors[colorIndex++];
            box.shape.setSize(sf::Vector2f(buttonSize, buttonSize));
            box.shape.setFillColor(box.color);
            box.shape.setPosition(
                posX + xStart + col * (buttonSize + spacing),
                posY + yStart + row * (buttonSize + spacing)
            );
            // Add border to each color box
            box.shape.setOutlineThickness(2);
            box.shape.setOutlineColor(sf::Color::Black);
            palette.push_back(box);
        }
    }
    // Primary and Secondary color boxes
    primaryColorBox.setSize(sf::Vector2f(buttonSize, buttonSize));
    primaryColorBox.setPosition(10+posX, 20+posY);
    primaryColorBox.setFillColor(sf::Color::Black);
    primaryColorBox.setOutlineThickness(2);
    primaryColorBox.setOutlineColor(sf::Color::Black);

    secondaryColorBox.setSize(sf::Vector2f(buttonSize , buttonSize ));
    secondaryColorBox.setPosition(20+posX, 10 + buttonSize + spacing+posY);
    secondaryColorBox.setFillColor(sf::Color::White);
    secondaryColorBox.setOutlineThickness(2);
    secondaryColorBox.setOutlineColor(sf::Color::Black);

}

sf::Color Pallete::getPrimaryColor(){
    return primaryColorBox.getFillColor();
}
sf::Color Pallete::getSecondaryColor(){
    return secondaryColorBox.getFillColor();
}

void Pallete::swapColors(){
    sf::Color temp = primaryColorBox.getFillColor();
    primaryColorBox.setFillColor(secondaryColorBox.getFillColor());
    secondaryColorBox.setFillColor(temp);
}

void Pallete::changePrimaryColor(sf::Color color){
    primaryColorBox.setFillColor(color);
}


void Pallete::draw(sf::RenderWindow& window){
    for (ColorBox& box : palette) {
        window.draw(box.shape);
    }
    window.draw(primaryColorBox);
    window.draw(secondaryColorBox);
}


void Pallete::handleEvent(LeftMouse* mouse){
    if (mouse->mousePos.x == -1 && mouse->mousePos.y == -1) return;
    if (mouse->lastMousePos.x != -1 || mouse->lastMousePos.y != -1) return;
    for (ColorBox& box : palette) {
        auto [nx,ny] = box.shape.getInverseTransform().transformPoint(mouse->mousePos);
        if (0 <= nx && nx <= buttonSize && 0 <= ny && ny <= buttonSize) {
            primaryColorBox.setFillColor(box.color);
        }
    }


    auto [px,py] = primaryColorBox.getInverseTransform().transformPoint(mouse->mousePos);
    auto [sx,sy] = secondaryColorBox.getInverseTransform().transformPoint(mouse->mousePos);
    
    
    if ((0 <= px && px <= buttonSize && 0 <= py && py <= buttonSize)
        || (0 <= sx && sx <= buttonSize && 0 <= sy && sy <= buttonSize)) {
        swapColors();
    }
}
