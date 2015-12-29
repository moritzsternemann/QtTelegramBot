#include "video.h"

using namespace Telegram;

Video::Video(QJsonObject video)
{
    fileId = video.value("file_id").toString();
    width = video.value("width").toInt();
    height = video.value("height").toInt();
    duration = video.value("duration").toInt();
    thumb = PhotoSize(video.value("thumb").toObject());
    mimeType = video.value("mime_type").toString();
    fileSize = video.value("file_size").toInt();
}
