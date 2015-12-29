#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QDebug>
#include <QString>
#include <QJsonObject>
#include "photosize.h"

namespace Telegram {

class Document
{
public:
    Document() {}
    Document(QJsonObject document);

    QString fileId;
    PhotoSize thumb;
    QString fileName;
    QString mimeType;
    quint64 fileSize;
};

inline QDebug operator<< (QDebug dbg, const Document &document)
{
    dbg.nospace() << qUtf8Printable(QString("Telegram::Document(fileId=%1; thumb=%2; fileName=%3; mimeType=%4; fileSize=%5)")
                                    .arg(document.fileId)
                                    .arg("PhotoSize(" + document.thumb.fileId + ")")
                                    .arg(document.fileName)
                                    .arg(document.mimeType)
                                    .arg(document.fileSize));

    return dbg.maybeSpace();
}

}

#endif // DOCUMENT_H
