#ifndef FORCEREPLY
#define FORCEREPLY

#include "genericreply.h"

namespace Telegram {

class ForceReply : public GenericReply
{
public:
    ForceReply(bool selective = false)
        : GenericReply(selective),
          forceReply(true) {}

    /**
     * Shows reply interface to the user, as if they manually selected the bot‘s message and tapped ’Reply'
     */
    const bool forceReply;

    virtual QString serialize() const {
        QJsonObject o = QJsonObject();
        o.insert("force_reply", forceReply);
        o.insert("selective", selective);
        return serializeJson(o);
    }
};

}

#endif // FORCEREPLY

