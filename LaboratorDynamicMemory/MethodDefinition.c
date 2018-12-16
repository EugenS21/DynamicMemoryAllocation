#include "Methods.h" 

sortingMethod get_sorting_method() {
	int userInput = 0;
	system("cls");
	printf("\n\tChose sorting method\n");
	printf("1. Ascending\n");
	printf("2. Descending\n");
	printf("Your choice: ");
	scanf_s("%d", &userInput);
	switch (userInput) {
	case 1: 
		return ASCENDING;
	default:
		return DESCENDING;
	}
}

fillingMethod get_filling_method() {
	int userInput = 0;
	system("cls");
	printf("\n\tChose filling method:\n");
	printf("1. Manually\n");
	printf("2. Automatically\n");
	printf("Your choice: ");
	scanf_s("%d", &userInput);
	switch (userInput) {
	case 1: {
		return KEYBOARD;
		break;
	}
	default: {
		return RANDOM;
		break;
	}
	}
}

int get_rows_number() {	
	int rowsNumber;
	do {
		system("cls");
		printf("\n\tChose rows number:\n");
		printf("Your choice: ");
		scanf_s("%d", &rowsNumber);
	} while (rowsNumber < 0);
	return rowsNumber;
}

int get_columns_number(){
	int columnsNumber;
	do {
		system("cls");
		printf("\n\tChose columns number:\n");
		printf("Your choice: ");
		scanf_s("%d", &columnsNumber);
	} while (columnsNumber < 0);
	return columnsNumber;
}

int get_keyboard_input(int rPosition, int cPosition) {
	int userInput;
	system("cls");
	printf("[%d:%d]: ", rPosition, cPosition);
	scanf_s("%d", &userInput);
	return userInput;
}

int get_random_input() {	
	int tempVar = rand();
	return tempVar;
}

int **allocate_dynamic_memory(int rowsNumber, int columnsNumber) {
	int **workingMatrix = (int **) malloc (rowsNumber * sizeof(int*))
		, i = 0;
	for (i; i < rowsNumber; i++) 
		workingMatrix[i] = (int *) malloc (columnsNumber * sizeof(int)); 
	return workingMatrix;
}

int **fill_matrix_with_values(fillingMethod dataInputType, int **workingMatrix, int rowsNumber, int columnsNumber) {
	int i = 0, j = 0;
	for (i = 0; i < rowsNumber; i++)
		for (j = 0; j < columnsNumber; j++)
			if (dataInputType == KEYBOARD)
				workingMatrix[i][j] = get_keyboard_input(i, j);
			else
				workingMatrix[i][j] = get_random_input();
	printf("\nValues was added to matrix!\n");
	system("pause > nul");
	return workingMatrix;
} 

int **sort_matrix(sortingMethod sortingType, int **workingMatrix, int rowsNumber, int columnsNumber) {
	int **ma = workingMatrix, i = 0, j = 0, k = 0, a = 0;

	if (sortingType == ASCENDING) {
		for (i = 0; i < rowsNumber; ++i) {
			for (j = 0; j < columnsNumber; ++j) {
				for (k = (j + 1); k < columnsNumber; ++k) {
					if (ma[i][j] > ma[i][k]) {
						a = ma[i][j];
						ma[i][j] = ma[i][k];
						ma[i][k] = a;
					}
				}
			}
		} 
	} 
	else {
		for (j = 0; j < columnsNumber; ++j) {
			for (i = 0; i < rowsNumber; ++i) {
				for (k = i + 1; k < rowsNumber; ++k) {
					if (ma[i][j] < ma[k][j]) {
						a = ma[i][j];
						ma[i][j] = ma[k][j];
						ma[k][j] = a;
					}
				}
			}
		}
	}
	return ma;
}

int initialize_matrix_menu() {
	int userInput;
	system("cls");
	printf(

		"--- Initialize matrix menu ---\n"
		"1. Read Rows and Columns\n"
		"2. Initialize matrix\n"
		"3. Return to previous menu\n"
		"Input: "
	);
	scanf_s("%d", &userInput);
	return userInput;
}

