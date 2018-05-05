
#include <stdlib.h>
#include <hash_table.h>
#include <assert.h>

size_t int_hash(void *k)
{
    size_t key = (size_t)k;
    return key * 257;
}

int
main(int argc, char *argv[])
{
    htab *ht = new_hash_table(int_hash);
    assert(NULL == ht);
    assert(NULL == get(NULL, NULL));
    assert(!set(ht, NULL, NULL));
    return 0;
}

