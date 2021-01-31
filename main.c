
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 1000
#define DATA_SIZE 1000


int take_quiz(void);
void edit();
void create_quiz();
void delete_question();



//function declaration
void homescreen();

int main (void) {
    create_quiz();
    take_quiz();
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
    sleep(5);

    int command;
    scanf("%d", &command);

    if (command == 1) {
        create_quiz(); // make quiz

    } else if (command == 2) {
        // add question;

    } else if (command == 3) {
        take_quiz();

    } else if (command == 4) {
        delete_question();
        // delete question;

    } else {
      printf("INVALID COMMAND\n");
    }

    sleep(1);

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
        //  -adding questions
        //  -delete questions?!
        // add a wait timer after each answer
        // add infinite questions when making 
        //function to convert both answers to same case. i.e both upper case or both lower case
        //  
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


}


#define MAXCHAR 1000
#define Q_LINES 5

// function should read line x 4
// scanf answer
// print correct or wrong
// go to next question

int take_quiz(void) {

    printf("---Welcome-to-your-Quiz---\n");
    int wrong_answers = 0;

    FILE *fp;
    char str[MAXCHAR];
    char* filename = "file1.txt"; // insert file name

    fp = fopen(filename, "r");
    if (fp == NULL) {

        printf("Could not open file %s", filename);
        return 1;
    }




    char line[256];
// start loop here
    int c = 0;
    while(c<2){

        int q_count = 0;
        char abcd[5] = {'A','B','C','D'};
        char dot[2] = ". ";

        fgets(str, MAXCHAR, fp);
        printf("\n%s",str);
        while (q_count < 4) {
            fgets(str, MAXCHAR, fp);
            printf("Option %c. %s",abcd[q_count], str);
            q_count++;
        }
        printf("Enter ur answer: \n");
        char user_ans[MAXCHAR];
        scanf("%s", user_ans);
        char ans[MAXCHAR];
        fgets(ans, MAXCHAR, fp);
        strtok(ans,"\n");



        if (strcmp(ans,user_ans)==0) {
            printf("Correct\n");
        } else {
            printf("Incorrect correct answer was %s\n", ans);
            wrong_answers++;
        }
        sleep(2);
    c++;

    }

    printf("\n Your score is %d/2",2-wrong_answers);


    return 0;
}

void edit(){
    FILE *fp; // creates a pointer to a file
    char filename[] = "file1.txt";
    fp = fopen(filename, "a"); 
    int n = 2;
    char str[1000];
    char data[DATA_SIZE];
    printf("Enter your question: \n");  
    fgets(str, sizeof str, stdin);
    fputs(str, fp);

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

  fclose(fp);
}


void create_quiz()
{
    /* Variable to store user content */
    char data[DATA_SIZE];

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
    char str1[20];
    fgets(str1,20,stdin);
    n = strtof(str1,NULL);
    int count = 0;
    /* Input contents from user to store in file */
    while(count < n){
        printf("---------------------------------\n");
        printf("Enter question: \n");
        fgets(data, DATA_SIZE, stdin);
        fputs(data, fPtr);

        char question[DATA_SIZE] = {"Q."};
        //remove newline from fgets
        strtok(data,"\n");
        strcat(question,data);
        fputs(question, fPtr);
        fputs("\n",fPtr);



        printf("Enter the 4 options : \n");

        int i = 0;
        while(i<4){
            char abcd[5] = {'A','B','C','D'};
            printf("Option %c: ", abcd[i]);
            fgets(data, DATA_SIZE, stdin);

            //char option[DATA_SIZE] = {abcd[i]};

            //remove newline from fgets

            //strcat(option,data);
            fputs(data, fPtr);
            i++;
        }



        printf("Enter correct option: ");
        char ans[1];
        fgets(ans, DATA_SIZE, stdin);
        fputs(ans, fPtr);
        count++;

    }
    /* Close file to save file data */
    fclose(fPtr);


    /* Success message */


}

void delete_question() {

    FILE *fileptr1, *fileptr2;
    char filename[40] = "file1.txt";
    char ch;
    int delete_line, temp = 1;


    //open file in read mode
    fileptr1 = fopen(filename, "r");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    //rewind
    int delete_q;
    int till_five = 0;

    rewind(fileptr1);
    // printf(" \n Enter line number of the line to be deleted:");
    printf(" \n Enter question number to be deleted:");
    scanf("%d", &delete_q);

    while (till_five < 5) {
        delete_line = (6 * delete_q) - till_five;

        //open new file in write mode
        fileptr2 = fopen("replica.txt", "w");
        ch = getc(fileptr1);

        while (ch != EOF) {

            ch = getc(fileptr1);
            if (ch == '\n'){
                temp++;
            }
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
        rename("replica.txt", filename);

        till_five++;
    }


    printf("\n The contents of file after being modified are as follows:\n");
    fileptr1 = fopen(filename, "r");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    fclose(fileptr1);



}
