#pragma once
#include <chessviz/const.h>
#include <string>

using namespace Constants;

void BoardRead(char** chessGrid);
bool command_recognition(
        std::string comand_move, int* i1, int* i2, int* j1, int* j2);
int command_convert(char comand_move);