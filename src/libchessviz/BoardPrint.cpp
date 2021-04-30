#include <chessviz/colorcheck.h>
#include <chessviz/const.h>
#include <iostream>
#include <libchessviz/BoardPrint.h>
#include <string>

using namespace Constants;
using namespace std;

void BoardPrint(char** chessGrid)
{
	cout << "\n";
	for (int i = 0; i < board_size; ++i) {
		cout << "\t\t\t\t" << i + 1 << " ";
		for (int j = 0; j < board_size; ++j) {
			if ((i + j) % 2 == 0) {
				printf("\033[47m");
			}
			else {
				printf("\033[100m");
			}
			printf(" \033[30m%c", chessGrid[i][2 * j]);
			printf("\033[30m%c ", chessGrid[i][2 * j + 1]);
		}
		printf("\033[0m\n");
	}
	cout << "\t\t\t\t    a   b   c   d   e   f   g   h\n\n";
}
