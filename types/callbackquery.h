#ifndef CALLBACKQUERY_H
#define CALLBACKQUERY_H

#include <QDebug>
#include <QString>
#include <QJsonObject>

#include "user.h"
#include "message.h"

namespace Telegram {

class CallbackQuery
{
public:
    CallbackQuery() : empty(true) {}
    CallbackQuery(QJsonObject callbackquery);

    QString id;
    User from;
    Message message;
    QString inline_message_id;
    QString chat_instance;
    QString data;
    QString game_short_name;
    bool isEmpty() const {
        return empty;
    }
private:
    bool empty;
};

inline QDebug operator<< (QDebug dbg, const CallbackQuery &callbackquery)
{
    dbg.nospace() << qUtf8Printable(QString("Telegram::CallbackQuery(id=%1; From=%2")
                                    .arg(callbackquery.id)
                                    .arg(callbackquery.from.username));
    return dbg.maybeSpace();
}
}

#endif // CALLBACKQUERY_H
