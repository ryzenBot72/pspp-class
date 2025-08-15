#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct longword {
    char line[128];
    int llen;
    int max_word_length;
    char longest_word[32];
} lw;

void longest(lw a[], int i) {
    int m = 0, p;
    for (int j = 0; j <= i; j++) {
        if (a[j].max_word_length > m) {
            m = a[j].max_word_length;
            p = j;
        }
    }
    for (int k = 0; k < a[p].llen; k++) {
        printf("%c", a[p].line[k]);
    }
    printf("\n");
}

void findlongestword(lw a[], int i) {
    int c = 0;
    int word_start = 0;
    for (int j = 0; j <= i; j++) { 
        a[j].max_word_length = 0;
        int k = 0;
        while (k <= a[j].llen) {
            if (a[j].line[k] == ' ' || a[j].line[k] == '\0') {
                if (c > a[j].max_word_length) {
                    a[j].max_word_length = c;
                    strncpy(a[j].longest_word, &a[j].line[word_start], c);
                    a[j].longest_word[c] = '\0';  // Null-terminate the longest word
                }
                c = 0;
                word_start = k + 1;
            } else {
                c++;
            }
            k++;
        }
    }
    longest(a, i);
}

void readline(int fd, lw a[], char *p) {
    int i = 0, j = 0;
    while (read(fd, p, 1)) {
        if (*p == '\n') {
            a[i].llen = j;
            i++;
            j = 0;
        } else {
            a[i].line[j] = *p;
            j++;
        }
    }
    findlongestword(a, i - 1);
}

int main(int argc, char *argv[]) {
    lw a[32];
    char ch[1];
    char filename[256];
    int fd;
    scanf("%s" , filename);
	fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("CAN'T OPEN FILE\n");
        exit(1);
    }
    readline(fd, a, ch);
    close(fd);
    return 0;
}
