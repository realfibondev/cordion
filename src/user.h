#pragma once

#include "types.h"

typedef enum : ul_t {
  STAFF = 1 << 0,
  PARTNER = 1 << 0,
  HYPESQUAD = 1 << 2,
  BUG_HUNTER_LEVEL_1 = 1 << 3,
  HYPESQUAD_ONLINE_HOUSE_1 = 1 << 6,
  HYPESQUAD_ONLINE_HOUSE_2 = 1 << 7,
  HYPESQUAD_ONLINE_HOUSE_3 = 1 << 8,
  PREMIUM_EARLY_SUPPORTER = 1 << 9,
  TEAM_PSEUDO_USER = 1 << 10,
  BUG_HUNTER_LEVEL_2 = 1 << 14,
  VERIFIED_BOT = 1 << 16,
  VERIFIED_DEVELOPER = 1 << 17,
  CERTIFIED_MODERATOR = 1 << 18,
  BOT_HTTP_INTERACTIONS = 1 << 19,
  ACTIVE_DEVELOPER = 1 << 22
} flags;

// abstract
struct avatar_decor {
  const char* asset;
  snowflake sku_id;
};

struct nameplate_t {
  snowflake sku_id;
  string asset;
  string label;
  string palette;
};

struct collectibles_t {
  struct nameplate_t* nameplate;
};

struct primary_guild_t {
  snowflake* identity_guild_id;
  bool* identity_enabled;
  nullable_string tag;
  nullable_string badge;
};

typedef struct {
  snowflake id;
  string username;
  string discriminator;
  nullable_string global_name;
  nullable_string avatar;
  bool bot;
  bool system;
  bool mfa_enabled;
  nullable_string banner;
  int* accent_color;
  nullable_string locale;
  bool* verified;
  nullable_string email;
  flags flags;
  int* premium_type;
  int* public_flags;
  struct avatar_decor* avatar_decoration_data;
  struct collectibles_t* collectibles;
  struct primary_guild_t* primary_guild;
} user;
