#ifndef REPLYKEYBOARDMARKUP_H
#define REPLYKEYBOARDMARKUP_H

#include <QString>

#include "genericreply.h"

namespace Telegram {

typedef QList<QStringList> KeyboardMarkup;

class ReplyKeyboardMarkup : public GenericReply
{
public:
    ReplyKeyboardMarkup(KeyboardMarkup keyboard, bool resizeKeyboard = false, bool oneTimeKeyboard = false, bool selective = false)
        : GenericReply(selective),
          keyboard(keyboard),
          resizeKeyboard(resizeKeyboard),
          oneTimeKeyboard(oneTimeKeyboard) {}

    /**
     * Array of button rows, each represented by an Array of Strings
     */
    KeyboardMarkup keyboard;

    /**
     * Optional. Requests clients to resize the keyboard vertically for optimal fit (e.g., make the keyboard smaller if there are just two rows of buttons).
     * Defaults to false, in which case the custom keyboard is always of the same height as the app's standard keyboard.
     */
    bool resizeKeyboard;

    /**
     * Optional. Requests clients to hide the keyboard as soon as it's been used.
     * Defaults to false.
     */
    bool oneTimeKeyboard;

    virtual QString serialize() const {
        QJsonObject o = QJsonObject();
        QJsonArray keyboardMarkup = QJsonArray();
        foreach (QStringList list, keyboard) {
            keyboardMarkup.append(QJsonArray::fromStringList(list));
        }
        o.insert("keyboard", keyboardMarkup);
        o.insert("resize_keyboard", resizeKeyboard);
        o.insert("one_time_keyboard", oneTimeKeyboard);
        o.insert("selective", selective);        
        return serializeJson(o);
    }
};

}

#endif // REPLYKEYBOARDMARKUP_H