int fill_matrix_menu() {
	int userInput;
	system("cls");
	printf(

		"--- Fill matrix with values menu ---\n"
		"1. Fill matrix manually\n"
		"2. Fill matrix automatically\n"
		"3. Return to previous menu\n"
		"Input: "
	);
	scanf_s("%d", &userInput);
	return userInput;
}

int sort_matrix_menu() {
	int userInput;
	system("cls");
	printf(

		"--- Sort matrix mnu ---\n"
		"1. Sort ascendingly\n"
		"2. Sort descendingly\n"
		"3. Return to previous menu\n"
		"Input: "
	);
	scanf_s("%d", &userInput);
	return userInput;
}

int main_menu() {
	int userInput;
	system("cls");
	printf(

		"Welcome\n"
		"1. Initialize matrix\n"
		"2. Fill matrix with values\n"
		"3. Print matrix values\n"
		"4. Sort matrix\n"
		"5. Destroy memory and exit\n"
		"Input: "
	);
	scanf_s("%d", &userInput);
	return userInput;
}

void user_menu() {
	int** workingMatrix=NULL, rows=0, columns=0;
	UpLevel:
	switch (main_menu()) {
	case 1: {
		LevelUp:
		switch (initialize_matrix_menu()) {
		case 1: { 
			LevelCols:
			columns = get_columns_number();
			rows = get_rows_number();
			goto LevelUp;
			break;
		}
		case 2: {
			if (rows > 0 && columns > 0){ 
				workingMatrix = allocate_dynamic_memory(rows, columns);
				goto LevelUp;
			}
			else {
				printf("\nNo data!\nPlease input rows and columns values!!\n");
				_getch();
				goto LevelCols; 
			}
			break;
		}  
		default: {
			goto UpLevel;
			break;
		}
		}
		break;
	}
	case 2: {   
		LevelUpFill:
		if (rows > 0 && columns > 0)
			switch (fill_matrix_menu()) {
			case 1: {

				workingMatrix = fill_matrix_with_values(KEYBOARD, workingMatrix, rows, columns);
				goto LevelUpFill;
				break; 
			}
			case 2: {
				workingMatrix = fill_matrix_with_values(RANDOM, workingMatrix, rows, columns);
				goto LevelUpFill;
				break;
			}
			default: {
				goto UpLevel;
				break;
			}
			}  
		else {
			printf("\nInvalid data!\nCheck rows [%d] or columns [%d] inputs!!\n", rows, columns); 
			_getch();
			goto UpLevel;
		}
		break;
	}

	case 3: { 
		print_matrix_values(workingMatrix, rows, columns);
		_getch();
		goto UpLevel;
		break;
	}

	case 4: { 
		if (rows > 0 && columns > 0) 
			LevelUpSort:
			switch (sort_matrix_menu()) {
			case 1: { 
				workingMatrix = sort_matrix (ASCENDING, workingMatrix, rows, columns);
				goto LevelUpSort;
				break;
			}
			case 2: { 
				workingMatrix = sort_matrix (DESCENDING, workingMatrix, rows, columns);
				goto LevelUpSort;
				break;
			}
			default: {
				goto UpLevel; 
				break;
			}
			}

		else {
			printf("\nInvalid data!\nCheck rows [%d] or columns [%d] inputs!!\n", rows, columns); 
			_getch();
		}
		break;
	}

	default: {
		destroy_allocated_memory(workingMatrix); 
		_getch();
		exit(0);
	}
	}
}

void print_matrix_values(int **workingMatrix, int rowsNumber, int columnsNumber) {
	int i = 0, j = 0;
	printf("\nMatrix values");
	for (i = 0; i < rowsNumber; i++) {
		printf("\n");
		for (j = 0; j < columnsNumber; j++)
			printf("%d   ", workingMatrix[i][j]);
	}
	printf("\n\n"); 
	_getch();
} 

void destroy_allocated_memory(int **workingMatrix) {
	printf("\n\tUnallocating used memory\n"); 
	free(workingMatrix); 
	printf("\n\tMemory was unallocated\n"); 
} 