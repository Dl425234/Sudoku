// A Backtracking program  in C++ to solve Sudoku problem
#include <stdio.h>
#include <stdlib.h>
#include <ctime> 
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for size  Sudoku grid. Size will be NxN
#define N 4
#define M 9
#define C 16
#define SQN 3

// This function finds an entry in grid that is still unassigned
bool FindUnassignedLocation(int grid[N][N], int &row, int &col);

// Checks whether it will be legal to assign num to the given row,col
bool isSafe(int grid[N][N], int row, int col, int num);


/* Takes a partially filled-in grid and attempts to assign values to
  all unassigned locations in such a way to meet the requirements
  for Sudoku solution (non-duplication across rows, columns, and boxes) */
bool SolveSudoku(int grid[N][N])
{
  int row, col;

  // If there is no unassigned location, we are done
  if (!FindUnassignedLocation(grid, row, col))
    return true; // success!

  // consider digits 1 to 9
  for (int num = 1; num <= N; num++)
    {
      
      // if looks promising
      if (isSafe(grid, row, col, num))
        {
    // make tentative assignment
   
        grid[row][col] = num;
   
    
    // return, if success, yay!
    if (SolveSudoku(grid))
      return true;

    // failure, unmake & try again
    grid[row][col] = UNASSIGNED;
        }
    }
  return false; // this triggers backtracking
}

/* Searches the grid to find an entry that is still unassigned. If
   found, the reference parameters row, col will be set the location
   that is unassigned, and true is returned. If no unassigned entries
   remain, false is returned. */
bool FindUnassignedLocation(int grid[N][N], int &row, int &col)
{
  for (row = 0; row < N; row++)
    for (col = 0; col < N; col++)
      if (grid[row][col] == UNASSIGNED)
        return true;
  return false;
}

/* Returns a boolean which indicates whether any assigned entry
   in the specified row matches the given number. */
bool UsedInRow(int grid[N][N], int row, int num)
{
  for (int col = 0; col < N; col++)
    if (grid[row][col] == num)
      return true;
  return false;
}

/* Returns a boolean which indicates whether any assigned entry
   in the specified column matches the given number. */
bool UsedInCol(int grid[N][N], int col, int num)
{
  for (int row = 0; row < N; row++)
    if (grid[row][col] == num)
      return true;
  return false;
}

/* Returns a boolean which indicates whether any assigned entry
   within the specified 3x3 box matches the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
  for (int row = 0; row < SQN-1; row++){
    for (int col = 0; col < SQN-1; col++){
      if (grid[row+boxStartRow][col+boxStartCol] == num) return true;
    }
  }
  return false;
}

/* Returns a boolean which indicates whether it will be legal to assign
   num to the given row,col location. */
bool isSafe(int grid[N][N], int row, int col, int num)
{
  /* Check if 'num' is not already placed in current row,
     current column and current 3x3 box */
  return !UsedInRow(grid, row, num) &&
    !UsedInCol(grid, col, num) &&
    !UsedInBox(grid, row - row%(SQN-1) , col - col%(SQN-1), num);
}

/* A utility function to print grid  */
void printGrid(int grid[N][N])
{
  for (int row = 0; row < N; row++)
    {
      for (int col = 0; col < N; col++)
  printf("%2d", grid[row][col]);
      printf("\n");
    }
}

/*
 *
 *  FUNCTIONS TO SOLVE 9_X_9 BOARD!
 *
 *
 */


bool FindUnassignedLocation(int grid[M][M], int &row, int &col);


// Checks whether it will be legal to assign num to the given row,col
bool isSafe(int grid[M][M], int row, int col, int num);

/* Takes a partially filled-in grid and attempts to assign values to
  all unassigned locations in such a way to meet the requirements
  for Sudoku solution (non-duplication across rows, columns, and boxes) */
bool SolveSudoku(int grid[M][M])
{
  int row, col;

  // If there is no unassigned location, we are done
  if (!FindUnassignedLocation(grid, row, col))
    return true; // success!

  // consider digits 1 to 9
  for (int num = 1; num <= M; num++)
    {
      // if looks promising
      if (isSafe(grid, row, col, num))
        {
    // make tentative assignment
    
    grid[row][col] = num;

    // return, if success, yay!
    if (SolveSudoku(grid))
      return true;

    // failure, unmake & try again
    grid[row][col] = UNASSIGNED;
        }
    }
  return false; // this triggers backtracking
}

/* Searches the grid to find an entry that is still unassigned. If
   found, the reference parameters row, col will be set the location
   that is unassigned, and true is returned. If no unassigned entries
   remain, false is returned. */
bool FindUnassignedLocation(int grid[M][M], int &row, int &col)
{
  for (row = 0; row < M; row++)
    for (col = 0; col < M; col++)
      if (grid[row][col] == UNASSIGNED)
  return true;
  return false;
}

