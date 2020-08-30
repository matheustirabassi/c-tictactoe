#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
#define tam 3
#define rows  tam
#define columns  tam
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

int **alocateBoard() {
    int **A =( int **) calloc(rows,sizeof(int));
    for(int i = 0; i < rows; i++) {
        A[i] = ( int *) calloc(columns, sizeof(int ) );
    }
    return A;
}
void printBoard(int **A) {
    cout << "  ";
    for(int i = 0; i < rows; i++) {
        cout << i + 1 << " ";
    }
    cout << endl;
    for(int i = 0; i < rows; i++) {
        cout << i + 1 << " ";
        for(int j = 0 ; j < columns; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

}
int firstTurn(int **A) {
    if(checkWin(A) == 0) {
        if(randomNumber() < 50) {
            cout << "Primeiro jogador é a bolinha!" << endl << endl;
            return 1;
        }
        cout << "Primeiro jogador é o xizinho!" << endl << endl;
        return 2;
    }
    return 0;
}

void scanBoard(int **A, int player) {
    int row = 0;
    int col = 0;
    if(player == 1) {
        cout << "Turno do jogador bolinha! ..." << endl;
    } else {
        cout << "Turno do jogador xizinho! ..." << endl ;
    }
    cout << "Digite a linha! ";
    cin >> row;
    cout << "Digite a coluna! ";
    cin >> col;
    row--;
    col--;

    while(markBoard(A,row, col, player) != 1) {
        cout << "Digite a linha! ";
        cin >> row;
        cout << "Digite a coluna! ";
        cin >> col;
        row--;
        col--;

    }
}
int checkWin(int **A) {
    //check the lines
    int sum1 = 0;
    int sum2 = 0;
    //checking the first line
    for(int i = 0; i < rows; i++) {
        for(int j = 0 ; j < columns; j++) {
            if(A[i][j] == 1) {
                sum1++;
            }
            if(A[i][j] == 2) {
                sum2++;
            }

            if(sum1 == rows) {
                return 1;
            }
            if(sum2 == rows) {
                return 2;
            }
        }
        sum1 = 0;
        sum2 = 0;
    }


    for(int i = 0; i < rows; i++) {
        for(int j = 0 ; j < columns; j++) {
            if(A[j][i] == 1) {
                sum1++;
            }
            if(A[j][i] == 2) {
                sum2++;
            }
            if(sum1 == rows) {
                return 1;
            }
            if(sum2 == columns) {
                return 2;
            }
        }
        sum1 = 0;
        sum2 = 0;
    }

    for(int i = 0, j = 0; i < rows ; i++, j++) {
        if(A[j][j] == 1) {
            sum1++;
        }
        if(A[i][j] == 2) {
            sum2++;
        }
        if(sum1 == rows) {
                return 1;
            }
            if(sum2 == columns) {
                return 2;
            }
    }
    sum1 = 0;
    sum2 = 0;

    for(int i = rows - 1, j = 0; i >= 0; i--, j++) {
        if(A[j][j] == 1) {
            sum1++;
        }
        if(A[i][j] == 2) {
            sum2++;
        }
        if(sum1 == rows) {
                return 1;
            }
            if(sum2 == columns) {
                return 2;
            }
    }
    int ticTacToe = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(checkPosition(A,i,j)) {
                ticTacToe++;
            }
        }
    }
    if(ticTacToe == (rows * columns)) {
        return -1;
    }

    return 0;
}

void printCorrectBoard(int **A) {
    cout << "TABULEIRO" << endl;
    cout << "--------" << endl;
    cout << "  ";
    for(int i = 0; i < rows; i++) {
        cout << i + 1 << " ";
    }
    cout << endl;
    for(int i = 0; i < rows; i++) {
        cout << i + 1 << " ";
        for(int j = 0 ; j < columns; j++) {
            if(A[i][j] == 1) {
                cout << "O" << " ";
            }
            if(A[i][j] == 2) {
                cout << "X" << " ";
            }
            if(!checkPosition(A,i, j)) {
                cout << "?" << " ";
            }

        }
        cout << endl;
    }
    cout << "--------" << endl;
}
int nextPlayer(int player) {
    if(player == 1) {
        return 2;
    }
    if(player == 2) {
        return 1;
    }
    return 0;
}
int randomNumber() {
    cout << endl << "Sorteando primeiro jogador..." << endl;
    unsigned sorteio = 0;
    srand(time(NULL));
    for(int i = 0; i < 100; i++) {
        sorteio = rand() % 100;
    }

    return sorteio;
}
bool checkPosition(int **A, int row, int column) {
    return A[row][column] != 0;
}
int markBoard(int **A, int row, int column, int color) {
    if(row >= rows || row < 0 || column >= columns || column < 0 ) {
        cout << endl << "This position not exist!" << endl;
        return -1;

    }
    if(!checkPosition(A, row, column)) {
        A[row][column] = color;
        return 1;
    }
    cout << "This position is occuped" << endl;
    return 0;
}


