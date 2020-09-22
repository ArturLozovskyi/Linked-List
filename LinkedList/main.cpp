#include <iostream>
#include "LinkedList.h"
//#include <gtest/gtest.h>



int main(int argc, const char * argv[])
{
        
    linked_list_type list = create_linked_list();
    
    append_to_linked_list(list, 5);
    append_to_linked_list(list, 6);
    append_to_linked_list(list, 7);
    append_to_linked_list(list, 5);
    append_to_linked_list(list, 6);
    append_to_linked_list(list, 7);
    
    linked_list_iterator begin = get_begin(list);
    
    int sum = 0;
    
    foreach_in_list(get_next(begin), get_end(list), [] (int* value, void* context) {
        *(int*)context += (*value);
        std::cout << *value << "\n";
    }, &sum);
    
    std::cout << sum << "\n";
    
    return 0;
}



