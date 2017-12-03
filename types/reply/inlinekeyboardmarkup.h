#ifndef INLINEKEYBOARDMARKUP_H
#define INLINEKEYBOARDMARKUP_H

#include <QString>

#include "genericreply.h"

namespace Telegram {

class InlineKeyboardButton
{
public:
    InlineKeyboardButton(QString text, QString url = QString(), QString callback_data = QString(), QString switch_inline_query = QString(), QString switch_inline_query_current_chat = QString())
        : text(text),
          url(url),
          callback_data(callback_data),
          switch_inline_query(switch_inline_query),
          switch_inline_query_current_chat(switch_inline_query_current_chat)
    {
        object = QJsonObject();
        object.insert("text", text);
        if (!url.isEmpty()) {
            object.insert("url", url);
            return;
        }
        if (!callback_data.isEmpty())
            object.insert("callback_data", callback_data);
        if (!switch_inline_query.isEmpty())
            object.insert("switch_inline_query", switch_inline_query);
        if (!switch_inline_query_current_chat.isEmpty())
            object.insert("switch_inline_query_current_chat", switch_inline_query_current_chat);
    }
    /**
     * @text - Label text on the button
     */
    QString text;

    /**
     * @url - Optional. HTTP url to be opened when button is pressed
     */
    QString url;

    /**
     * @callback_data - Optional. Data to be sent in a callback query to the bot when button is pressed, 1-64 bytes
     */
    QString callback_data;

    /**
     * @switch_inline_query - Optional. If set, pressing the button will prompt the user to select one of their chats, open that chat and insert the bot‘s username and the specified inline query in the input field.
     * Can be empty, in which case just the bot’s username will be inserted.
     */
    QString switch_inline_query;

    /**
     * @switch_inline_query_current_chat - Optional. If set, pressing the button will insert the bot‘s username and the specified inline query in the current chat's input field.
     * Can be empty, in which case only the bot’s username will be inserted.
     */
    QString switch_inline_query_current_chat;

    QJsonObject toJsonObject(){ return object; }
private:
    QJsonObject object;
};

typedef QList<InlineKeyboardButton> InlineKeyboardButtons;

class InlineKeyboardMarkup : public GenericReply
{
public:
    InlineKeyboardMarkup(InlineKeyboardButtons buttons)
        : GenericReply(false),
          buttons(buttons) { qDebug()<<"InlineKeyboardMarkup Constructor";}

    /**
     * @buttons - Array of button rows, each represented by an Array of InlineKeyboardButton objects
     */
    InlineKeyboardButtons buttons;

    virtual QString serialize() const {
        QJsonObject o = QJsonObject();
        QJsonArray keyboardButtons = QJsonArray();
        foreach (InlineKeyboardButton button, buttons) {
            QJsonArray array; array.append(button.toJsonObject());
            keyboardButtons.append(array);
        }
        o.insert("inline_keyboard", keyboardButtons);
        qDebug()<<o;
        return serializeJson(o);
    }
};

}

#endif // INLINEKEYBOARDMARKUP_H
