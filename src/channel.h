#pragma once

#include "objects/emoji.h"
#include "objects/guild.h"
#include "objects/user.h"
#include "types.h"

typedef enum : int {
  GUILD_TEXT = 0,
  DM = 1,
  GUILD_VOICE = 2,
  GROUP_DM = 3,
  GUILD_CATEGORY = 4,
  GUILD_ANNOUNCEMENT = 5,
  ANNOUNCEMENT_THREAD = 10,
  PUBLIC_THREAD = 11,
  PRIVATE_THREAD = 12,
  GUILD_STAGE_VOICE = 13,
  GUILD_DIRECTORY = 14,
  GUILD_FORUM = 15,
  GUILD_MEDIA = 16
} channel_type;

enum overwrite_enum_t {
  overwrite_role,
  overwrite_member
};

enum permissions : ul_t {
  CREATE_INSTANT_INVITE = 1ul << 0,
  KICK_MEMBERS = 1ul << 1,
  BAN_MEMBERS = 1ul << 2,
  ADMINISTRATOR = 1ul << 3,
  MANAGE_CHANNELS = 1ul << 4,
  MANAGE_GUILD = 1ul << 5,
  ADD_REACTIONS = 1ul << 6,
  VIEW_AUDIT_LOG = 1ul << 7,
  PRIORITY_SPEAKER = 1ul << 8,
  STREAM = 1ul << 9,
  VIEW_CHANNEL = 1ul << 10,
  SEND_MESSAGES = 1ul << 11,
  SEND_TTS_MESSAGES = 1ul << 12,
  MANAGE_MESSAGES = 1ul << 13,
  EMBED_LINKS = 1ul << 14,
  ATTACH_FILES = 1ul << 15,
  READ_MESSAGE_HISTORY = 1ul << 16,
  MENTION_EVERYONE = 1ul << 17,
  USE_EXTERNAL_EMOJIS = 1ul << 18,
  VIEW_GUILD_INSIGHTS = 1ul << 19,
  CONNECT = 1ul << 20,
  SPEAK = 1ul << 21,
  MUTE_MEMBERS = 1ul << 22,
  DEAFEN_MEMBERS = 1ul << 23,
  MOVE_MEMBERS = 1ul << 24,
  USE_VAD = 1ul << 25,
  CHANGE_NICKNAME = 1ul << 26,
  MANAGE_NICKNAMES = 1ul << 27,
  MANAGE_ROLES = 1ul << 28,
  MANAGE_WEBHOOKS = 1ul << 29,
  MANAGE_GUILD_EXPRESSIONS = 1ul << 30,
  USE_APPLICATION_COMMANDS = 1ul << 31,
  REQUEST_TO_SPEAK = 1ul << 32,
  MANAGE_EVENTS = 1ul << 33,
  MANAGE_THREADS = 1ul << 34,
  CREATE_PUBLIC_THREADS = 1ul << 35,
  CREATE_PRIVATE_THREADS = 1ul << 36,
  USE_EXTERNAL_STICKERS = 1ul << 37,
  SEND_MESSAGES_IN_THREADS = 1ul << 38,
  USE_EMBEDDED_ACTIVITIES = 1ul << 39,
  MODERATE_MEMBERS = 1ul << 40,
  VIEW_CREATOR_MONETIZATION_ANALYTICS = 1ul << 41,
  USE_SOUNDBOARD = 1ul << 42,
  CREATE_GUILD_EXPRESSIONS = 1ul << 43,
  CREATE_EVENTS = 1ul << 44,
  USE_EXTERNAL_SOUNDS = 1ul << 45,
  SEND_VOICE_MESSAGES = 1ul << 46,
  SEND_POLLS = 1ul << 49,
  USE_EXTERNAL_APPS = 1ul << 50,
  PIN_MESSAGES = 1ul << 51
}

struct overwrite_t {
  snowflake id;
  enum overwrite_enum_t type;
  enum permissions allow;
  enum permissions deny;
};

// thread_metadata
struct threadm_t {
  bool archived;
  int auto_archive_duration;
  timestamp_t archive_timestamp;
  bool locked;
  bool* invitable;
  timestamp_t* create_timestamp; // nullable
};

struct threadm_member_t {
  nullable_snowflake id;
  nullable_snowflake user_id;
  timestamp_t join_timestamp;
  int flags;
  member* member; // nullable
};

struct tag_t {
  snowflake id;
  string name;
  bool moderated;
  nullable_snowflake emoji_id;
  nullable_string emoji_name;
};

struct default_reaction_t {
  nullable_snowflake emoji_id;
  nullable_string emoji_name;
};

enum video_quality_t {
  AUTO = 1,
  FULL
};

enum channel_flags_t : ul_t {
  PINNED = 1 << 1,
  REQUIRE_TAG = 1 << 4,
  HIDE_MEDIA_DOWNLOAD_OPTIONS = 1 << 15
};

typedef struct {
  snowflake id;
  channel_type type;
  nullable_snowflake guild_id;
  int* position;
  struct overwrite_t** permission_overwrites; // nullable array 
  nullable_string name;
  nullable_string topic;
  bool* nsfw;
  nullable_snowflake last_message_id;
  int* bitrate;
  int* user_limit;
  int* rate_limit_per_user;
  user** recipients; // nullable array
  nullable_string icon;
  nullable_snowflake owner_id;
  nullable_snowflake application_id;
  bool* managed;
  nullable_snowflake parent_id;
  timestamp_t last_pin_timestamp;
  nullable_string rtc_region;
  enum video_quality_t* video_quality_mode; // nullable
  int* message_count;
  int* member_count;
  struct threadm_t* thread_metadata; // nullable
  struct threadm_member_t* member; // nullable
  int* default_auto_archive_duration;
  nullable_string permissions;
  enum channel_flags_t* flags; // nullable
  int* total_message_sent;
  struct tag** available_tags; // nullable array
  struct snowflake* applied_tags; // nullable array
  struct default_reaction_t* default_reaction_emoji; // nullable
  int* default_thread_rate_limit_per_user;
  int* default_sort_order;
  int* default_forum_layout;
} channel;

// typedef struct = can be used
// struct = shouldn't be used (directly)
struct channel_mention_t {
  snowflake id;
  snowflake guild_id;
  channel_type type;
  string name;
};
