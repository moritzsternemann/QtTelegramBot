#include "contact.h"

using namespace Telegram;

Contact::Contact(QJsonObject contact)
{
    phoneNumber = contact.value("phone_number").toString();
    firstname = contact.value("first_name").toString();
    lastname = contact.value("last_name").toString();
    userId = contact.value("user_id").toInt();
}
