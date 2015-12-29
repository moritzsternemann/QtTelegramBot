#include "photosize.h"

using namespace Telegram;

PhotoSize::PhotoSize(QJsonObject photoSize)
{
    fileId = photoSize.value("file_id").toString();
    width = photoSize.value("width").toInt();
    height = photoSize.value("height").toInt();
    fileSize = photoSize.value("file_size").toInt();
}
