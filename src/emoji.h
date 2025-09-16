#pragma once

#include "objects/role.h"
#include "objects/user.h"
#include "types.h"

typedef snowflake nullable_snowflake;
typedef struct {
  nullable_snowflake id;
  nullable_string name;
  role** roles;
  user* user;
  bool* require_colons;
  bool* managed;
  bool* animated;
  bool* available;
} emoji;

// reactionc = reaction_count
struct reactionc_details_t {
  int burst;
  int normal;
};

typedef struct {
  int count;
  struct reactionc_details_t* count_details;
  bool me;
  bool me_burst;
  emoji* emoji; // non-nullable
  hex* burst_colors; // ARRAY!
} reaction;
