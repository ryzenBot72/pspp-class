#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct grade{
	float lower;
	float upper;
}grade;

typedef struct subject{
	char name[16];
	int credits;
	int semester;
	grade grades[7];
}subject;

typedef struct student{
	int misid;
	double marks[128];
	int num;
}student;

enum commands{GRADE, GRADES, CGPA, SGPA, FAILED, TOPSEM, TOPSUB, TOPNSUB, STDEV, EXIT, INVALID};

typedef struct result{
	int mis;
	char subname[16];
	int sem;
	int numst;
	enum commands type;
}result;

int fdreadline(int fd, char *s, int size) {
	int x;
	char *p = s;
	while(((s - p) < size - 1) && ((x = read(fd, s, 1)) == 1) && (*s != '\n'))
		s++;
	*s = '\0';
	if(x == 0)
		return -1;
	return (s - p);
}

int readSubjects(subject subjects[128]) { //function to read and store data in subjects.csv
	char line[128];
	int fd, i;
	char *token;
	fd = open("subjects.csv", O_RDONLY);
	i = 0;
	while(fdreadline(fd, line, 128) != -1) {
		token = strtok(line, ",\n");
		strcpy(subjects[i].name, token);
		token = strtok(NULL, ",\n");
		subjects[i].credits = atoi(token);
		token = strtok(NULL, ",\n");
		subjects[i].semester = atoi(token);
		i++;
	}
	close(fd);
	return i;
}

int readStudents(student students[], int nsub) {
	char line[128];
	int fd, i, j;
	char *token;
	fd = open("marks.csv", O_RDONLY);
	i = 0;
	while(fdreadline(fd, line, 128) != -1) {
		token = strtok(line, ",\n");
		students[i].misid = atoi(token); ///////////////////////////////CHANGE INT TO LONG FOR MISID///////////////////////////////////////////
		j = 0;
		while(*token != '\n' && j < nsub) {
			token = strtok(NULL, ",\n");
			students[i].marks[j] = atof(token);
			j++;
		}
		students[i].num = j;
		i++;
	}
	close(fd);
	return i;
}

void readGrades(subject subjects[], int nsub) {
	char line[128];
	int fd, i, j;
	char *token;
	fd = open("grades.csv", O_RDONLY);
	i = 0;
	while(fdreadline(fd, line, 128) != -1) {
		j = 0;
		token = strtok(line, ",\n");
		subjects[i].grades[j].lower = 0;
		subjects[i].grades[j].upper = atof(token);
		j++;
		while(*token != '\n' && j < 7) {
			token = strtok(NULL, ",\n");
			subjects[i].grades[j].lower = subjects[i].grades[j-1].upper + 0.01;
			subjects[i].grades[j].upper = atof(token);
			j++;
		}
		i++;
	}
	close(fd);
}

void exitnow(int n){
	exit(1);
}

result interprete(char cmd[], result results){
	char *token;
	token = strtok(cmd, " \n");
	if (token) {
		if(strcmp(token, "grade") == 0)
			results.type = GRADE;
		else if(strcmp(token, "grade") == 0)
			results.type = GRADES;
		else if(strcmp(token, "cgpa") == 0)
			results.type = CGPA;
		else if(strcmp(token, "sgpa") == 0)
			results.type = SGPA;
		else if(strcmp(token, "failed") == 0)
			results.type = FAILED;
		else if(strcmp(token, "topsem") == 0)
			results.type = TOPSEM;
		else if(strcmp(token, "topsub") == 0)
			results.type = TOPSUB;
		else if(strcmp(token, "topnsub") == 0)
			results.type = TOPNSUB;
		else if(strcmp(token, "stdev") == 0)
			results.type = STDEV;
		else if(strcmp(token, "exit") == 0)
			results.type = EXIT;
		else
			results.type = INVALID;
	}
	token = strtok(NULL, " \n");
	if (token) {
		if(results.type == GRADE){
			results.mis = atoi(token);
			if(strcmp(token,"all")){
				token = strtok(NULL, " \n");
				strcpy(results.subname, token);
			}
			else{
				results.type = GRADES;
			}
		}
		else if(results.type == CGPA)
			results.mis = atoi(token);
		else if(results.type == SGPA){
			results.mis = atoi(token);
			token = strtok(NULL, " \n");
			results.sem = atoi(token);
		}
		else if(results.type == FAILED)
			results.mis = atoi(token);
		else if(results.type == TOPSEM)
			results.sem = atoi(token);
		else if(results.type == TOPSUB)
			strcpy(results.subname, token);
		else if(results.type == TOPNSUB){
			strcpy(results.subname, token);
			token = strtok(NULL, " \n");
			results.numst = atoi(token);
		}
		else if(results.type == STDEV)
			strcpy(results.subname, token);
		else if(results.type == EXIT)
			exit(1);
		else{
			printf("INVALID DATA\n");
			exit(1);
		}
	}
	return results;
}

