#pragma once

#include "objects/emoji.h"
#include "types.h"

struct poll_media_t {
  nullable_string text;
  emoji* emoji;
};

struct poll_answer_t {
  int answer_id;
  struct poll_media_t* poll_media;
};

struct poll_answer_count_t {
  int id;
  int count;
  bool me_voted;
};

struct poll_result_t {
  bool is_finalized;
  struct poll_answer_count_t** answer_counts; // non-nullable array
};

struct poll_t {
  struct poll_media_t* question; // not nullable
  struct poll_answer_t** answers; // non-nullable array
  timestamp_t expiry;
  bool allow_multiselect;

  enum {
    LT_DEFAULT = 1
  } layout_type;

  struct poll_result_t** results; // nullable array
};
