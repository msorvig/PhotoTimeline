# Add more folders to ship with the application, here
folder_01.source = qml/PhotoTimeLine
folder_01.target = qml

DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

symbian:TARGET.UID3 = 0xE5BB7687

# Smart Installer package's UID
# This UID is from the protected range and therefore the package will
# fail to install if self-signed. By default qmake uses the unprotected
# range value if unprotected UID is defined for the application and
# 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# The .cpp file which was generated for your project. Feel free to hack it.

include(../../qtconcurrent/src/qtconcurrent.pri)
include(../../qtwebservices/src/qtwebservices.pri)

SOURCES += main.cpp
SOURCES += \
    phototimelinemodelplugin/phototimelinemodel.cpp \
    mainlogic.cpp

HEADERS += \
    phototimelinemodelplugin/phototimelinemodel.h \
    mainlogic.h \


# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()
