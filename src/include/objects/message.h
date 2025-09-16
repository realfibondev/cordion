#pragma once

// everything is handwritten
#include "objects/attachment.h"
#include "objects/channel.h"
#include "objects/embed.h"
#include "objects/emoji.h"
#include "objects/rich_presence.h"
#include "objects/role.h"
#include "types.h"
#include "user.h"

enum nonce_type { 
  STRING, 
  INTEGER 
};

enum message_reference_t {
  REF_DEFAULT,
  REF_FORWARDED
};

typedef union {
  struct {
    enum nonce_type type;
    int *value;
  } int_t;

  struct {
    enum nonce_type type;
    string *value;
  } str_t;

  struct {
    bool is_null;
    enum nonce_type type;
  } nonce_base;
} nonce_t;

struct message_reference {
  enum message_reference_t* type; // nullable 
  nullable_snowflake message_id;
  nullable_snowflake channel_id;
  nullable_snowflake guild_id;
  bool* fail_if_not_exists;
};

typedef struct message message;
struct message_snapshot {
  message* message; // nullable
};

struct msg_call_t {
  snowflake* participants; // non-nullable array
  timestamp_t* ended_timestamp; // nullable timestamp
};

typedef enum {
  DEFAULT,
  RECIPIENT_ADD,
  RECIPIENT_REMOVE,
  CALL,
  CHANNEL_NAME_CHANGE,
  CHANNEL_ICON_CHANGE,
  CHANNEL_PINNED_MESSAGE,
  USER_JOIN,
  GUILD_BOOST,
  GUILD_BOOST_TIER_1,
  GUILD_BOOST_TIER_2,
  GUILD_BOOST_TIER_3,
  CHANNEL_FOLLOW_ADD,
  GUILD_DISCOVERY_DISQUALIFIED = 14,
  GUILD_DISCOVERY_REQUALIFIED,
  GUILD_DISCOVERY_GRACE_PERIOD_INITIAL_WARNING,
  GUILD_DISCOVERY_GRACE_PERIOD_FINAL_WARNING,
  THREAD_CREATED,
  REPLY,
  CHAT_INPUT_COMMAND,
  THREAD_STARTER_MESSAGE,
  GUILD_INVITE_REMINDER,
  CONTEXT_MENU_COMMAND,
  AUTO_MODERATION_ACTION,
  ROLE_SUBSCRIPTION_PURCHASE,
  INTERACTION_PREMIUM_UPSELL,
  STAGE_START,
  STAGE_END,
  STAGE_SPEAKER,
  STAGE_TOPIC = 31,
  GUILD_APPLICATION_PREMIUM_SUBSCRIPTION,
  GUILD_INCIDENT_ALERT_MODE_ENABLED = 36,
  GUILD_INCIDENT_ALERT_MODE_DISABLED,
  GUILD_INCIDENT_REPORT_RAID,
  GUILD_INCIDENT_REPORT_FALSE_ALARM,
  PURCHASE_NOTIFICATION = 44,
  POLL_RESULT = 46
} message_t;

typedef enum : ul_t {
  CROSSPOSTED = 1 << 0,
  IS_CROSSPOST = 1 << 1,
  SUPPRESS_EMBEDS = 1 << 2,
  SOURCE_MESSAGE_DELETED = 1 << 3,
  URGENT = 1 << 4,
  HAS_THREAD = 1 << 5,
  EPHEMERAL = 1 << 6,
  LOADING = 1 << 7,
  FAILED_TO_MENTION_SOME_ROLES_IN_THREAD = 1 << 8,
  SUPPRESS_NOTIFICATIONS = 1 << 12,
  IS_VOICE_MESSAGE = 1 << 13,
  HAS_SNAPSHOT = 1 << 14,
  IS_COMPONENTS_V2 = 1 << 15
} message_flags;

typedef enum {
  action_row = 1,
  button,
  string_select,
  text_input,
  user_select,
  role_select,
  mentionable_select,
  channel_select,
  section,
  text_display,
  thumbnail,
  media_gallery,
  file,
  separator,
  container = 17,
  label
} message_components;

// does a MESSAGE need all of this??
// even tho its struct message, you can use it.
struct message {
  snowflake id;
  const char *content;
  snowflake channel_id;
  user* author; // NOT nullable!!
  timestamp_t timestamp;
  timestamp_t edited_timestamp;
  bool tts;
  bool mention_everyone;
  user** mentions;
  role** mention_roles;
  struct channel_mention_t** mention_channels;
  attachment **attachments;
  embed** embeds;
  reaction** reactions;
  nonce_t* nonce;
  bool pinned;
  nullable_snowflake webhook_id;
  message_t type;
  struct message_activity* activity;
  application* application; // nullable
  nullable_snowflake application_id;
  message_flags flags;
  struct message_reference* message_reference; // nullable
  struct message_snapshot** message_snapshots; // nullable array
  message* referenced_message; // nullable
  union interaction_metadata_t* interaction_metadata; // nullable 
  struct interaction* interaction; // nullable 
  channel* thread; // nullable
  message_components** components; // nullable array
  struct sticker_item** sticker_items; // nullable array 
  struct sticker** stickers; // nullable array 
  int* position;
  role_sub_t* role_subscription_data; // nullable 
  struct resolved_t* resolved; // nullable 
  struct poll* poll; // nullable
  struct message_t* call; // nullable
};
