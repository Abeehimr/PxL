#include "Toolbar.h"

Toolbar::Toolbar(int x, int y){
    posX = x;
    posY = y;
    buttonSize = 35;
    spacing = 5;
    xStart = 20;
    yStart = 20;

    tools = {
        new Eraser(),
        new Bucket(),
        new EyeDropper(),
        new Pencil(),
        new CircleBrush(),
        new SprayBrush(),
    };


    texture.loadFromFile("icon.png");    

    // Create buttons for the toolbar
    int toolIndex = 0;
    for (int row = 0; row < tools.size()/2; row++) {
        for (int col = 0; col < 2; col++) {
            if (toolIndex >= tools.size()) break;
            Button button;
            button.index = toolIndex++;
            button.shape.setSize(sf::Vector2f(buttonSize, buttonSize));
            button.shape.setFillColor(sf::Color(192,192,192));
            button.shape.setPosition(
                posX + xStart + col * (buttonSize + spacing),
                posY + yStart + row * (buttonSize + spacing)
            );
            button.icon.setTexture(texture);

            float scaleX = buttonSize / button.icon.getGlobalBounds().width * 0.8f; // Adjust scaling factor
            float scaleY = buttonSize / button.icon.getGlobalBounds().height * 0.8f;
            button.icon.setScale(scaleX, scaleY);

            sf::FloatRect buttonBounds = button.shape.getGlobalBounds();
            sf::FloatRect iconBounds = button.icon.getGlobalBounds();
            button.icon.setPosition(
                buttonBounds.left + (buttonBounds.width - iconBounds.width) / 2,
                buttonBounds.top + (buttonBounds.height - iconBounds.height) / 2
            );

            buttons.push_back(button);
        }
    }

    currentTool = 3;
    pressButton(currentTool);
}

Toolbar::~Toolbar(){
    for (Tool* tool : tools) {
        delete tool;
    }
}

void Toolbar::pressButton(int index){
    if (buttons[index].isPressed == true) return;
    buttons[index].isPressed = true;
    buttons[index].shape.setFillColor(sf::Color(150, 150, 150)); // Darker gray
    buttons[index].icon.setPosition(
        buttons[index].icon.getPosition().x + 2,
        buttons[index].icon.getPosition().y + 2
    ); // Offset for "pressed" effect
}

void Toolbar::releaseButton(int index){
    if (buttons[index].isPressed == false) return;
    buttons[index].isPressed = false;
    buttons[index].shape.setFillColor(sf::Color(192, 192, 192)); // Light gray
    buttons[index].icon.setPosition(
        buttons[index].icon.getPosition().x - 2,
        buttons[index].icon.getPosition().y - 2
    ); // Reset icon position
}



void Toolbar::draw(sf::RenderWindow& window){
    for (Button& button : buttons) {
        window.draw(button.shape);
        window.draw(button.icon);
    }
}

Tool* Toolbar::getTool(int index){
    return tools[index];
}

void Toolbar::handleEvent(LeftMouse* mouse, Pallete* pallete, Canvas* canvas){
    if (mouse->mousePos == INVALID_POS_f) return;
    if (mouse->lastMousePos != INVALID_POS_f) return;
    for (Button& button : buttons) {
        auto [x,y] = button.shape.getInverseTransform().transformPoint(mouse->mousePos);
        if (0 <= x && x <= buttonSize && 0 <= y && y <= buttonSize) {
            releaseButton(currentTool);
            currentTool = button.index;
            pressButton(currentTool);
            break;
        }
    }
}