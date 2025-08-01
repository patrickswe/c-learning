#include <stdio.h>
#include <string.h>
#define FILENAME "names.txt"

int main() {
    int num_names;
    printf("How many names do you want to enter?\n");
    scanf("%d", &num_names);

    char names[num_names][100];
    FILE *fileptr;

    // Get names from user
    for (int i = 0; i < num_names; i++) {
        printf("Name %d: ", i + 1);
        scanf("%s", names[i]);  // No & needed for array names
    }

    // Write to file
    fileptr = fopen(FILENAME, "w");
    if (fileptr == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int i = 0; i < num_names; i++) {
        fprintf(fileptr, "%s\n", names[i]);
    }

    fclose(fileptr);

    char test_name[100];
    char search_name[100];

    while (1) {
        printf("Enter a name to search for (type \"exit\" to quit): ");
        scanf("%s", search_name);
        //test for exit
        if (strcmp(search_name, "exit") == 0){
            break;
        }
        // Open file
        fileptr = fopen(FILENAME, "r");
        if (fileptr == NULL) {
            printf("Error opening file for reading.\n");
            return 1;
        }
        //test for word in file
        int flag = 0;
        while (fscanf(fileptr, "%s", test_name) != EOF) {
            if (strcmp(test_name, search_name) == 0) {
                flag = 1;
                break;
            }
        }
           
        fclose(fileptr); 
        if (flag) {
            printf("%s was found in %s\n", search_name, FILENAME);
        } else {
            printf("%s was not found in %s\n", search_name, FILENAME);
        }
    }
    return 0;
}
