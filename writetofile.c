#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LARGEINT 1000
#define NEWLINE 1

int copyFileContents(char *, char *);

int main(int argc, char ** argv)
{
    char openFile[LARGEINT];
    char destinationFile[LARGEINT]; 
    int avgLength;

    if(argc > 1)
    {
        strcpy(openFile, argv[1]);
        strcpy(destinationFile, argv[2]);
        
        if(openFile != NULL && destinationFile != NULL)
        {
            avgLength = copyFileContents(openFile, destinationFile);
            printf("The average line length is %d.\n", avgLength);
        }
    }
    else
    {
        printf("Error: File not found\n");
    }
    return 0;
}

int copyFileContents(char * openFile, char * destinationFile)
{
    FILE *fpOR = fopen(openFile, "r");
    FILE *fpDS = fopen(destinationFile, "w+");
    
    char text[LARGEINT];
    int stringLength;
    int avgLength = 0;
    int i = 1;

    if(fpOR != NULL)
    {
        while(fgets(text, LARGEINT, fpOR))
        {   
            stringLength = (int) strlen(text) - NEWLINE;
            avgLength = avgLength + stringLength;
            fprintf(fpDS, "%d ", stringLength);
            fputs (text, fpDS);
            i++;
        }
        avgLength = avgLength/i;
    }
    else
    {
        printf("Error: File not found\n");
    }
    fclose(fpDS);
    fclose(fpOR);
    return avgLength;
}
