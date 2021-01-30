#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 1000

void save();
void ret();


int main(){
    save();
    ret();
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


#define MAXCHAR 1000

void ret(){
    FILE *fp;
    char str[MAXCHAR];
    char* filename = "file1.txt";
 
    fp = fopen(filename, "r");
    char line[256];

    if (fp == NULL){
        printf("Could not open file %s",filename);
    }
    while (fgets(line, sizeof(line), fp)) {
        /* note that fgets don't strip the terminating \n, checking its

           presence would allow to handle lines longer that sizeof(line) */
        printf("%s", line); 
        

        //function to cross check 5th line with

    }
    fclose(fp);
}

