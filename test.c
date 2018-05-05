
#include <stdlib.h>
#include <hash_table.h>
#include <assert.h>

size_t
int_hash(void *k)
{
    size_t key = (size_t)k;
    return key * 257;
}

int
int_eq(void *k1, void *k2)
{
    return k1 == k2;
}

int
main(int argc, char *argv[])
{
    htab *ht = new_hash_table(int_hash, int_eq);
    #if 0
    assert(NULL == ht);
    assert(NULL == get(NULL, NULL));
    assert(!set(ht, NULL, NULL));
    #endif
    htab_item items[3] = {{(void*)5,(void*)23,NULL}, {0}, {0}};
    ht->buckets[ht->hash((void*)5) % _DEFAULT_SIZE].head = &items[0];
    assert((void*)23 == get(ht, (void*)5));
    return 0;
}

