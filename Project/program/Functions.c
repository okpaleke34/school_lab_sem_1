#include "Functions.h"

int go2Menu(char * newCommand){
    char cpycmd[CLEN];
    strcpy(cpycmd,newCommand);
    strtoupper(cpycmd);
    if(strcmp(cpycmd, "MAIN_MENU") == 0){
        mainMenu();
        return 1;
    }
    return 0;
}
void mainMenu(){
    srand(time(NULL));   // Initialization, should only be called once.
    char newCommand[CLEN],prevCommand[CLEN];
    int continueProgram = 1;

    while(continueProgram){
        printf("\nEnter a new command, or type help for list of commands: ");
        scanf("%[^\n]%*c",newCommand);
        strtoupper(newCommand);
        printf("\nNew Command: %s \n",newCommand);

        //run all the functions
        if(strcmp(newCommand, "HELP") == 0){
            printf("Here are the list of commands: \n");
            printf("%*s You can use this to go to program main menu\n",-CLEN, "MAIN_MENU");
            printf("%*s You can use this to quit the program\n",-CLEN, "QUIT_PROGRAM");
            printf("%*s You can use this to reset the program\n",-CLEN, "RESET_PROGRAM");
            printf("%*s You can use this to create new subject\n",-CLEN, "CREATE_SUBJECT");
            printf("%*s You can use this to create new student\n",-CLEN, "CREATE_STUDENT");
            printf("%*s You can use this to edit a subject\n",-CLEN, "EDIT_SUBJECT");
            printf("%*s You can use this to edit a student\n",-CLEN, "EDIT_STUDENT");
            printf("%*s You can use this to edit a grade\n",-CLEN, "EDIT_GRADE");
            printf("%*s You can use this to list a subject\n",-CLEN, "LIST_SUBJECT");
            printf("%*s You can use this to list a student\n",-CLEN, "LIST_STUDENT");
            printf("%*s You can use this to list a grade\n",-CLEN, "LIST_GRADE");
            printf("%*s You can use this to delete a subject\n",-CLEN, "DELETE_SUBJECT");
            printf("%*s You can use this to delete a student\n",-CLEN, "DELETE_STUDENT");
            printf("%*s You can use this to calculate \n",-CLEN, "CALCULATE_RESULT");
            printf("%*s You can use this to print the information about this program\n",-CLEN, "INFO");
        }
        //shut down the program
        if(strcmp(newCommand, "QUIT_PROGRAM") == 0){
            char quitDecision;
            //chance to use recursion
            while(quitDecision != 'N' && quitDecision != 'Y'){
                printf("Are you sure you want to quit this program? \nNote that when you quit the program you have to run it again to start.\n\nEnter Y to quit or N to continue with the program:");
                quitDecision = getchar();
                getchar();
                quitDecision = toupper(quitDecision);
                if(quitDecision == 'Y'){
                    continueProgram = 0;
                }
                else{
                    if(quitDecision != 'N'){
                        printf("%c is not a valid command\n",quitDecision);
                    }
                }
            }
        }
        if(strcmp(newCommand, "RESET_PROGRAM") == 0){
            char resetDecision;
            while(resetDecision != 'N' && resetDecision != 'Y'){
                printf("Are you sure you want to reset this program? \nNote that when you reset the program all your entered data will be wiped out.\n\nEnter Y to reset or N to continue with the program:");
                resetDecision = getchar();
                getchar();
                resetDecision = toupper(resetDecision);
                if(resetDecision == 'Y'){
                    deleteFile(STUDENT_DB);
                    deleteFile(SUBJECT_DB);
                    deleteFile(GRADE_DB);
                    deleteFile(RESULT_DB);
                    continueProgram = 0;
                }
                else{
                    if(resetDecision != 'N'){
                        printf("%c is not a valid command\n",resetDecision);
                    }
                }
            }
        }
        else if(strcmp(newCommand, "CREATE_SUBJECT") == 0){
            char subjectName[25];
            printf("\nEnter the name of the new subject: ");
            scanf("%[^\n]%*c",subjectName);
            go2Menu(subjectName);
            //search db to know if subject exist
            if(searchDB(SUBJECT_DB,2,subjectName) > 0)
            {
                printf("This subject already exist in the database, please enter new subject");
            }
            else{
                createSubject(subjectName);
            }
        }
        else if(strcmp(newCommand, "LIST_SUBJECT") == 0)
        {
            printSubject();
        }
        else if(strcmp(newCommand, "EDIT_SUBJECT") == 0){
            printSubject();

            char subjectID[11];
            char subjectName[25];
            printf("\nEnter the subject ID to edit: ");
            scanf("%[^\n]%*c",subjectID);
            go2Menu(subjectID);
            printf("\nEnter the new subject name: ");
            scanf("%[^\n]%*c",subjectName);
            go2Menu(subjectName);

            editSubject(subjectID,subjectName);
        }

        else if(strcmp(newCommand, "DELETE_SUBJECT") == 0){
            printSubject();
            char subjectID[11];
            printf("\nEnter the subject ID to delete: ");
            scanf("%[^\n]%*c",subjectID);
            go2Menu(subjectID);
            deleteSubject(subjectID);
        }
        else if(strcmp(newCommand, "LIST_GRADE") == 0)
        {
            printGrades();
        }
        else if(strcmp(newCommand, "EDIT_GRADE") == 0){
            printGrades();

            char studentID[11];
            char subjectID[11];
            char studentName[25];
            char subjectName[25];
            int grade = 0;
            int enterMore = 1;
            while(enterMore == 1){
                printf("\nEnter the student name: ");
                scanf("%[^\n]%*c",studentName);
                go2Menu(studentName);
                printf("\nEnter the subject name: ");
                scanf("%[^\n]%*c",subjectName);
                go2Menu(subjectName);
                printf("\nEnter the grade: ");
                scanf("%d%*c", &grade);
                int valid1 = 0, valid2 = 0;
                //validating the subject name
                if(searchDB(SUBJECT_DB,2,subjectName) > 0){
                    strcpy(subjectID,getIDByName(SUBJECT_DB, subjectName));
                    valid1 = 1;
                }
                else if(searchDB(SUBJECT_DB,2,strtoupper(subjectName)) > 0){
                    strcpy(subjectID,getIDByName(SUBJECT_DB, strtoupper(subjectName)));
                    valid1 = 1;
                }
                else{
                    printf("Subject name does not exist in database");
                }
                //validating the student name
                if(searchDB(STUDENT_DB,2,studentName) > 0){
                    strcpy(studentID,getIDByName(STUDENT_DB, studentName));
                    valid2 = 1;
                }
                else if(searchDB(STUDENT_DB,2,strtoupper(studentName)) > 0){
                    strcpy(studentID,getIDByName(STUDENT_DB, strtoupper(studentName)));
                    valid2 = 1;
                }
                else{
                    printf("Student name does not exist in database");
                }


                if(valid1 && valid2 ){
                    addStudentGrade(studentID,subjectID,grade);
                    printf("Do you want to enter another student? 1 for yes, 0 for No: ");
                    scanf("%d%*c", &enterMore);
                }

            }
        }
        else if(strcmp(newCommand, "CREATE_STUDENT") == 0){
            char studentName[25];
            printf("\nEnter the name of the new student: ");
            scanf("%[^\n]%*c",studentName);
            go2Menu(studentName);

            //search db to know if student exist
            if(searchDB(STUDENT_DB,2,studentName) > 0)
            {
                printf("This student already exist in the database, please enter new student");
            }
            else{
                createStudent(studentName);
            }
        }
        else if(strcmp(newCommand, "LIST_STUDENT") == 0)
        {
            printStudent();
        }
        else if(strcmp(newCommand, "EDIT_STUDENT") == 0){
            printStudent();

            char studentID[11];
            char studentName[25];
            printf("\nEnter the student ID to edit: ");
            scanf("%[^\n]%*c",studentID);
            go2Menu(studentID);
            printf("\nEnter the new student name: ");
            scanf("%[^\n]%*c",studentName);
            go2Menu(studentName);
            editStudent(studentID,studentName);
        }
        else if(strcmp(newCommand, "DELETE_STUDENT") == 0){
            printStudent();

            char studentID[11];
            printf("\nEnter the student ID to delete: ");
            scanf("%[^\n]%*c",studentID);
            go2Menu(studentID);
            deleteStudent(studentID);
        }
        else if(strcmp(newCommand, "INFO") == 0)
        {
            printf("\n\nYou have to create the student and subject first then, you can start working on their grades. Most of the Input \
                   \ncommand in the program are case sensitive, that is why whenever you are needed to enter the student id/name the \
                   \ntable will be printed so that it will be easy to copy, that is also applicable in subject id/name. After creating \
                   \nthe student and the subjects. Use the EDIT_GRADE command to insert grades for all the students in their respective \
                   \nsubjects.  After all the grades were entered, use the CALCULATE_RESULT command to calculate and print the student result. \
                   \nThe program was tested with 5 students and 5 subjects. If you increase the subjects it might not print well to the \
                   \nscreen but it will be saved in the results.csv file. There might be malfunction of the program if a lot of data \
                   \ngreater than 8000 characters are required to be stored. There should be a folder named 'database' in the root \
                   \ndir. of the project(Tested in Codeblocks). You can also PATH const in the top of the program to generate the \
                   \ndatabase files in your preferred location. \n\n");
        }

        else if(strcmp(newCommand, "CALCULATE_RESULT") == 0)
        {
            calResult();
            printf("\n\n\nThis result has been calculated and saved a copy in results.csv file");
        }
        else{
            printf("This command does not exist, please type HELP to see the list of all available commands.\n");
        }




        //store prevCommand
        strcpy(prevCommand,newCommand);
    }

}

