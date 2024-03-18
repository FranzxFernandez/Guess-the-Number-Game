#include "functions.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "stdbool.h"

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
    int guess, numScanned;
    bool validInput = false;

    while (!validInput)
    {
        printf("\nPlease enter your guess: ");

        numScanned = scanf("%d", &guess);

        if (numScanned == 1)
        {
            validInput = true;
        }
        else
        {
            printf("That's not an integer. Please try again.\n");

            // Cleaning the input buffer to remove unwanted characters
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
        }
    }

    return guess;
}

int check_guess(int guess, int actual_number)
{
    if (guess > actual_number)
    {
        return 1;
    }
    else if (guess < actual_number)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

void display_result(int result, int attemps)
{
    printf("\n");
    printf("******************************\n");
    printf("Answer: %d\n", result);
    printf("Number of attempts: %d\n", attemps);
    printf("******************************\n");
}

void play_game(void)
{
    printf("==================================================================================\n");
    printf("\t\tWelcome to Guess the Number Game\n\nIn this game, the computer picks a random number within a chosen range, and you\ntry to guess it. The goal is to guess the number in the fewest attempts possible\n");
    printf("==================================================================================\n");

    printf("\n\tPlease enter the range!\n\t-----------------------\nMin: ");
    int min, max;
    (void)scanf("%d", &min);
    printf("Max: ");
    (void)scanf("%d", &max);
    printf("\nThe range you entered is between %d and %d\n", min, max);

    init_random_seed();
    int rand_number = generate_random_number(min, max);

    bool exit = false;
    int attemps = 0, result = 0;
    while (!exit)
    {
        int userGuess = get_player_guess();
        result = check_guess(userGuess, rand_number);

        if (result == 1)
        {
            printf("Too high!\n");
        }
        else if (result == 2)
        {
            printf("Too low!\n");
        }
        else
        {
            printf("\nCorrect guess. You win!\n");
            result = userGuess;
            exit = true;
        }
        attemps++;
    }
    display_result(result, attemps);
}
