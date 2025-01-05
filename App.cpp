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
            //canvas->updatePosition(100,50);
            cout << "App created\n";
        }
        ~App(){
            delete canvas;
        }

        void run(){
            cout << "Running\n";
            sf::Vector2i lastMousePos(-1, -1);
            while (window.isOpen()) {

                cout << "event handling\n";
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

                        if (mousePos.x >= 0 && mousePos.x < 800 && mousePos.y >= 0 && mousePos.y < 600) {
                            if (lastMousePos.x != -1 && lastMousePos.y != -1) {
                                canvas->getImage().setPixel(mousePos.x, mousePos.y, sf::Color::Black);
                                //drawLine(canvas->getImage(), lastMousePos.x, lastMousePos.y, mousePos.x, mousePos.y, radius, col_arr[cur_col]);
                            }
                            lastMousePos = mousePos;
                        }
                    } else {
                        lastMousePos = sf::Vector2i(-1, -1); // Reset when the mouse is not pressed
                    }                    
                }

                cout << "update\n";
                // update
                canvas->UpdateTexture();
                cout << "Running\n";
                window.clear(sf::Color(0,128,127));
                window.draw(canvas->getSprite());
                //canvas->draw(window);
                window.display();
            }
        }
};