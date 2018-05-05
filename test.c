
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
    return (size_t)k1 == (size_t)k2;
}

int
main(int argc, char *argv[])
{
    htab *ht = new_hash_table(int_hash, int_eq);

    // Test linking:
    #if 0
    assert(NULL == ht);
    assert(NULL == get(NULL, NULL));
    assert(!set(ht, NULL, NULL));
    #endif

    // Test get:
    htab_item items[3] = {{(void*)5, (void*)23, NULL, NULL}, {0}, {0}};
    ht->buckets[ht->hash((void*)5) % _DEFAULT_SIZE].head = &(items[0]);
    ht->buckets[ht->hash((void*)5) % _DEFAULT_SIZE].tail = &(items[0]);
    ht->buckets[ht->hash((void*)5) % _DEFAULT_SIZE].len = 1;
    assert((void*)23 == get(ht, (void*)5));

    // Test set:
    assert(set(ht, (void*)5, (void*)24));
    assert((void*)24 == get(ht, (void*)5));
    assert(set(ht, (void*)29, (void*)12));
    assert((void*)12 == get(ht, (void*)29));
    assert(set(ht, (void*)37, (void*)52));
    assert((void*)52 == get(ht, (void*)37));
    assert((void*)24 == get(ht, (void*)5));
    assert((void*)12 == get(ht, (void*)29));

    return 0;
}

