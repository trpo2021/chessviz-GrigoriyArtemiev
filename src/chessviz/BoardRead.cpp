#include <chessviz/BoardRead.hpp>
#include <iostream>
#include <libchessviz/BoardPrint.hpp>
#include <libchessviz/move.hpp>
#include <string>

using namespace std;

void BoardRead(char** chessGrid)
{
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int number_of_move = 1;
    int* pnumber_of_move = &number_of_move;
    while (true) {
        string comand_move;
        if (number_of_move % 2)
            cout << "  White move: ";
        else
            cout << endl << "  Black move: ";
        cin >> comand_move;
        cout << endl;
        if (comand_move == "exit")
            break;
        j1 = 2 * (int(comand_move[0]) - 97);
        i1 = int(comand_move[1]) - 49;
        j2 = 2 * (int(comand_move[3]) - 97);
        i2 = int(comand_move[4]) - 49;
        if (chessGrid[i1][j1 + 1] == 'w' && number_of_move % 2 == 1) {
            number_of_move++;
            move(chessGrid, i1, j1, i2, j2, pnumber_of_move);
        } else if (chessGrid[i1][j1 + 1] == 'b' && number_of_move % 2 == 0) {
            number_of_move++;
            move(chessGrid, i1, j1, i2, j2, pnumber_of_move);
        } else
            cout << "Incorrect move\n\n";
        BoardPrint(chessGrid);
    }
}
