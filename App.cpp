#pragma once
#include "Dep.h"
#include "Canvas.cpp"
#include "Mouse.cpp"
#include "Tools.cpp"

class App {
    private:
        sf::RenderWindow window;
        sf::Vector2u size;
        Canvas* canvas;
        LeftMouse* mouse;
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
            delete mouse;
        }

        void run(){

            mouse = new LeftMouse();
            Pencil p;

            while (window.isOpen()) {

                // event hanlding
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                        canvas->clear();
                }
                mouse->Update(&window);
                p.handleEvent(mouse, canvas);

                // update
                canvas->UpdateTexture();
                window.clear(sf::Color(0,128,127));
                
                //window.draw(canvas->getSprite());
                canvas->draw(window);
                window.display();
            }
        }
};