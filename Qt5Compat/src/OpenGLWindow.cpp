/*
 * Basic GL Window modified from the example here
 * http://qt-project.org/doc/qt-5.0/qtgui/openglwindow.html
 * adapted to use NGL
 */
#include "OpenGLWindow.h"
#include <QtCore/QCoreApplication>
#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLPaintDevice>
#include <QtGui/QPainter>
#include <QKeyEvent>
#include <QApplication>
#include <iostream>
#ifdef __APPLE__
  #include <glu.h>
#else
  #include <GL/glu.h>
#endif


OpenGLWindow::OpenGLWindow()
{
  setTitle("Qt5 compat profile OpenGL 2.1");
}

OpenGLWindow::~OpenGLWindow()
{
}



void OpenGLWindow::initializeGL()
{
  glMatrixMode(GL_PROJECTION);
  int w=width();
  int h=height();
  gluPerspective(45,(float)w/h,0.5,100);
  glMatrixMode(GL_MODELVIEW);


  glEnable(GL_DEPTH);
  glEnable(GL_NORMALIZE);
  gluLookAt(4,4,2,0,0,0,0,1,0);
  startTimer(20);
  glViewport(0,0,width(),height());

}

void OpenGLWindow::drawCube()
{
    glVertex3d(0,0,0);
    glVertex3d(0,1,0);
    glVertex3d(1,0,0);
    glVertex3d(1,0,0);
    glVertex3d(1,1,0);
    glVertex3d(0,1,0);
}
static int rot=0;

void OpenGLWindow::paintGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0,0,m_width,m_height);



    for(int i=0;i<2;i++)
    {
        glPushMatrix();

          //the following line is offseting the "phase" as you named it
          //practically both are rotate around 1 0 0  AXIS which is the x' axis in the cartesian system:
                //rot + (i*90) is 0 when i is 0 for --> the red surface drawn
                //rot + (i*90) is 1 when i is 1 for --> the yellow surface drawn

          glRotated(rot +(i*90),1,0,0);
          glTranslatef(-2*i,0,0);

              glBegin(GL_TRIANGLES);
              if (i==0)
              {
                  glColor3f(1,0,0);
              }
              if (i==1)
              {
                  glColor3f(1,1,0);
              }
              drawCube();

         glEnd();
       glPopMatrix();
    }


}

void OpenGLWindow::timerEvent(QTimerEvent *)
{
  rot++;
  update();
}

void OpenGLWindow::keyPressEvent(QKeyEvent *_event)
{
  switch (_event->key())
  {
   case Qt::Key_Escape : QApplication::exit(EXIT_SUCCESS); break;
  }
}

void OpenGLWindow::resizeGL(QResizeEvent *_event)
{
  /*
Note: This is merely a convenience function in order to provide an API that is compatible with QOpenGLWidget. Unlike with QOpenGLWidget, derived classes are free to choose to override
resizeEvent() instead of this function.
Note: Avoid issuing OpenGL commands from this function as there may not be
 a context current when it is invoked. If it cannot be avoided, call makeCurrent().
*/
  m_width=_event->size().width()*devicePixelRatio();
  m_height=_event->size().height()*devicePixelRatio();

}

void OpenGLWindow::resizeGL(int _w, int _h)
{
  /*
Note: This is merely a convenience function in order to provide an API that is compatible with QOpenGLWidget. Unlike with QOpenGLWidget, derived classes are free to choose to override
resizeEvent() instead of this function.
Note: Avoid issuing OpenGL commands from this function as there may not be
 a context current when it is invoked. If it cannot be avoided, call makeCurrent().
*/
  m_width=_w;
  m_height=_h;

}
