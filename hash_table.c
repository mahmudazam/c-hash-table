
#include <stdlib.h>
#include <hash_table.h>
#include <string.h>
#include <stdio.h>

htab_item*
_get_from_bucket(bucket *b, void *k, int (*eq)(void *, void *))
{
    htab_item *curr = b->head;
    while (NULL != curr)
    {
        if (eq(curr->key, k))
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void
_insert_tail(bucket *b, void *k, void *v)
{
    htab_item *insert = (htab_item*)malloc(sizeof(htab_item));
    insert->next = NULL;
    insert->prev = NULL;
    insert->key = k;
    insert->value = v;
    if (NULL == b->tail)
    {
        b->head = insert;
        b->tail = insert;
        b->len = 1;
    } else
    {
        b->tail->next = insert;
        insert->prev = b->tail;
        b->tail = insert;
        b->len++;
    }
}

htab_item*
_get_htab_item(htab *t, void *k)
{
    size_t index = t->hash(k) % t->bucket_list_size;
    bucket *b = &(t->buckets[index]);

    return _get_from_bucket(b, k, t->eq);
}

htab*
new_hash_table(size_t (*hash)(void *), int (*eq)(void *k1, void *k2))
{
    htab *ht = (htab*)malloc(sizeof(htab));
    if (NULL == ht)
    {
        return NULL;
    }
    ht->count = 0;
    ht->bucket_list_size = _DEFAULT_SIZE;
    ht->buckets = (bucket*)malloc(sizeof(bucket) * _DEFAULT_SIZE);
    memset((void*)(ht->buckets), 0, (sizeof(bucket) * _DEFAULT_SIZE));
    ht->hash = hash;
    ht->eq = eq;

    return ht;
}

void*
get(htab *t, void *k)
{
    htab_item *item = _get_htab_item(t, k);

    return (NULL != item) ? item->value : NULL;
}

int
set(htab *t, void *k, void *v)
{
    htab_item *existing =  _get_htab_item(t, k);
    if (NULL != existing)
    {
        existing->value = v;
    } else
    {
        size_t index = t->hash(k) % t->bucket_list_size;
        bucket *b = &(t->buckets[index]);
        _insert_tail(b, k, v);
        t->count++;
    }

    return 1;
}

