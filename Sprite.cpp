#include "Sprite.hpp"
#include <string>

using namespace std;

Sprite::Sprite(string imageName) : imageName(imageName){

}

Sprite::~Sprite(){

}

string Sprite::getImageName(){
    return this->imageName;
}

void Sprite::setImageName(string imageName){
    this->imageName = imageName;
}
