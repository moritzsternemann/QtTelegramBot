#ifndef LOCATION_H
#define LOCATION_H

#include <QDebug>
#include <QString>
#include <QJsonObject>

namespace Telegram {

class Location
{
public:
    Location() {}
    Location(QJsonObject location);

    float longitude;
    float latitude;
};

inline QDebug operator<< (QDebug dbg, const Location &location)
{
    dbg.nospace() << qUtf8Printable(QString("Telegram::Location(longitude=%1; latitude=%2)")
                                    .arg(location.longitude)
                                    .arg(location.latitude));

    return dbg.maybeSpace();
}

}

#endif // LOCATION_H
