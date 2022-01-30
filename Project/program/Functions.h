#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>

#define DATALEN 1024 //Data length
#define CLEN 17 //Command length
#define LONG_PATH "/Users/Okpaleke Chukwudi/Documents/sem1_project/database/"
#define PATH "database/"
#define STUDENT_DB "students.csv"
#define GRADE_DB "grades.csv"
#define SUBJECT_DB "subjects.csv"
#define RESULT_DB "results.csv"
#define randnum(min, max) \
            ((rand() % (int)(((max) + 1) - (min))) + (min))

/* ^^ these are the include guards */



/* Link list node */
struct Node
{
	char data[DATALEN];     //Data of the node
	struct Node* next;      //Address of the next node
};

/* Prototypes for the functions */
void push2Node(struct Node**, char*);
void printNode(struct Node*); // function to display the list
void node2File(char*, struct Node*);
void persistData(char*, struct Node*);

void deleteFile(char*);
const char* strtoupper(char*);
const char* getField(char*,int);
char* filedir(const char*);
const int fileExists(char*, int);
char* randstring(size_t,int);
int searchDB(char*,int,char*);
void createSubject(char*);
void printSubject();
void editSubject(char*,char*);
void deleteSubject(char*);
void createStudent(char*);
void printStudent();
void editStudent(char*,char*);
void deleteStudent(char*);
int getRowLength(char*);
char* getNameByID(const char*,char*);
char* getIDByName(const char*,char*);
int getRowIndex(char*,char*);
void printGrades();
void addGradeSubject(char*);
void addGradeStudent(char*);
void addStudentGrade(char*,char*,int);
void removeGradeRow(char*);
void removeGradeColumn(char*);
void reverseString(char*, int);
int intToStr(int, char*, int);
void ftoa(float, char*, int);
void calResult();
void mainMenu();
int go2Menu(char*);

#endif
