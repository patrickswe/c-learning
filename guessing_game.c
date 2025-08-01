#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //get random number
    srand(time(NULL));
    int secret = rand() % 100 + 1;
    int guess, count = 0;
    
    printf("I'm thinking of a number between 1 and 100.");

    while ( guess != secret )
    {
        printf("Take a guess: ");
        scanf("%d", &guess);
        count += 1;
        if (guess > secret) printf("Too High\n");
        else if (guess > secret) printf("Too Low\n");
    }
    printf("Correct! You got it in %d tries.\n");

    return 0;
}    


