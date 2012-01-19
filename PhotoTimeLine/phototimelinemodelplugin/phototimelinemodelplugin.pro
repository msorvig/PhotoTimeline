
 TEMPLATE = lib
 CONFIG += qt plugin
 QT += declarative

 include(../../../qtconcurrent/src/qtconcurrent.pri)
 include(../../../qtwebservices/src/qtwebservices.pri)

 DESTDIR = lib
 OBJECTS_DIR = tmp
 MOC_DIR = tmp

 HEADERS += phototimelinemodel.h \
            
 SOURCES += phototimelinemodel.cpp \

 symbian {
     include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
     TARGET.EPOCALLOWDLLDATA = 1
 }
