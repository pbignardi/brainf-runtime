#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <parsers.h>
#include <converters.h>

#define REGSIZE 10

char * forward_find_bracket(char * p, char * end) {
    char * match = p;
    int l = 0;
    while (match <= end) {
        if (*match == '[') 
            l++;

        if (*match == ']') {
            l--;
            if (l == 0) 
                return match;
        }
        match++;
    }
    return NULL;
}

char * backward_find_bracket(char * p, char * start) {
    char * match = p;
    int l = 0;
    while (match >= start) {
        if (*match == '[' && l++) {
            // l++;
            if (l == 0) 
                return match;
        }

        if (*match == ']' && l--) {}

        match--;
    }
    return NULL;
}


void runtime(char * p) {
    // initialise registry
    int *reg = malloc(sizeof(int) * REGSIZE);
    int *regstart = reg;
    int *regend = reg + (REGSIZE - 1);

    // define program boundaries
    char *start = p;
    char *end = p + (strlen(p) - 1);

    while (p <= end) {
        if (*p == '>') {
            if (reg < regend) {
                reg++;
            } else {
                // should reallocate probably
                fprintf(stderr, "out of registry!\n");
                exit(1);
            }
        } else if (*p == '<') {
            if (reg > regstart) {
                reg--;
            } else {
                // should reallocate probably
                fprintf(stderr, "out of registry!\n");
                exit(1);
            }
        } else if (*p == '+') {
            (*reg)++;
        } else if (*p == '-') {
            (*reg)--;
        } else if (*p == '.') {
            putc(*reg, stdout);
        } else if (*p == ',') {
            *reg = getc(stdin);
        } else if (*p == '[') {
            if (*reg == 0) {
                // goto matching bracket
                p = forward_find_bracket(p, end);
                if (p == NULL) {
                    fprintf(stderr, "unbalanced loop brackets!\n");
                    exit(1);
                }
            }
        } else if (*p == ']') {
            if (*reg != 0) {
                // goto previous matching bracket
                p = backward_find_bracket(p, start);
                if (p == NULL) {
                    fprintf(stderr, "unbalanced loop brackets!\n");
                    exit(1);
                }
            }
        }
        p++;
    }
}


int main(int argc, char *argv[])
{
    // char *program = parse_bf(argv[1]);
    char *program = parse_ook(argv[1]);
    char *ook_program = ook_to_bf(program);
    runtime(ook_program);
    return EXIT_SUCCESS;
}