void calcGrade(double mrks, char *gra, int indexsub, subject subjects[]) {
	if (mrks >= subjects[indexsub].grades[0].lower && mrks <= subjects[indexsub].grades[0].upper)
	   strcpy(gra, "FF");
	else if (mrks >= subjects[indexsub].grades[1].lower && mrks <= subjects[indexsub].grades[1].upper)
	   strcpy(gra, "DD");
	else if (mrks >= subjects[indexsub].grades[2].lower && mrks <= subjects[indexsub].grades[2].upper)
	   strcpy(gra, "CD");
	else if (mrks >= subjects[indexsub].grades[3].lower && mrks <= subjects[indexsub].grades[3].upper)
	   strcpy(gra, "CC");
	else if (mrks >= subjects[indexsub].grades[4].lower && mrks <= subjects[indexsub].grades[4].upper)
	   strcpy(gra, "BC");
	else if (mrks >= subjects[indexsub].grades[5].lower && mrks <= subjects[indexsub].grades[5].upper)
	   strcpy(gra, "BB");
	else if (mrks >= subjects[indexsub].grades[6].lower && mrks <= subjects[indexsub].grades[6].upper)
	   strcpy(gra, "AB");
	else
	   strcpy(gra, "AA");
}

void printGrade(result results, subject subjects[], student students[], int nsub, int nstu) {
	int indexmis = -1, indexsub = -1;
	double mrks;
	char grads[2];
	for (int i = 0; i < nstu; i++) {
		if (students[i].misid == results.mis) {
			indexmis = i;
			break;
	   }
	}

	if (indexmis == -1){
		printf("Student data not found\n");
		return;
	}
	
	if(students[indexmis].num != nsub){
		printf("INSUFFICIENT DATA\n");
		return;
	}
	
	for (int i = 0; i < nsub; i++) {
	   if (strcmp(subjects[i].name, results.subname) == 0) {
		  indexsub = i;
		  break;
	   }
	}
	if (indexsub == -1){
		printf("Student data not found\n");
		return;
	}

	mrks = students[indexmis].marks[indexsub];
	calcGrade(mrks, grads, indexsub, subjects);
	printf("%s\n", grads);
}

void printGradsAll(result results, subject subjects[], student students[], int nsub, int nstu){
	double mrks;
	char grads[2];
	for(int i = 0; i < nstu ; i++){ //iterate over the Students struct
		if(students[i].num < nsub){
			printf("INSUFFICIENT DATA\n");
			return;
		}
		printf("%d" , students[i].misid);
		for(int j = 0; j < nsub; j++){ //iterate over the Marks Array
			mrks = students[i].marks[j];
			calcGrade(mrks, grads, j, subjects);
			printf(",%s" , grads);
		}
		printf("\n");
	}
}

