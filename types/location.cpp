#include "location.h"

using namespace Telegram;

Location::Location(QJsonObject location)
{
    longitude = location.value("longitude").toDouble();
    latitude = location.value("latitude").toDouble();
}
