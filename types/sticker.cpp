#include "sticker.h"

using namespace Telegram;

Sticker::Sticker(QJsonObject sticker)
{
    fileId = sticker.value("file_id").toString();
    width = sticker.value("width").toInt();
    height = sticker.value("height").toInt();
    thumb = PhotoSize(sticker.value("thumb").toObject());
    fileSize = sticker.value("file_size").toInt();
}
