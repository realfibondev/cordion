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

// TODO: bitwise permission fields are missing
// https://discord.com/developers/docs/topics/permissions#permissions
struct overwrite_t {
  snowflake id;
  enum overwrite_enum_t type;
  string allow;
  string deny;
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
