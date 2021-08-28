#include <stdint.h>
#include "api_hash_map.h"

uint32_t _hash_map_calculate_hash(const char *pcKey, uint32_t u32KeyLength)
{
  uint32_t u32Digest;
  uint8_t u08Index;

  u32Digest = 0;
  for(u08Index = 0; u08Index < u32KeyLength; u08Index++)
  {
    u32Digest += pcKey[u08Index];
  }
  return u32Digest;
}

api_hash_map_err_t api_hash_map_init(api_hash_map_t *pstHashMap,
                                     api_hash_map_item_t *pstHashMapList,
                                     int32_t s32Size)
{
  api_hash_map_err_t eRetVal;

  if(pstHashMap && pstHashMapList && s32Size)
  {
    pstHashMap->pstHashMapList = pstHashMapList;
    pstHashMap->u32Size = s32Size;
    eRetVal = API_HASH_MAP_OK;
  }
  else
  {
    eRetVal = API_HASH_MAP_ERR_ARG;
  }
  return eRetVal;
}

api_hash_map_err_t api_hash_map_put(api_hash_map_t *pstHashMap, api_hash_map_item_t *pstItem)
{
  uint8_t u08Index;
  uint32_t u32Digest;
  api_hash_map_err_t eRetVal;

  if(pstHashMap && pstItem)
  {
    /* 1. Calculate hash from key */
    u32Digest = _hash_map_calculate_hash(pstItem->pcKey, pstItem->u32KeyLength);
    /* 2. Calculate the index in the hashmap to put the item in */
    u08Index = u32Digest % pstHashMap->u32Size;
    /* 3. Insert the item at the calculated index */
    pstHashMap->pstHashMapList[u08Index] = *pstItem;
    eRetVal = API_HASH_MAP_OK;
  }
  else
  {
    eRetVal = API_HASH_MAP_ERR_ARG;
  }
  return eRetVal;
}

api_hash_map_err_t api_hash_map_get(api_hash_map_t *pstHashMap,
                                    const char *pcKey,
                                    uint32_t u32KeyLength,
                                    api_hash_map_item_t *pstItem)
{
  uint8_t u08Index;
  uint32_t u32Digest;
  api_hash_map_err_t eRetVal;

  if(pstHashMap && pcKey && u32KeyLength && pstItem)
  {
    /* 1. Calculate hash from key */
    u32Digest = _hash_map_calculate_hash(pcKey, u32KeyLength);
    /* 2. Calculate the index in the hashmap to get the item from */
    u08Index = u32Digest % pstHashMap->u32Size;
    /* 3. Get the item at the calculated index */
    *pstItem = pstHashMap->pstHashMapList[u08Index];
    eRetVal = API_HASH_MAP_OK;
  }
  else
  {
    eRetVal = API_HASH_MAP_ERR_ARG;
  }
  return eRetVal;
}

api_hash_map_err_t api_hash_map_remove(api_hash_map_t *pstHashMap,
                                       const char *pcKey,
                                       uint32_t u32KeyLength)
{
  api_hash_map_err_t eRetVal;

  eRetVal = API_HASH_MAP_ERR;
  return eRetVal;
}

api_hash_map_err_t api_hash_map_clear(api_hash_map_t *pstHashMap, api_hash_map_item_t *pstMap)
{
  api_hash_map_err_t eRetVal;

  eRetVal = API_HASH_MAP_ERR;
  return eRetVal;
}

api_hash_map_err_t api_hash_map_size(api_hash_map_t *pstHashMap, uint32_t *pu32Size)
{
  api_hash_map_err_t eRetVal;

  if(pstHashMap && pu32Size)
  {
    *pu32Size = pstHashMap->u32Size;
    eRetVal = API_HASH_MAP_OK;
  }
  else
  {
    eRetVal = API_HASH_MAP_ERR_ARG;
  }
  return eRetVal;
}
