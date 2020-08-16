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
