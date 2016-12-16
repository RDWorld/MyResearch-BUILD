// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <algorithm>
using namespace std;


//0=48, 9 = 57
//a=97 , h = 104

int checkPOS(char *str)
{
 	int row = str[0];
	int col = str[1];
	int nRetVal = 0;

	if (row <'a' || row >'h')
		return -1;
	if (col <'1' || col >'8')
		return -1;

	return nRetVal;
}

void possibleMoveKnight(char *str)
{	
	if (!checkPOS(str))
	{	
		int row = str[0];
		int col = str[1];


		if (row-2 >= 'a' && col-1 >='1')
		{
			printf("%c%c ",row-2,col-1);
		}
		if (row-2 >= 'a'  && col+1 <='8')
		{
			printf("%c%c ", row-2, col+1);
		}

		if (row+2 <= 'h' && col-1 >='1')
		{
			printf("%c%c ", row+2, col-1);
		}
		if (row+2 <= 'h' && col+1 <= '8')
		{
			printf("%c%c ", row+2, col+1);
		}

		if (col+2 <= '8' && row -1 >= 'a')
		{
			printf("%c%c ", row-1,col+2 );
		}
		if (col+2 <= '8' && row+1 <= 'h')
		{
			printf("%c%c ", row+1,col+2 );
		}

		if (col-2 >= '1' && row+1 <= 'h')
		{
			printf("%c%c ", row+1,col-2);
		}
		if (col-2 >= '1' && row-1 >= 'a')
		{
			printf("%c%c ", row-1,col-2);
		}

	}
}

void possibleMoveRook(char *str)
{
	if (!checkPOS(str))
	{	
		int row = str[0];
		int col = str[1];

		for (int c = col-1; c >= '1'; c--)
			printf("%c%c ", row,c);

		for (int c = col+1; c <= '8'; c++)
			printf("%c%c ", row,c);

		for (int r= row-1; r >= 'a'; r--)
			printf("%c%c ", r,col);

		for (int r= row+1; r <= 'h'; r++)
			printf("%c%c ", r,col);
	}
}

void possibleMoveQueen(char *str)
{
	possibleMoveRook(str);
	
	if (!checkPOS(str))
	{	
		int row = str[0];
		int col = str[1];

		int tmpR, tmpC;

		for (tmpC = col-1, tmpR = row-1; tmpC >= '1' && tmpR <= 'h'; tmpC--,tmpR--)
			printf("%c%c ", tmpR,tmpC);

		for (tmpC = col+1, tmpR = row+1; tmpC <= '8' && tmpR <= 'h'; tmpC++, tmpR++)
			printf("%c%c ", tmpR,tmpC);

		for (tmpR= row-1, tmpC = col+1; tmpR >= 'a' && tmpC >='1'; tmpR--, tmpC++)
			printf("%c%c ", tmpR,tmpC);

		for (tmpR= row+1, tmpC = col-1; tmpR <= 'h' && tmpC >='1'; tmpR++, tmpC--)
			printf("%c%c ", tmpR,tmpC);

	}
}
char randomPos[][3] = {"b2", "d2", "b5", "d5", "c7", "e7", "h2", "h5"};

int GetMostDistantTileLocation(char* originPoint)
{
	int MaxCount[9];
	int nIdx;

	if (!checkPOS(originPoint))
	{
		int originRow = originPoint[0];
		int originCol = originPoint[1];
		int Cnt=0;
		for(nIdx=0; nIdx < 9 ; nIdx++)
		{
			Cnt =0;
			int randRow = randomPos[nIdx][0];
			int randCol = randomPos[nIdx][1];

			if (originRow > randRow)
				Cnt += originRow - randRow;
			else
				Cnt += randRow - originRow;

			if (originCol > randCol)
				Cnt += originCol - randCol;
			else
			    Cnt += randCol - originCol;		

			MaxCount[nIdx]=Cnt;
		}
	}
	printf("Distance between originPoint and all Random location\r\n ");
	
	for (nIdx =0; nIdx< 8; nIdx++)
		printf("%s to %s is %d\r\n", originPoint, randomPos[nIdx], MaxCount[nIdx]); 

   const int N = sizeof(randomPos) / sizeof(int);

   int nLoc = distance(randomPos, max_element(randomPos, randomPos + N));

   return nLoc-1;

}

