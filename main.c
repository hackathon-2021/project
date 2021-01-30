
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



int addQuestion();


int main (void){



    ///////// STRUCTURE  //////////////


    // Read text from user for question(s)

    // Read in 4 possible answers; 1 is the correct answer

    // EOF to end adding questions

    // Starts quiz
        // A, B, C, D to select answer.
        // Right answer: correct
        // Wrong answer: incorrect, show answer, next question, no second chance
        // try to randomise the answers

    //



}



