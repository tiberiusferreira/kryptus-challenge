/*
 ============================================================================
 Name        : Prompt.c
 Author      :
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
void print_entry(char *entry) {
	printf("You entered: %s\n", entry);
}

int main() {
	char input[201];
	struct LLNode * list = 0; // empty list = null pointer
	while(1) {
	    // put, get, list, remove, clear, first e last.
	    // maybe this should be a switch case?
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error occurred.\n");
			break;
		}else if (strncmp(input, "put", 3) == 0) {
            char *ptr;
            int val;
            val = (int) strtol(&input[3], &ptr, 10);
            ll_insert(&list, val);
            print_ll_list(&list);
        }else if (strncmp(input, "list\n", 5) == 0) {
            print_ll_list(&list);
        }else if (strncmp(input, "get", 3) == 0) {
            char *ptr;
            int val;
            val = (int) strtol(&input[3], &ptr, 10);
            if (val <= 0){
                printf("Cant get element of negative or 0 index");
                exit(EXIT_FAILURE);
            }
            // need to subtract one because we read a value which is 1 indexed
            struct LLNode * node = ll_get(&list, val-1);
            printf("%d\n", node->val);
        } else if (strncmp(input, "first\n", 6) == 0) {
            struct LLNode * node = ll_first(&list);
            printf("%d\n", node->val);
        } else if (strncmp(input, "last\n", 5) == 0) {
            struct LLNode * node = ll_last(&list);
            printf("%d\n", node->val);
        }else if (strncmp(input, "remove", 6) == 0) {
            char *ptr;
            int val;
            val = (int) strtol(&input[6], &ptr, 10);
            if (val <= 0){
                printf("Cant remove element of negative or 0 index");
                exit(EXIT_FAILURE);
            }
            // need to subtract one because we read a value which is 1 indexed
            struct LLNode * to_be_removed = ll_get(&list, val-1);
            printf("%d\n", to_be_removed->val);
            ll_remove(&list, val-1);
            print_ll_list(&list);
        }else if (strncmp(input, "clear\n", 6) == 0) {
            clear(&list);
        }else if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		} else if (strncmp(input, "sort\n", 5) == 0){
		    // we are LEAKING memory here
		    // TODO FIX
		    list = ll_sort(&list);
		    print_ll_list(&list);
		} else{
		    printf("Invalid input\n");
		}
	}

	return EXIT_SUCCESS;
}
