#include "Pallete.h"

Pallete::Pallete(){
    primaryColorIndex = 0;
    secondaryColorIndex = 1;

    colors.push_back(sf::Color(0,0,0));
    colors.push_back(sf::Color(255,255,255));
}
sf::Color Pallete::getPrimaryColor(){
    return colors[primaryColorIndex];
}
sf::Color Pallete::getSecondaryColor(){
    return colors[secondaryColorIndex];
}
void Pallete::swapColors(){
    swap(primaryColorIndex,secondaryColorIndex);
}

void Pallete::changePrimaryColor(int index){
    primaryColorIndex = index;   
}
void Pallete::changeSecondaryColor(int index) {
    secondaryColorIndex = index;
}