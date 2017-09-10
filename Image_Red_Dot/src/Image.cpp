#include "Image.h"
#include <Magick++.h>


void Image::setPixel (size_t _x, size_t _y, unsigned char _r, unsigned char _g, unsigned char _b)

{
  size_t arrayIndex = _y* WIDTH*pixelDepth + _x * pixelDepth;

    m_data[arrayIndex] = _r;
    m_data[arrayIndex + 1] = _g;
    m_data[arrayIndex + 2] = _b;

    //image[arrayIndex] = m_data[arrayIndex];
}


void Image::clearScreen (unsigned char _r, unsigned char _g, unsigned char _b)
{
  for (size_t x = 0; x < WIDTH; ++x)
    {
       for (size_t y = 0; y < HEIGHT; ++y)
       {
           setPixel( x, y, _r, _g, _b);
       }
    }
}


bool Image::save (std::string _fname)
{
    Magick::Image output(WIDTH,HEIGHT,"RGB",Magick::CharPixel,m_data);
    output.depth(16);
    output.write(_fname+".jpg");
    return true;
}
