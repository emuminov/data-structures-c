#include <stddef.h>

typedef struct {
    void *next;
    void *prev;
    void *value;
} ls_node;

typedef struct {
    ls_node *head;
    ls_node *tail;
    size_t length;
} ls_list;

