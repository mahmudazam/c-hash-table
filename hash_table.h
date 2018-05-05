
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct htab_item
{
    void *elem1;
    void *elem2;
    struct htab_item *next;
    struct htab_item *prev;
} htab_item;

typedef struct bucket
{
    htab_item *head;
    htab_item *tail;
    size_t len;
} pair_list;

typedef struct htab
{
    size_t count;
    htab_item *buckets;
    size_t (*hash)(void *);
} htab;

htab*
new_hash_table(size_t (*hash)(void *));

void*
get(htab *t, void *k);

int
set(htab *t, void *k, void *v);

#endif /* ! HASH_TABLE_H */

