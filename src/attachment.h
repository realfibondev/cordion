#pragma once

#include "types.h"

typedef enum : ul_t {
  IS_REMIX = 1 << 2
} attachment_flags;

typedef struct {
  snowflake id;
  string filename;
  nullable_string title;
  nullable_string description;
  nullable_string content_type;
  int size;
  string url;
  string proxy_url;
  int* height;
  int* width;
  bool* ephemeral;
  float duration_secs;
  string waveform;
  attachment_flags flags;
} attachment;
