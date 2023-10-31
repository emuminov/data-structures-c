#include <stdlib.h>
// TODO: replace with my own library functions
#include <string.h>
#include <math.h>

#include "base.h"
#include "hash_table.h"

local ht_item *ht_new_item(const char *k, const char *v) {
    ht_item *i = malloc(sizeof(ht_item));
    i->key = strdup(k);
    i->value = strdup(v);
    return i;
}

ht_hash_table *ht_new() {
    ht_hash_table *ht = malloc(sizeof(ht_hash_table));
    ht->size = 53;
    ht->count = 0;
    // TODO: replace with my implementation of calloc
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
    return ht;
}

local void ht_del_item(ht_item *i) {
    free(i->key);
    free(i->value);
    free(i);
}

void ht_del_hash_table(ht_hash_table *ht) {
    int i = 0;
    while (i < ht->count) {
        ht_item *item = ht->items[i];
        if (item != 0) {
            ht_del_item(item);
        }
        i++;
    }
    free(ht->items);
    free(ht);
}

/* function hash(string, a, num_buckets):
    hash = 0
    string_len = length(string)
    for i = 0, 1, ..., string_len:
        hash += (a ** (string_len - (i+1))) * char_code(string[i])
    hash = hash % num_buckets
    return hash */
local int ht_hash(const char *s, const int a, const int m) {
    long hash = 0;
    // TODO: replace with my strlen function
    int l = strlen(s);
    int i = 0;
    while (i < l) {
        // TODO: replace pow with my own function
        hash += (long) pow(a, (l - (i + 1))) * s[i];
        hash %= m;
        i++;
    }
    return (int) hash;
}

local int ht_get_hash(const char *s, const int buckets, const int attempt) {
    const int hash_a = ht_hash(s, HT_PRIME_1, buckets);
    const int hash_b = ht_hash(s, HT_PRIME_2, buckets);
    return (hash_a + (attempt * (hash_b + 1)) % buckets);
}
