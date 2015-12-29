#ifndef AUDIO_H
#define AUDIO_H

#include <QDebug>
#include <QString>
#include <QJsonObject>

namespace Telegram {

class Audio
{
public:
    Audio() {}
    Audio(QJsonObject audio);

    QString fileId;
    quint64 duration;
    QString performer;
    QString title;
    QString mimeType;
    quint64 fileSize;
};

inline QDebug operator<< (QDebug dbg, const Audio &audio)
{
    dbg.nospace() << qUtf8Printable(QString("Telegram::Audio(fileId=%1; duration=%2; performer=%3; title=%4; mimeType=%5; fileSize=%6)")
                                    .arg(audio.fileId)
                                    .arg(audio.duration)
                                    .arg(audio.performer)
                                    .arg(audio.title)
                                    .arg(audio.mimeType)
                                    .arg(audio.fileSize));

    return dbg.maybeSpace();
}

}

#endif // AUDIO_H