char **Moves;

//Assuming Knight is located at originPoint
void GetOptimalMove(char *randomPos, char* originPoint)
{
	int randomRow = randomPos[0];
	int randomCol = randomPos[1];

	int originRow = originPoint[0];
	int originCol = originPoint[1];
	
	Moves = new char*[100];
	for (int i=0; i < 100; i++)
	{
		Moves[i] = new char[1000];
		memset(Moves[i], 0, 1000);
	}
	
	int idx=0, jdx=0;
	char pos[3];
	for( ; originRow!=randomRow && originCol!=randomCol;)
	{
		if (originRow-2 >= 'a' &&  originCol-1 >='1')
		{
			sprintf_s(pos, "%c%c", originRow-2, originCol-1);
			if (!strstr(Moves[idx], pos))
			{
				originRow -=2;
				originCol -=1;
				Moves[idx][jdx++]=originRow;
				Moves[idx][jdx++]=originCol;
				Moves[idx][jdx++]=' ';
			}
		}
		if (originRow-2 >= 'a' && originCol+1 <= '8')
		{
			sprintf_s(pos, "%c%c", originRow-2, originCol+1);
			if (!strstr(Moves[idx], pos))
			{
				originRow -= 2;
				originCol += 1;
				Moves[idx][jdx++]=originRow;
				Moves[idx][jdx++]=originCol;
				Moves[idx][jdx++]=' ';
			}
		}

		if (originRow+2 <= 'h' && originCol-1 >= '1')
		{
			sprintf_s(pos, "%c%c", originRow+2, originCol-1);
			if (!strstr(Moves[idx], pos))
			{
				originRow += 2;
				originCol -= 1;
				Moves[idx][jdx++]=originRow;
				Moves[idx][jdx++]=originCol;
				Moves[idx][jdx++]=' ';
			}
		}
		if (originRow+2 <= 'h' && originCol+1 <= '8')
		{
			sprintf_s(pos, "%c%c", originRow+2, originCol+1);
			if (!strstr(Moves[idx], pos))
			{
				originRow += 2;
				originCol += 1;
				Moves[idx][jdx++]=originRow;
				Moves[idx][jdx++]=originCol;
				Moves[idx][jdx++]=' ';
			}
		}

		if (originCol+2 <= '8' && originRow-1 >= 'a')
		{
			sprintf_s(pos, "%c%c", originCol+2, originRow-1);
			if (!strstr(Moves[idx], pos))
			{
				originCol +=2;
				originRow -=1;
				Moves[idx][jdx++]=originRow;
				Moves[idx][jdx++]=originCol;
				Moves[idx][jdx++]=' ';
			}
		}
		if (originCol+2 <= '8' && originRow+1 <= 'h')
		{
			sprintf_s(pos, "%c%c", originCol+2, originRow+1);
			if (!strstr(Moves[idx], pos))
			{
				originCol += 2;
				originRow += 1;
				Moves[idx][jdx++]=originRow;
				Moves[idx][jdx++]=originCol;
				Moves[idx][jdx++]=' ';
			}
		}

		if (originCol-2 >= '1' && originRow+1 <= 'h')
		{
			sprintf_s(pos, "%c%c", originCol-2, originRow+1);
			if (!strstr(Moves[idx], pos))
			{
				originCol -= 2;
				originRow += 1;
				Moves[idx][jdx++]=originRow;
				Moves[idx][jdx++]=originCol;
				Moves[idx][jdx++]=' ';
			}
		}
		if (originCol-2 >= '1' && originRow-1 >= 'a')
		{
			sprintf_s(pos, "%c%c", originRow-1, originCol-2);
			if (!strstr(Moves[idx], pos))
			{
			originCol -= 2;
			originRow -= 1;
			Moves[idx][jdx++]=originRow;
			Moves[idx][jdx++]=originCol;
			Moves[idx][jdx++]=' ';
			}
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf(" Moves of Knight\r\n");
	possibleMoveKnight("d2");

	printf("\r\n\r\n Moves of Rook\r\n");
	possibleMoveRook("d2");

	printf("\r\n\r\n Moves of Queen\r\n");
	possibleMoveQueen("d2");
	
	char *originPoint = "e1";

	int loc = GetMostDistantTileLocation(originPoint);

	GetOptimalMove(randomPos[loc], originPoint);

	
}
