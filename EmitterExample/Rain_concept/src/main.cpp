#include <cstdlib>
#include <cstring>
#include <chrono>
#include <thread>
#include <array>
#include <iostream>
#include <string>
#include <random>
#include "Framebuffer.h"
#include "Image.h"
#include "Vec2.h"
#include "Emitter.h"

int main()
{
   Vec2<int> a;
   Vec2<int> b(2,3);

   std::cout<<a<<b << a+b;

   a+=b;
   std::cout<<a;


    std::unique_ptr<frm::Framebuffer> framebuffer( new frm::Framebuffer());
    size_t width=1024;
    size_t height=500;
    framebuffer->init(width, height, NULL);

    Image image(width,height);
    image.setBackground(255,255,255);

    framebuffer->bind();
    framebuffer->poll();

    //! change
    Vec2<int> pos(width/4,0);
    Vec2<int> pos2(width/2,0);
    Vec2<int> pos3(3*width/4,0);
 //   Vec2<int> dir(1,0);


    framebuffer->title("Particle");
   //  Vec2<int> pos(width/2,height/2);
   //  Vec2<int> dir(1,1);
    Emitter p(pos,100);
    Emitter p2(pos2,100);
    Emitter p3(pos3,100);
    while(!framebuffer->shouldClose())
    {
      image.setBackground(0,0,0);
      image.setPixel(pos.m_x, pos.m_y, 255, 0, 0);
      p.update();
      p.draw(image);

      p2.update();
      p2.draw(image);

      p3.update();
      p3.draw(image);

      framebuffer->image(image.get(),width, height);
      framebuffer->draw();
      framebuffer->poll();
    }


  return EXIT_SUCCESS;
}
