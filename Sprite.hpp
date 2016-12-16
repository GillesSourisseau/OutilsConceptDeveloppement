#ifndef __SPRITE__
#define __SPRITE__

#include <string>

class Sprite{
    private:
        std::string imageName;

    public:
        Sprite(std::string imageName);
        ~Sprite();
        std::string getImageName();
        void setImageName(std::string imageName);
        //method to recover the file ........  
};



#endif // __SPRITE__