/* Returns a boolean which indicates whether any assigned entry
   in the specified row matches the given number. */
bool UsedInRow(int grid[M][M], int row, int num)
{
  for (int col = 0; col < M; col++)
    if (grid[row][col] == num)
      return true;
  return false;
}

/* Returns a boolean which indicates whether any assigned entry
   in the specified column matches the given number. */
bool UsedInCol(int grid[M][M], int col, int num)
{
  for (int row = 0; row < M; row++)
    if (grid[row][col] == num)
      return true;
  return false;
}

/* Returns a boolean which indicates whether any assigned entry
   within the specified 3x3 box matches the given number. */
bool UsedInBox(int grid[M][M], int boxStartRow, int boxStartCol, int num)
{
  for (int row = 0; row < SQN; row++)
    for (int col = 0; col < SQN; col++)
      if (grid[row+boxStartRow][col+boxStartCol] == num)
  return true;
  return false;
}

/* Returns a boolean which indicates whether it will be legal to assign
   num to the given row,col location. */
bool isSafe(int grid[M][M], int row, int col, int num)
{
  /* Check if 'num' is not already placed in current row,
     current column and current 3x3 box */
  return !UsedInRow(grid, row, num) &&
    !UsedInCol(grid, col, num) &&
    !UsedInBox(grid, row - row%SQN , col - col%SQN, num);
}

/* A utility function to print grid  */
void printGrid(int grid[M][M])
{
  for (int row = 0; row < M; row++)
    {
      for (int col = 0; col < M; col++)
  printf("%2d", grid[row][col]);
      printf("\n");
    }
}

/*
 *
 *  FUNCTIONS TO SOLVE 16_X_16 BOARD!
 *
 *
 */


bool FindUnassignedLocation(int grid[C][C], int &row, int &col);


// Checks whether it will be legal to assign num to the given row,col
bool isSafe(int grid[C][C], int row, int col, int num);

/* Takes a partially filled-in grid and attempts to assign values to
  all unassigned locations in such a way to meet the requirements
  for Sudoku solution (non-duplication across rows, columns, and boxes) */
bool SolveSudoku(int grid[C][C])
{
  int row, col;

  // If there is no unassigned location, we are done
  if (!FindUnassignedLocation(grid, row, col))
    return true; // success!

  // consider digits 1 to 9
  for (int num = 1; num <= C; num++)
    {
      // if looks promising
      if (isSafe(grid, row, col, num))
        {
    // make tentative assignment
    grid[row][col] = num;

    // return, if success, yay!
    if (SolveSudoku(grid))
      return true;

    // failure, unmake & try again
    grid[row][col] = UNASSIGNED;
        }
    }
  return false; // this triggers backtracking
}

/* Searches the grid to find an entry that is still unassigned. If
   found, the reference parameters row, col will be set the location
   that is unassigned, and true is returned. If no unassigned entries
   remain, false is returned. */
bool FindUnassignedLocation(int grid[C][C], int &row, int &col)
{
  for (row = 0; row < C; row++)
    for (col = 0; col < C; col++)
      if (grid[row][col] == UNASSIGNED)
  return true;
  return false;
}

/* Returns a boolean which indicates whether any assigned entry
   in the specified row matches the given number. */
bool UsedInRow(int grid[C][C], int row, int num)
{
  for (int col = 0; col < C; col++)
    if (grid[row][col] == num)
      return true;
  return false;
}

/* Returns a boolean which indicates whether any assigned entry
   in the specified column matches the given number. */
bool UsedInCol(int grid[C][C], int col, int num)
{
  for (int row = 0; row < C; row++)
    if (grid[row][col] == num)
      return true;
  return false;
}

/* Returns a boolean which indicates whether any assigned entry
   within the specified 4x4 box matches the given number. */
bool UsedInBox(int grid[C][C], int boxStartRow, int boxStartCol, int num)
{
  for (int row = 0; row < SQN+1; row++)
    for (int col = 0; col < SQN+1; col++)
      if (grid[row+boxStartRow][col+boxStartCol] == num)
        return true;
  return false;
}

/* Returns a boolean which indicates whether it will be legal to assign
   num to the given row,col location. */
bool isSafe(int grid[C][C], int row, int col, int num)
{
  /* Check if 'num' is not already placed in current row,
     current column and current 3x3 box */
  return !UsedInRow(grid, row, num) &&
    !UsedInCol(grid, col, num) &&
    !UsedInBox(grid, row - row%SQN , col - col%SQN, num);
}

/* A utility function to print grid  */
void printGrid(int grid[C][C])
{
  for (int row = 0; row < C; row++)
    {
      for (int col = 0; col < C; col++)
  printf("%2d ", grid[row][col]);
      printf("\n");
    }
}


