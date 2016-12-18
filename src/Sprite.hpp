#ifndef __SPRITE__
#define __SPRITE__

#include <string>

/*!
 *\class Sprite
 *\name Sprite
 *\brief class that describes a Sprite and it's behaviour
 */
class Sprite{
private:
  std::string imageName;
  
public:
  /*!
   *\brief Constructor for Sprite
   *\param[in] imageName - file name that contains the sprite
   */
  Sprite(std::string imageName);

  /*!
   *\brief Destructor for Sprite
   */
  virtual ~Sprite();

  /*!
   *\name getImageName
   *\return imageName
   */
  std::string getImageName();

  /*!
   *\name setImageName
   *\post the name of the file containing the sprite is changed
   */
  void setImageName(std::string imageName); 
};



#endif // __SPRITE__
