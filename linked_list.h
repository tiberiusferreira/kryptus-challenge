//
// Created by Tiberio D A R Ferreira on 15/08/20.
//

#ifndef KRYPTUS_CHALLENGE_LINKED_LIST_H
#define KRYPTUS_CHALLENGE_LINKED_LIST_H

struct LLNode{
    int val;
    struct LLNode * next;
};

// Prefixes to avoid name conflict
void ll_insert(struct LLNode **linked_list, int val);
// index is zero indexed
struct LLNode* ll_get(struct LLNode **linked_list, unsigned int index);
struct LLNode*  ll_first(struct LLNode **linked_list);
struct LLNode*  ll_last(struct LLNode **linked_list);
void print_ll_list(struct LLNode **linked_list);
void ll_remove(struct LLNode **linked_list, unsigned int index);
void clear(struct LLNode **linked_list);
void ll_free(struct LLNode **linked_list); // need to do, but might not have time

#endif //KRYPTUS_CHALLENGE_LINKED_LIST_H
