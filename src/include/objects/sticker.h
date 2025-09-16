#pragma once

#include "objects/emoji.h"
#include "objects/user.h"
#include "types.h"

enum sticker_t {
  STANDARD = 1,
  GUILD
};

enum sticker_fmt_t {
  PNG = 1,
  APNG,
  LOTTIE,
  GIF
};

struct sticker_item {
  snowflake id;
  string name;
  enum sticker_fmt_t format_type;
};

// any primitive type with a pointer immediately means its nullable
typedef struct {
  snowflake id;
  nullable_snowflake pack_id;
  string name;
  nullable_string description;
  string tags;
  enum sticker_t type;
  enum sticker_fmt_t format_type;
  bool* available;
  nullable_snowflake guild_id;
  user* user; // nullable
  int* sort_value;
} sticker;


