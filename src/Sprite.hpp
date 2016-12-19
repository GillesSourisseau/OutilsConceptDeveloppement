#ifndef __SPRITE__
#define __SPRITE__

#include <string>
#include <map>
#include <vector>
/*!
 *\class Sprite
 *\name Sprite
 *\brief class that describes a Sprite and it's behaviour
 */
class Sprite{
public:
  std::map<int,std::string> imageNames;
  
  /*!
   *\brief Constructor for Sprite
   *\param[in] imageName - file name that contains the sprite
   */
  Sprite(std::map<int,std::string> imageNames);

  /*!
   *\brief Destructor for Sprite
   */
  virtual ~Sprite();

  /*!
   *\name getImageName
   *\return imageName
   */
  std::string getImage(int key);

  std::vector<int> getKeys();
};



#endif // __SPRITE__
