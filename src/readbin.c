/*Given that

A file contains the data in this order

<n> : number of records in the file
<sequence of n records>

Each record in the file is of the following type:

#include <time.h>
typedef struct transaction{
	double amount;
	time_t time;	
	unsigned int from_id;
	unsigned int to_id;
	char location[32];	
}transaction;
Write a program that reads the file (three examples of such files attached),  and then prints the location and human-readable time of the transaction with the lowest amount.   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

typedef struct transaction {
    double amount;
    time_t time;
    unsigned int from_id;
    unsigned int to_id;
    char location[32];
    int len;
} transaction;

void findlow(int i, transaction a[]) {
    double min = a[0].amount;
    int j = 0;
    while(i > 0){
        if(a[i].amount < min){
            min = a[i].amount;
            j = i;
        }
        i--;
    }

    struct tm *tm_info;
    char time_str[20];
    
    tm_info = gmtime(&a[j].time);
    strftime(time_str, sizeof(time_str), "%d:%m:%Y %H:%M:%S", tm_info);
    
    printf("Location: %s\n", a[j].location);
    printf("Time: %s\n", time_str);
}

int readline(int fd, char *line, int size) {
    char c;
    int j = 0;
    while (read(fd, &c, 1) > 0) {
        if (c == '\n') {
            break;
        }
        line[j] = c;
        j++;
        if (j >= size - 1) {
            break;
        }
    }
    line[j] = '\0';
    return j;
}

void readtoken(char *line, int i, transaction a[]) {
    char *token;
    token = strtok(line, " ");
    a[i].amount = atof(token);

    token = strtok(NULL, " ");
    a[i].time = atol(token);

    token = strtok(NULL, " ");
    a[i].from_id = strtoul(token, NULL, 10);

    token = strtok(NULL, " ");
    a[i].to_id = strtoul(token, NULL, 10);

    token = strtok(NULL, "\n");
    strcpy(a[i].location, token);
}

void readfile(char *filename) {
    char line[128], c;
    int n = 0, i = 0, len;
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Can't open file\n");
        exit(1);
    }
    if (read(fd, &c, 1) > 0) {
        while (c != '\n') {
            n = (n * 10) + ((int)c - 48);
            read(fd, &c, 1);
        }
    }
    transaction a[n];
    while ((len = readline(fd, line, 128)) > 0) {
        readtoken(line, i, a);
        i++;
    }
    
    findlow(i - 1, a);
    close(fd);
}

int main() {
    char filename[64];
    scanf("%s", filename);
    readfile(filename);
    return 0;
}
