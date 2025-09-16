#pragma once

#include "objects/emoji.h"
#include "objects/guild.h"
#include "objects/user.h"
#include "types.h"

enum message_activity_t {
  JOIN,
  SPECTATE,
  LISTEN,
  JOIN_REQUEST = 5
};

struct message_activity {
  enum message_activity_t type;
  nullable_string party_id;
};

// s = state
enum membership_s {
  OWNER,
  ADMIN,
  DEVELOPER,
  READ_ONLY
};

struct team_mem_t {
  enum membership_s membership_state;
  snowflake team_id;
  user user;
  string role;
};

struct team_t {
  nullable_string icon;
  snowflake id;
  struct team_mem_t** members;
  string name;
  snowflake owner_user_id;
};

// st = status
enum webhook_st {
  DISABLED = 1,
  ENABLED,
  DISABLED_BY_DISCORD = 3
};

struct install_params_t {
  string* scope; // array
  string permissions;
};

// itc = integration_types_config
enum itc_key {
  GUILD_INSTALL,
  USER_INSTALL
};

struct itc_dict {
  enum itc_key key;
  struct {
    struct install_params_t* oauth2_install_params; // nullable
  } value;
};

// application //
typedef enum : ul_t {
  APPLICATION_AUTO_MODERATION_RULE_CREATE_BADGE = 1 << 6,
  GATEWAY_PRESENCE = 1 << 12,
  GATEWAY_PRESENCE_LIMITED = 1 << 13,
  GATEWAY_GUILD_MEMBERS = 1 << 14,
  GATEWAY_GUILD_MEMBERS_LIMITED = 1 << 15,
  VERIFICATION_PENDING_GUILD_LIMIT = 1 << 16,
  EMBEDDED = 1 << 17,
  GATEWAY_MESSAGE_CONTENT = 1 << 18,
  GATEWAY_MESSAGE_CONTENT_LIMITED = 1 << 19,
  APPLICATION_COMMAND_BADGE = 1 << 23
} application_flags;

typedef struct {
  snowflake id;
  string name;
  nullable_string icon;
  string description;
  string* rpc_origins; // array
  bool bot_public;
  bool bot_require_code_grant;
  user* bot; // nullable
  nullable_string terms_of_service_url;
  nullable_string privacy_policy_url;
  user* owner; // nullable
  hex verify_key;
  struct team_t* team; // nullable
  nullable_snowflake guild_id;
  guild* guild; // nullable
  nullable_snowflake primary_sku_id;
  nullable_string slug;
  nullable_string cover_image;
  application_flags* flags; // nullable
  int* approximate_guild_count; // nullable
  int* approximate_user_install_count; // nullable
  int* approximate_user_authorization_count; // nullable
  string* redirect_uris; // array 
  nullable_string interactions_endpoint_url;
  nullable_string role_connections_verification_url;
  nullable_string event_webhooks_url;
  enum webhook_st event_webhooks_status;
  string* event_webhooks_types; // array
  string* tags; // array
  struct install_params_t* install_params; // nullable
  struct itc_dict* integration_types_config; // array
  nullable_string custom_install_url;
} application;
