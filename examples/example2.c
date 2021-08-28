#include <stdio.h>
#include "api_hash_map.h"

#define HASH_MAP_SIZE 8

api_hash_map_t stHashmapCtx;
api_hash_map_item_t stHashmapItem;
api_hash_map_item_t tstHashmap[HASH_MAP_SIZE];

api_hash_map_item_t stHashmapItem1 = {"alice", (sizeof("alice")-1), 23};
api_hash_map_item_t stHashmapItem2 = {"bob", (sizeof("bob")-1), 45};
api_hash_map_item_t stHashmapItem3 = {"eve", (sizeof("eve")-1), 67};

int main(int s32Argc, char const *pcArgv[])
{
  if(API_HASH_MAP_OK == api_hash_map_init(&stHashmapCtx,
                                          tstHashmap,
                                          (sizeof(tstHashmap) / sizeof(tstHashmap[0]))))
  {
    printf("Hash map is initialized successfully\r\n");
    printf("\r\n");
    /* Add items */
    if(API_HASH_MAP_OK == api_hash_map_put(&stHashmapCtx, &stHashmapItem1))
    {
      printf("Item is added successfully\r\n");
    }
    else
    {
      printf("Failed to add item\r\n");
    }
    if(API_HASH_MAP_OK == api_hash_map_put(&stHashmapCtx, &stHashmapItem2))
    {
      printf("Item is added successfully\r\n");
    }
    else
    {
      printf("Failed to add item\r\n");
    }
    if(API_HASH_MAP_OK == api_hash_map_put(&stHashmapCtx, &stHashmapItem3))
    {
      printf("Item is added successfully\r\n");
    }
    else
    {
      printf("Failed to add item\r\n");
    }
    printf("\r\n");
    /* Get items */
    if(API_HASH_MAP_OK == api_hash_map_get(&stHashmapCtx,
                                           "alice",
                                           (sizeof("alice")-1),
                                           &stHashmapItem))
    {
      printf("key: %s\r\n", stHashmapItem.pcKey);
      printf("value: %d\r\n", stHashmapItem.u08Value);
      printf("\r\n");
    }
    else
    {
      printf("Failed to get item\r\n");
    }
    if(API_HASH_MAP_OK == api_hash_map_get(&stHashmapCtx,
                                           "bob",
                                           (sizeof("bob")-1),
                                           &stHashmapItem))
    {
      printf("key: %s\r\n", stHashmapItem.pcKey);
      printf("value: %d\r\n", stHashmapItem.u08Value);
      printf("\r\n");
    }
    else
    {
      printf("Failed to get item\r\n");
    }
    if(API_HASH_MAP_OK == api_hash_map_get(&stHashmapCtx,
                                           "eve",
                                           (sizeof("eve")-1),
                                           &stHashmapItem))
    {
      printf("key: %s\r\n", stHashmapItem.pcKey);
      printf("value: %d\r\n", stHashmapItem.u08Value);
      printf("\r\n");
    }
    else
    {
      printf("Failed to get item\r\n");
    }
  }
  else
  {
    printf("Failed to initialize hash map\r\n");
  }
  return 0;
}
