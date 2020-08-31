#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "../boardGame/board.h"
using namespace std;
struct Players {
    string name;
    int points;
};

int main() {
    setlocale(LC_ALL,"");
    int rodadas = 0;
    int winner = 0;
    cout << "Qual é o seu nome player 1?" << endl;
    Players player1;
    cin >> player1.name;
    cout << "Qual é o seu nome player 2?" << endl;
    Players player2;
    cin >> player2.name;
    cout << "Melhor de quanto?" << endl;
    cin >> rodadas;
    player1.points = 0;
    player2.points = 0;
    cout << "Serão " << rodadas << " rodadas" << endl;
    system("pause");
    while(rodadas > player1.points  && rodadas > player2.points ) {
        winner = createGame();
        if(winner == 1) {
            player1.points++;
            cout << player1.name << " com " << player1.points;
            if(player1.points == 1) {
                cout <<" ponto!";
            } else {
                cout <<" pontos!";
            }
        }
        if(winner == 2) {
            player2.points++;
            cout << player2.name << " com " << player2.points;
            if(player2.points == 1) {
                cout <<" ponto!";
            } else {
                cout << " pontos!";
            }
        }
        cout << endl;
        system("pause");
    }
    if(winner == 1)
        cout << "O ganhador é : " <<  player1.name;
    else
        cout << "O ganhador é : " <<  player2.name;
    return 0;
}
