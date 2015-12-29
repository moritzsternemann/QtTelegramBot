#ifndef GENERICREPLY_H
#define GENERICREPLY_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace Telegram {

class GenericReply
{
public:
    GenericReply() : valid(false) {}
    GenericReply(bool selective) : selective(selective), valid(true) {}

    /**
     * Optional. Use this parameter if you want to show the keyboard to specific users only.
     * Targets: 1) users that are @mentioned in the text of the Message object;
     *          2) if the bot's message is a reply (has reply_to_message_id), sender of the original message.
     */
    bool selective;

    virtual QString serialize() const {
        return QString();
    }

    bool isValid() const {
        return valid;
    }

private:
    bool valid;

protected:
    QByteArray serializeJson(QJsonObject o) const {
        QJsonDocument d = QJsonDocument(o);
        return d.toJson(QJsonDocument::Compact);
    }
};

}

#endif // GENERICREPLY_H
