
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
int show_score(void);


int main (void) {
    void homescreen(void);
    char command[10];
    if (scanf("%s", &command) == 1) {
        if (command == 'A') {

        }
        if (command == 'D') {

        }
        if (command == 'S') {
            
        }
    }


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


}

int homescreen(void) {
    printf("______________________________________\n");
    printf("WELCOME TO THE QUIZ GAME\n");
    printf("______________________________________\n");
    printf(" >Press A to add a question\n");
    printf("______________________________________\n\n");
    printf("______________________________________\n");
    printf(" >Press A to add a question\n");
    printf(" >Press D to delete a question\n");
    printf(" >Press S to start quiz");
    printf(" >Press Q to quit\n");
    printf("\n______________________________________\n");
    printf("______________________________________\n");
    return;
}


int show_score(void) {
    // traverse through linked list w questions and count 
        // Calculate Score;
        // ("Congrats, you got %d out of %d\n", correct, total)
        // track right answers;
        // after last question of quiz, show score
        // back to home screen; resets score

    // call the linked list with questions
    int a = correct_answers;
    int b = total_questions;
    printf("Congratulations! You scored %d out of %d\n", a, b);

    return 0;
}
    