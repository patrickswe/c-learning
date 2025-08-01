#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 10

int generate_secret(void)
{
    srand(time(NULL));
    int secret = rand() % 100 + 1;
    return secret;
}
    
int get_guess(void)
{    
    int guess;
    printf("Take a guess: ");
    scanf("%d", &guess);
    return guess;
}

void play_game(void)
{
    int secret = generate_secret();
    int guess = 0;
    int count = 0;
    printf("I'm thinking of a number between 1 and 100");
    while ( guess != secret && count < MAX_TRIES )
    {
        guess = get_guess();
        count++;
        if (guess > secret) printf("Too High\n");
        else if (guess <  secret) printf("Too Low\n");
    }
    if (count >= 10) printf("You've run out of tries, the correct answer was %d.", secret);
    else printf("Correct! You got it in %d tries.\n", count);
}

int main()
{
    play_game();
    return 0;
}    


