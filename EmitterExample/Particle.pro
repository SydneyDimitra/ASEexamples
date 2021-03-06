QT -= core
QT -=opengl
QT -=xml
# as I want to support 4.8 and 5 this will set a flag for some of the mac stuff
# mainly in the types.h file for the setMacVisual which is native in Qt5
isEqual(QT_MAJOR_VERSION, 5) {
cache()
DEFINES +=QT5BUILD
}
TARGET=Particle
CONFIG-=app_bundle
CONFIG+=c++11
QT +=opengl
DESTDIR=./
OBJECTS_DIR=obj
DEPENDPATH+=$$PWD/include

SOURCES=$$PWD/src/main.cpp \
        $$PWD/common/Image.cpp \
        $$PWD/common/Framebuffer.cpp  \
        $$PWD/src/Particle.cpp \
        $$PWD/src/Emitter.cpp



HEADERS =$$PWD/common/Image.h \
         $$PWD/common/Framebuffer.h \
         $$PWD/include/Vec2.h   \
         $$PWD/include/Particle.h   \
         $$PWD/include/Emitter.h


INCLUDEPATH +=$$PWD/include
INCLUDEPATH +=$$PWD/common/

QMAKE_CXXFLAGS+= -msse -msse2 -msse3
macx:QMAKE_CXXFLAGS+= -arch x86_64
macx:INCLUDEPATH+=/usr/local/boost/
linux-g++:QMAKE_CXXFLAGS +=  -march=native
linux-g++-64:QMAKE_CXXFLAGS +=  -march=native


LIBS+=-L/usr/local/lib -lglfw3

macx:INCLUDEPATH+=/usr/local/include
LIBS += -L/usr/local/lib
macx:LIBS+= -framework OpenGL -framework IOKit -framework Cocoa -framework CoreVideo
linux:LIBS+= -lGL -lX11 -lXxf86vm -lXrandr -lXi -ldl -lXinerama -lXcursor -lglfw3 -lGLEW -lpthread
macx:QMAKE_MAC_SDK = macosx10.12
