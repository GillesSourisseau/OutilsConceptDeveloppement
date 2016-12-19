#include "SpriteB.hpp"
#include <string>
using namespace std;

SpriteB::SpriteB(){
  map<int, string> m;
  m.insert(0,"red");
  m.insert(1,"blue");
  this->imageNames = m;
}

SpriteB::~SpriteB(){

}
