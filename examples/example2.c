#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "api_hash_map.h"

#define HASH_MAP_SIZE 8

api_hash_map_t stHashmapCtx;
api_hash_map_item_t tstHashmap[HASH_MAP_SIZE];
api_hash_map_item_t stHashmapItem;
api_hash_map_item_t stHashmapItem1;
api_hash_map_item_t stHashmapItem2;
api_hash_map_item_t stHashmapItem3;

int main(int s32Argc, char const *pcArgv[])
{
  if(api_hash_map_init(&stHashmapCtx, tstHashmap, (sizeof(tstHashmap) / sizeof(tstHashmap[0]))))
  {
    printf("Hash map is initialized successfully\r\n");
    printf("\r\n");
    /* Add items */
    stHashmapItem1.pcKey = "alice";
    stHashmapItem1.u08Value = 23;
    if(api_hash_map_put(&stHashmapCtx, &stHashmapItem1))
    {
      printf("Item is added successfully\r\n");
    }
    else
    {
      printf("Failed to add item\r\n");
    }
    stHashmapItem2.pcKey = "bob";
    stHashmapItem2.u08Value = 45;
    if(api_hash_map_put(&stHashmapCtx, &stHashmapItem2))
    {
      printf("Item is added successfully\r\n");
    }
    else
    {
      printf("Failed to add item\r\n");
    }
    stHashmapItem3.pcKey = "eve";
    stHashmapItem3.u08Value = 67;
    if(api_hash_map_put(&stHashmapCtx, &stHashmapItem3))
    {
      printf("Item is added successfully\r\n");
    }
    else
    {
      printf("Failed to add item\r\n");
    }
    printf("\r\n");
    /* Get items */
    if(api_hash_map_get(&stHashmapCtx, "alice", &stHashmapItem))
    {
      printf("key: %s\r\n", stHashmapItem.pcKey);
      printf("value: %d\r\n", stHashmapItem.u08Value);
      printf("\r\n");
    }
    else
    {
      printf("Failed to get item\r\n");
    }
    if(api_hash_map_get(&stHashmapCtx, "bob", &stHashmapItem))
    {
      printf("key: %s\r\n", stHashmapItem.pcKey);
      printf("value: %d\r\n", stHashmapItem.u08Value);
      printf("\r\n");
    }
    else
    {
      printf("Failed to get item\r\n");
    }
    if(api_hash_map_get(&stHashmapCtx, "eve", &stHashmapItem))
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
