#ifndef REPLYKEYBOARDHIDE
#define REPLYKEYBOARDHIDE

#include "genericreply.h"

namespace Telegram {

class ReplyKeyboardHide : public GenericReply
{
public:
    ReplyKeyboardHide(bool selective = false)
        : GenericReply(selective),
          hideKeyboard(true) {}

    /**
     * Requests clients to hide the custom keyboard
     */
    const bool hideKeyboard;

    virtual QString serialize() const {
        QJsonObject o = QJsonObject();
        o.insert("hide_keyboard", hideKeyboard);
        o.insert("selective", selective);
        return serializeJson(o);
    }
};

}

#endif // REPLYKEYBOARDHIDE