//this deletes a file from the folder
void deleteFile(char *filename){
    if(fileExists(filename,0) == 0){
        printf("%s does not exist..\n",filename);
    }
    else{
        char *file_path = filedir(filename);
        if (remove(file_path) == 0)
          printf("%s deleted successfully..\n",filename);
        else
          printf("Unable to delete %s",filename);
    }
}

//covert lower case to uppercase
const char* strtoupper(char str[CLEN]) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }

    return str;
}

//get a field(cell) value in a comma separated data
const char* getField(char* str, int index){
    char* arrayOfString[30];
    char temp[1024];
    strcpy(temp,str);
    const char s[2] = ",";
    char *token;
    int count=0;
    /* get the first token */

    token = strtok(str, s);

    /* walk through other tokens*/
    while( token != NULL )
    {
        arrayOfString[count] = token;
        token = strtok(NULL, s);
        count++;
    }

    if(index > count){
        return NULL;
    }

    char* retVal = malloc(50);
    for(int i=0;i<count;i++)
    if(i + 1 == index)
        strcpy(retVal,arrayOfString[i]);

    strcpy(str,temp);
    retVal[ strcspn(retVal, "\r\n") ] = 0; //remove the break line at the last column
    return retVal;
}

//generate the full file path using the filname
char *filedir(const char *filename){
    char* file_path =  malloc(50);

    strcpy(file_path,PATH);
    strcat(file_path,filename);
    return file_path;
}

