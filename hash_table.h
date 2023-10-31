typedef struct {
    char *key;
    char *value;
} ht_item;

typedef struct {
    int size;
    int count;
    ht_item **items;
} ht_hash_table;

ht_hash_table *ht_new(void);
void ht_del_hash_table(ht_hash_table *ht);

#define HT_PRIME_1 151
#define HT_PRIME_2 163
