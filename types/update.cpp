#include "update.h"

using namespace Telegram;

Update::Update(QJsonObject update)
{
    id = update.value("update_id").toInt();
    message = Message(update.value("message").toObject());
    if (update.contains("callback_query")) {
        callbackquery = CallbackQuery(update.value("callback_query").toObject());
    }
}
