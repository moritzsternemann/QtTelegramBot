#include "document.h"

using namespace Telegram;

Document::Document(QJsonObject document)
{
    fileId = document.value("file_id").toString();
    thumb = PhotoSize(document.value("thumb").toObject());
    fileName = document.value("file_name").toString();
    mimeType = document.value("mime_type").toString();
    fileSize = document.value("file_size").toInt();
}
