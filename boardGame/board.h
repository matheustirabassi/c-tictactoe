#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
int checkWin(int **A);
int markBoard(int **A, int row, int column, int color);
bool checkPosition(int **A, int row, int column);
int **alocateBoard();
void printBoard(int **A);
int firstTurn(int **A);
void scanBoard(int **A, int player);
void printCorrectBoard(int **A);
int nextPlayer(int player);
int randomNumber();
int createGame();
#endif // BOARD_H_INCLUDED
