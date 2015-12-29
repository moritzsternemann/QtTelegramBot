#ifndef VOICE_H
#define VOICE_H

#include <QDebug>
#include <QString>
#include <QJsonObject>

namespace Telegram {

class Voice
{
public:
    Voice() {}
    Voice(QJsonObject voice);

    QString fileId;
    quint64 duration;
    QString mimeType;
    quint64 fileSize;
};

inline QDebug operator<< (QDebug dbg, const Voice &voice)
{
    dbg.nospace() << qUtf8Printable(QString("Telegram::Voice(fileId=%1; duration=%2; mimeType=%3; fileSize=%4)")
                                    .arg(voice.fileId)
                                    .arg(voice.duration)
                                    .arg(voice.mimeType)
                                    .arg(voice.fileSize));

    return dbg.maybeSpace();
}

}

#endif // VOICE_H
