#include "audio.h"

using namespace Telegram;

Audio::Audio(QJsonObject audio)
{
    fileId = audio.value("file_id").toString();
    duration = audio.value("duration").toInt();
    performer = audio.value("performer").toString();
    title = audio.value("title").toString();
    mimeType = audio.value("mime_type").toString();
    fileSize = audio.value("file_size").toInt();
}
