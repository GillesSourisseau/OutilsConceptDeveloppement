#ifndef __SPRITEL__
#define __SPRITEL__

#include <string>
#include <map>
#include "Sprite.hpp"

class SpriteLife : public Sprite{
public:
  SpriteLife(std::map<int,std::string> imageNames);
  ~SpriteLife();
};


#endif //__SPRITEL__
