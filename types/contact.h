#ifndef CONTACT_H
#define CONTACT_H

#include <QDebug>
#include <QString>
#include <QJsonObject>

namespace Telegram {

class Contact
{
public:
    Contact() {}
    Contact(QJsonObject contact);

    QString phoneNumber;
    QString firstname;
    QString lastname;
    quint32 userId;
};

inline QDebug operator<< (QDebug dbg, const Contact &contact)
{
    dbg.nospace() << qUtf8Printable(QString("Telegram::Contact(phoneNumber=%1; firstname=%2; lastname=%3; userId=%4)")
                                    .arg(contact.phoneNumber)
                                    .arg(contact.firstname)
                                    .arg(contact.lastname)
                                    .arg(contact.userId));

    return dbg.maybeSpace();
}

}

#endif // CONTACT_H
