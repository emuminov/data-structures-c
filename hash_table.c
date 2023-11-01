#include <stdlib.h> // TODO: replace with my own library functions
#include <string.h>
#include <math.h>

#include "base.h"
#include "hash_table.h"

local ht_item HT_DELETED_ITEM = {0, 0};

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

// bash hash function
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

// actual hash function that double hashes
local int ht_get_hash(const char *s, const int buckets, const int attempt) {
    const int hash_a = ht_hash(s, HT_PRIME_1, buckets);
    const int hash_b = ht_hash(s, HT_PRIME_2, buckets);
    return (hash_a + (attempt * (hash_b + 1)) % buckets);
}

void ht_insert(ht_hash_table *ht, const char *key, const char *value) {
    ht_item *new_item = ht_new_item(key, value);
    int attempt = 0;
    int index = ht_get_hash(key, ht->size, attempt);
    ht_item *curr_item = ht->items[index];
    while (curr_item != 0 && curr_item != &HT_DELETED_ITEM) {
        index = ht_get_hash(new_item->key, ht->size, ++attempt);
        curr_item = ht->items[index];
    }
    ht->items[index] = new_item;
    ht->count++;
}

char *ht_search(ht_hash_table *ht, const char *key) {
    int attempt = 0;
    int index = ht_get_hash(key, ht->size, attempt);
    ht_item *item = ht->items[index];
    while (item != 0) {
        // TODO: replace with my own function
        if (strcmp(key, item->key) == 0 && item != &HT_DELETED_ITEM) {
            return item->value;
        }
        index = ht_get_hash(key, ht->size, ++attempt);
        item = ht->items[index];
    }
    return (0);
}

void ht_delete(ht_hash_table *ht, const char *key) {
    int attempt = 0;
    int index = ht_get_hash(key, ht->size, attempt);
    ht_item *item = ht->items[index];
    while (item != 0) {
        if (item != &HT_DELETED_ITEM && strcmp(key, item->key) == 0) {
            ht_del_item(item);
            ht->items[index] = &HT_DELETED_ITEM;
        }
        index = ht_get_hash(key, ht->size, ++attempt);
        item = ht->items[index];
    }
    ht->count--;
}
