#pragma once

#include "objects/attachment.h"
#include "objects/channel.h"
#include "objects/guild.h"
#include "objects/message.h"
#include "objects/role.h"
#include "objects/user.h"
#include "types.h"

struct su_dict_t { 
  snowflake key;
  user* value;
};

struct sm_dict_t { 
  snowflake key;
  member* value;
};

struct sr_dict_t {
  snowflake key;
  role* value;
};

struct sc_dict_t {
  snowflake key;
  channel* value;
};

struct sa_dict_t {
  snowflake key;
  attachment* value;
};

struct smsg_dict_t {
  snowflake key;
  message* value;
};

// everything is nullable
struct resolved_t {
  struct su_dict_t* users;
  struct sm_dict_t* members;
  struct sr_dict_t* roles;
  struct sc_dict_t* channels;
  struct sa_dict_t* attachments;
  struct smsg_dict_t* messages;
};
