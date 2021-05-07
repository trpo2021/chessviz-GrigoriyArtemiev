#include <chessviz/BoardRead.h>
#include <iostream>
#include <libchessviz/BoardPrint.h>
#include <libchessviz/move.h>
#include <string>

using namespace std;

bool command_recognition(
        string comand_move, int* i1, int* i2, int* j1, int* j2);
int command_convert(char comand_move);
const int first_symbol_ascii = 97, first_number_ascii = 49;

void BoardRead(char** chessGrid)
{
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
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
        command_recognition(comand_move, pi1, pi2, pj1, pj2);
        if (i1 > -1 && i1 < 8 && i2 > -1 && i2 < 8 && j1 > -1 && j1 < 15
            && j2 > -1 && j2 < 15) {
            if (chessGrid[i1][j1 + 1] == 'w' && number_of_move % 2 == 1) {
                number_of_move++;
                move(chessGrid, i1, j1, i2, j2, pnumber_of_move);
            } else if (
                    chessGrid[i1][j1 + 1] == 'b' && number_of_move % 2 == 0) {
                number_of_move++;
                move(chessGrid, i1, j1, i2, j2, pnumber_of_move);
            } else
                cout << "Incorrect move\n\n";
            BoardPrint(chessGrid);
        } else
            cout << "Incorrect move\n\n";
    }
}

bool command_recognition(string comand_move, int* i1, int* i2, int* j1, int* j2)
{
    if (comand_move.length() == 5) {
        *j1 = command_convert(comand_move[0]);
        *i1 = command_convert(comand_move[1]);
        *j2 = command_convert(comand_move[3]);
        *i2 = command_convert(comand_move[4]);
        return false;
    } else {
        cout << "  Incorrect command\n\n";
        return true;
    }
}

int command_convert(char comand_move)
{
    int i = int(comand_move);
    if (i < first_symbol_ascii) {
        i -= first_number_ascii;
    } else {
        i = 2 * (i - first_symbol_ascii);
    }
    return i;
}