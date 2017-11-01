#include <iostream>
#include <cstdlib>
#include "Image.h"
#include <random>

int main()
{


    std::cout<<"testing image\n";
    Image test(200,200);

    test.clearScreen(0, 255 , 0);

    test.save("green.png");

 /*
    test.save("red.tiff");
    test.save("red.exr");
    test.save("red.jpg");
    test.save("red.gif");
    test.save("red.pdf");
 */

    return EXIT_SUCCESS;
}