/* Driver Program to test above functions */
int main()
{
  // 0 means unassigned cells
  int rando =0;//random number 
  srand((unsigned)time(0)); //seed based on time
  //make 4x4g rid
   int grid4[N][N] = {{0,0,3,4},{3,4,0,0},{0,0,4,3},{0,3,2,0}};
   int grid4_1[N][N] = {};
    for (int row = 0; row <N; row++){
    for (int col = 0; col < N; col++){
      rando = rand()%(N+1);//number is in range of 0 and 4
      if (isSafe(grid4_1,row,col,rando)&&(col%rando)==0) grid4_1[row][col]=rando;
      else grid4_1[row][col]=0;
        }
    }  
    //make 9x9 grid
  int grid9_1[M][M] = {};
    for (int row = 0; row < M; row++){
    for (int col = 0; col < M; col++){
      rando = rand()%(M+1);//number is in range of 0 and 9
      if (isSafe(grid9_1,row,col,rando)&&(col%rando)==0) grid9_1[row][col]=rando;
      else grid9_1[row][col]=0;
        }
    }  
    
     //make 16x16 grid
  int grid16_1[C][C] = {};
    for (int row = 0; row < C; row++){
    for (int col = 0; col < C; col++){
      rando = rand()%(C+1);//number is in range of 0 and 16
      if (isSafe(grid16_1,row,col,rando)&&(col%rando)==0) grid16_1[row][col]=rando;
      else grid16_1[row][col]=0;
        }
    } 
    
  int grid16[C][C]={//set example
    {5,11,16,4,0,0,13,1,0,0,0,0,0,0,0,0},
    {0,0,0,10,0,11,14,2,13,0,0,16,0,12,8,0},
    {13,0,0,12,0,0,5,0,0,10,3,0,11,0,2,0},
    {1,0,0,2,0,0,0,0,0,0,14,5,10,0,4,0},
    
    {4,0,0,8,13,0,0,15,0,0,0,10,16,0,0,2},
    {0,0,0,0,0,10,16,0,7,0,0,0,0,3,13,0},
    {0,10,0,0,8,0,0,0,1,5,16,13,0,11,0,9},
    {0,0,0,0,2,0,0,14,8,0,11,0,6,1,5,0},
    
    {0,13,12,16,0,4,0,10,15,0,0,7,0,0,0,11},
    {8,0,1,0,14,12,11,16,0,0,0,6,0,0,10,0},
    {0,4,10,0,0,0,0,6,0,16,1,0,0,0,0,0},
    {3,0,0,5,15,0,0,0,10,0,0,2,4,0,0,11},
    
    {0,16,0,3,1,15,0,0,0,0,0,0,9,0,0,13},
    {0,6,0,11,0,7,10,0,0,15,0,0,5,0,0,14},
    {0,9,13,0,16,0,0,8,6,7,5,0,3,0,0,0},
    {0,0,0,0,0,0,0,0,16,3,0,0,1,8,12,7}
    
  };
    
  
  printf("\n");
  printf("4x4 Grid. Constraints: \n -No Same Number in Row or Column \n -Numbers 1-4 Present in Each Row and Column\n");
  printf("-2x2 Internal Grids Contain the Numbers 1-4 and do not Repeat Numbers\n\n");
  printf("Problem Grid (Set example): \n");
  printGrid(grid4);


  if (SolveSudoku(grid4) == true){
    printf("\n\nSolved Grid: \n");
    printGrid(grid4);
  } else
    printf("No solution exists");
    
  printf("\n\n");
  printf("Problem Grid (Random example): \n");
  printGrid(grid4_1);
  
  if (SolveSudoku(grid4_1) == true){
    printf("\n\nSolved Grid: \n");
    printGrid(grid4_1);
  } else
    printf("No solution exists");
    
  printf("\n\n");
  
  printf("9x9 Grid. Constraints: \n -No Same Number in Row or Column \n -Numbers 1-9 Present in Each Row and Column\n");
  printf("-3x3 Internal Grids Contain the Numbers 1-9 and do not Repeat Numbers\n\n");
  printf("Problem Grid: \n");
  printGrid(grid9_1);


  if (SolveSudoku(grid9_1) == true){
    printf("\n\nSolved Grid: \n");
    printGrid(grid9_1);
  } else
    printf("No solution exists");

  printf("\n");
  printf("16x16 Grid. Constraints: \n -No Same Number in Row or Column \n -Numbers 1-16 Present in Each Row and Column\n");
  printf("-4x4 Internal Grids Contain the Numbers 1-16 and do not Repeat Numbers\n\n");
  printf("Problem Grid: \n");
  printGrid(grid16);


  if (SolveSudoku(grid16) == true){
    printf("\n\nSolved Grid: \n");
    printGrid(grid16);
  } else
    printf("No solution exists");

  printf("\n\n");

  return 0;
}
