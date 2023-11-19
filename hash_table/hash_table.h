typedef struct {
    char *key;
    char *value;
} ht_item;

typedef struct {
    int base_size;
    int size;
    int count;
    ht_item **items;
} ht_hash_table;

ht_hash_table *ht_new(void);
void ht_delete(ht_hash_table *ht);
void ht_insert(ht_hash_table *ht, const char *key, const char *value);
void ht_remove(ht_hash_table *ht, const char *key);
char *ht_search(ht_hash_table *ht, const char *key);

// it's important for HT_PRIME_* to be bigger than
// the number of ASCII symbols
#define HT_PRIME_1 151
#define HT_PRIME_2 163
#define HT_INITIAL_BASE_SIZE 53
