#include <Magick++.h>
#include <iostream>

#include <memory>

#include "Image.h"

int main()
{

/*  size_t width;
    size_t height;

    std::cout<<"Enter a width:";
    std::cin>>width;
    std::cout<<"Enter a height:";
    std::cin>>height;
*/
Image pic( 300, 300);

pic.clearScreen (250, 250, 250);


pic.setPixel (10, 10, 255, 0, 0);


pic.save ("Test2");


    return EXIT_SUCCESS;
}
