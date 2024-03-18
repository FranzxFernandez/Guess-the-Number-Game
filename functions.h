#if !defined(functions_h)
#define functions_h

void init_random_seed(void);
int generate_random_number(int min, int max);
int get_player_guess(void);
int check_guess(int guess, int actual_number);
void display_result(int result, int attemps);
void play_game(void);

#endif // functions_h
