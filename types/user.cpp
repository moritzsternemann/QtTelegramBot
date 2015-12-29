#include "user.h"

using namespace Telegram;

Telegram::User::User(QJsonObject user)
{
    id = user.value("id").toInt();
    firstname = user.value("first_name").toString();
    lastname = user.value("last_name").toString();
    username = user.value("username").toString();
}
