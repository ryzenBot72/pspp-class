/*Write a C program which carries out the following:
Reads a file, and prints all palindrome words in the file. A word is considered to be separated only on whitespace. Each palindrome should be printed on a new line.*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct palin {
    char word[32];
    int len;
} palin;

int readword(int fd, palin a[], int i, char *t) {
    int j = 0, len = 0;
    char *s = t;
    int n = read(fd, s, 1);
    while (n && *s != ' ' && *s != '\n' && *s != '\t') {
        a[i].word[j] = *s;
        j++;
        len++;
        n = read(fd, s, 1);
    }
    a[i].len = len;
    if (len != 0)
        return 1;
    return 0;
}

int readfile(int fd, palin a[], int size) {
    int i = 0;
    char ch[1];
    while (readword(fd, a, i, ch)) {
        i++;
    }
    return i;
}

int palinornot(palin a[], int j) {
    int l = a[j].len;
    int n, c = 0;
    if (l % 2)
        n = (l / 2) + 1;
    else
        n = l / 2;
    for (int i = 0; i < n; i++) {
        if (tolower(a[j].word[i]) == tolower(a[j].word[l - i - 1]))
            c++;
    }
    if (c == n)
        return 1;
    else
        return 0;
}

int main() {
    int fd;
    char filename[64];
    palin a[32];

    scanf("%s", filename);
    
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("CAN'T OPEN FILE\n");
        exit(1);
    }

    int i = readfile(fd, a, 32);

    for (int j = 0; j < i; j++) {
        int r = palinornot(a, j);
        if (r == 1) {
            for (int k = 0; k < a[j].len; k++) {
                printf("%c", a[j].word[k]);
            }
            printf("\n");
        }
    }
    close(fd);
    return 0;
}
