#ifndef IMAGE_H_
#define IMAGE_H_

#include <memory>

 class Image
 {
 private:
     size_t WIDTH;
     size_t HEIGHT;
     size_t pixelDepth;

     unsigned char *m_data;

 public :

//constructor
     Image(size_t _width, size_t _height, size_t _depth = 3)
     {
        WIDTH = _width;
        HEIGHT = _height;
        pixelDepth = _depth;

        int imageSize  = WIDTH * HEIGHT * pixelDepth;

        m_data = new unsigned char[imageSize];

        //std::unique_ptr<unsigned char[]> image(new unsigned char[imageSize]);
     }

     bool save (std::string _fname);

     void setPixel (size_t _x, size_t _y, unsigned char _r, unsigned char _g, unsigned char _b);

     void clearScreen (unsigned char _r, unsigned char _g, unsigned char _b);

// destructor
     ~Image()
     {
         delete[] m_data;
     }
 };





#endif
