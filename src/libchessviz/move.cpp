#include <chessviz/const.h>
#include <iostream>
#include <libchessviz/move.h>
void pawn_move(
	char** chessGrid, int i1, int j1, int i2, int j2, int* number_of_move);
void knight_move(
	char** chessGrid, int i1, int j1, int i2, int j2, int* number_of_move);
void rook_move(
	char** chessGrid, int i1, int j1, int i2, int j2, int* number_of_move);
void bishop_move(
	char** chessGrid, int i1, int j1, int i2, int j2, int* number_of_move);
void queen_move(
	char** chessGrid, int i1, int j1, int i2, int j2, int* number_of_move);
void king_move(
	char** chessGrid, int i1, int j1, int i2, int j2, int* number_of_move);

using namespace Constants;
using namespace std;

void swaps(char& a, char& b)
{
	char temp;
	temp = a;
	a = b;
	b = temp;
}

void chop(char** chessGrid, int i1, int j1, int i2, int j2, int* number_of_move)
{
	if (((chessGrid[i2][j2 + 1] != 'w') && (chessGrid[i1][j1 + 1] == 'w'))
		|| ((chessGrid[i2][j2 + 1] != 'b') && (chessGrid[i1][j1 + 1] == 'b'))) {
		chessGrid[i2][j2] = ' ';
		chessGrid[i2][j2 + 1] = ' ';
	}
	else {
		cout << "  Incorrect command\n\n";
		*number_of_move = *number_of_move - 1;
	}
}

void swapfigure(char** chessGrid, int i1, int j1, int i2, int j2)
{
	if (((chessGrid[i2][j2 + 1] != 'w') && (chessGrid[i1][j1 + 1] == 'w'))
		|| ((chessGrid[i2][j2 + 1] != 'b') && (chessGrid[i1][j1 + 1] == 'b'))) {
		swaps(chessGrid[i1][j1], chessGrid[i2][j2]);
		swaps(chessGrid[i1][j1 + 1], chessGrid[i2][j2 + 1]);
	}
}

void move(char** chessGrid, int i1, int j1, int i2, int j2, int* number_of_move)
{
	if (chessGrid[i1][j1] == 'P') {
		if (abs(i2 - i1) < 3 && (i1 == 1 || i1 == 6) && (abs(j2 - j1) <= 1))
			pawn_move(chessGrid, i1, j1, i2, j2, number_of_move);
		else if (abs(i2 - i1) < 2)
			pawn_move(chessGrid, i1, j1, i2, j2, number_of_move);
		else {
			cout << "  Incorrect command\n\n";
			*number_of_move = *number_of_move - 1;
		}
	}
	else {
		if (chessGrid[i1][j1] == 'N') {
			knight_move(chessGrid, i1, j1, i2, j2, number_of_move);
		}
		else {
			if (chessGrid[i1][j1] == 'R')
				rook_move(chessGrid, i1, j1, i2, j2, number_of_move);
			else {
				if (chessGrid[i1][j1] == 'B')
					bishop_move(chessGrid, i1, j1, i2, j2, number_of_move);
				else {
					if (chessGrid[i1][j1] == 'Q')
						queen_move(chessGrid, i1, j1, i2, j2, number_of_move);
					else {
						if (chessGrid[i1][j1] == 'K')
							king_move(
								chessGrid, i1, j1, i2, j2, number_of_move);
						else {
							cout << "  Incorrect command\n\n";
							*number_of_move = *number_of_move - 1;
						}
					}
				}
			}
		}
	}
}

void pawn_move(
	char** chessGrid, int i1, int j1, int i2, int j2, int* number_of_move)
{
	bool coolcheck = false;
	if ((i1 > i2 && chessGrid[i1][j1 + 1] == 'b')
		|| (i1 < i2 && chessGrid[i1][j1 + 1] == 'w')) {
		cout << "  Incorrect move\n\n";
		*number_of_move = *number_of_move - 1;
	}
	else {
		if ((chessGrid[i2][j2] != ' ')
			&& ((j2 == j1 - 2 || j2 == j1 + 2)
				&& (i2 == i1 + 1 || i2 == i1 - 1))) {
			chop(chessGrid, i1, j1, i2, j2, number_of_move);
			coolcheck = true;
		}
		if (((chessGrid[i2][j2] == ' ') && (j2 - j1 == 0)) || coolcheck)
			swapfigure(chessGrid, i1, j1, i2, j2);
		else {
			cout << "  Incorrect move\n\n";
			*number_of_move = *number_of_move - 1;
		}
	}
}

void knight_move(
	char** chessGrid, int i1, int j1, int i2, int j2, int* number_of_move)
{
	int buff, check = 0;
	for (int i = -2; i < 3; i++) {
		if (i == 0)
			continue;
		if (abs(i) == 2) {
			buff = 2;
		}
		else
			buff = 4;
		if ((i2 == i1 + i) && (j2 == j1 - buff || j2 == j1 + buff))
			check++;
	}
	if (check > 0) {
		chop(chessGrid, i1, j1, i2, j2, number_of_move);
		swapfigure(chessGrid, i1, j1, i2, j2);
	}
	else {
		cout << "  Incorrect move\n\n";
		*number_of_move = *number_of_move - 1;
	}
}

