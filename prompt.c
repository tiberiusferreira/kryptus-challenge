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

void print_entry(char *entry) {
	printf("You entered: %s\n", entry);
}

int main(int argc, char *argv[]) {
	char input[201];

	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error occurred.\n");
			break;
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}

		print_entry(input);
	}

	return EXIT_SUCCESS;
}
