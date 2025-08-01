#include <stdio.h>
#define NUM_NAMES 3
#define FILENAME "names.txt"

int main(){
    char names[NUM_NAMES][100];
    FILE *fileptr;

    //get names from user
    for (int i = 0; i < NUM_NAMES; i++){
        printf("Name %d: ", i + 1);
        scanf("%s", &names[i]);
    }
    //write to file
    printf("Writing to file...\n");

    fileptr = fopen(FILENAME,"w");
    if (fileptr ==NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int i = 0; i < NUM_NAMES; i++){
        fprintf(fileptr,"%s\n",  names[i]);
    }

    //close the file
    fclose(fileptr);
    printf("File written and closed\n");

    //read from file
    char printed_names[NUM_NAMES][100];
    fileptr = fopen(FILENAME, "r");
    if (fileptr == NULL) {
            printf("Error opening file for reading. \n");
            return 1;
    }

    for (int i = 0; i < NUM_NAMES; i++){
        fscanf(fileptr, "%s", printed_names[i]);
    }
    fclose(fileptr);
    
    //Print names read from file
    printf("Names from file:\n");
    for (int i = 0; i < NUM_NAMES; i++){ 
        printf("%d. %s\n", i + 1, printed_names[i]);
        }
    return 0;
}
 
