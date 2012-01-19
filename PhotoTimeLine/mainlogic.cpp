#include "mainlogic.h"
#include <QtDeclarative>

MainLogic::MainLogic(QObject *parent) :
    QObject(parent)
{

}

void MainLogic::registerType()
{
    qmlRegisterType<MainLogic>("mainlogic", 1, 0, "MainLogic");
}

QString MainLogic::username() const
{
    qDebug() << "read user";
    return m_settings.value("user1").toString();
}

void MainLogic::setUsername(const QString &username)
{
    qDebug() << "set user" << username;
    m_settings.setValue("user1", username);
}

QString MainLogic::password() const
{
    return m_settings.value("user2").toString();
}

void MainLogic::setPassword(const QString &password)
{
    m_settings.setValue("user2", password);
}
