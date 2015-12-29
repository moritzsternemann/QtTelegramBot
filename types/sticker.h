#ifndef STICKER_H
#define STICKER_H

#include <QDebug>
#include <QString>
#include <QJsonObject>
#include "photosize.h"

namespace Telegram {

class Sticker
{
public:
    Sticker() {}
    Sticker(QJsonObject sticker);

    QString fileId;
    quint16 width;
    quint16 height;
    PhotoSize thumb;
    quint64 fileSize;
};

inline QDebug operator<< (QDebug dbg, const Sticker &sticker)
{
    dbg.nospace() << qUtf8Printable(QString("Telegram::Sticker(fileId=%1; width=%2; height=%3; thumb=%4; fileSize=%5)")
                                    .arg(sticker.fileId)
                                    .arg(sticker.width)
                                    .arg(sticker.height)
                                    .arg("PhotoSize(" + sticker.thumb.fileId + ")")
                                    .arg(sticker.fileSize));

    return dbg.maybeSpace();
}

}

#endif // STICKER_H
