/*
 * This stupid example demonstrates the use of a hashtable
 * to store and retrieve person structs by their names
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define HASH_MAP_SIZE 8
#define STRING_MAX_LEN 32

typedef struct
{
  char *pcName;
  uint8_t u08Age;
  char *pcJob;
}person_t;

person_t tstTable[HASH_MAP_SIZE];

uint32_t calculate_hash(char *pcString)
{
  uint32_t u32Digest;
  uint8_t u08Index;

  u32Digest = 0;
  for(u08Index = 0; u08Index < strnlen(pcString, STRING_MAX_LEN); u08Index++)
  {
    u32Digest += pcString[u08Index];
  }
  return u32Digest;
}

void add_person(person_t stPerson)
{
  uint32_t u32Digest;
  uint8_t u08PersonIndex;

  /* 1. Calculate the hash of the person name */
  u32Digest = calculate_hash(stPerson.pcName);
  /* 2. Calculate the index in the table to put the person into */
  u08PersonIndex = u32Digest % (sizeof(tstTable) / sizeof(tstTable[0]));
  /* 3. Insert the person at the calculated index */
  tstTable[u08PersonIndex] = stPerson;
}

person_t get_person(char *pcPersonName)
{
  uint32_t u32Digest;
  uint8_t u08PersonIndex;

  /* 1. Calculate the hash of the person name */
  u32Digest = calculate_hash(pcPersonName);
  /* 2. Calculate the index in the table to get the person from */
  u08PersonIndex = u32Digest % (sizeof(tstTable) / sizeof(tstTable[0]));
  /* 3. Return the person at the calculated index */
  return tstTable[u08PersonIndex];
}

int main(int s32Argc, char const *pcArgv[])
{
  person_t stPerson1;
  person_t stPerson2;
  person_t stPerson3;
  person_t stPerson;

  stPerson1.pcName = "Bayrem";
  stPerson1.u08Age = 23;
  stPerson1.pcJob = "Software developer";
  add_person(stPerson1);

  stPerson2.pcName = "Alice";
  stPerson2.u08Age = 24;
  stPerson2.pcJob = "Social engineer";
  add_person(stPerson2);

  stPerson3.pcName = "Bob";
  stPerson3.u08Age = 25;
  stPerson3.pcJob = "Security expert";
  add_person(stPerson3);

  printf("\r\n");
  stPerson = get_person("Bayrem");
  printf("name: %s\r\n", stPerson.pcName);
  printf("age: %d\r\n", stPerson.u08Age);
  printf("job: %s\r\n", stPerson.pcJob);
  printf("\r\n");

  stPerson = get_person("Alice");
  printf("name: %s\r\n", stPerson.pcName);
  printf("age: %d\r\n", stPerson.u08Age);
  printf("job: %s\r\n", stPerson.pcJob);
  printf("\r\n");

  stPerson = get_person("Bob");
  printf("name: %s\r\n", stPerson.pcName);
  printf("age: %d\r\n", stPerson.u08Age);
  printf("job: %s\r\n", stPerson.pcJob);
  printf("\r\n");

  return 0;
}
