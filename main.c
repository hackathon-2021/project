
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 100
#define DATA_SIZE 100


int take_quiz(void);
void edit();
void create_quiz();
void delete_question();



//function declaration
void homescreen();

int main (void) {
    /*homescreen();
    sleep(5);
    edit();
    sleep(1);
    take_quiz();
*/
    // Command 1; Create Quiz
    // Command 2; Add question
    // Command 3; Take Quiz
    // Command 4; Delete question

    homescreen();


    ///////// STRUCTURE //////////////

    // HOME SCREEN
    // press 1: add question
    // press 2: delete question
    // press 3: take quiz

    // press 1: add question
    // Read text from user for question(s)
    // Read in 4 possible answers; 1 is the correct answer;
    // Ask user for option A, option B etc.
    // Ask user for correct option
    // either continue adding or stop adding questions


    // press 3: take quiz
    // Starts quiz
        // A, B, C, D to select answer; scanf users option;
        // Right answer: correct; +1 to score counter
        // Wrong answer: incorrect, show answer, next question, no second chance
        // at the end of the quiz, call the show score function?

        // TRY to randomise the answers

    // Show score
        // number of questions = total score
        // traverse through linked list w questions and count
        // Calculate Score;
        // ("Congrats, you got %d out of %d\n", correct, total)
        // track right answers;
        // after last question of quiz, show score
        // back to home screen; resets score

        //TODO
        // if else cases for homescreen to go to function, so A calls add function.. etc
        // new functions to be added:
        //  -delete questions?!
        //function to convert both answers to same case. i.e both upper case or both lower case
        // add a wait timer after each answer
        // add infinite questions when making
        //function to convert both answers to same case. i.e both upper case or both lower case
        // change take quiz number of questions
        //
        //
        //

}

void homescreen() {
    printf("______________________________________\n");
    printf("WELCOME TO THE QUIZ GAME\n");
    printf("______________________________________\n");
    printf(" >Press 1 to make a quiz\n");
    printf(" >Press 2 to add a question\n");
    printf(" >Press 3 to take the quiz\n");
    printf(" >Press 4 to delete a question\n");
    // printf(" >Press Q to quit\n");
    printf("______________________________________\n");

    int command;
    char str1[1001];
    fgets(str1,1001,stdin);
    command = strtof(str1,NULL);

    if (command == 1) {
        create_quiz(); // make quiz

    } else if (command == 2) {
        edit();
    } else if (command == 3) {
        take_quiz();

    } else if (command == 4) {
        delete_question();
        // delete question;

    } else {
      printf("INVALID COMMAND\n");
    }

    sleep(1);

}


#define MAXCHAR 1000
#define Q_LINES 5

// function should read line x 4
// scanf answer
// print correct or wrong
// go to next question

int take_quiz(void) {

    printf("\n---Welcome-to-your-Quiz---\n");
    int wrong_answers = 0;

    FILE *fp;
    char str[MAXCHAR];
    char* filename = "file1.txt"; // insert file name

    fp = fopen(filename, "r");
    if (fp == NULL) {

        printf("Could not open file %s", filename);
        return 1;
    }

    //count2 how many lines to find number of questions
    
    char ce;
    int count = 0;
     for (ce = getc(fp); ce != EOF; ce = getc(fp)) 
        if (ce == '\n') // Increment count if this character is newline 
            count = count + 1; 

    printf("count is %d",count);
    fclose(fp);
    fp = fopen(filename, "r");
    
    count = count / 6;
    char line[256];
// start loop here
    int c = 0; 
    while(c < count){

        int q_count = 0;
        char abcd[5] = {'A','B','C','D'};
        char dot[2] = ". ";
        fgets(str, MAXCHAR, fp);
        printf("\n%s\n",str);
        while (q_count < 4) {
            fgets(str, MAXCHAR, fp);
            printf("Option %c. %s",abcd[q_count], str);
            q_count++;
        }
        printf("\nEnter ur answer: \n");
        char user_ans[MAXCHAR];
        fgets(user_ans,1001,stdin);
        char ans[MAXCHAR];
        fgets(ans, MAXCHAR, fp);

        if (strcmp(ans,user_ans)==0) {
            printf("Correct\n");
        } else {
            printf("Incorrect correct answer was %s\n", ans);
            wrong_answers++;
        }
        sleep(2);
        printf("\n------------------------------\n");
    c++;

    }

    printf("Quiz completed!!!\n");
    printf("\n Your score is %d/%d\n",count-wrong_answers,count);

    sleep(1);

    homescreen();
}

