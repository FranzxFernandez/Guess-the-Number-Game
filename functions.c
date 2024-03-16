#include "functions.h"
#include <stdio.h>
#include <ctime>
#include <cstdlib>

void init_random_seed(void)
{
    srand((unsigned)time(NULL));
}

int generate_random_number(int min, int max)
{
    return (rand() % max) + min;
}

int get_player_guess(void)
{
    printf("\nPlease enter your guess: ");
    int guess;
    (void)scanf("%d", &guess);

    return guess;
}

int check_guess(int guess, int actual_number);

void display_result(int result);

void play_game(void)
{
    printf("==================================================================================\n");
    printf("\t\tWelcome to Guess the Number Game\n\nIn this game, the computer picks a random number within a chosen range, and you\ntry to guess it. The goal is to guess the number in the fewest attempts possible\n");
    printf("==================================================================================\n");

    printf("\nPlease enter the range [min to max]: ");
    int min, max;
    (void)scanf("%d %d", &min, &max);

    printf("\nThe range you entered is between %d and %d\n", min, max);

    init_random_seed();
    int rand_number = generate_random_number(min, max);
    int userGuess = get_player_guess();
    int result = check_guess(userGuess, rand_number);
}
