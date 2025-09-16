#pragma once

#include "types.h"

// the type is converted from string to embed_t in the embed
// json parser
enum embed_t {
  rich,
  image,
  video,
  gifv,
  article,
  link,
  poll_result
};

struct embed_footer_t {
  string text;
  nullable_string icon_url;
  nullable_string proxy_icon_url;
};

struct embed_image_t {
  string url;
  string proxy_url;
  int* height;
  int* width;
};

struct embed_provider_t {
  nullable_string name;
  nullable_string url;
};

struct embed_author_t {
  string name;
  nullable_string url;
  nullable_string icon_url;
  nullable_string proxy_icon_url;
};

struct embed_field_t {
  string name;
  string value;
  bool* is_inline; // inline
};

typedef struct {
  nullable_string title;
  enum embed_t type;
  nullable_string description;
  nullable_string url;
  timestamp_t* timestamp;
  int* color;
  struct embed_footer_t* footer;
  struct embed_image_t* image;
  struct embed_image_t* thumbnail;
  struct embed_image_t* video;
  struct embed_provider_t* provider;
  struct embed_author_t* author;
  struct embed_field_t** fields;
} embed;
