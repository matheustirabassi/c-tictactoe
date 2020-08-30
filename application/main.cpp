#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "../boardGame/board.h"
using namespace std;


int main() {
    setlocale(LC_ALL,"");
    int **board = alocateBoard();
    printCorrectBoard(board);
    int player = firstTurn(board);
    scanBoard(board, player);

    while (checkWin(board) == 0 || checkWin(board) == -1) {
            system("cls");
            printCorrectBoard(board);
            player = nextPlayer(player);
            if(checkWin(board) == -1){
                 cout << "O jogo deu velha! "<< endl;
                 return 0;
            }
            scanBoard(board,player);

    }
    printCorrectBoard(board);
    if(checkWin(board) == 1)
        cout << "O jogador ganhador é o bolinha! "<< endl;
    if(checkWin(board) == 2)
        cout << "O jogador ganhador é o xizinho! "<< endl;

    return 0;
}
