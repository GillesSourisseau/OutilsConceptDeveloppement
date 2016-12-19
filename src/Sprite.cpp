#include "Sprite.hpp"
#include <string>

using namespace std;

Sprite::Sprite(string imageName0, string imageName1) : imageName0(imageName0),imageName1(imageName1){

}

Sprite::~Sprite(){

}

string Sprite::getImage0(){
    return this->imageName0;
}

string Sprite::getImage1(){
    return this->imageName1;
}

void Sprite::setImage0(string imageName){
    this->imageName0 = imageName;
}

void Sprite::setImage1(string imageName){
    this->imageName1 = imageName;
}
