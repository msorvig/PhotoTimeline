#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <qtgoogleclientlogin.h>
#include <phototimelinemodelplugin/phototimelinemodel.h>
#include "mainlogic.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QtGoogleClientLogin::registerQmlType();
    PhotoTimelineModel::registerType();
    MainLogic::registerType();

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/PhotoTimeLine/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
