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

CTEST(colorcheck, test1)
{
    // Given
    char* figure = new char[2];
    figure[0] = 'P';
    figure[1] = 'w';
    // When
    const int result = colorcheck(figure);
    // Then
    const int expected = 0;

    // Test
    ASSERT_EQUAL(expected, result);
}

CTEST(colorcheck, test2)
{
    // Given
    char* figure = new char[2];
    figure[0] = 'R';
    figure[1] = 'w';
    // When
    const int result = colorcheck(figure);
    // Then
    const int expected = 0;

    // Test
    ASSERT_EQUAL(expected, result);
}

CTEST(colorcheck, test3)
{
    // Given
    char* figure = new char[2];
    figure[0] = 'N';
    figure[1] = 'w';
    // When
    const int result = colorcheck(figure);
    // Then
    const int expected = 0;

    // Test
    ASSERT_EQUAL(expected, result);
}

CTEST(colorcheck, test4)
{
    // Given
    char* figure = new char[2];
    figure[0] = 'B';
    figure[1] = 'w';
    // When
    const int result = colorcheck(figure);
    // Then
    const int expected = 0;

    // Test
    ASSERT_EQUAL(expected, result);
}

CTEST(colorcheck, test5)
{
    // Given
    char* figure = new char[2];
    figure[0] = 'K';
    figure[1] = 'w';
    // When
    const int result = colorcheck(figure);
    // Then
    const int expected = 0;

    // Test
    ASSERT_EQUAL(expected, result);
}

CTEST(colorcheck, test6)
{
    // Given
    char* figure = new char[2];
    figure[0] = 'Q';
    figure[1] = 'w';
    // When
    const int result = colorcheck(figure);
    // Then
    const int expected = 0;

    // Test
    ASSERT_EQUAL(expected, result);
}

CTEST(colorcheck, test7)
{
    // Given
    char* figure = new char[2];
    figure[0] = 'P';
    figure[1] = 'b';
    // When
    const int result = colorcheck(figure);
    // Then
    const int expected = 1;

    // Test
    ASSERT_EQUAL(expected, result);
}

CTEST(colorcheck, test8)
{
    // Given
    char* figure = new char[2];
    figure[0] = 'R';
    figure[1] = 'b';
    // When
    const int result = colorcheck(figure);
    // Then
    const int expected = 1;

    // Test
    ASSERT_EQUAL(expected, result);
}

CTEST(colorcheck, test9)
{
    // Given
    char* figure = new char[2];
    figure[0] = 'N';
    figure[1] = 'b';
    // When
    const int result = colorcheck(figure);
    // Then
    const int expected = 1;

    // Test
    ASSERT_EQUAL(expected, result);
}

CTEST(colorcheck, test10)
{
    // Given
    char* figure = new char[2];
    figure[0] = 'B';
    figure[1] = 'b';
    // When
    const int result = colorcheck(figure);
    // Then
    const int expected = 1;

    // Test
    ASSERT_EQUAL(expected, result);
}

CTEST(colorcheck, test11)
{
    // Given
    char* figure = new char[2];
    figure[0] = 'K';
    figure[1] = 'b';
    // When
    const int result = colorcheck(figure);
    // Then
    const int expected = 1;

    // Test
    ASSERT_EQUAL(expected, result);
}

CTEST(colorcheck, test12)
{
    // Given
    char* figure = new char[2];
    figure[0] = 'Q';
    figure[1] = 'b';
    // When
    const int result = colorcheck(figure);
    // Then
    const int expected = 1;

    // Test
    ASSERT_EQUAL(expected, result);
}

CTEST(command_recognition, test1)
{
    // Given
    const string comand_move = "a7-a5";
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
    const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(command_recognition, test2)
{
    // Given
    const string comand_move = "a7-a6";
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
    const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(command_recognition, test3)
{
    // Given
    const string comand_move = "b7-b5";
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
    const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(command_recognition, test4)
{
    // Given
    const string comand_move = "b7-b6";
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
    const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(command_recognition, test5)
{
    // Given
    const string comand_move = "c7-c5";
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
    const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(command_recognition, test6)
{
    // Given
    const string comand_move = "c7-c6";
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
    const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(command_recognition, test7)
{
    // Given
    const string comand_move = "d7-d5";
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
    const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(command_recognition, test8)
{
    // Given
    const string comand_move = "d7-d6";
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
    const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(command_recognition, test9)
{
    // Given
    const string comand_move = "e7-e5";
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
    const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(command_recognition, test10)
{
    // Given
    const string comand_move = "e7-e6";
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
    const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(command_recognition, test11)
{
    // Given
    const string comand_move = "f7-f5";
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
    const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(command_recognition, test12)
{
    // Given
    const string comand_move = "f7-f6";
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
    const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(command_recognition, test13)
{
    // Given
    const string comand_move = "g7-g5";
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
    const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(command_recognition, test14)
{
    // Given
    const string comand_move = "g7-g6";
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
    const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(command_recognition, test15)
{
    // Given
    const string comand_move = "h7-h5";
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
    const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(command_recognition, test16)
{
    // Given
    const string comand_move = "h7-h6";
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    int *pi1 = &i1, *pi2 = &i2, *pj1 = &j1, *pj2 = &j2;
    const bool result = command_recognition(comand_move, pi1, pi2, pj1, pj2);

    // Then
    ASSERT_FALSE(result);
}

CTEST(command_convert, test1)
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

CTEST(command_convert, test2)
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

CTEST(command_convert, test3)
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

CTEST(command_convert, test4)
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

CTEST(command_convert, test5)
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

CTEST(command_convert, test6)
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

CTEST(command_convert, test7)
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

CTEST(command_convert, test8)
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

CTEST(command_convert, test9)
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

CTEST(command_convert, test10)
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

CTEST(command_convert, test11)
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

CTEST(command_convert, test12)
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

CTEST(command_convert, test13)
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

CTEST(command_convert, test14)
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

CTEST(command_convert, test15)
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

CTEST(command_convert, test16)
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