#pragma once
#include <string>
#include "TTree.h"

using namespace std;

ref class TZeroOne3
{

private:
	// ������ �������� ������� ��������� �������� ����
	int *gamebox;

	// ������������� ������
	int index;

public:
	// ������ �������
	TTree *Tree;

	TZeroOne3()
	{
		index = 0;	
		Tree = new TTree;

		gamebox = new int[9];
		for (int i = 0; i < 9; i++)
			gamebox[i] = 1;

		Tree->ReadFile("text.txt");
		Tree->Allfilling();
		Tree->GoFirstLink();
	}

	~TZeroOne3()
	{
		//delete[] Tree;
	}

private:
	// ������� ������������ �� ����������� ������ ������� gamebox
	int idMove(int x, int y)
	{
		if ((x == 0) && (y == 0))
			return 0;
		else if ((x == 0) && (y == 1))
			return 1;
		else if ((x == 0) && (y == 2))
			return 2;
		else if ((x == 1) && (y == 0))
			return 3;
		else if ((x == 1) && (y == 1))
			return 4;
		else if ((x == 1) && (y == 2))
			return 5;
		else if ((x == 2) && (y == 0))
			return 6;
		else if ((x == 2) && (y == 1))
			return 7;
		else if ((x == 2) && (y == 2))
			return 8;
		else return -1;
	}

public:
	// ������� ������ ������ � gamebox[i]
	int GetGamebox(int i)
	{
		return gamebox[i];
	}

	// ������� ����������� ������ gamebox �� ����� ����
	void TZeroOne3::DoMove(int x, int y, char XO)
	{
		// ���������� ������������ �������� �� ���� ������� ��� �����
		int XOi;
		// XO = 1 - ����� | XO = 2 - ������� | XO = 3 - �����
		if (XO == '_') XOi = 1;
		else if (XO == 'X') XOi = 2;
		else if (XO == 'O') XOi = 3;

		gamebox[idMove(x, y)] = XOi;
		
		Tree->GoDownLink();

		bool flag = true;

		while (flag)
		{
			flag = false;
			for (int i = 0; i < 9; i++)
				if (gamebox[i] != Tree->GetBattleField(i))
				{
					flag = true;
					break;
				}
			if (flag)
			{
				Tree->GoNextLink();
				Tree->DontPush();
			}
		}

	}

	// ������� ������������ ������ �� ����
	bool IsEmpty(int x, int y)
	{
		if (gamebox[idMove(x, y)] == 1) 
			return true;
		else 
			return false;
	}

	// ������� ������������ ���� ��� ���� ������
	bool IsFull()
	{
		for (int i = 0; i < 9; i++)
			if (gamebox[i] == 1)
				return false;
		return true;
	}

	// ������� ������������ ����������
	int locality(int iLoc, int jLoc, int XO)
	{
		int k; // �������
		int flagi = 0, flagj = 0; // ����� ��� ����������� ������

		index++;

		// �������� ��������� � �����������
		for (k = 0; k < 3; k++)
		{
			if (gamebox[idMove(k, jLoc)] == XO) flagi++;
			if (gamebox[idMove(iLoc, k)] == XO) flagj++;
		}

		if ((flagi == 3) || (flagj == 3))
		{
			return XO;
		}

		flagi = 0;
		flagj = 0;

		// �������� ��������	
		if (((iLoc == 0) && (jLoc == 0)) || ((iLoc == 1) && (jLoc == 1)) || ((iLoc == 2) && (jLoc == 2)))
			for (k = 0; k < 3; k++)
				if (gamebox[idMove(k, k)] == XO) flagi++;

		if (((iLoc == 2) && (jLoc == 0)) || ((iLoc == 1) && (jLoc == 1)) || ((iLoc == 0) && (jLoc == 2)))
			for (k = 0; k < 3; k++)
				if (gamebox[idMove(2 - k, k)] == XO) flagj++;



		if ((flagi == 3) || (flagj == 3))
		{
			return XO;
		}
		else
			if (index != 9)
				return 0; // ������
			else
				return 3; // �����
	}

	// ������� ���������� ��� ����� ����
	void EndOfTheGame(int XO)
	{
		while (!Tree->IsEnd())
		{
			if (XO == 2)
				Tree->IncWeight(-1);
			else if (XO == 3)
				Tree->IncWeight(2);
			else
				Tree->IncWeight(1);
			Tree->GoPrevLink();
		}

		for (int i = 0; i < 9; i++)
			gamebox[i] = 1;
	}

	// ������� ��� ����������� ���������� ���� ��� ����
	void BotMove(int &x, int &y)
	{
		Tree->BotMoveTree(x, y);
	}
};


