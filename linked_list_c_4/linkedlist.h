#ifndef __CUSTOM_LINKED_LIST__
#define __CUSTOM_LINKED_LIST__

typedef struct LinkedListNode {
    struct LinkedListNode* previous;
    struct LinkedListNode* next;
    int value;
} LinkedListNode;

LinkedListNode* create_linked_list(int start_value);
LinkedListNode* add_node_linked_list(LinkedListNode* linked_list_start, int value);
int remove_node_at_index_linked_list(LinkedListNode* linked_list_start, int index);
void clean_linked_list(LinkedListNode* linked_list_start);
void print_linked_list(LinkedListNode* list);
LinkedListNode* get_node_at_index_linked_list(LinkedListNode* linked_list_start, int index);
LinkedListNode* add_node_after_index_linked_list(LinkedListNode* linked_list_start, int index, int value);
unsigned int get_length_linked_list(LinkedListNode* linked_list_start);
LinkedListNode* search_for_value_linked_list(LinkedListNode* linked_list_start, int value);
LinkedListNode* insert_node_at_begin_linked_list(LinkedListNode** linked_list_start, int value);
LinkedListNode* insert_node_at_end_linked_list(LinkedListNode* linked_list_start, int value);
#endif