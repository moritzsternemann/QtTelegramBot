#include "callbackquery.h"

using namespace Telegram;

CallbackQuery::CallbackQuery(QJsonObject callbackquery) : empty(false)
{
    id = callbackquery.value("id").toString();
    from = User(callbackquery.value("from").toObject());
    if (callbackquery.contains("message")) {
        message = Message(callbackquery.value("message").toObject());
    }
    if (callbackquery.contains("inline_message_id")) {
        inline_message_id = callbackquery.value("inline_message_id").toString();
    }
    if (callbackquery.contains("chat_instance")) {
        chat_instance = callbackquery.value("chat_instance").toString();
    }
    if (callbackquery.contains("data")) {
        data = callbackquery.value("data").toString();
    }
    if (callbackquery.contains("game_short_name")) {
        game_short_name = callbackquery.value("game_short_name").toString();
    }
}
