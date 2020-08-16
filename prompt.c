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
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error occurred.\n");
			break;
		}

        if (strncmp(input, "put", 3) == 0) {
            char *ptr;
            int val;
            val = (int) strtol(&input[3], &ptr, 10);
            ll_insert(&list, val);
            print_ll_list(&list);
        }

        if (strncmp(input, "list\n", 5) == 0) {
            print_ll_list(&list);
        }

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}

//		print_entry(input);
	}

	return EXIT_SUCCESS;
}
