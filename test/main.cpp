#define CTEST_MAIN
#include "ctest.h"
#include <chessviz/BoardRead.h>
#include <chessviz/colorcheck.h>
#include <chessviz/const.h>
#include <iostream>
#include <libchessviz/BoardPrint.h>
#include <libchessviz/move.h>
#include <string>

using namespace Constants;
using namespace std;

int main(int argc, const char** argv)
{
	return ctest_main(argc, argv);
}

CTEST_SKIP(BoadrPrint, test_skip)
{
	ASSERT_FAIL();
}

CTEST_SKIP(const, test_skip)
{
	ASSERT_FAIL();
}

CTEST(colorcheck, test1_White_Pawn)
{
	// Given
	char figure[2] = { 'P', 'w' };
	// When
	const int result = colorcheck(figure);
	// Then
	const int expected = 0;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(colorcheck, test2_Black_Knight)
{
	// Given
	char figure[2] = { 'N', 'b' };
	// When
	const int result = colorcheck(figure);
	// Then
	const int expected = 1;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(command_recognition, test1_White_Pawn_Move_2_Cells_a)
{
	// Given
	const string comand_move = "a7-a5";
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
	const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

	// Then
	ASSERT_FALSE(result);
}

CTEST(command_recognition, test2_White_Pawn_Move_1_Cell_a)
{
	// Given
	const string comand_move = "a7-a6";
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
	const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

	// Then
	ASSERT_FALSE(result);
}

CTEST(command_recognition, test3_White_Pawn_Move_2_Cells_b)
{
	// Given
	const string comand_move = "b7-b5";
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
	const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

	// Then
	ASSERT_FALSE(result);
}

CTEST(command_recognition, test4_White_Pawn_Move_1_Cell_b)
{
	// Given
	const string comand_move = "b7-b6";
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
	const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

	// Then
	ASSERT_FALSE(result);
}

CTEST(command_recognition, test5_White_Pawn_Move_2_Cells_c)
{
	// Given
	const string comand_move = "c7-c5";
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
	const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

	// Then
	ASSERT_FALSE(result);
}

CTEST(command_recognition, test6_White_Pawn_Move_1_Cell_c)
{
	// Given
	const string comand_move = "c7-c6";
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
	const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

	// Then
	ASSERT_FALSE(result);
}

CTEST(command_recognition, test7_White_Pawn_Move_2_Cells_d)
{
	// Given
	const string comand_move = "d7-d5";
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
	const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

	// Then
	ASSERT_FALSE(result);
}

CTEST(command_recognition, test8_White_Pawn_Move_1_Cell_d)
{
	// Given
	const string comand_move = "d7-d6";
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
	const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

	// Then
	ASSERT_FALSE(result);
}

CTEST(command_recognition, test9_White_Pawn_Move_2_Cells_e)
{
	// Given
	const string comand_move = "e7-e5";
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
	const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

	// Then
	ASSERT_FALSE(result);
}

CTEST(command_recognition, test10_White_Pawn_Move_1_Cell_e)
{
	// Given
	const string comand_move = "e7-e6";
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
	const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

	// Then
	ASSERT_FALSE(result);
}

CTEST(command_recognition, test11_White_Pawn_Move_2_Cells_f)
{
	// Given
	const string comand_move = "f7-f5";
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
	const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

	// Then
	ASSERT_FALSE(result);
}

CTEST(command_recognition, test12_White_Pawn_Move_1_Cell_f)
{
	// Given
	const string comand_move = "f7-f6";
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
	const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

	// Then
	ASSERT_FALSE(result);
}

CTEST(command_recognition, test13_White_Pawn_Move_2_Cells_g)
{
	// Given
	const string comand_move = "g7-g5";
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
	const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

	// Then
	ASSERT_FALSE(result);
}

CTEST(command_recognition, test14_White_Pawn_Move_1_Cell_g)
{
	// Given
	const string comand_move = "g7-g6";
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
	const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

	// Then
	ASSERT_FALSE(result);
}

CTEST(command_recognition, test15_White_Pawn_Move_2_Cells_h)
{
	// Given
	const string comand_move = "h7-h5";
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
	const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

	// Then
	ASSERT_FALSE(result);
}

CTEST(command_recognition, test16_White_Pawn_Move_1_Cell_h)
{
	// Given
	const string comand_move = "h7-h6";
	int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
	int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
	const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

	// Then
	ASSERT_FALSE(result);
}

CTEST(command_convert, test1_a_from_ascii_to_int_grid)
{
	// Given
	const char comand_move = 'a';
	// When
	const int result = command_convert(comand_move);
	// Then
	const int expected = 0;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(command_convert, test2_b_from_ascii_to_int_grid)
{
	// Given
	const char comand_move = 'b';
	// When
	const int result = command_convert(comand_move);
	// Then
	const int expected = 2;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(command_convert, test3_c_from_ascii_to_int_grid)
{
	// Given
	const char comand_move = 'c';
	// When
	const int result = command_convert(comand_move);
	// Then
	const int expected = 4;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(command_convert, test4_d_from_ascii_to_int_grid)
{
	// Given
	const char comand_move = 'd';
	// When
	const int result = command_convert(comand_move);
	// Then
	const int expected = 6;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(command_convert, test5_e_from_ascii_to_int_grid)
{
	// Given
	const char comand_move = 'e';
	// When
	const int result = command_convert(comand_move);
	// Then
	const int expected = 8;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(command_convert, test6_f_from_ascii_to_int_grid)
{
	// Given
	const char comand_move = 'f';
	// When
	const int result = command_convert(comand_move);
	// Then
	const int expected = 10;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(command_convert, test7_g_from_ascii_to_int_grid)
{
	// Given
	const char comand_move = 'g';
	// When
	const int result = command_convert(comand_move);
	// Then
	const int expected = 12;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(command_convert, test8_h_from_ascii_to_int_grid)
{
	// Given
	const char comand_move = 'h';
	// When
	const int result = command_convert(comand_move);
	// Then
	const int expected = 14;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(command_convert, test9_1_from_ascii_to_int_grid)
{
	// Given
	const char comand_move = '1';
	// When
	const int result = command_convert(comand_move);
	// Then
	const int expected = 0;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(command_convert, test10_2_from_ascii_to_int_grid)
{
	// Given
	const char comand_move = '2';
	// When
	const int result = command_convert(comand_move);
	// Then
	const int expected = 1;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(command_convert, test11_3_from_ascii_to_int_grid)
{
	// Given
	const char comand_move = '3';
	// When
	const int result = command_convert(comand_move);
	// Then
	const int expected = 2;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(command_convert, test12_4_from_ascii_to_int_grid)
{
	// Given
	const char comand_move = '4';
	// When
	const int result = command_convert(comand_move);
	// Then
	const int expected = 3;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(command_convert, test13_5_from_ascii_to_int_grid)
{
	// Given
	const char comand_move = '5';
	// When
	const int result = command_convert(comand_move);
	// Then
	const int expected = 4;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(command_convert, test14_6_from_ascii_to_int_grid)
{
	// Given
	const char comand_move = '6';
	// When
	const int result = command_convert(comand_move);
	// Then
	const int expected = 5;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(command_convert, test15_7_from_ascii_to_int_grid)
{
	// Given
	const char comand_move = '7';
	// When
	const int result = command_convert(comand_move);
	// Then
	const int expected = 6;

	// Test
	ASSERT_EQUAL(expected, result);
}

CTEST(command_convert, test16_8_from_ascii_to_int_grid)
{
	// Given
	const char comand_move = '8';
	// When
	const int result = command_convert(comand_move);
	// Then
	const int expected = 7;

	// Test
	ASSERT_EQUAL(expected, result);
}