
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct pair
{
    void *elem1;
    void *elem2;
} pair;

typedef struct htab
{
    size_t count;
    pair **buckets;
} htab;

void*
get(htab *t, void *k);

#endif /* ! HASH_TABLE_H */

