//
// Created by Tiberio D A R Ferreira on 15/08/20.
//

#include "linked_list.h"
#include <stdlib.h>
#include "stdio.h"

void exit_on_invalid_list(struct LLNode **linked_list){
    if (linked_list == 0){
        printf("Can't insert into invalid list");
        exit(EXIT_FAILURE);
    }
}

struct LLNode * new_ll_node(int val){
    struct LLNode * node = malloc(sizeof(struct LLNode));
    node->next = 0;
    node->val = val;
    return node;
}

void ll_insert(struct LLNode **linked_list, int val){
    exit_on_invalid_list(linked_list);
    if (*linked_list == 0){
        *linked_list = new_ll_node(val);
    }else{
        struct LLNode * head = *linked_list;
        while (head->next != 0){
            head = head->next;
        }
        // head->next is null, which means head is the last valid node
        head->next = new_ll_node(val);
    }
}


void print_ll_list(struct LLNode **linked_list){
    exit_on_invalid_list(linked_list);
    struct LLNode* current = (*linked_list);
    while(current){
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// index is zero indexed
struct LLNode* ll_get(struct LLNode **linked_list, unsigned int index){
    exit_on_invalid_list(linked_list);
    struct LLNode * head = *linked_list;
    struct LLNode * current_node = head;
    for (unsigned int i = 0; ; i++){
        if (current_node == 0){
            return 0;
        }
        if (i == index){
            return current_node;
        }
        current_node = current_node->next;
    }
}

struct LLNode*  ll_first(struct LLNode **linked_list){
    exit_on_invalid_list(linked_list);
    // return first node
    return (*linked_list);
}

struct LLNode*  ll_last(struct LLNode **linked_list){
    exit_on_invalid_list(linked_list);
    struct LLNode* current = (*linked_list);
    // walk whole list, until there is "next"
    while(current->next){
        current = current->next;
    }
    return current;
}

void ll_remove(struct LLNode **linked_list, unsigned int index){
    exit_on_invalid_list(linked_list);
    struct LLNode* current = (*linked_list);
    if (index == 0){
        // remove the "root" node
        if (current){
            // root node exists
            struct LLNode * to_be_removed = current;
            (*linked_list) = current->next;
            free(to_be_removed);
            return;
        }else{
            // empty linked list
            printf("Tried removing non-existing node of index: %d", index);
        }
    }
    // index greater than 0
    for (unsigned int i = 0; ; i++){
        // get to the node right before the one to be removed, because we need to set his new "next"
        if (i == index-1){
            struct LLNode* to_be_deleted = current->next;
            if (to_be_deleted == 0){
                printf("Tried removing non-existing node of index: %d", index);
                return;
            }
            struct LLNode* node_after_to_be_deleted = to_be_deleted->next;
            if (node_after_to_be_deleted != 0){
                current->next = node_after_to_be_deleted;
            }else{
                current->next = 0;
            }
            free(to_be_deleted);
            break;
        }else{
            current = current->next;
        }
    }
}

void clear(struct LLNode **linked_list){
    // dont need to check, if list is already cleared this is basically a no-op
    *linked_list = 0; // replace with free of the whole linked list!
}


void insert_value_sorted(struct LLNode** sorted_ll, int new_val){
    // assumes non empty list, internal use
    struct LLNode * current = *sorted_ll; // the current node while walking the list
    struct LLNode * previous_node = 0;    // the previous node while walking the list

    while (current != 0){
        // find node which is bigger than the value we want to store, then
        // put value in a node just before that one
        if (current->val >= new_val){
            // insert new_val in a new node and put it right before current sorted_ll node
            struct LLNode * new_node = new_ll_node(new_val);
            new_node->next = current;
            if (previous_node != 0){
                previous_node->next = new_node;
            }else{
                // if previous node was 0, it means we are at the first node of the list
                *sorted_ll = new_node;
            }
            return;
        }
        previous_node = current;
        current = current->next;
    }
    // if we got here, it means the new_val is bigger than any other value in the list,
    // put it in the end of it
    previous_node->next = new_ll_node(new_val);
}

/*
 * No time, so we wont do it in place, too complicated.
 * So we return a copy of the linked list sorted, the returned value is a pointer
 * to the first Node of the list, or 0 (NULL) if the list is empty
*/
struct LLNode* ll_sort(struct LLNode **linked_list){
    if (*linked_list == 0){
        // empty list
        return 0;
    }
    struct LLNode * original_current_node = (*linked_list);
    struct LLNode * sorted_linked_list = new_ll_node(original_current_node->val);
    original_current_node = original_current_node->next;

    while (original_current_node != 0){
        // insert original_current_node val into sorted_linked_list
        insert_value_sorted(&sorted_linked_list, original_current_node->val);
        original_current_node = original_current_node->next;
    }

    return sorted_linked_list;
}

