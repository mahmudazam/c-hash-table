
#include <stdlib.h>
#include <hash_table.h>
#include <string.h>

htab_item*
_get_from_bucket(bucket *b, void *k, int (*eq)(void *, void *))
{
    htab_item *curr = b->head;
    while (NULL != curr)
    {
        if (eq(curr->elem1, k))
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
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

htab_item*
_get_htab_item(htab *t, void *k)
{
    size_t index = t->hash(k) % t->bucket_list_size;
    bucket *b = &(t->buckets[index]);
    return _get_from_bucket(b, k, t->eq);
}

void*
get(htab *t, void *k)
{
    return _get_htab_item(t, k)->elem2;
}

int
set(htab *t, void *k, void *v)
{
    #if 0
    htab_item *existing =  _get_htab_item(t, k);
    if (NULL != existing)
    {
        existing->
    }
    return 0;
    #endif
    return 0;
}

