
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 1000
#define DATA_SIZE 1000


int take_quiz(void);
void save();

struct question {

    char prompt[MAX_LEN];
    char opt_a[MAX_LEN];
    char opt_b[MAX_LEN];
    char opt_c[MAX_LEN];
    char opt_d[MAX_LEN];
    char answer[MAX_LEN];
    struct question *next;

};

//function declaration
void homescreen();

int main (void) {
    homescreen();
    sleep(5);
    save();
    sleep(1);
    take_quiz();

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
        //  

}

void homescreen() {
    printf("______________________________________\n");
    printf("WELCOME TO THE QUIZ GAME\n");
    printf("______________________________________\n");
    printf(" >Press M to make a quiz\n");
    printf("______________________________________\n\n");
    printf("______________________________________\n");
    printf("\n >Press T to take the quiz\n");
    printf(" >Press D to delete a question\n");
    printf(" >Press Q to quit\n");
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

        while (q_count < Q_LINES) {
            fgets(str, MAXCHAR, fp);
            printf("%s", str);
            q_count++;
        }
        printf("Enter ur answer: \n");
        char user_ans[MAXCHAR];
        scanf("%s", user_ans);
        char ans[MAXCHAR];
        fgets(ans, MAXCHAR, fp);
        strtok(ans,"\n");

        //function to convert both answers to same case. i.e both upper case or both lower case


        if (strcmp(ans,user_ans)==0) {
            printf("Correct\n");
        } else {
            printf("Incorrect correct answer was %s\n", ans);
            wrong_answers++;
        }
        sleep(3);
    c++;    

    }

    printf("\n Your score is %d/2",2-wrong_answers);



}


void save()
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


    /* Input contents from user to store in file */
    printf("Enter the first question: \n");
    
    int count = 0; 
    while(count < 2){

        fgets(data, DATA_SIZE, stdin);
        char question[DATA_SIZE] = {"Q."};
        //remove newline from fgets
        strtok(data,"\n");
        strcat(question,data);
        fputs(question, fPtr);
        fputs("\n",fPtr);



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
            fputs(option, fPtr);
            i++;
        }



        printf("Enter correct option: ");
        char ans[1];
        fgets(ans, DATA_SIZE, stdin);
        fputs(ans, fPtr);
        printf("Enter Next question: \n");
        count++;

    }
    /* Close file to save file data */
    fclose(fPtr);


    /* Success message */


}

