#include <iostream>
#include <chessviz/BoardRead.hpp>
#include <chessviz/const.hpp>
#include <libchessviz/BoardPrint.hpp>
#include <libchessviz/move.hpp>
#include <string>

using namespace Constants;
using namespace std;

int main()
{
    string pawnb, knightb, bishopb, rookb, queenb, kingb, empty, pawnw, knightw,
            bishopw, rookw, queenw, kingw;
    char** chessGrid = new char*[board_size];
    for (int i = 0; i < board_size; i++)
        chessGrid[i] = new char[2 * board_size];
    pawnb = "Pb", knightb = "Nb", bishopb = "Bb", rookb = "Rb", queenb = "Qb",
    kingb = "Kb", empty = "  ";
    pawnw = "Pw", knightw = "Nw", bishopw = "Bw", rookw = "Rw", queenw = "Qw",
    kingw = "Kw";
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < 2 * board_size; ++j) {
            chessGrid[i][j] = empty[0];
        }
    }
    for (int i = 0; i < 2; i++) {
        chessGrid[0][i] = rookb[i];
        chessGrid[0][i + 2] = knightb[i];
        chessGrid[0][i + 4] = bishopb[i];
        chessGrid[0][i + 6] = queenb[i];
        chessGrid[0][i + 8] = kingb[i];
        chessGrid[0][i + 10] = bishopb[i];
        chessGrid[0][i + 12] = knightb[i];
        chessGrid[0][i + 14] = rookb[i];
        chessGrid[7][i] = rookw[i];
        chessGrid[7][i + 2] = knightw[i];
        chessGrid[7][i + 4] = bishopw[i];
        chessGrid[7][i + 6] = queenw[i];
        chessGrid[7][i + 8] = kingw[i];
        chessGrid[7][i + 10] = bishopw[i];
        chessGrid[7][i + 12] = knightw[i];
        chessGrid[7][i + 14] = rookw[i];
    }
    for (int j = 0; j < board_size; ++j) {
        for (int i = 0; i < 2; ++i) {
            chessGrid[1][i + 2 * j] = pawnb[i];
        }
    }
    for (int j = 0; j < board_size; ++j) {
        for (int i = 0; i < 2; ++i) {
            chessGrid[6][i + 2 * j] = pawnw[i];
        }
    }
    BoardPrint(chessGrid);
    BoardRead(chessGrid);
    return 0;
}
