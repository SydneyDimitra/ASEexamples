TARGET=ImageTest
SOURCES += $$PWD/src/main.cpp \
           $$PWD/src/Image.cpp
HEADERS+= $$PWD/include/Image.h

INCLUDEPATH += $$PWD/include

OTHER_FILES+=$$PWD/README.md

QMAKE_CXXFLAGS += $$system(Magick++-config --cppflags)
LIBS += $$system(Magick++-config --libs)


#git add . --all
#git commit -am "mesage"
#git push origin master
