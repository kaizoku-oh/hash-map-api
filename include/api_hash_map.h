#ifndef _API_HASH_MAP_H_
#define _API_HASH_MAP_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
  const char *pcKey;
  uint8_t u08Value;
}api_hash_map_item_t;

typedef struct
{
  api_hash_map_item_t *pstHashMapList;
  uint32_t u32Size;
}api_hash_map_t;

bool api_hash_map_init(api_hash_map_t *, api_hash_map_item_t *, int32_t);
bool api_hash_map_put(api_hash_map_t *, api_hash_map_item_t *);
bool api_hash_map_get(api_hash_map_t *, const char *, api_hash_map_item_t *);
bool api_hash_map_remove(api_hash_map_t *, const char *);
bool api_hash_map_clear(api_hash_map_t *, api_hash_map_item_t *);
bool api_hash_map_size(api_hash_map_t *, uint32_t *);

#endif /* _API_HASH_MAP_H_ */