//check if a file exist, if the second argument is 1 then it will create a file if it does not exist
const int fileExists(char* filename, int create)
{
    FILE *file;

    char *file_path = filedir(filename);


    if((file = fopen(file_path,"r"))!=NULL)
    {
        fclose(file);
        return 1;//"exists";
    }
    else
    {
        if(create == 1){
            //create file if it does not exist
            if(strcmp(filename, "subjects.csv") == 0){
                file = fopen(file_path, "w");
                fprintf(file,"%s\n","id,subject_name,date_created");
                fclose(file);
                return 2;// File just created
            }
            else if(strcmp(filename, "grades.csv") == 0){

                file = fopen(file_path, "w");
                fprintf(file,"%s\n","student_id");
                fclose(file);

                return 2;// File just created
            }
            else if(strcmp(filename, "students.csv") == 0){

                file = fopen(file_path, "w");
                fprintf(file,"%s\n","id,fullname,date_created");
                fclose(file);

                return 2;// File just created
            }
            else if(strcmp(filename, "results.csv") == 0){

                file = fopen(file_path, "w");
                fprintf(file,"%s","");
                fclose(file);

                return 2;// File just created
            }
            else{
                printf(": %s: ",filename);
                return 3; // File type not found
            }

        }
        else{
            return 0; //file does not exist
        }
    }
}

