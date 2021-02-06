#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 1000

void save();
void ret();
void del();
void edit();

int main(){
    //edit();
    //save();
    //ret();


    del();
}


void edit(){
    FILE *fp; // creates a pointer to a file
    char filename[] = "file1.txt";
    fp = fopen(filename, "a"); 
    int n = 2;
    char str[1000];
    printf(" The lines are : \n");  
    for(int i = 0; i < n+1;i++)
    {
    fgets(str, sizeof str, stdin);
    fputs(str, fp);
  }
  fclose (fp);
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
        fgets(line, sizeof(line), fp);
        printf("%s", line); 
        

        //function to cross check 5th line with

    }
    fclose(fp);
}


void del(){


        FILE *fptr1, *fptr2;
    char file1[] ="file1.txt";
    char file2[] ="file2.txt";
    char curr;
    int del, line_number = 0;
    printf("Please enter the line number you want to delete : ");
    scanf("%d", &del);
    fptr1 = fopen(file1,"r");
    fptr2 = fopen(file2, "w");
    curr = getc(fptr1);
    if(curr!=EOF) {line_number =1;}
    while(1){
      if(del != line_number)
        putc(curr, fptr2);
        curr = getc(fptr1);
        if(curr =='\n') line_number++;
        if(curr == EOF) break;
    }
    fclose(fptr1);
    fclose(fptr2);

    remove("file1.txt");
    rename("file2.txt","file1.txt")
}