void rook_move(
	char** chessGrid, int i1, int j1, int i2, int j2, int* number_of_move)
{
	int check = 0;
	if (j1 == j2) {
		if (i1 > i2) {
			for (int i = i1 - 1; i > i2; i--) {
				if (i == 0)
					continue;
				if (chessGrid[i][j1] != ' ')
					check++;
			}
		}
		else {
			if (i1 < i2) {
				for (int i = i1 + 1; i < i2; i++) {
					if (i == 0)
						continue;
					if (chessGrid[i][j1] != ' ')
						check++;
				}
			}
		}
	}
	if (i1 == i2) {
		if (j1 > j2) {
			for (int i = j1 - 2; i >= j2 + 2; i -= 2) {
				if (i == 0)
					continue;
				if (chessGrid[i1][i] != ' ')
					check++;
			}
		}
		else {
			for (int i = j1 + 2; i <= j2 - 2; i += 2) {
				if (i == 0)
					continue;
				if (chessGrid[i1][i] != ' ')
					check++;
			}
		}
	}
	if (i1 != i2 && j1 != j2)
		check = 1;
	if (check == 0) {
		chop(chessGrid, i1, j1, i2, j2, number_of_move);
		swapfigure(chessGrid, i1, j1, i2, j2);
	}
	else {
		cout << "  Incorrect move\n\n";
		*number_of_move = *number_of_move - 1;
	}
}

void bishop_move(
	char** chessGrid, int i1, int j1, int i2, int j2, int* number_of_move)
{
	int check = 0;
	if (j1 > j2) {
		if (i1 > i2) {
			for (int i = 1; i1 - i > i2; i++) {
				if (chessGrid[i1 - i][j1 - 2 * i] != ' ')
					check++;
			}
		}
		else {
			if (i1 < i2) {
				for (int i = 1; i1 + i < i2; i++) {
					if (chessGrid[i1 + i][j1 - 2 * i] != ' ')
						check++;
				}
			}
		}
	}
	else {
		if (j1 < j2) {
			if (i1 > i2) {
				for (int i = 1; j1 + 2 * i < j2; i++) {
					if (chessGrid[i1 - i][j1 + 2 * i] != ' ')
						check++;
				}
			}
			else {
				if (i1 < i2) {
					for (int i = 1; i1 + i < i2; i++) {
						if (chessGrid[i1 + i][j1 + 2 * i] != ' ')
							check++;
					}
				}
			}
		}
	}
	if (i1 == i2 || j1 == j2)
		check = 1;
	if (abs(i1 - i2) * 2 != abs(j1 - j2))
		check = 1;
	if (check == 0) {
		chop(chessGrid, i1, j1, i2, j2, number_of_move);
		swapfigure(chessGrid, i1, j1, i2, j2);
	}
	else {
		cout << "  Incorrect move\n\n";
		*number_of_move = *number_of_move - 1;
	}
}

void queen_move(
	char** chessGrid, int i1, int j1, int i2, int j2, int* number_of_move)
{
	int check = 0;
	if (j1 > j2) {
		if (i1 > i2) {
			for (int i = 1; i1 - i > i2; i++) {
				if (chessGrid[i1 - i][j1 - 2 * i] != ' ')
					check++;
			}
		}
		else {
			if (i1 < i2) {
				for (int i = 1; i1 + i < i2; i++) {
					if (chessGrid[i1 + i][j1 - 2 * i] != ' ')
						check++;
				}
			}
		}
	}
	else {
		if (j1 < j2) {
			if (i1 > i2) {
				for (int i = 1; j1 + 2 * i < j2; i++) {
					if (chessGrid[i1 - i][j1 + 2 * i] != ' ')
						check++;
				}
			}
			else {
				if (i1 < i2) {
					for (int i = 1; i1 + i < i2; i++) {
						if (chessGrid[i1 + i][j1 + 2 * i] != ' ')
							check++;
					}
				}
			}
		}
	}
	if (j1 == j2) {
		if (i1 > i2) {
			for (int i = i1 - 1; i > i2; i--) {
				if (i == 0)
					continue;
				if (chessGrid[i][j1] != ' ')
					check++;
			}
		}
		else {
			if (i1 < i2) {
				for (int i = i1 + 1; i < i2; i++) {
					if (i == 0)
						continue;
					if (chessGrid[i][j1] != ' ')
						check++;
				}
			}
		}
	}
	if (i1 == i2) {
		if (j1 > j2) {
			for (int i = j1 - 2; i >= j2 + 2; i -= 2) {
				if (i == 0)
					continue;
				if (chessGrid[i1][i] != ' ')
					check++;
			}
		}
		else {
			for (int i = j1 + 2; i <= j2 - 2; i += 2) {
				if (i == 0)
					continue;
				if (chessGrid[i1][i] != ' ')
					check++;
			}
		}
	}
	if ((abs(i1 - i2) * 2 != abs(j1 - j2)) && (i1 != i2) && (j1 != j2))
		check = 1;
	if (check == 0) {
		chop(chessGrid, i1, j1, i2, j2, number_of_move);
		swapfigure(chessGrid, i1, j1, i2, j2);
	}
	else {
		cout << "  Incorrect move\n\n";
		*number_of_move = *number_of_move - 1;
	}
}

void king_move(
	char** chessGrid, int i1, int j1, int i2, int j2, int* number_of_move)
{
	bool coolcheck = false;
	if ((i1 > i2 && chessGrid[i1][j1 + 1] == 'b')
		|| (i1 < i2 && chessGrid[i1][j1 + 1] == 'w')) {
		cout << "  Incorrect move\n\n";
		*number_of_move = *number_of_move - 1;
	}
	else {
		if ((chessGrid[i2][j2] != ' ') && (abs(j2 - j1) <= 2)
			&& (abs(i2 - i1) <= 1)) {
			chop(chessGrid, i1, j1, i2, j2, number_of_move);
			coolcheck = true;
		}
		if (((chessGrid[i2][j2] == ' ') && (abs(j2 - j1) <= 2)
			&& (abs(i2 - i1) <= 1))
			|| coolcheck)
			swapfigure(chessGrid, i1, j1, i2, j2);
		else {
			cout << "  Incorrect move\n\n";
			*number_of_move = *number_of_move - 1;
		}
	}
}