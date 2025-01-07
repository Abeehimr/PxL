#pragma once
#include "Dep.h"

// color pallete of old ms paint



// pallete class that stores colors and give 2 colors 1. primary and 2. seconadary
class Pallete {
    private:
        vector<sf::Color> colors;
        int primaryColorIndex;
        int secondaryColorIndex;
    public:
        Pallete();
        sf::Color getPrimaryColor();
        sf::Color getSecondaryColor();
        void swapColors();
        void changePrimaryColor(int index);
        void changeSecondaryColor(int index);

};
