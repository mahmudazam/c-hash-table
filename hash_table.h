
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define _DEFAULT_SIZE 32

typedef struct htab_item
{
    void *key;
    void *value;
    struct htab_item *next;
    struct htab_item *prev;
} htab_item;

typedef struct bucket
{
    htab_item *head;
    htab_item *tail;
    size_t len;
} bucket;

typedef struct htab
{
    size_t count;
    bucket *buckets;
    size_t (*hash)(void *);
    int (*eq)(void *, void *);
    size_t bucket_list_size;
} htab;

htab*
new_hash_table(size_t (*hash)(void *), int (*eq)(void *, void *));

void*
get(htab *t, void *k);

int
set(htab *t, void *k, void *v);

#endif /* ! HASH_TABLE_H */

