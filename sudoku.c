#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                          'H', 'I', 'J', 'K', 'L', 'M', 'N',
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                          'V', 'W', 'X', 'Y', 'Z' };
static char board[9][9];

void createSudoku()
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            board[i][j] = alphabet[rand() % 26];
            
            printf(" %c ", board[i][j]);
        }
    }

}
void printSudoku()
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            printf(" %c ", board[i][j]);
            if ((j + 1) % 3 == 0 && j < 8)
                printf(" | ");
        }
        printf("\n");
        if ((i + 1) % 3 == 0 && i < 8)
            printf("---------   ---------   ---------\n");
    }
}


// Program starts
int main()
{
     srand(16600051);
    // printf("\n\n1kanye first char is %c\n\n",board[0][0]);
    createSudoku();
    // char realmap[9][9] = createSudoku();
    // printf("\n\n2kanye first char is %c\n\n",board[0][0]);
    // printf("%c",map[0][1]);
    printSudoku();
    // printf("\n\n3kanye first char is %c\n\n",board[0][0]);
    return 0;
}