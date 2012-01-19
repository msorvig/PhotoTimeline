#include "phototimelinemodel.h"
#include <qtgoogleclientlogin.h>
#include <qdeclarative.h>

const int testDataCount = 10000;

PhotoEntry::PhotoEntry()
:timestamp(0)
{

}

PhotoTimelineModel::PhotoTimelineModel()
{
    QHash<int, QByteArray> roles;
    roles[TimeStampRole] = "timeStamp";
    setRoleNames(roles);

    createTestData();
}

// Create photo test data: random time stamps, no images
void PhotoTimelineModel::createTestData()
{
    for (int i = 0; i < testDataCount; ++i) {
        PhotoEntry entry;
        entry.timestamp = (qrand() % 100000) * 100000;
        entry.photo = QPixmap(); // no photo
        photos.append(entry);

       //    QList<PhotoEntry>::const_iterator it =  qUpperBound(photos, entry.timestamp);
        //photos.insert(it, entry);
    }
    qSort(photos);
}

void PhotoTimelineModel::startPhotoUpdate()
{

}

void PhotoTimelineModel::photoUpdateWorker()
{
    // Get album list
    // for each album, get photo list
}

void PhotoTimelineModel::mergePhotos(QList<PhotoEntry> newPhotos)
{

}

int PhotoTimelineModel::rowCount (const QModelIndex & parent) const
{
    return photos.count();
}

QVariant PhotoTimelineModel::data(const QModelIndex &index, int role) const
{
    const PhotoEntry &photo = photos.at(index.row());
    switch (role) {
        case Qt::DisplayRole:
        case TimeStampRole:
            return QVariant(QDateTime::fromMSecsSinceEpoch(photo.timestamp).toString());
        default:
            return QVariant();
    };
}

void PhotoTimelineModel::registerType()
{
    qmlRegisterType<PhotoTimelineModel>("phototimelinemodel", 1, 0, "PhotoTimelineModel");
}

