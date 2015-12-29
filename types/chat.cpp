#include "chat.h"

using namespace Telegram;

Chat::Chat(QJsonObject chat)
{
    id = chat.value("id").toInt();
    QString chatType = chat.value("type").toString();
    if (chatType == "private") type = Private;
    else if (chatType == "group") type = Group;
    else if (chatType == "channel") type = Channel;
    username = chat.value("username").toString();
    firstname = chat.value("first_name").toString();
    lastname = chat.value("last_name").toString();
}
