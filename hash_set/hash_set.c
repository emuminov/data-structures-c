#include "../base.h"
#include "../prime/prime.h"
#include "hash_set.h"

local int d = -1;
local int *DELETED_ITEM = &d;

// FNV-1a hash
unsigned int hash(int n) {
	unsigned long hash = FNV_OFFSET;
	int i = 0;
	while (i <= 3) {
		hash ^= ((unsigned char *)&n)[i];
		hash *= FNV_PRIME;
		i++;
	}
	return (unsigned int) hash;
}

local hs_set *hs_new_sized(size_t base_size) {
	hs_set *set = malloc(sizeof(hs_set));
	if (!set) return (0);
	set->base_size = base_size;
	set->size = next_prime(base_size);
	set->length = 0;
	set->items = calloc(set->size, sizeof(int *));
	return set;
}

local int *hs_new_item(int value) {
	int *item = malloc(sizeof(value));
	if (!item) return (0);
	*item = value;
	return item;
}

hs_set *hs_new() {
	return hs_new_sized(HS_INITIAL_BASE_SIZE);
}

void hs_insert(int value, hs_set *hs) {
	int index = hash(value) % hs->size;
	int *curr_item = hs->items[index];
	if (curr_item && *curr_item == value)
		return;
	int attempt = 1;
	while (curr_item && (*curr_item != value || curr_item == DELETED_ITEM)) {
		index = (index + (attempt++ * hash(value) + 1)) % hs->size;
		curr_item = hs->items[index];
	}
	hs->items[index] = hs_new_item(value);
	if (!hs->items[index]) return ;
	hs->length++;
}

void hs_remove(int value, hs_set *hs) {
	int index = hash(value) % hs->size;
	int *curr_item = hs->items[index];
	if (!curr_item) return;
	if (*curr_item == value && curr_item != DELETED_ITEM) {
		free(hs->items[index]);
		hs->items[index] = DELETED_ITEM;
		hs->length--;
		return;
	}
	int attempt = 1;
	while (curr_item && (*curr_item != value || curr_item == DELETED_ITEM)) {
		index = (index + (attempt++ * hash(value) + 1)) % hs->size;
		curr_item = hs->items[index];
		if (curr_item && *curr_item == value && curr_item != DELETED_ITEM) {
			free(hs->items[index]);
			hs->items[index] = DELETED_ITEM;
			hs->length--;
			return;
		}
	}
}

void hs_delete(hs_set *hs) {
	int i = 0;
	while (i < hs->size) {
		if (hs->items[i] && hs->items[i] != DELETED_ITEM) free(hs->items[i]);
		i++;
	}
	free(hs->items);
	free(hs);
}

bool hs_has(int value, hs_set *hs) {
	int index = hash(value) % hs->size;
	int *curr_item = hs->items[index];
	if (!curr_item) return false;
	if (*curr_item == value || curr_item != DELETED_ITEM) return true;
	int attempt = 1;
	while (curr_item && (*curr_item != value || curr_item == DELETED_ITEM)) {
		index = (index + (attempt++ * hash(value) + 1)) % hs->size;
		curr_item = hs->items[index];
		if (curr_item && (*curr_item == value || curr_item != DELETED_ITEM)) return true;
	}
	return false;
}

void hs_print(hs_set *hs) {
	int i = 0;

	while (i <= hs->size) {
		if (hs->items[i] == DELETED_ITEM && i < hs->size) {
			printf("[%d]:\t\tDELETED", i);
		} else if (hs->items[i] && i < hs->size) {
			printf("[%d]:\t\t%d", i, *hs->items[i]);
		} else if (!hs->items[i] && i < hs->size) {
			printf("[%d]:\t\tNULL", i);
		}
		if (i != hs->size) {
			printf("\n");
		}
		i++;
	}
}
