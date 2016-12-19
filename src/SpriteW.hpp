#ifndef __SPRITEW__
#define __SPRITEW__

#include <string>
#include <map>
#include "Sprite.hpp"

class SpriteW : public Sprite{
public:
  SpriteW(std::map<int,std::string> imageNames);
  ~SpriteW();
};


#endif //__SPRITEW__
