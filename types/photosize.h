#ifndef PHOTOSIZE_H
#define PHOTOSIZE_H

#include <QDebug>
#include <QString>
#include <QJsonObject>

namespace Telegram {

class PhotoSize
{
public:
    PhotoSize() {}
    PhotoSize(QJsonObject photoSize);

    QString fileId;
    quint16 width;
    quint16 height;
    quint64 fileSize;
};

inline QDebug operator<< (QDebug dbg, const PhotoSize &photoSize)
{
    dbg.nospace() << qUtf8Printable(QString("Telegram::PhotoSize(fileId=%1; width=%2; height=%3; fileSize=%4)")
                                    .arg(photoSize.fileId)
                                    .arg(photoSize.width)
                                    .arg(photoSize.height)
                                    .arg(photoSize.fileSize));

    return dbg.maybeSpace();
}

}

#endif // PHOTOSIZE_H
