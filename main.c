
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_LEN 1000

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
int homescreen(void);


int main (void){



    ///////// STRUCTURE  //////////////

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

        // TRY to randomise the answers

    // Show score
        // number of questions = total score
        // Calculate Score;
        // track right answers;
        // after last question of quiz, show score
        // back to home screen; resets score


}


int homescreen(void) {
    printf("______________________________________\n\n");
    printf("WELCOME TO THE QUIZ GAME\n");
    printf("\n______________________________________\n");
    printf("\n >Press A to add a question\n");
    printf(" >Press D to delete a question\n");
    printf(" >Press D to delete a question\n");
    printf(" >Press S to add options");
    printf(" >Press R to reset\n");
    printf(" >Press Q to quit\n");
    printf("\n______________________________________\n");

}