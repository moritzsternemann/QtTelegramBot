#ifndef FILE_H
#define FILE_H

#include <QDebug>
#include <QString>

namespace Telegram {

class File
{
public:
    File(QString fileId, qint64 fileSize = -1,  QString filePath = QString()) :
    fileId(fileId), fileSize(fileSize), filePath(filePath) {}

    QString fileId;
    qint64 fileSize;
    QString filePath;
};

inline QDebug operator<< (QDebug dbg, const File &file)
{
    dbg.nospace() << qUtf8Printable(QString("Telegram::File(fileId=%1; fileSize=%2; filePath=%3)")
                                    .arg(file.fileId)
                                    .arg(file.fileSize)
                                    .arg(file.filePath));

    return dbg.maybeSpace();
}

}

#endif // FILE_H
