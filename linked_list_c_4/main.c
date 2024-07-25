#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#define panic(msg) fprintf(stderr, "panic on line %d: %s", __LINE__, msg);\
    exit(1);
int main(void) {
    LinkedListNode* mainlist = create_linked_list(-3);
    if (mainlist == NULL)
    {
        panic("Could not allocate memory for linked list\n");
    }
    for (int i = 0; i < 5; i++)
        add_node_linked_list(mainlist, i);
    insert_node_at_end_linked_list(mainlist, 5);
    print_linked_list(mainlist);
    clean_linked_list(mainlist);
    return 0;
}