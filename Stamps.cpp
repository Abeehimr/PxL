#include "Dep.h"
#include "Canvas.cpp"


class Stamp {
    public:
        // draw on canvas the stamp with centre
        virtual void draw(sf::Vector2i ,sf::Color,Canvas*) = 0;
};

class Point: public Stamp {
    public:
        void draw(sf::Vector2i pos,sf::Color color,Canvas* canvas){
            canvas->setPixel(pos.x,pos.y,color);
        }
};

class Circle: public Stamp {
    private:
        int radius;
    public:
        Circle(int radius){
            this->radius = max(0,radius);
        }

        void setRadius(int radius){
            this->radius = max(0,radius);
        }

        int getRadius(){
            return radius;
        }

        void draw(sf::Vector2i pos,sf::Color color,Canvas* canvas){
            for(int i = -radius; i <= radius; i++){
                for(int j = -radius; j <= radius; j++){
                    if(i*i + j*j <= radius*radius){
                        canvas->setPixel(pos.x+i,pos.y+j,color);
                    }
                }
            }
        }
};

class Square: public Stamp {
    private:
        int radius;
    public:
        Square(int radius){
            this->radius = max(0,radius);
        }

        void setRadius(int radius){
            this->radius = max(0,radius);
        }

        int getRadius(){
            return radius;
        }

        void draw(sf::Vector2i pos,sf::Color color,Canvas* canvas){
            for(int i = -radius; i <= radius; i++){
                for(int j = -radius; j <= radius; j++){
                    canvas->setPixel(pos.x+i,pos.y+j,color);
                }
            }
        }
};

class BackSlash: public Stamp {
    private:
        int radius;
    public:
        BackSlash(int radius){
            this->radius = max(0,radius);
        }

        void setRadius(int radius){
            this->radius = max(0,radius);
        }

        int getRadius(){
            return radius;
        }

        void draw(sf::Vector2i pos,sf::Color color,Canvas* canvas){
            for(int i = -radius; i <= radius; i++){
                canvas->setPixel(pos.x+i,pos.y+i,color);       
            }
        }
};

class ForwardSlash: public Stamp {
    private:
        int radius;
    public:
        ForwardSlash(int radius){
            this->radius = max(0,radius);
        }

        void setRadius(int radius){
            this->radius = max(0,radius);
        }

        int getRadius(){
            return radius;
        }

        void draw(sf::Vector2i pos,sf::Color color,Canvas* canvas){
            for(int i = -radius; i <= radius; i++){
                canvas->setPixel(pos.x+i,pos.y-i,color);       
            }
        }
};