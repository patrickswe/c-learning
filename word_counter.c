#include <stdio.h>
#include <ctype.h>

int main(){
    
    char select[100];
    printf("Welcome to file counter\n");
    printf("What file would you like me to check? ");
    scanf("%s", select);
    int in_word = 0;

    FILE *fp;
    int ch;
    fp = fopen(select, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int char_count = 0, line_count = 0, word_count= 0;
    while ((ch = fgetc(fp)) != EOF) {
        char_count++;
        if ( ch == '\n' ) {
            line_count++;
        }
        if (isspace(ch)) {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            word_count++;
        }
    }

    fclose(fp);

    printf("Lines: %d\n", line_count);
    printf("Words: %d\n", word_count);
    printf("Characters: %d\n", char_count);

    return 0;
}
