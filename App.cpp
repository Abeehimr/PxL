#pragma once
#include "Dep.h"
#include "Canvas.cpp"

class App {
    private:
        sf::RenderWindow window;
        sf::Vector2u size;
        Canvas* canvas;
    public:

        App(){
            window.create(sf::VideoMode::getDesktopMode(), "Paint 95",sf::Style::Close);
            size = window.getSize();
            canvas = new Canvas(size.x-100, size.y-150);
            canvas->updatePosition(100,50);
            cout << "App created\n";
        }
        ~App(){
            delete canvas;
        }

        void run(){
            sf::Vector2i lastMousePos(-1, -1);
            while (window.isOpen()) {

                // event hanlding
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                    
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                        canvas->clear();

                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        if (canvas->isInside(mousePos.x, mousePos.y)) {
                            if (lastMousePos.x != -1 && lastMousePos.y != -1) {
                                canvas->setPixel(mousePos.x, mousePos.y, sf::Color::Black);
                            }
                            lastMousePos = mousePos;
                        }
                    } else {
                        lastMousePos = sf::Vector2i(-1, -1); // Reset when the mouse is not pressed
                    }                    
                }

                // update
                canvas->UpdateTexture();
                window.clear(sf::Color(0,128,127));
                
                //window.draw(canvas->getSprite());
                canvas->draw(window);
                window.display();
            }
        }
};