double calcPts(char *gra){
	if((strcmp(gra,"AA") == 0))
		return 10;
	else if((strcmp(gra,"AB") == 0))
		return 9;
	else if((strcmp(gra,"BB") == 0))
		return 8;
	else if((strcmp(gra,"BC") == 0))
		return 7;
	else if((strcmp(gra,"CC") == 0))
		return 6;
	else if((strcmp(gra,"CD") == 0))
		return 5;
	else if((strcmp(gra,"DD") == 0))
		return 4;
	else
		return 0;
}

void printCGPA(result results, subject subjects[], student students[], int nsub, int nstu){
	int indexmis = -1;
	char grads[2];
	int pts;
	double mrks;
	double sumpts = 0, sumcred = 0;
	double cgpa;
	for (int i = 0; i < nstu; i++) {
		if (students[i].misid == results.mis) {
			indexmis = i;
			break;
	   }
	}
	if(indexmis == -1){
		printf("Student data not found\n");
		return;
	}
	if(students[indexmis].num < nsub){
		printf("INSUFFICIENT DATA\n");
		return;
	}
	for(int j = 0; j < nsub; j++){ //iterate to calculate sum of points according to grades of the student
		mrks = students[indexmis].marks[j];
		calcGrade(mrks, grads, j, subjects);
		pts = calcPts(grads);
		sumpts += ((subjects[j].credits) * pts);
		sumcred += subjects[j].credits;
	}
	cgpa = sumpts/sumcred;
	printf("%.2lf\n", cgpa);
}

void printSGPA(result results, subject subjects[], student students[], int nsub, int nstu){
	int indexmis = -1, count = 0;
	char grads[2];
	int pts;
	double mrks;
	double sumpts = 0, sumcred = 0;
	double sgpa;
	for (int i = 0; i < nstu; i++) {
		if (students[i].misid == results.mis) {
			indexmis = i;
			break;
	   }
	}
	if(indexmis == -1){
		printf("Student data not found\n");
		return;
	}
	if(students[indexmis].num < nsub){
		printf("INSUFFICIENT DATA\n");
		return;
	}
	for(int j = 0; j < nsub; j++){ //iterate to calculate sum of points according to grades of the student
		if(subjects[j].semester == results.sem){
			mrks = students[indexmis].marks[j];
			calcGrade(mrks, grads, j, subjects);
			pts = calcPts(grads);
			sumpts += ((subjects[j].credits) * pts);
			sumcred += subjects[j].credits;
			count++;
		}
	}
	if(count == 0){
		printf("INVALID SEMESTER\n");
		return;
	}	
	sgpa = sumpts/sumcred;
	printf("%.2lf\n", sgpa);
}

void printFailed(result results, subject subjects[], student students[], int nsub, int nstu){
	int indexmis = -1, count = 0;
	char grads[2];
	double mrks;
	for (int i = 0; i < nstu; i++) {
		if (students[i].misid == results.mis) {
			indexmis = i;
			break;
	   }
	}
	if(indexmis == -1){
		printf("Student data not found\n");
		return;
	}
	if(students[indexmis].num < nsub){
		printf("INSUFFICIENT DATA\n");
		return;
	}
	for(int j = 0; j < nsub; j++){ //iterate to get marks of each subject and calculate its grade
		mrks = students[indexmis].marks[j];
		calcGrade(mrks, grads, j, subjects);
		if(strcmp(grads,"FF") == 0 && count == 0){
			printf("%s" , subjects[j].name);
			count++;
		}
		if(strcmp(grads,"FF") == 0){
			printf(",%s" , subjects[j].name);
			count++;
		}
	}
	if(count == 0){
		printf("PASSED ALL SUBJECTS\n");
		return;
	}
	printf("\n");
}

void printTopSem(result results, subject subjects[], student students[], int nsub, int nstu){
	double max = 0;
	int studindex;
	for(int i = 0; i < nsub; i++){ //iterate over Subject struct
		if(subjects[i].semester == results.sem){
			for(int j = 0; j < nstu; j++){ //iterate over Student struct
				if(students[j].marks[i] > max){
					studindex = j;
					max = students[j].marks[i];
				}
			}
			printf("%d,%s\n" , students[studindex].misid, subjects[i].name);
		}
	}
}

