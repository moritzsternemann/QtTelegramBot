#ifndef UPDATE_H
#define UPDATE_H

#include <QDebug>
#include <QJsonObject>
#include "message.h"
#include "callbackquery.h"

namespace Telegram {

class Update
{
public:
    Update() {}
    Update(QJsonObject update);

    quint32 id;
    Message message;
    CallbackQuery callbackquery;
};

inline QDebug operator<< (QDebug dbg, const Update &update)
{
    dbg.nospace() << qUtf8Printable(QString("Telegram::Update(id=%1; message=%2)")
                                    .arg(update.id)
                                    .arg("Message(" + QString::number(update.message.id) + ")"));

    return dbg.maybeSpace();
}

}

#endif // UPDATE_H
