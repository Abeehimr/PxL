#include "App.h"

App::App(){
    window.create(sf::VideoMode::getDesktopMode(), "Paint 95",sf::Style::Default);
    size = window.getSize();
    canvas = new Canvas(size.x-100, size.y-100);
    pallete = new Pallete(0, static_cast<int>(size.y-100));
    toolbar = new Toolbar(0,0);
    canvas->updatePosition(100,0);
    cout << "App created\n";
}

App::~App(){
    delete canvas;
    delete mouse;
    delete pallete;
    delete toolbar;
}

void App::keyEvent(sf::Event event){
    if (event.key.code == sf::Keyboard::Equal &&
        event.key.control &&
        event.key.shift) {
        toolbar->getTool()->incStampRadius();
    }
    if (event.key.code == sf::Keyboard::Dash &&
        event.key.control &&
        event.key.shift) {
        toolbar->getTool()->decStampRadius();
    }
    if (event.key.code == sf::Keyboard::C &&
        event.key.control &&
        event.key.shift) {
        canvas->clear();
    }
}


void App::run(){

    mouse = new LeftMouse();




    while (window.isOpen()) {

        // event hanlding
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
            // key press event
            if (event.type == sf::Event::KeyPressed) {
                keyEvent(event);
            }
        }

        mouse->Update(&window);
        pallete->handleEvent(mouse);
        toolbar->handleEvent(mouse,pallete,canvas);

        toolbar->getTool()->handleEvent(mouse,pallete,canvas);

        // update
        canvas->UpdateTexture();
        window.clear(sf::Color(0,128,127));
        
        //window.draw(canvas->getSprite());
        canvas->draw(window);
        pallete->draw(window);
        toolbar->draw(window);
        window.display();
    }
}