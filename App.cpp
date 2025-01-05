#include "App.h"

App::App(){
    window.create(sf::VideoMode::getDesktopMode(), "Paint 95",sf::Style::Close);
    size = window.getSize();
    canvas = new Canvas(size.x-100, size.y-150);
    canvas->updatePosition(100,50);
    cout << "App created\n";
}

App::~App(){
    delete canvas;
    delete mouse;
}

void App::run(){

    mouse = new LeftMouse();
    ForwardSlashBrush p;
    Bucket b;
    bool active = false;

    while (window.isOpen()) {

        // event hanlding
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                canvas->clear();
            
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::B)
                active = !active;

        }
        mouse->Update(&window);
        p.handleEvent(mouse,sf::Color::Black,canvas);
        if (active)
            b.handleEvent(mouse,sf::Color::Red,canvas);
        // update
        canvas->UpdateTexture();
        window.clear(sf::Color(0,128,127));
        
        //window.draw(canvas->getSprite());
        canvas->draw(window);
        window.display();
    }
}