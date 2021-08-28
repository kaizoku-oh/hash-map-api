#ifndef _API_HASH_MAP_H_
#define _API_HASH_MAP_H_

#include <stdint.h>

typedef enum
{
  API_HASH_MAP_OK = 0,
  API_HASH_MAP_ERR,
  API_HASH_MAP_ERR_ARG,
  API_HASH_MAP_ERR_COLLISION,
  API_HASH_MAP_ERR_OUT_OF_SPACE,
}api_hash_map_err_t;

typedef struct
{
  const char *pcKey;
  uint32_t u32KeyLength;
  uint8_t u08Value;
}api_hash_map_item_t;

typedef struct
{
  api_hash_map_item_t *pstHashMapList;
  uint32_t u32Size;
}api_hash_map_t;

api_hash_map_err_t api_hash_map_init(api_hash_map_t *, api_hash_map_item_t *, int32_t);
api_hash_map_err_t api_hash_map_put(api_hash_map_t *, api_hash_map_item_t *);
api_hash_map_err_t api_hash_map_get(api_hash_map_t *, const char *, uint32_t, api_hash_map_item_t *);
api_hash_map_err_t api_hash_map_remove(api_hash_map_t *, const char *, uint32_t);
api_hash_map_err_t api_hash_map_clear(api_hash_map_t *, api_hash_map_item_t *);
api_hash_map_err_t api_hash_map_size(api_hash_map_t *, uint32_t *);

#endif /* _API_HASH_MAP_H_ */
