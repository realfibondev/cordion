#pragma once

#include "objects/emoji.h"
#include "objects/role.h"
#include "objects/sticker.h"
#include "objects/user.h"
#include "types.h"

enum member_flags_t : ul_t {
  DID_REJOIN = 1 << 0,
  COMPLETED_ONBOARDING = 1 << 1,
  BYPASSES_VERIFICATION = 1 << 2,
  STARTED_ONBOARDING = 1 << 3,
  IS_GUEST = 1 << 4,
  STARTED_HOME_ACTIONS = 1 << 5,
  COMPLETED_HOME_ACTIONS = 1 << 6,
  AUTOMOD_QUARANTINED_USERNAME = 1 << 7,
  DM_SETTINGS_UPSELL_ACKNOWLEDGED = 1 << 9,
  AUTOMOD_QUARANTINED_GUILD_TAG = 1 << 10
};

typedef struct {
  user* user; // nullable
  nullable_string nick;
  nullable_string avatar;
  nullable_string banner;
  snowflake* roles; // non-nullable array
  timestamp_t joined_at;
  timestamp_t premium_since;
  bool deaf;
  bool mute;
  enum member_flags_t flags;
  bool* pending;
  nullable_string permissions;
  timestamp_t* communication_disabled_until; // nullable
  struct avatar_decor* avatar_decoration_data; // nullable 
} member;

enum guild_features_t {
  ANIMATED_BANNER,
  ANIMATED_ICON,
  APPLICATION_COMMAND_PERMISSIONS_V2,
  AUTO_MODERATION,
  BANNER,
  COMMUNITY,
  CREATOR_MONETIZABLE_PROVISIONAL,
  CREATOR_STORE_PAGE,
  DEVELOPER_SUPPORT_SERVER,
  DISCOVERABLE,
  FEATURABLE,
  INVITES_DISABLED,
  INVITE_SPLASH,
  MEMBER_VERIFICATION_GATE_ENABLED,
  MORE_SOUNDBOARD,
  MORE_STICKERS,
  NEWS,
  PARTNERED,
  PREVIEW_ENABLED,
  RAID_ALERTS_DISABLED,
  ROLE_ICONS,
  ROLE_SUBSCRIPTIONS_AVAILABLE_FOR_PURCHASE,
  ROLE_SUBSCRIPTIONS_ENABLED,
  SOUNDBOARD,
  TICKETED_EVENTS_ENABLED,
  VANITY_URL,
  VERIFIED,
  VIP_REGIONS,
  WELCOME_SCREEN_ENABLED,
  GUESTS_ENABLED,
  GUILD_TAGS,
  ENHANCED_ROLE_COLORS
};

// welcome_screenc_t = welcome_screen_channel_t
struct welcome_screenc_t {
  snowflake channel_id;
  string description;
  nullable_snowflake emoji_id;
  nullable_string emoji_name;
};

struct welcome_screen_t {
  nullable_string description;
  struct welcome_screenc_t** welcome_channels; // non-nullable array
};

struct incidents_data_t {
  timestamp_t invites_disabled_until;
  timestamp_t dms_disabled_until;
  timestamp_t* dm_spam_detected_at; // nullable
  timestamp_t* raid_detected_at; // nullable
};

typedef struct {
  snowflake id;
  string name;
  nullable_string icon;
  nullable_string icon_hash;
  nullable_string splash;
  nullable_string discovery_splash;
  bool* owner;
  snowflake owner_id;
  nullable_string permissions;
  nullable_string region;
  nullable_snowflake afk_channel_id;
  int afk_timeout;
  bool* widget_enabled;
  nullable_snowflake widget_channel_id;
  int verification_level;
  int default_message_notifications;
  int explicit_content_filter;
  role** roles; // non-nullable array
  emoji** emojis; // non-nullable array
  enum guild_features_t** features; // non-nullable array
  int mfa_level;
  nullable_snowflake application_id;
  nullable_snowflake system_channel_id;
  int system_channel_flags;
  nullable_snowflake rules_channel_id;
  int* max_presences;
  int* max_members;
  nullable_string vanity_url_code;
  nullable_string description;
  nullable_string banner;
  int premium_tier;
  int* premium_subscription_count;
  string preferred_locale;
  nullable_snowflake public_updates_channel_id;
  int* max_video_channel_users;
  int* max_stage_video_channel_users;
  int* approximate_member_count;
  int* approximate_presence_count;
  struct welcome_screen_t* welcome_screen; // nullable
  int nsfw_level;
  sticker** stickers; // nullable array
  bool premium_progress_bar_enabled;
  nullable_snowflake safety_alerts_channel_id;
  struct incidents_data_t* incidents_data; // nullable
} guild;
