#ifndef MAINLOGIC_H
#define MAINLOGIC_H

#include <QObject>
#include <QtCore>

class MainLogic : public QObject
{
    Q_OBJECT
public:
    explicit MainLogic(QObject *parent = 0);
    Q_PROPERTY(QString username READ username WRITE setUsername)
    Q_PROPERTY(QString password READ password WRITE setPassword)

    static void registerType();

    QString username() const;
    void setUsername(const QString &username);

    QString password() const;
    void setPassword(const QString &password);
signals:

public slots:

private:
    QSettings m_settings;
};

#endif // MAINLOGIC_H
