#pragma once

/*
client* bot = bot_login(token);
bot->messages->send_dm_msg(bot, channel, (message_data){});
*/

#include "objects/message.h"

typedef unsigned long snowflake;
typedef struct {

} client;

client* bot_login(const char* token);
