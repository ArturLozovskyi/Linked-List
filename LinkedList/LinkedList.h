#pragma once

#include <stdint.h>
#include <string.h>

using linked_list_type = char*;
using linked_list_iterator = char*;

linked_list_type create_linked_list();
int* append_to_linked_list(linked_list_type list, int value);
uint32_t get_list_size(linked_list_type list);
linked_list_iterator get_begin(linked_list_type list);
linked_list_iterator get_end(linked_list_type list);
int* get_it_value(linked_list_iterator it);
linked_list_iterator get_next(linked_list_iterator it);
void foreach_in_list(linked_list_iterator from, linked_list_iterator to, void (*func)(int*, void* context), void* context);
