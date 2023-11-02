#include <stdlib.h> // TODO: replace with my own library functions
#include <string.h>
#include <math.h>

#include "base.h"
#include "hash_table.h"
#include "prime.h"

local ht_item HT_DELETED_ITEM = {0, 0};


local ht_hash_table *ht_new_sized(const int base_size) {
    ht_hash_table *ht = malloc(sizeof(ht_hash_table));
    ht->base_size = base_size;
    ht->size = next_prime(base_size);
    ht->count = 0;
    // TODO: add my own calloc implemention
    ht->items = calloc(ht->size, sizeof(ht_item*));
    return ht;
}

local void ht_resize(ht_hash_table *ht, int base_size) {
    if (ht->base_size < HT_INITIAL_BASE_SIZE) return;
    ht_hash_table *new_ht = ht_new_sized(base_size);
    int i = 0;
    while (i < ht->size) {
        ht_item *item = ht->items[i];
        if (item != 0 && item != &HT_DELETED_ITEM) {
            ht_insert(new_ht, item->key, item->value);
        }
    }
    ht->base_size = base_size;
    ht->count = new_ht->count;

    int tmp_size = ht->size;
    ht->size = new_ht->size;
    new_ht->size = tmp_size;
    
    ht_item **tmp_items = ht->items;
    ht->items = new_ht->items;
    new_ht->items = tmp_items;

    ht_del_hash_table(new_ht);
}

local void ht_resize_up(ht_hash_table *ht) {
    ht_resize(ht, ht->base_size * 2);
}

local void ht_resize_down(ht_hash_table *ht) {
    ht_resize(ht, ht->base_size / 2);
}

local ht_item *ht_new_item(const char *k, const char *v) {
    ht_item *i = malloc(sizeof(ht_item));
    i->key = strdup(k);
    i->value = strdup(v);
    return i;
}

ht_hash_table *ht_new() {
    return ht_new_sized(HT_INITIAL_BASE_SIZE);
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
    // doubling the size of the table if the table is 70% filled
    const int load = (ht->count * 100) / ht->size;
    if (load > 70) ht_resize_up(ht);

    ht_item *item = ht_new_item(key, value);
    int attempt = 0;
    int index = ht_get_hash(key, ht->size, attempt);
    ht_item *curr_item = ht->items[index];
    while (curr_item != 0 && curr_item != &HT_DELETED_ITEM) {
        if (strcmp(key, curr_item->key)) {
            ht_del_item(curr_item);
            ht->items[index] = item;
            return;
        }
        index = ht_get_hash(item->key, ht->size, ++attempt);
        curr_item = ht->items[index];
    }
    ht->items[index] = item;
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
    // cuttin the size in two if the table is 10% filled
    // AND if it was resized up at least once
    const int load = (ht->count * 100) / ht->size;
    if (load < 10) ht_resize_down(ht);

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
