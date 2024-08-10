#include "string.h"
#include "stdlib.h"
#include "stdio.h"

/* 
 * convert_to_bf: convert text from ook to brainf**k code.
 *
 * char * content: valid Ook code
 */
char * ook_to_bf(char * content) {

    // keep only buf as relevant
    char valid[] = ".!?";

    // measure length of content parsed (by counting valids)
    int ci = 0;
    int length = 0;
    while (ci < strlen(content)) {
        for (int v = 0; v < 3; v++) {
            if (valid[v] == content[ci]) {
                length++;
            }
        }
        ci++;
    }

    char parsed[length];
    ci = 0;
    int cj = 0;
    while (ci < strlen(content)) {
        for (int v = 0; v < 3; v++) {
            if (valid[v] == content[ci]) {
                parsed[cj] = content[ci];
                cj++;
            }
        }
        ci++;
    }

    // construct the bf code
    int buf_length = (int) (length / 2) + 1;
    char *buf = malloc(sizeof(char) * buf_length);

    ci = 0;
    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) 
            continue;

        char ft = parsed[i-1];
        char st = parsed[i];

        switch (ft) {
            case '.':
                switch (st) {
                    case '.':
                        buf[ci++] = '+';
                        break;
                    case '!':
                        buf[ci++] = ',';
                        break;
                    case '?':
                        buf[ci++] = '>';
                        break;
                }
                break;
            case '?':
                switch (st) {
                    case '.':
                        buf[ci++] = '<';
                        break;
                    case '!':
                        buf[ci++] = ']';
                        break;
                }
                break;
            case '!':
                switch (st) {
                    case '.':
                        buf[ci++] = '.';
                        break;
                    case '!':
                        buf[ci++] = '-';
                        break;
                    case '?':
                        buf[ci++] = '[';
                        break;
                }
                break;
        }
    }
    buf[ci] = '\0';

    return buf;
}
