#include "Sprite.hpp"
#include <iostream>
#include <string>
#include <map>
using namespace std;

Sprite::Sprite(map<int,string> imageNames) : imageNames(imageNames){

}

Sprite::~Sprite(){

}

string Sprite::getImage(int key){
  map<int,string>::iterator it;
  it = imageNames.find(key);
  if(it != imageNames.end()){
    return it->second;
  }else{
    cout<<"key not found"<<endl;
    return "default";
  }
}