void edit(){
    FILE *fp; // creates a pointer to a file
    char filename[] = "file1.txt";
    fp = fopen(filename, "r"); 

     char ce;
    int count = 1;
     for (ce = getc(fp); ce != EOF; ce = getc(fp)){ 
        if (ce == '\n') // Increment count if this character is newline 
            count = count + 1; 
     }

    fclose(fp);









    FILE *fileptr1, *fileptr2;
    char ch;
    int delete_line, temp = 1;

    //open file in read mode
    fileptr1 = fopen(filename, "r");
    ch = getc(fileptr1);
   while (ch != EOF)
    {
        ch = getc(fileptr1);
    }
    //rewind
    rewind(fileptr1);
    delete_line = count;
    //open new file in write mode
    fileptr2 = fopen("replica.c", "w");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        ch = getc(fileptr1);
        if (ch == '\n')
            temp++;
            //except the line to be deleted
            if (temp != delete_line)
            {
                //copy all lines in file replica.c
                putc(ch, fileptr2);
            }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove(filename);
    //rename the file replica.c to original name
    rename("replica.c", filename);
    
















    fp = fopen(filename, "a");
    int n = 2;
    char str[1000];
    char data[DATA_SIZE];
    printf("\nEnter your question: \n");  
    fgets(str, sizeof str, stdin);
    char qq[MAXCHAR] = "\nQ.";
    strcat(qq,str);
    fputs(qq, fp);

    printf("Enter the 4 options : \n");

    char abcd[5] = {'A','B','C','D'};
    char dot[2] = ". ";
    int i = 0;
    while(i<4){

            printf("Option %c: ", abcd[i]);
            fgets(data, DATA_SIZE, stdin);

            char option[DATA_SIZE] = {abcd[i]};

            //remove newline from fgets

            strcat(option,data);
            fputs(option, fp);
            i++;

    }
    printf("Enter correct option: ");
    char ans[1];
    fgets(ans, DATA_SIZE, stdin);
    strtok(ans,"\n");
    fputs(ans, fp);
    fputs("\n",fp);

  fclose(fp);
  sleep(1);
  
    printf("Question added successfully !!!\n");
  homescreen();
}


void create_quiz()
{
    /* Variable to store user content */
    char data[100];

    /* File pointer to hold reference to our file */
    FILE * fPtr;


    /*
     * Open file in w (write) mode.
     * "data/file1.txt" is complete path to create file
     */
    fPtr = fopen("file1.txt", "w");


    /* fopen() return NULL if last operation was unsuccessful */
    if(fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }


    printf("How many questions would you like to add to your quiz? \n");
    int n;
    char str1[1001];
    fgets(str1,1001,stdin);
    n = strtof(str1,NULL);
    int count = 0;
    /* Input contents from user to store in file */
    while(count < n){
        printf("---------------------------------\n");
        printf("Enter question: \n");
        fgets(data, DATA_SIZE, stdin);

        char question[DATA_SIZE] = {"Q."};
        //remove newline from fgets
        strtok(data,"\n");
        strcat(question,data);
        fputs(question, fPtr);



        printf("Enter the 4 options : \n");

        int i = 0;
        while(i<4){
            char abcd[5] = {'A','B','C','D'};
            printf("Option %c: ", abcd[i]);
            fgets(data, DATA_SIZE, stdin);
            fputs("\n",fPtr);
            //char option[DATA_SIZE] = {abcd[i]};

            //remove newline from fgets
            strtok(data,"\n");
            //strcat(option,data);
            fputs(data, fPtr);
            i++;
        }



        printf("Enter correct option: ");
        char ans[1];
        fgets(ans, DATA_SIZE, stdin);
        fputs("\n",fPtr);

        fputs(ans, fPtr);
        count++;

    }
    /* Close file to save file data */
    fclose(fPtr);

    /* Success message */
    printf("Quiz successfully created!!!\n");
    homescreen();
}

void delete_question() {

    FILE *fileptr1, *fileptr2;
    char filename[40] = "file1.txt";
    char ch;
    int delete_line, temp = 1;

    //printf("Enter file name: ");
    //scanf("%s", filename);
    //open file in read mode
    fileptr1 = fopen(filename, "r");
    ch = getc(fileptr1);
        while (ch != EOF)
    {
        //printf("%c", ch);
        ch = getc(fileptr1);
    }
    //rewind
    rewind(fileptr1);
    /*printf(" \n Enter line number of the line to be deleted:");
    scanf("%d", &delete_line);*/

    // if Q2; lines
    //open new file in write mode
    int question_num;
    printf("Enter question to be deleted: \n");
    scanf("%d", &question_num);


    int lower_ignore = (7 * question_num) - 6;
    int upper_ignore = 7 * question_num;

    fileptr2 = fopen("replica.c", "w");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        ch = getc(fileptr1);
        if (ch == '\n')
            temp++;
            //except the line to be deleted
            if (temp < lower_ignore || temp > upper_ignore)
            {
                //copy all lines in file replica.c
                putc(ch, fileptr2);
            }
    }


    fclose(fileptr1);
    fclose(fileptr2);
    remove(filename);
    //rename the file replica.c to original name
    rename("replica.c", filename);
    // printf("\n The contents of file after being modified are as follows:\n");
    fileptr1 = fopen(filename, "r");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        ch = getc(fileptr1);
    }
    fclose(fileptr1);
    homescreen();

}
