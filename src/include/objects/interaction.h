#pragma once

#include "objects/emoji.h"
#include "objects/guild.h"
#include "objects/rich_presence.h"
#include "objects/user.h"
#include "types.h"

enum interaction_t {
  PING = 1,
  APPLICATION_COMMAND,
  MESSAGE_COMPONENT,
  APPLICATION_COMMAND_AUTOCOMPLETE,
  MODAL_SUBMIT
};

// io = integration_owners
struct authio_dict {
  enum itc_key key;
  snowflake value;
};

// i prefix = interaction
struct iapp_command_t {
  snowflake id;
  enum interaction_t type;
  user* user; // not nullable
  struct authio_dict** authorizing_integration_owners; // non-nullable array
  nullable_snowflake original_response_message_id;
  user* target_user; // nullable 
  nullable_snowflake target_message_id;
};

struct imsg_component_t {
  snowflake id;
  enum interaction_t type;
  user* user; // not nullable
  struct authiodict** authorizing_integration_owners;
  nullable_snowflake original_response_message_id;
  snowflake interacted_message_id;
};

struct imodal_submit_t {
  snowflake id;
  enum interaction_t type;
  user* user;
  struct authiodict** authorizing_integration_owners;
  nullable_snowflake original_response_message_id;
  
  union {
    struct {
      enum interaction_t type;
    } base;

    struct iapp_command_t app_command;
    struct imsg_component_t msg_component;
  } triggering_interaction_metadata;
};

union interaction_metadata {
  struct {
    enum interaction_t type;
  } base;

  struct iapp_command_t app_command;
  struct imsg_component_t msg_component;
  struct imodal_submit_t modal_submit;
};

typedef struct {
  snowflake id;
  enum interaction_t type;
  string name;
  user* user; // not nullable!!
  member* member; // nullable
} interaction;
