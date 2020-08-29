#include <stdio.h>
#include <stdlib.h>
#include "colors.h"

int main() {
	int chr = 'a';
	int in_new_line = 1;
	int in_ast = 0;
	int ast_count = 0;
	int in_header = 0;
	int escaped = 0;
	while(1) {
		chr = getchar();
		if(chr == EOF) break;
		if(escaped) {
			putchar(chr);
			escaped = 0;
			continue;	
		}
		switch(chr){
			case '\n':
				if(in_header) printf(RESET);
				in_new_line = 1;
				putchar('\n');
				break;
			case '\\':
				escaped = 1;
				break;
			case '#':
				if(in_new_line) {
					in_header = 1;
					printf(HEADER);
				}
				putchar('#');
				break;
			case '*':
				if(ast_count == 0) {
					in_ast = 1;
					ast_count++;
					printf(ITALIC);
					break;
				}
				else if(ast_count == 1 && in_ast) {
					ast_count++;
					printf(RESET);
					printf(BOLD);
					break;
				}
				else if(ast_count == 1) {
					ast_count--;
					printf(RESET);
					break;
				}
				else if(ast_count == 2) {
					ast_count--;
					break;
				}
			case '[':
				printf(LINK);
				chr = getchar();
				while(chr != ']') {
					putchar(chr);
					chr = getchar();
				}
				printf(RESET);
				chr = getchar();
				while(chr != ')' && chr != ']') chr = getchar();
				break;
			case '`':
				printf(CODE);
				putchar('`');
				chr = getchar();
				int quotes_left = 1;
				if(chr == '`') quotes_left = 4;
				putchar(chr);
				while(quotes_left != 0) {
					if(chr == '`') quotes_left--;
					chr = getchar();
					putchar(chr);
				}
				printf(RESET);
				break;
			default:
				in_ast = 0;
				in_new_line = 0;
				putchar(chr);
				break;
		}
	}
}

