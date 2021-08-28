#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "api_hash_map.h"

uint32_t _hash_map_calculate_hash(const char *pcKey)
{
  uint32_t u32Digest;
  uint8_t u08Index;

  u32Digest = 0;
  for(u08Index = 0; u08Index < strlen(pcKey); u08Index++)
  {
    u32Digest += pcKey[u08Index];
  }
  return u32Digest;
}

bool api_hash_map_init(api_hash_map_t *pstHashMap, api_hash_map_item_t *pstHashMapList, int32_t s32Size)
{
  bool bRetVal;

  if(pstHashMap && pstHashMapList && s32Size)
  {
    pstHashMap->pstHashMapList = pstHashMapList;
    pstHashMap->u32Size = s32Size;
    bRetVal = true;
  }
  else
  {
    bRetVal = false;
  }
  return bRetVal;
}

bool api_hash_map_put(api_hash_map_t *pstHashMap, api_hash_map_item_t *pstItem)
{
  bool bRetVal;
  uint8_t u08Index;
  uint32_t u32Digest;

  if(pstHashMap && pstItem)
  {
    /* 1. Calculate hash from key */
    u32Digest = _hash_map_calculate_hash(pstItem->pcKey);
    /* 2. Calculate the index in the hashmap to put the item in */
    u08Index = u32Digest % pstHashMap->u32Size;
    /* 3. Insert the item at the calculated index */
    pstHashMap->pstHashMapList[u08Index] = *pstItem;
    bRetVal = true;
  }
  else
  {
    bRetVal = false;
  }
  return bRetVal;
}

bool api_hash_map_get(api_hash_map_t *pstHashMap, const char *pcKey, api_hash_map_item_t *pstItem)
{
  bool bRetVal;
  uint8_t u08Index;
  uint32_t u32Digest;

  if(pstHashMap && pcKey && pstItem)
  {
    /* 1. Calculate hash from key */
    u32Digest = _hash_map_calculate_hash(pcKey);
    /* 2. Calculate the index in the hashmap to get the item from */
    u08Index = u32Digest % pstHashMap->u32Size;
    /* 3. Get the item at the calculated index */
    *pstItem = pstHashMap->pstHashMapList[u08Index];
    bRetVal = true;
  }
  else
  {
    bRetVal = false;
  }
  return bRetVal;
}

bool api_hash_map_remove(api_hash_map_t *pstHashMap, const char *pcKey)
{
  bool bRetVal;

  bRetVal = false;
  return bRetVal;
}

bool api_hash_map_clear(api_hash_map_t *pstHashMap, api_hash_map_item_t *pstMap)
{
  bool bRetVal;

  bRetVal = false;
  return bRetVal;
}

bool api_hash_map_size(api_hash_map_t *pstHashMap, uint32_t *pu32Size)
{
  bool bRetVal;

  bRetVal = false;
  return bRetVal;
}
