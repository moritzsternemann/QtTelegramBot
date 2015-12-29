#include "voice.h"

using namespace Telegram;

Voice::Voice(QJsonObject voice)
{
    fileId = voice.value("file_id").toString();
    duration = voice.value("duration").toInt();
    mimeType = voice.value("mime_type").toString();
    fileSize = voice.value("file_size").toInt();
}
