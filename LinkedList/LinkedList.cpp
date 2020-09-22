#include "LinkedList.h"
#include <iostream>
using linked_list_node = char*;
#define LINKED_LIST_INVALID_ITERATOR  nullptr

struct LinkedListNode
{
    LinkedListNode* next;
    int data;
};

struct LinkedList
{
    LinkedListNode* head;
    LinkedListNode* tail;
    int size;
};

namespace  {
    linked_list_node* get_list_head(linked_list_type list)
    {
        linked_list_node* head = (linked_list_node*)list;
        return head;
    }

    linked_list_node* get_list_tail(linked_list_type list)
    {
        linked_list_node* tail = (linked_list_node*)(list + sizeof(linked_list_node));
        return tail;
    }

    void increment_list_size (linked_list_type list)
    {
        uint32_t size = get_list_size(list);
        *(uint32_t*)(list + 2 * sizeof(linked_list_node)) = size + 1;
    }

    linked_list_node create_linked_list_node()
    {
        linked_list_node node = new char[sizeof(linked_list_node) + sizeof(int)];
        memset(node, 0, sizeof(linked_list_node) + sizeof(int));
        return node;
    }
}

uint32_t get_list_size(linked_list_type list)
{
    uint32_t size = *(uint32_t*)(list + 2*sizeof(linked_list_node));
    return size;
}

// head tail size
linked_list_type create_linked_list()
{
    linked_list_type list = new char[sizeof(linked_list_node) + sizeof(linked_list_node) + sizeof(uint32_t)];
    memset(list, 0, sizeof(linked_list_node) + sizeof(linked_list_node) + sizeof(uint32_t));
    return list;
}

int* append_to_linked_list(linked_list_type list, int value)
{
    linked_list_node node = create_linked_list_node();

    *(int*)(node + sizeof(linked_list_node)) = value;
    
//    std::cout << *(int*)(node + sizeof(linked_list_node)) << "\n";
    
//    std::cout << "Current node address: " << (int*)node << "\n";
    
    linked_list_node* head = get_list_head(list);
    linked_list_node* tail = get_list_tail(list);
    
//    printf("Tail: %p \n", *tail);
    
    if(get_list_size(list) == 0)
    {
        *head = node;
        *tail = node;
    }
    else
    {
        *(linked_list_node*)(*tail) = node;
        *tail = node;
    }
    increment_list_size(list);
    return (int*)(node + sizeof(linked_list_node));
}

linked_list_iterator get_begin(linked_list_type list)
{
    return *(get_list_head(list));
}

linked_list_iterator get_end(linked_list_type list)
{
    return LINKED_LIST_INVALID_ITERATOR;
}

int* get_it_value(linked_list_iterator it)
{
    return (int*)(it + sizeof(linked_list_node));
}

linked_list_iterator get_next(linked_list_iterator it)
{
    return *(linked_list_node*)(it);
}

void foreach_in_list(linked_list_iterator from, linked_list_iterator to, void (*func)(int*, void*), void* context)
{
    linked_list_iterator it;
    it = from;
    do {
        func(get_it_value(it), context);
        it = get_next(it);
    }
    while (it != to);
}
