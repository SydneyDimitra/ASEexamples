#ifndef IMAGE_H_
#define IMAGE_H_
#include <cstring>
#include <memory>


class Image
{
   public:
     Image (size_t _width, size_t _height, size_t _depth=3);
     //make sure this class can't copied
     Image (const Image &)=delete;
     Image & operator = (const Image &)=delete;

     void setPixel(size_t _x, size_t _y,
                   unsigned char _r,
                   unsigned char _g,
                   unsigned char _b);

     void clearScreen (unsigned char _r,
                       unsigned char _g,
                       unsigned char _b);

     bool save(const std::string &_fname) const;


   private:
     size_t m_width;          //!< width of image
     size_t m_height;         //!< height of image
     size_t m_pixelDepth=3;   //!< pixel depth default to 3 for RGB make 4 for RGBA
     // using a smart pointer for data
     //wraps up unsigned char * m_data in an RAII way
     std::unique_ptr< unsigned char []> m_data;

};


#endif