//generate random string: small letters only, Capital letters only, Digits only, alpha-numerals and alpha-numerals with special letter
// length should be qualified as const if you follow a rigorous standard
char *randstring(size_t length, int type) {

    char charset[100];
    int charsetlen;
    switch(type){
        case 0:
            strcpy(charset,"abcdefghijklmnopqrstuvwxyz");
            charsetlen = 26;
            break;
        case 1:
            strcpy(charset,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
            charsetlen = 26;
        break;
        case 2:
            strcpy(charset,"0123456789");
            charsetlen = 10;
            break;
        case 3:
            strcpy(charset,"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
            charsetlen = 62;
            break;
        default:
            strcpy(charset,"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!");
            charsetlen = 69;
            break;
    }
    char *randomString;   // initializing to NULL isn't necessary as malloc() returns NULL if it couldn't allocate memory as requested

    if (length) {
        randomString = malloc(length +1); // I removed your `sizeof(char) * (length +1)` as sizeof(char) == 1, cf. C99

        if (randomString) {
            for (int n = 0;n < length;n++) {
                int key = rand() % charsetlen;//(int) (sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[length] = '\0';
        }
    }

    return randomString;
}


//search a partuclar column in a file to know if it exist, if it exist return the row ID where it exist or return 0
int searchDB(char* file,int index,char* keyword){

    int position = 0;
    int found = 0;

    char *file_path = filedir(file);

    int db_exist = fileExists(file,1);

    if(db_exist == 1 || db_exist == 2){

        FILE *file = fopen(file_path,"r");

        char line[1024];
        while (fgets(line, 1024, file))
        {
            char* tmp = strdup(line);
            if(strcmp(getField(tmp, index),keyword) == 0){
                found = position;
                break;
            }
            position++;
            free(tmp);
        }
        fclose(file);
    }
    return found;
}


//create new student by taking the student name then generate the random alpha-numeral as ID
void createSubject(char* subject_name)
{
    FILE *file;
    int db_exist = fileExists(SUBJECT_DB, 1);
    if(db_exist ==  1 || db_exist == 2){
        char subject_id[15];
        //generate an ID with random 6 alphabets and random 4 digits
        strcpy(subject_id,randstring(6,1));
        strcat(subject_id,randstring(4,2));
        //generate the current time
        time_t t;   // not a primitive datatype
        time(&t);

        char *file_path = filedir(SUBJECT_DB);

        file = fopen(file_path, "a");
        fprintf(file,"%s,%s,%s",subject_id,subject_name,ctime(&t));
        fclose(file);
        printf("Subject created successfully...\n");
        //after creating subject, enter the student in grades.csv file
        addGradeSubject(subject_id);
    }
    else{
        printf("\nERROR MSG: Failed to create file, there is probably a problem with the program, ERROR CODE:%d",db_exist);
    }
}


//print subjects.csv file
void printSubject(){
    char *file_path = filedir(SUBJECT_DB);
    int db_exist = fileExists(SUBJECT_DB,1);
    if(db_exist == 1 || db_exist == 2){
        FILE *file = fopen(file_path,"r");

        char line[1024];
        while (fgets(line, 1024, file))
        {

            char* tmp = strdup(line);
            char lines[1024];
            strcpy(lines,tmp);
            printf("%*s %*s %*s\n\n",-CLEN, getField(tmp, 1),-CLEN,getField(tmp, 2),-CLEN,getField(tmp, 3));
            free(tmp);
        }
        fclose(file);
    }
}

// update the subject name in the subject.csv file using the subject ID
void editSubject(char* subjectID,char* subjectName){
    char lines[1024];
    char *file_path = filedir(SUBJECT_DB);
    FILE *file = fopen(file_path,"r");
    char data[DATALEN];
    int update = 0;

    struct Node* dataList = NULL;

    while (fgets(lines, 1024, file))
    {
        strcpy(data,"");
        char* tmp = strdup(lines);
        strcpy(lines,tmp);
        // if the first column matches with the subject ID then update the name else repeat the other lines
        if(strcmp(getField(tmp, 1),subjectID) == 0){
            strcat(data,getField(tmp, 1));
            strcat(data,",");
            strcat(data,subjectName);
            strcat(data,",");
            strcat(data,getField(tmp, 3));
            strcat(data,"\n");
            push2Node(&dataList, data);
            update = 1;
        }
        else{
            push2Node(&dataList, lines);
        }
        free(tmp);
    }
    fclose(file);


    node2File(file_path,dataList);

    if(update == 1){
        printf("subject updated successfully....\n");
    }
    else{
        printf("Failed to update subject....\n");
    }
    //print subject after editing
    printSubject();
}


//delete a subject using the subject ID
void deleteSubject(char * subjectID){
    char lines[DATALEN];
    char *file_path = filedir(SUBJECT_DB);
    FILE *file = fopen(file_path,"r");
    int update = 0;
    struct Node* dataList = NULL;
    while (fgets(lines, DATALEN, file))
    {
        char* tmp = strdup(lines);
        strcpy(lines,tmp);
        //if the column matches with the subject ID skip the row
        if(strcmp(getField(tmp, 1),subjectID) == 0){
            update = 1;
            continue;
        }
        else{
            push2Node(&dataList, lines);
        }
        free(tmp);
    }
    fclose(file);
    //update file after deleting the subject
    node2File(file_path,dataList);

    if(update == 1){
        //delete subject column from grades.csv file
        removeGradeColumn(subjectID);
        printf("subject deleted successfully....\n");
    }
    else{
        printf("Failed to delete subject....\n");
    }
    // print subject after deleting data
    printSubject();
}

//create new student by taking the student name then generate the random alpha-numeral as ID
void createStudent(char* student_name)
{
    FILE *file;
    int db_exist = fileExists(STUDENT_DB, 1);
    if(db_exist ==  1 || db_exist == 2){
        char student_id[11];
        //generate an ID with random 6 alphabets and random 4 digits
        strcpy(student_id,randstring(6,1));
        strcat(student_id,randstring(4,2));
        //generate the current time
        time_t t;   // not a primitive datatype
        time(&t);

        char *file_path = filedir(STUDENT_DB);

        file = fopen(file_path, "a");
        fprintf(file,"%s,%s,%s",student_id,student_name,ctime(&t));
        fclose(file);
        printf("Student created successfully...\n");
        //after creating student, enter the student in grades.csv file
        addGradeStudent(student_id);
    }
    else{
        printf("ERROR MSG: Failed to create file, there is probably a problem with the program, ERROR CODE:%d",db_exist);
    }
}

//print the students.csv file data
void printStudent(){
    char *file_path = filedir(STUDENT_DB);
    int db_exist = fileExists(STUDENT_DB,1);
    if(db_exist == 1 || db_exist == 2){
        FILE *file = fopen(file_path,"r");

        char line[DATALEN];
        while (fgets(line, DATALEN, file))
        {

            char* tmp = strdup(line);
            char lines[DATALEN];
            strcpy(lines,tmp);
            printf("%*s %*s %*s\n\n",-CLEN, getField(tmp, 1),-CLEN,getField(tmp, 2),-CLEN,getField(tmp, 3));
            free(tmp);
        }
        fclose(file);
    }
}


// This function takes two parameter, student ID and the student name then update the student ID with the new name
void editStudent(char* studentID,char* studentName){
    char lines[DATALEN];
    char *file_path = filedir(STUDENT_DB);
    FILE *file = fopen(file_path,"r");
    char data[DATALEN];
    int update = 0;
    struct Node* dataList = NULL;
    while (fgets(lines, DATALEN, file))
    {
        strcpy(data,"");
        char* tmp = strdup(lines);
        strcpy(lines,tmp);
        //if the student id match the column, update it else copy the previous rows
        if(strcmp(getField(tmp, 1),studentID) == 0){
            strcat(data,getField(tmp, 1));
            strcat(data,",");
            strcat(data,studentName);
            strcat(data,",");
            strcat(data,getField(tmp, 3));
            strcat(data,"\n");
            push2Node(&dataList, data);
            update = 1;
        }
        else{
            push2Node(&dataList, lines);
        }
        free(tmp);
    }
    fclose(file);
    //update the students.csv file with the new data
    node2File(file_path,dataList);
    if(update == 1){
        printf("student updated successfully....\n");
    }
    else{
        printf("Failed to update student....\n");
    }
    //print the student after editing the student
    printStudent();
}

//delete a student from the students.csv file and also delete the the student row in grades,csv file
void deleteStudent(char * studentID){
    char lines[DATALEN];
    char *file_path = filedir(STUDENT_DB);
    FILE *file = fopen(file_path,"r");
    int update = 0;
    struct Node* dataList = NULL;
    while (fgets(lines, DATALEN, file))
    {
        char* tmp = strdup(lines);
        strcpy(lines,tmp);
        if(strcmp(getField(tmp, 1),studentID) == 0){
            update = 1;
            continue;
        }
        else{
            push2Node(&dataList, lines);
        }
        free(tmp);
    }
    fclose(file);
    //update students.csv file with the new data
    node2File(file_path,dataList);
    if(update == 1){
        // if the student row was removed, then remove the row too in grades.csv file
        removeGradeRow(studentID);
        printf("student deleted successfully....\n");
    }
    else{
        printf("Failed to delete student....\n");
    }
    //print the student file
    printStudent();
}

// get the count of the rows in a file
int getRowLength(char* filename){
    int count = 0;
    char line[DATALEN];
    char *file_path = filedir(filename);
    FILE *file = fopen(file_path,"r");
    while (fgets(line, DATALEN, file))
    {
        char* tmp = strdup(line);
        free(tmp);
        count++;
    }
    fclose(file);
    return count;
}

//This function returns the name of subject or student using the id cell
char* getNameByID(const char* filename,char* id){
    char lines[DATALEN];
    char *file_path = filedir(filename);
    FILE *file = fopen(file_path,"r");
    char* retVal = malloc(25);
    int found = 0;
    while (fgets(lines, DATALEN, file))
    {
        char* tmp = strdup(lines);
        if(strcmp(getField(tmp, 1),id) == 0){
            strcpy(retVal,getField(tmp, 2));
            found = 1;
            break;
        }
        free(tmp);
    }
    fclose(file);
    if(found == 1){
        return retVal;
    }
    else{
        return NULL;
    }
}

//This function returns the ID of subject or student using the name cell
char* getIDByName(const char* filename,char* name){
    char lines[DATALEN];
    char *file_path = filedir(filename);
    FILE *file = fopen(file_path,"r");
    char* retID = malloc(25);
    int found = 0;
    while (fgets(lines, DATALEN, file))
    {
        char* tmp = strdup(lines);
        if(strcmp(getField(tmp, 2),name) == 0){
            strcpy(retID,getField(tmp, 1));
            found = 1;
            break;
        }
        free(tmp);
    }
    fclose(file);
    if(found == 1){
        return retID;
    }
    else{
        return NULL;
    }
}

//get the column index of a row in a file
int getRowIndex(char* filename,char* keyword){
    int index = 0;
    char lines[DATALEN];
    char *file_path = filedir(filename);
    FILE *file = fopen(file_path,"r");
    char innerKeyword[25];
    strcpy(innerKeyword,keyword);
    while (fgets(lines, DATALEN, file))
    {
        char* tmp = strdup(lines);
        int i = 1;
        while(getField(tmp, i) != NULL){
            strcat(innerKeyword,"\n");
            //if the keyord or the keyword + "\n" is in the column break from the loop and return the column index
            if(strcmp(getField(tmp, i),keyword) == 0 || strcmp(getField(tmp, i),innerKeyword) == 0){
                index =  i;
                break;
            }
            strcpy(innerKeyword,keyword);
            i++;
        }
        free(tmp);
    }
    fclose(file);
    return index;
}


//print grades.csv file
void printGrades(){
    char *file_path = filedir(GRADE_DB);

    int db_exist = fileExists(GRADE_DB,1);


    if(db_exist == 1 || db_exist == 2){
        FILE *file = fopen(file_path,"r");

        char line[DATALEN];
        int rowLen =  getRowLength(SUBJECT_DB);// row length for the subject
        int row =  0;
        while (fgets(line, DATALEN, file))
        {
            char* tmp = strdup(line);
            char lines[DATALEN];
            strcpy(lines,tmp);
            for(int i =1; i <= rowLen; i++){
                if(getField(tmp, i) == NULL){
                    continue;
                }
                if(row == 0){
                    if(i != 1){
                        printf("%*s",-CLEN, getNameByID(SUBJECT_DB,getField(tmp, i)));
                    }
                    else{
                        printf("%*s",-CLEN, getField(tmp, i));
                    }
                }
                else{
                    if(i == 1){
                        printf("%*s",-CLEN, getNameByID(STUDENT_DB,getField(tmp, i)));
                    }
                    else{
                        printf("%*s",-CLEN, getField(tmp, i));
                    }
                }
            }
            printf("\n\n");
            row++;
            free(tmp);
        }
        fclose(file);
    }
}


//Add  a new subject to the grades.csv file by adding an extra column
// the head column will be the subject ID while the rest will be filled with '0'
void addGradeSubject(char * subjectID){
    int db_exist = fileExists(GRADE_DB, 1);
    char lines[DATALEN];

    if(db_exist ==  1 || db_exist == 2){
        char *file_path = filedir(GRADE_DB);
        FILE *file = fopen(file_path,"r");
        char data[DATALEN];
        int row = 0;
        struct Node* dataList = NULL;
        while (fgets(lines, 1024, file))
        {
            strcpy(data,"");
            char* tmp = strdup(lines);
            strcpy(lines,tmp);
            // if it is the first row add append the subject ID at the end
            if(row == 0){
                lines[ strcspn(lines, "\r\n") ] = 0;// this will remove the carriage return and end of line in this row
                strcat(lines,",");
                strcat(lines,subjectID);
                strcat(data,lines);
                strcat(data,"\n");
                push2Node(&dataList, data);
            }
            else{
                lines[ strcspn(lines, "\r\n") ] = 0;// this will remove the carriage return and end of line in this row
                strcat(lines,",0");
                strcat(data,lines);
                strcat(data,"\n");
                push2Node(&dataList, data);
            }
            row++;
            free(tmp);
        }
        fclose(file);
        //Save the data to the grades.csv
        node2File(file_path,dataList);
        printf("\nSubject added to grade successfully");
    }
    else{
        printf("ERROR MSG: Failed to create grade file, there is probably a problem with the program, ERROR CODE:%d",db_exist);
    }
}


//Add a new student to grades.csv file by adding the student id in the first column of the last row and the rest column will be '0'
void addGradeStudent(char * studentID){
    int db_exist = fileExists(GRADE_DB, 1);
    char lines[DATALEN];

    if(db_exist ==  1 || db_exist == 2){
        char *file_path = filedir(GRADE_DB);
        FILE *file = fopen(file_path,"r");
        char data[DATALEN];
        int row = 0;
        int count = 0;
        struct Node* dataList = NULL;
        //Recopy all the data to a variable
        while (fgets(lines, DATALEN, file))
        {
            char* tmp = strdup(lines);
            strcpy(lines,tmp);
            if(row == 0){
                while(getField(tmp,count) != NULL){
                    count++;
                }
            }
            push2Node(&dataList, lines);
            row++;
            free(tmp);
        }
        fclose(file);
        //Then add the student ID to the first column
        strcpy(data,"");
        strcat(data,studentID);
        //update the rest of the column with '0'
        for(int i = 0; i < count - 1; i++){
            if(i == count - 2){
                strcat(data,"\n");
                break;
            }
            strcat(data,",0");
        }
        push2Node(&dataList, data);
        //update the grades.csv file with the new data
        node2File(file_path,dataList);
        printf("Student added to grade successfully\n");
    }
    else{
        printf("ERROR MSG: Failed to create grade file, there is probably a problem with the program, ERROR CODE:%d",db_exist);
    }
}

//Add a student grade in a subject by updating the matching cell in grades.csv
void addStudentGrade(char * studentID,char * subjectID,int grade){
    char lines[DATALEN];
    char *file_path = filedir(GRADE_DB);
    FILE *file = fopen(file_path,"r");
    char data[DATALEN];

    int update = 0;
    struct Node* dataList = NULL;
    int SBJID = getRowIndex(GRADE_DB,subjectID); // get the column index of the subject

    int rowLen =  getRowLength(SUBJECT_DB);// row length for the subject
    while (fgets(lines, DATALEN, file))
    {
        char* tmp = strdup(lines);
        strcpy(lines,tmp);
        strcpy(data,"");
        //if the first column cell matches the student ID
        if(strcmp(getField(tmp, 1),studentID) == 0){
            for(int i =1; i <= rowLen; i++){
                if(getField(tmp, i) == NULL){
                    continue;
                }
                //if the subject column index matches with the current column index then update the data, else write the previous data
                if(SBJID == i){
                    char gradeStr[25];
                    itoa(grade, gradeStr, 10);
                    strcat(data,gradeStr);
                    if(rowLen == i){
                        strcat(data,"\n");
                        push2Node(&dataList, data);
                    }
                    else{
                        strcat(data,",");
                    }
                }
                else{
                    strcat(data,getField(tmp, i));
                    if(rowLen == i){
                        strcat(data,"\n");
                        push2Node(&dataList, data);
                    }
                    else{
                        strcat(data,",");
                    }
                }
            }

            update = 1;
        }
        else{
            for(int i =1; i <= rowLen; i++){
                if(getField(tmp, i) == NULL){
                    continue;
                }
                strcat(data,getField(tmp, i));
                if(rowLen == i){
                    strcat(data,"\n");
                    push2Node(&dataList, data);
                }
                else{
                    strcat(data,",");
                }
            }
        }
        free(tmp);
    }
    fclose(file);

    //update the grades.csv file by saving it
    node2File(file_path,dataList);
    if(update == 1){
        printf("subject updated successfully....\n");
    }
    else{
        printf("Failed to update subject....\n");
    }
    printGrades();
}



//This function removes a row(student) data from the grades.csv file
void removeGradeRow(char * studentID){
    char *file_path = filedir(GRADE_DB);
    FILE *file = fopen(file_path,"r");
    char lines[DATALEN];
    int update = 0;
    struct Node* dataList = NULL;
    while (fgets(lines, DATALEN, file))
    {
        char* tmp = strdup(lines);
        strcpy(lines,tmp);
        //if the data cell matched with the studentID passed through the function, skip the row
        if(strcmp(getField(tmp, 1),studentID) == 0){
            update = 1;
            continue;
        }
        else{
            push2Node(&dataList, lines);
        }
        free(tmp);
    }
    fclose(file);
    //save new data to the grades.csv
    node2File(file_path,dataList);
    if(update == 1){
        printf("student deleted from grade successfully....\n");
    }
    else{
        printf("Failed to delete student from grade....\n");
    }
}


//This function removes a specified column from the grade.csv file
void removeGradeColumn(char * subjectID){
    int colID = getRowIndex(GRADE_DB,subjectID);//get the row index of the subject id to remove
    char lines[DATALEN];
    char data[DATALEN];
    int update = 0;
    char *file_path = filedir(GRADE_DB);
    FILE *file = fopen(file_path,"r");
    struct Node* dataList = NULL;
    while (fgets(lines, DATALEN, file))
    {
        strcpy(data,"");
        char* tmp = strdup(lines);
        int i = 1;
        while(getField(tmp, i) != NULL){
            if(i != colID){
                strcat(data,getField(tmp, i));
                //do not put comma in the last
                // if the next is not null(if it is not the last column) and { [if the next two is null(the next is the last column) and the next is also the column id to be deleted] are all false }
                if(getField(tmp, i+1) != NULL ){ //&&  (getField(tmp, i+2) == NULL && i+ 1 == colID) == 0
                    if(getField(tmp, i+2) == NULL && i+ 1 == colID){
                        update = 1;
                    }
                    else{
                        strcat(data,",");
                    }
                }
            }
            else{
                update = 1;
            }
            i++;
        }
        strcat(data,"\n");
        push2Node(&dataList, data);
        free(tmp);
    }
    fclose(file);
    //save the new data to the file
    node2File(file_path,dataList);
    if(update == 1){
        printf("subject deleted from grade successfully....\n");
    }
    else{
        printf("Failed to delete subject from grade....\n");
    }
}


// Reverses a string 'str' of length 'len'
void reverseString(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Converts a given integer x to string str[].
// d is the number of digits required in the output.
// If d is more than the number of digits in x,
// then 0s are added at the beginning.
int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';

    reverseString(str, i);
    str[i] = '\0';
    return i;
}

// Converts a floating-point/double number to a string.
void ftoa(float n, char* res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0) {
        res[i] = '.'; // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter
        // is needed to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);

        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}

// This function calculates the result by adding two extra columns(total mark and average)
//the total is calculated by converting all the student grades to integer then  sum all of them
// the average is gotten by dividing the total of each student by the number of subjects
void calResult(){
    char *file_path = filedir(GRADE_DB);

    int db_exist = fileExists(GRADE_DB,1);


    char data[DATALEN];

    struct Node* dataList = NULL;
    if(db_exist == 1 || db_exist == 2){
        FILE *file = fopen(file_path,"r");

        char line[DATALEN];
        int rowLen =  getRowLength(SUBJECT_DB);// row length for the subject
        int row =  0;
        while (fgets(line, DATALEN, file))
        {
            strcpy(data,"");
            char* tmp = strdup(line);
            char lines[DATALEN];
            strcpy(lines,tmp);
            int total = 0;
            char cell[DATALEN];//variable to take the value of each cell
            float average;
            for(int i =1; i <= rowLen + 2; i++){
                if(getField(tmp, i - 2) == NULL){
                    continue;
                }
                // The first row is the heading
                if(row == 0){
                    if(i != 1){
                        if(i > rowLen){
                            if( i == rowLen +1){
                                strcpy(cell,"Total");
                                printf("%*s",-CLEN, cell);
                                strcat(data,cell);
                                strcat(data,",");
                            }
                            else if( i == rowLen +2){
                                strcpy(cell,"Average");
                                printf("%*s",-CLEN, cell);
                                strcat(data,cell);
                                strcat(data,"\n");
                                push2Node(&dataList, data);
                                strcpy(data,"");
                            }
                        }
                        else{
                            // use the subject id in the grade file to get the subject name from subjects.csv
                            strcpy(cell,getNameByID(SUBJECT_DB,getField(tmp, i)));
                            printf("%*s",-CLEN, cell);
                            strcat(data,cell);
                            strcat(data,",");
                        }
                    }
                    else{
                        strcpy(cell, getField(tmp, i));
                        printf("%*s",-CLEN, cell);
                        strcat(data,cell);
                        strcat(data,",");
                    }
                }
                else{
                    if(i == 1){
                        // use the student id in the grade file to get the student name from students.csv
                        strcpy(cell, getNameByID(STUDENT_DB,getField(tmp, i)));
                        printf("%*s",-CLEN, cell);
                        strcat(data,cell);
                        strcat(data,",");
                    }
                    else{

                        if(i > rowLen){
                            if( i == rowLen + 1){
                                printf("%*d",-CLEN, total);
                                char totalStr[25];
                                //converting int to string
                                itoa(total, totalStr, 10);
                                strcat(data,totalStr);
                                strcat(data,",");
                            }
                            else if( i == rowLen + 2){
                                average = total / ((rowLen - 1) * 1.0);
                                //converting float to string
                                char averageStr[25];
                                printf("%*.2f",-CLEN, average );
                                ftoa(average, averageStr, 2);
                                strcat(data,averageStr);
                                strcat(data,"\n");
                                push2Node(&dataList, data);
                            }
                        }
                        else{
                            strcpy(cell,getField(tmp, i));
                            total = atoi(cell) + total;
                            printf("%*s",-CLEN, cell);
                            strcat(data,cell);
                            strcat(data,",");
                        }
                    }
                }

            }
            printf("\n\n");
            row++;
            free(tmp);
        }
        fclose(file);

        //save file to results.csv file
        char *result_path = filedir(RESULT_DB);
        db_exist = fileExists(RESULT_DB,1);
        if(db_exist == 1 || db_exist == 2){
//            FILE *fileWrite = fopen(result_path, "w");
//            fprintf(fileWrite,"%s",data);
//            fclose(fileWrite);
            node2File(result_path,dataList);
        }
    }
}



// Node list functions

/* Function to reverse the linked list */
void printNode(struct Node* head)
{
	// Base case
	if (head == NULL)
	return;

	// print the list after head node
	printNode(head->next);

	// After everything else is printed, print head
	printf("%s \n", head->data);
}
void node2File(char file_path[],struct Node* dataList)
{
    //empty the file
    FILE *fileEdit = fopen(file_path, "w");
    fprintf(fileEdit,"%s","");
    fclose(fileEdit);
    //store data to file
    persistData(file_path,dataList);
}

/* Function to reverse the linked list */
void persistData(char file_path[],struct Node* head)
{
	// Base case
	if (head == NULL)
	return;

	// print the list after head node
	//printReverse(head->next);
	persistData(file_path, head->next);

	// After everything else is printed, print head
	//printf("%s \n", head->data);

    FILE *fileEdit = fopen(file_path, "a");
    fprintf(fileEdit,"%s",head->data);
    fclose(fileEdit);
}

/*UTILITY FUNCTIONS*/
/* Push a node to linked list. Note that this function
changes the head */
void push2Node(struct Node** head_ref, char new_data[DATALEN])
{
	/* allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	/* put in the data */
	strcpy(new_node->data,new_data);

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}
