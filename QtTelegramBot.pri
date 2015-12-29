INCLUDEPATH += $$PWD

QT       += core network

SOURCES += \
    $$PWD/qttelegrambot.cpp \
    $$PWD/networking.cpp \
    $$PWD/types/message.cpp \
    $$PWD/types/update.cpp \
    $$PWD/types/chat.cpp \
    $$PWD/types/user.cpp \
    $$PWD/types/document.cpp \
    $$PWD/types/photosize.cpp \
    $$PWD/types/audio.cpp \
    $$PWD/types/sticker.cpp \
    $$PWD/types/video.cpp \
    $$PWD/types/voice.cpp \
    $$PWD/types/contact.cpp \
    $$PWD/types/location.cpp

HEADERS += \
    $$PWD/qttelegrambot.h \
    $$PWD/networking.h \
    $$PWD/types/message.h \
    $$PWD/types/update.h \
    $$PWD/types/chat.h \
    $$PWD/types/user.h \
    $$PWD/types/file.h \
    $$PWD/types/document.h \
    $$PWD/types/photosize.h \
    $$PWD/types/audio.h \
    $$PWD/types/sticker.h \
    $$PWD/types/video.h \
    $$PWD/types/voice.h \
    $$PWD/types/contact.h \
    $$PWD/types/location.h \
    $$PWD/types/reply/genericreply.h \
    $$PWD/types/reply/replykeyboardmarkup.h \
    $$PWD/types/reply/replykeyboardhide.h \
    $$PWD/types/reply/forcereply.h

OTHER_FILES += \
    $$PWD/README.md
