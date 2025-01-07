#include "App.h"

App::App(){
    window.create(sf::VideoMode::getDesktopMode(), "Paint 95",sf::Style::Default);
    size = window.getSize();
    canvas = new Canvas(size.x-100, size.y-150);
    pallete = new Pallete();
    canvas->updatePosition(100,50);
    cout << "App created\n";
}

App::~App(){
    delete canvas;
    delete mouse;
    delete pallete;
}

void App::run(){

    mouse = new LeftMouse();
    Tool* t = new CircleBrush();
    t->setStampRadius(20);
    Tool* e = new Eraser();
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
        if (active)
            e->handleEvent(mouse,pallete,canvas);
        else{
            t->handleEvent(mouse,pallete,canvas);
        }
        // update
        canvas->UpdateTexture();
        window.clear(sf::Color(0,128,127));
        
        //window.draw(canvas->getSprite());
        canvas->draw(window);
        window.display();
    }
}