#ifndef REPLYKEYBOARDREMOVE_H
#define REPLYKEYBOARDREMOVE_H

#include "genericreply.h"

namespace Telegram {

class ReplyKeyboardRemove : public GenericReply
{
  public:
    ReplyKeyboardRemove(bool selective = false)
        : GenericReply(selective),
          removeKeyboard(true) {}
    /**
     * @removeKeyboard - Requests clients to remove the custom keyboard (user will not be able to summon this keyboard;
     */
    const bool removeKeyboard;

    virtual QString serialize() const {
        QJsonObject o = QJsonObject();
        o.insert("remove_keyboard", removeKeyboard);
        if(selective) o.insert("selective", selective);
        qDebug()<< o;
        return serializeJson(o);
    }
};
}

#endif // REPLYKEYBOARDREMOVE_H
