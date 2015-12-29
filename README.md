## Introduction
Qt5 library for the Telegram Bot API ([https://core.telegram.org/bots/api]()).
It can be used to interact with the API directly and/or configured to automatically notify you on updates using Qt’s signals and slots.
You need a bot token to make API calls. Text the [@botfather](https://telegram.me/BotFather) to create a new bot and obtain a token.

## Usage
Create a lib directory in your project directory and cd into it:
```sh
mkdir lib && cd lib
```

Clone the repo to your projects source directory:
```bash
git clone https://github.com/iMoritz/QtTelegramBot.git
```

Alternatively you can add QtTelegramBot as a git submodule to always stay up-to-date:
```bash
git submodule add https://github.com/iMoritz/QtTelegramBot.git
```

In your project file (*project*.pro) add this include:
```qmake
include($$PWD/lib/QtTelegramBot/QtTelegramBot.pri)
```

Now you can use the Bot classes using:
```c++
#include "qttelegrambot.h"
```
    

Everything in *QtTelegramBot* is in the `Telegram` namespace.


## Examples
Examples can be found in the `examples` directory. You can build them in QtCreator or using the command line.
