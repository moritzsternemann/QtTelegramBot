#include "message.h"

using namespace Telegram;

Message::Message(QJsonObject message)
{
    id = message.value("message_id").toInt();
    date = QDateTime::fromMSecsSinceEpoch(message.value("date").toInt());
    chat = Chat(message.value("chat").toObject());

    /**
    x audio               Audio     Optional. Message is an audio file, information about the file
      document            Document	Optional. Message is a general file, information about the file
      photo               Array of PhotoSize	Optional. Message is a photo, available sizes of the photo
      sticker             Sticker	Optional. Message is a sticker, information about the sticker
      video               Video	Optional. Message is a video, information about the video
      voice               Voice	Optional. Message is a voice message, information about the file
      caption             String	Optional. Caption for the photo or video
      contact             Contact	Optional. Message is a shared contact, information about the contact
      location            Location	Optional. Message is a shared location, information about the location
      new_chat_participant	User	Optional. A new member was added to the group, information about them (this member may be bot itself)
      left_chat_participant	User	Optional. A member was removed from the group, information about them (this member may be bot itself)
      new_chat_photo	Array of PhotoSize	Optional. A chat photo was change to this value
      delete_chat_photo	True	Optional. Informs that the chat photo was deleted
      group_chat_created	True	Optional. Informs that the group has been created
    */

    if (message.contains("from")) {
        from = User(message.value("from").toObject());
    }
    if (message.contains("forward_from")) {
        forwardFrom = User(message.value("forward_from").toObject());
    }
    if (message.contains("forward_date")) {
        forwardDate = QDateTime::fromMSecsSinceEpoch(message.value("forward_date").toInt());
    }
    if (message.contains("reply_to_message")) {
        replyToMessage = new Message(message.value("reply_to_message").toObject());
    }

    // Parse payload
    QJsonObject obj;
    if (message.contains("text")) {
        string = message.value("text").toString();
        type = Message::TextType;
    }
    if (message.contains("audio")) {
        obj = message.value("audio").toObject();
        audio = Audio(obj);
        type = Message::AudioType;
    }
    if (message.contains("document")) {
        obj = message.value("document").toObject();
        document = Document(obj);
        type = Message::DocumentType;
    }
    if (message.contains("photo")) {
        foreach (QJsonValue val, message.value("photo").toArray()) {
            photo.append(PhotoSize(val.toObject()));
        }
        type = Message::PhotoType;
    }
    if (message.contains("sticker")) {
        obj = message.value("sticker").toObject();
        sticker = Sticker(obj);
        type = Message::StickerType;
    }
    if (message.contains("video")) {
        obj = message.value("video").toObject();
        video = Video(obj);
        type = Message::VideoType;
    }
    if (message.contains("voice")) {
        obj = message.value("voice").toObject();
        voice = Voice(obj);
        type = Message::VoiceType;
    }
    if (message.contains("contact")) {
        obj = message.value("contact").toObject();
        contact = Contact(obj);
        type = Message::ContactType;
    }
    if (message.contains("location")) {
        obj = message.value("location").toObject();
        location = Location(obj);
        type = Message::LocationType;
    }
    if (message.contains("new_chat_participant")) {
        obj = message.value("new_chat_participant").toObject();
        user = User(obj);
        type = Message::NewChatParticipantType;
    }
    if (message.contains("left_chat_participant")) {
        obj = message.value("left_chat_participant").toObject();
        user = User(obj);
        type = Message::LeftChatParticipantType;
    }
    if (message.contains("new_chat_title")) {
        string = message.value("new_chat_title").toString();
        type = Message::NewChatTitleType;
    }
    if (message.contains("new_chat_photo")) {
        foreach (QJsonValue val, message.value("new_chat_photo").toArray()) {
            photo.append(PhotoSize(val.toObject()));
        }
        type = Message::NewChatPhotoType;
    }
    if (message.contains("delete_chat_photo")) {
        boolean = true;
        type = Message::DeleteChatPhotoType;
    }
    if (message.contains("group_chat_created")) {
        boolean = true;
        type = Message::GroupChatCreatedType;
    }
}
