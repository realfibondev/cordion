#pragma once

#include "types.h"

typedef struct {
  snowflake role_subscription_listing_id;
  string tier_name;
  int total_months_subscribed;
  bool is_renewal;
} role_sub_t; // sub = subscription

typedef struct {
  snowflake* bot_id;
  snowflake* integration_id;
  bool* premium_subscriber;
  snowflake* subscription_listing_id;
  bool* available_for_purchase;
  bool* guild_connections;
} role;
