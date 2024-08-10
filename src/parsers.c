#include "stddef.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define INCREMENTSIZE 20

/* 
 * parse_bf: read file content and parse its input,
 * keeping only valid brainf**k code
 *
 * char * filename: string to filename to read 
 */
char * parse_bf(char *filename){

    // exit if no file is provided
    if (filename == NULL) {
        fprintf(stderr, "no file provided\n");
        exit(1);
    }

    // allocate space for input file content
    char *buf = (char*) malloc(sizeof(char) * INCREMENTSIZE);
    if (buf == NULL) {
        fprintf(stderr, "out of memory\n"); exit(1);
    }

    // read file
    FILE *input = fopen(filename, "r");
    if (input == NULL) {
        fprintf(stderr, "file does not exist!\n");
        exit(1);
    }
    char ch;
    int ci = 0;
    int stringsize = INCREMENTSIZE;

    do {
        ch = fgetc(input);
        if (ci > stringsize) {
            stringsize += INCREMENTSIZE;
            buf = realloc(buf, sizeof(char) * stringsize);
            if (buf == NULL) {
                fprintf(stderr, "out of memory\n");
                exit(1);
            }
        }
        
        // characters validation
        char valid[] = "><+-.,[]";
        int num_valid_chars = 8;
        for (int id = 0; id < num_valid_chars; id++){
            if (ch == valid[id]) {
                buf[ci++] = ch;
            }
        }

    } while (ch != EOF);
    buf[ci] = '\0';
    return buf;
}


/* 
 * parse_ook: read file content. Expect only Ook* instructions.
 * Check that instructions are in even number.
 *
 * char * filename: string to filename to read 
 */
char * parse_ook(char *filename) {

    // exit if no file is provided
    if (filename == NULL) {
        fprintf(stderr, "no file provided\n");
        exit(1);
    }

    // allocate space for input file content
    char *buf = (char*) malloc(sizeof(char) * 4 * INCREMENTSIZE);
    if (buf == NULL) {
        fprintf(stderr, "out of memory\n"); exit(1);
    }

    // read file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "file does not exist!\n");
        exit(1);
    }

    char ch;
    int ci = 0;
    int stringsize = 0;
    int token_count = 0;

    do {
        // read token with whitespace
        ch = fgetc(file);
        if (ci > stringsize) {
            stringsize += INCREMENTSIZE;
            buf = realloc(buf, sizeof(char) * stringsize);
            if (buf == NULL) {
                fprintf(stderr, "out of memory\n");
                exit(1);
            }
        }
        
        // characters validation
        char valid[] = "Ook.?!";
        int num_valid_chars = 6;
        for (int id = 0; id < num_valid_chars; id++){
            if (ch == valid[id]) {
                buf[ci++] = ch;
                if (id > 2) {
                    token_count++;
                }
            }
        }

    } while (ch != EOF);
    
    if (token_count % 2 != 0) {
        fprintf(stderr, "syntax error: un-even number of tokens!\n");
        exit(1);
    }

    buf[ci] = '\0';
    return buf;
}

/* 
 * parse_blub: read file content. Expect only Ook* instructions.
 * Check that instructions are in even number.
 *
 * char * filename: string to filename to read 
 */
char * parse_blub(char *filename) {

    // exit if no file is provided
    if (filename == NULL) {
        fprintf(stderr, "no file provided\n");
        exit(1);
    }

    // allocate space for input file content
    char *buf = (char*) malloc(sizeof(char) * 4 * INCREMENTSIZE);
    if (buf == NULL) {
        fprintf(stderr, "out of memory\n"); exit(1);
    }

    // read file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "file does not exist!\n");
        exit(1);
    }

    char ch;
    int ci = 0;
    int stringsize = 0;
    int token_count = 0;

    do {
        // read token with whitespace
        ch = fgetc(file);
        if (ci > stringsize) {
            stringsize += INCREMENTSIZE;
            buf = realloc(buf, sizeof(char) * stringsize);
            if (buf == NULL) {
                fprintf(stderr, "out of memory\n");
                exit(1);
            }
        }
        
        // characters validation
        char valid[] = "Blub.?!";
        int num_valid_chars = 7;
        for (int id = 0; id < num_valid_chars; id++){
            if (ch == valid[id]) {
                buf[ci++] = ch;
                if (id > 3) {
                    token_count++;
                }
            }
        }

    } while (ch != EOF);
    
    if (token_count % 2 != 0) {
        fprintf(stderr, "syntax error: un-even number of tokens!\n");
        exit(1);
    }

    buf[ci] = '\0';
    return buf;
}
