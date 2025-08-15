/*Write a C program which carries out the following:
Reads a sequence of following structures from the standard input, until the end user presses Ctrl-D.
struct course { char name[32]; char course_id[16]; int credits; int type; char category[16];};
where type=1 is theory course, and type=2 is a lab course, and type=3 is a tutorial course.
and category can "PCC", "HSSC", "LC", "LLC", "OE", "DE".
Then the program prints (a) the sum of credits of all courses (b) the sum of credits for all lab courses (c) sum of credits for all theory courses, category wise.  */
#include <stdio.h>
#include <string.h>
#define THEORY 1
#define LAB 2
#define TUTORIAL 3
typedef struct course{
    char name[32];
    char course_id[16];
    int credits;
    int type;
    char category[16];
}course;

int sumth(course a[], int i){
    int c = 0;
    for(int j = 0;j <= i;j++){
        if(a[j].type == 1)
            c += a[j].credits;
    }
    return c;
}

int sumla(course a[], int i){
    int c = 0;
    for(int j = 0;j <= i;j++){
        if(a[j].type == 2)
            c += a[j].credits;
    }
    return c;
}

void sumtu(course a[], int i){
    int c = 0;
    for(int j = 0;j <= i;j++){
        if(a[j].type == 3)
            c += a[j].credits;
    }
}

void sumthcat(course a[], int i){
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;
    for(int j = 0;j <= i;j++){
            if(strcmp(a[j].category, "PCC") == 0)
                c1 += a[j].credits;
            else if(strcmp(a[j].category, "HSSC") == 0)
                c2 += a[j].credits;
            else if(strcmp(a[j].category, "LC") == 0)
                c3 += a[j].credits;
            else if(strcmp(a[j].category, "LLC") == 0)
                c4 += a[j].credits;
            else if(strcmp(a[j].category, "OE") == 0)
                c5 += a[j].credits;
            else if(strcmp(a[j].category, "DE") == 0)
                c6 += a[j].credits;
            else
                continue;
    }
    printf("PCC %d\n" , c1);
    printf("HSSC %d\n" , c2);
    printf("LC %d\n" , c3);
    printf("LLC %d\n" , c4);
    printf("OE %d\n" , c5);
    printf("DE %d\n" , c6);
}

int main(){
    course a[32];
    int i = 0, count = 0;
    while(scanf("%s %s %d %d %s" , a[i].name, a[i].course_id, &a[i].credits, &a[i].type, a[i].category) != EOF)
        i++;
    for(int j = 0;j < i;j++){
        count += a[j].credits;
    }
    int l = sumla(a, i-1);
    sumtu(a, i-1);
    
    printf("%d\n" , count);
    printf("%d\n" , l);
    
    sumthcat(a, i-1);
    return 0;
}
