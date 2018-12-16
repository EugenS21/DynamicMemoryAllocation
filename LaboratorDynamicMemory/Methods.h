#include <conio.h> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

typedef enum  {ASCENDING, DESCENDING} sortingMethod;

typedef enum  {KEYBOARD, RANDOM} fillingMethod;

sortingMethod get_sorting_method();

fillingMethod get_filling_method();

int get_rows_number();

int get_columns_number();

int get_keyboard_input(int, int);

int get_random_input();

int **allocate_dynamic_memory(int, int);

int **fill_matrix_with_values(fillingMethod, int**, int, int); 

int **sort_matrix(sortingMethod, int **, int, int);

int initialize_matrix_menu();

int fill_matrix_menu();

int sort_matrix_menu();

int main_menu();

void destroy_allocated_memory(int**); 

void user_menu();

void print_matrix_values(int**, int, int); 