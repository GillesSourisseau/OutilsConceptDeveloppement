#ifndef __SPRITEB__
#define __SPRITEB__

#include <string>
#include <map>
#include "Sprite.hpp"

class SpriteB : public Sprite{
public:
  SpriteB(std::map<int,std::string> imageNames);
  ~SpriteB();
};


#endif //__SPRITEB__