void printTopSub(result results, subject subjects[], student students[], int nsub, int nstu){
	double max = 0;
	int studindex;
	for(int i = 0; i < nsub; i++){ //iterate over Subject struct
		if(strcmp(subjects[i].name, results.subname) == 0){
			for(int j = 0; j < nstu; j++){ //iterate over Student struct
				if(students[j].marks[i] > max){
					studindex = j;
					max = students[j].marks[i];
				}
			}
			printf("%d\n" , students[studindex].misid);
		}
	}
}

void printTopNSub(result results, subject subjects[], student students[], int nsub, int nstu){
	double max1 = 100, max2 = -1, maxtm;
	int studindex;
	int n = results.numst;
	for(int i = 0; i < nsub; i++){ 
		if(strcmp(subjects[i].name, results.subname) == 0){
			while(n > 0) {
				for(int j = 0; j < nstu; j++){ 
					if(students[j].marks[i] > max2 && students[j].marks[i] < max1){
						maxtm = max1;
						studindex = j;
						max1 = students[j].marks[i];
					}
				}
				if(max1 != maxtm){
					printf("%d\n", students[studindex].misid);
					n--;
					if(n == 0)
						return;
					max2 = max1; 
					max1 = 100; // reset max1 after printing
				}
			}
		}
	}
}

void printStDev(result results, subject subjects[], student students[], int nsub, int nstu){
	int indexsub = -1;
	double sum = 0, mean, stdev, term, variance;
	for(int i = 0; i < nsub; i++){ //find the subject name index
		if(strcmp(subjects[i].name, results.subname) == 0){
			indexsub = i;
			break;
		}
	}
	if(indexsub == -1){
		printf("SUBJECT NAME NOT FOUND\n");
		return;
	}
	for(int i = 0; i < nstu; i++){ //find the mean by iterating over students
		if(students[i].num < nsub){
			printf("INSUFFICIENT DATA\n");
			return;
		}
		sum += students[i].marks[indexsub]; //sum to calculate mean
	}
	mean = sum/nsub;
	for(int i = 0; i < nsub; i++){ //sum the squared terms
		term = students[i].marks[indexsub] - mean;
		sum += (term * term);
	}
	variance = sum/nstu;
	
	stdev = sqrt(variance);
	printf("%.2lf\n", stdev);
}

int main(){
	char cmd[1024];
	subject subjects[128];
	int nsubjects;
	student students[1024];
	int nstudents;
	result results;
	
	nsubjects = readSubjects(subjects);
	
	nstudents = readStudents(students, nsubjects);
	
	readGrades(subjects, nsubjects);
	
	while(1){
		printf(">");
		fgets(cmd, 1024, stdin);
		results = interprete(cmd, results);
		
		if(results.type == GRADE)
			printGrade(results, subjects, students, nsubjects, nstudents);
		else if(results.type == GRADES)
			printGradsAll(results, subjects, students, nsubjects, nstudents);
		else if(results.type == CGPA)
			printCGPA(results, subjects, students, nsubjects, nstudents);
		else if(results.type == SGPA)
			printSGPA(results, subjects, students, nsubjects, nstudents);
		else if(results.type == FAILED)
			printFailed(results, subjects, students, nsubjects, nstudents);
		else if(results.type == TOPSEM)
			printTopSem(results, subjects, students, nsubjects, nstudents);
		else if(results.type == TOPSUB)
			printTopSub(results, subjects, students, nsubjects, nstudents);
		else if(results.type == TOPNSUB)
			printTopNSub(results, subjects, students, nsubjects, nstudents);
		else if(results.type == STDEV)
			printStDev(results, subjects, students, nsubjects, nstudents);
		else if(results.type == EXIT)
			exit(1);
		else{
			printf("INVALID COMMAND\n");
			exit(1);
		}
	}
	return 0;
}