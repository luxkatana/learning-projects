#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

LinkedListNode* create_linked_list(int start_value) {
    LinkedListNode* newnode = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    if (newnode == NULL) {
        return NULL;
    }
    newnode->value = start_value;
    return newnode;

}
void clean_linked_list(LinkedListNode* linked_list_start) {
    LinkedListNode* current = linked_list_start->next;
    while (current != NULL) {
        LinkedListNode* tmpbuffer = current->next;
        free(current);
        current = tmpbuffer;
    }
    free(linked_list_start); // to finalize

}
void print_linked_list(LinkedListNode* list) {
    LinkedListNode* current_node = list;
    while (current_node != NULL) {
        if (current_node->next == NULL)
            printf("%d", current_node->value);
        else
            printf("%d -> ", current_node->value);
        current_node = current_node->next;
    }
    puts(""); // adding a '\n' at the end
}

LinkedListNode* add_node_linked_list(LinkedListNode* linked_list_start, int value) {
    LinkedListNode* current_node = linked_list_start;
    while (current_node != NULL && current_node->next != NULL)
        current_node = current_node->next;
    LinkedListNode* new_node = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    if (new_node == NULL)
        return NULL;
    new_node->previous = current_node;
    new_node->value = value;
    current_node->next = new_node;
    return new_node;
}

int remove_node_at_index_linked_list(LinkedListNode* linked_List_start, int index) {
    if (index < 0)
        return -1;
    LinkedListNode* current_node = linked_List_start;
    int currently_at = 0;
    while (current_node != NULL) {
        if (currently_at == index) {
            current_node->previous->next = current_node->next;
            free(current_node);
            return index;
        }

        currently_at++;
        current_node = current_node->next;
    }
    return -1;
}
LinkedListNode* get_node_at_index_linked_list(LinkedListNode* linked_list_start, int index) {
    LinkedListNode* current_node = linked_list_start;
    int currently = 0;
    while (current_node != NULL) {
        if (currently == index)
            return current_node;
        currently++;
        current_node = current_node->next;
    }
    return NULL;
}

LinkedListNode* add_node_after_index_linked_list(LinkedListNode* linked_list_start, int index, int value) {
    LinkedListNode* node_before = get_node_at_index_linked_list(linked_list_start, index);
    if (node_before == NULL)
        return NULL;
    LinkedListNode* new_node = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    if (new_node == NULL)
        return NULL;
    new_node->value = value;
    if (node_before->next == NULL)
    {
        new_node->previous = node_before;
        node_before->next = new_node;
    }
    else { // next one is a Node
        LinkedListNode* next_node = node_before->next;
        next_node->previous = new_node;
        node_before->next = new_node;
        new_node->next = next_node;
    }
    return new_node;
}
unsigned int get_length_linked_list(LinkedListNode* linked_list_start) {
    unsigned int length = 0;
    LinkedListNode* current = linked_list_start;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}
LinkedListNode* search_for_value_linked_list(LinkedListNode* linked_list_start, int value) {
    LinkedListNode* currently = linked_list_start;
    while (currently != NULL && currently->value != value)
        currently = currently->next;
    return currently;

}
LinkedListNode* insert_node_at_begin_linked_list(LinkedListNode** linked_list_start, int value) {
    LinkedListNode* new_node = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    if (new_node == NULL)
        return NULL;
    (*linked_list_start)->previous = new_node;
    new_node->value = value;
    new_node->next = *linked_list_start;
    *linked_list_start = new_node;
    return new_node;
}
LinkedListNode* insert_node_at_end_linked_list(LinkedListNode* linked_list_start, int value) {
    LinkedListNode* current = linked_list_start;
    LinkedListNode* new_node = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    if (new_node == NULL)
        return NULL;
    new_node->value = value;

    while (current->next != NULL)
        current = current->next;

    new_node->previous = current;
    current->next = new_node;
    return new_node;
}