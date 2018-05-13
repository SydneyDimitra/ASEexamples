#include <Magick++.h>
#include <iostream>

#include <memory>
#include "Image.h"

int main()
{
  /*  unsigned char width;
    unsigned char height;
    std::cout<<"Enter a width:";
    std::cin>>width;
    std::cout<<"Enter a height:";
    std::cin>>height;
*/

//image width and height
Image pic(700, 700);

size_t checkSize = 10;

   for (size_t y = 1; y < 200; ++y)
   {
     for (size_t x = 1; x < 200; ++x)
     {
       if ((x / checkSize + y / checkSize) % 2 < 1)
       {
         pic.setPixel(x, y, 255, 0, 0);
       }
       else
       {
         pic.setPixel(x, y, 255, 255, 255);
       }
     }
   }

   pic.save ("TestRGB");

   pic.clearScreen (0,0,0);
   	
   return EXIT_SUCCESS;
}
