#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                          'H', 'I', 'J', 'K', 'L', 'M', 'N',
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                          'V', 'W', 'X', 'Y', 'Z' };
static char board[12][12];


void createSudoku()
{
    int i, j;
    int filledletters = 0;
    char holder;
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if(rand() % 2 == 0){
                board[i][j] = '*';
                continue;
            }
            holder = alphabet[rand() % 26];
            if(isSafe(i,j,holder) != 1 || rand() % 12  != 0){
                board[i][j] = '*';
                continue;
            }
            board[i][j] = alphabet[rand() % 26];
            filledletters =+1;
            if(filledletters == 100)
                break;
            
            if(i == 11 && j == 11 && filledletters < 100){
                i = 0;
                j = 0;
                continue;
            }
        }
    
    }

}

// Checks whether it will be legal to assign num to the given row, col
int isSafe(int row,int col, char item)
{
	
	// Check if we find the same item
	// in the similar row , we return 0
	for (int x = 0; x < 12; x++)
		if (board[row][x] == item)
			return 0;

	// Check if we find the same item in the
	// similar column , we return 0
	for (int x = 0; x < 12; x++)
		if (board[x][col] == item)
			return 0;

	// Check if we find the same item in the
	// particular 3*3 matrix, we return 0
	int startRow = row - row % 4,
				startCol = col - col % 4;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (board[i + startRow][j +
						startCol] == item)
				return 0;

	return 1;
}

/* Takes a partially filled-in board and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
int solveSudoku(int row, int col)
{
	
	// Check if we have reached the 12th row and 9th column (0 indexed matrix) , 
    // we are returning true to avoid further backtracking
	if (row == 12 - 1 && col == 12)
		return 1;

	// Check if column value becomes 12 ,
	// we move to next row and
	// column start from 0
	if (col == 12)
	{
		row++;
		col = 0;
	}

	// Check if the current position is not empty
	if (board[row][col] != '*')
		return solveSudoku(row, col + 1);

	for (int num = 1; num <= 26; num++)
	{
		
		// Check if it is safe to place
		// the num (1-9) in the
		// given row ,col ->we move to next column
        char item = alphabet[num]; 
		if (isSafe(row, col, item)==1)
		{
			/* assigning the num in the
			current (row,col)
			position of the board
			and assuming our assigned num
			in the position
			is correct	 */
			board[row][col] = item;
		
			// Checking for next possibility with next
			// column
			if (solveSudoku(row, col + 1)==1)
				return 1;
		}
	
		// Removing the assigned num ,
		// since our assumption
		// was wrong , and we go for next
		// assumption with
		// diff num value
		board[row][col] = "*";
	}
	return 0;
}


void printSudoku()
{
    int i, j;
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            printf(" %c ", board[i][j]);
            if ((j + 1) % 4 == 0 && j < 11)
                printf(" | ");
        }
        printf("\n");
        if ((i + 1) % 4 == 0 && i < 11)
            printf("---------   ---------   ---------\n");
    }
}


// Program starts
int main()
{
     srand(16600051);
    // printf("\n\n1kanye first char is %c\n\n",board[0][0]);
    createSudoku();
    printf("\n created sudoku:\n");
    printSudoku();
    // printf("\n\n3kanye first char is %c\n\n",board[0][0]);
    printf("\n\n Solved sudoku:\n");
    int result = solveSudoku(0,0);
    printSudoku();
    printf("the result code is %d \n",result);
    return 0;
}