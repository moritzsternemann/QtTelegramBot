#include <QCoreApplication>
#include <QDebug>
#include "qttelegrambot.h"

#define TOKEN "YOUR BOT TOKEN"

Telegram::Bot *bot;

void newMessage(Telegram::Message message)
{
    qDebug() << "new message:" << message;

    if (bot && message.type == Telegram::Message::TextType) {
        bot->sendMessage(message.from.id, message.string);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bot = new Telegram::Bot(TOKEN, true, 500, 4);
    QObject::connect(bot, &Telegram::Bot::message, &newMessage);
    qDebug() << "Started Telegram Bot";

    return a.exec();
}
