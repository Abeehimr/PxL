#pragma once
#include "Dep.h"

// color pallete of old ms paint
int r[] = {};
int g[] = {};
int b[] = {};


// pallete class that stores colors and give 2 colors 1. primary and 2. seconadary
class Pallete {
    private:
        sf::Color colors[30];
        int primaryColorIndex;
        int secondaryColorIndex;
    public:
        Pallete(){

        }
        sf::Color getPrimaryColor(){
            return colors[primaryColorIndex];
        }
        sf::Color getSecondaryColor(){
            return colors[secondaryColorIndex];
        }
        void changePrimaryColor(int index){
            primaryColorIndex = index;   
        }
        void changeSecondaryColor(int index) {
            secondaryColorIndex = index;
        }
};
