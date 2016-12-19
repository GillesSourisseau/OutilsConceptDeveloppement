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
  std::string imageName0;
  std::string imageName1;
  
public:
  /*!
   *\brief Constructor for Sprite
   *\param[in] imageName - file name that contains the sprite
   */
  Sprite(std::string imageName0, std::string imageName1);

  /*!
   *\brief Destructor for Sprite
   */
  virtual ~Sprite();

  /*!
   *\name getImageName
   *\return imageName
   */
  std::string getImage0();

  std::string getImage1();

  /*!
   *\name setImageName
   *\post the name of the file containing the sprite is changed
   */
  void setImage0(std::string imageName);

  void setImage1(std::string imageName);
};



#endif // __SPRITE__
