#ifndef PHOTOTIMELINEMODEL_H
#define PHOTOTIMELINEMODEL_H

#include <QtGui>
#include <QDeclarativeExtensionPlugin>

class PhotoEntry
{
public:
    PhotoEntry();
    uint timestamp;
    QString url;
    QPixmap photo;
    bool operator<(const PhotoEntry &other) const { return this->timestamp < other.timestamp; }
};

class PhotoTimelineModel : public QAbstractListModel
{
public:
    PhotoTimelineModel();
    enum PhotoRoles {
        TimeStampRole = Qt::UserRole + 1
    };

    static void registerType();

    void createTestData();
    void startPhotoUpdate();

    void photoUpdateWorker();

    void mergePhotos(QList<PhotoEntry> newPhotos);

    int rowCount (const QModelIndex & parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    QList<PhotoEntry> photos;
};
/*
class PhotoTimelineModelPlugin : public QDeclarativeExtensionPlugin
{
    Q_OBJECT
public:
    void registerTypes(const char *uri);
};
*/
#endif
