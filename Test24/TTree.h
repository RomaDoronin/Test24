#pragma once
#include "TTreeLink.h"
using namespace std;

class TTreeLink;

class TTree
{
	// ��������� �� ������ ������� ������ - "������"
	TTreeLink *pFirst;

	// ��������� �� ������� ������� ������
	TTreeLink *pCurr;

	// ���� ��� ����������� ����, ������� ������ pCurr � �������� �� ����
	TStack <TTreeLink*> path;

public:

	TTree(TTreeLink *_pFirst = NULL) : path(100)
	{
		if (_pFirst != 0)
			pFirst = pCurr = _pFirst;
		else
		{
			pCurr = pFirst;
		}
	}

	~TTree(){}

	//--------------------------------------------
	// ������� ��� ������� � ��������� BattleField

	int GetBattleField(int i);

	void SetBattleField(int num);

	//--------------------------------------------
	// ������� ��������� �� ������

	// ������� �� ��������� pNext
	void GoNextLink();

	// ������� �� ��������� pDown
	void GoDownLink();

	// ��������� � ���������� ���������
	void GoPrevLink();

	// ������� � "�����"
	void GoFirstLink();

	// (4) ������� ���������� ������ � ������
	void IncNextLine(int _str);

	void IncNextSection(int _str);

	void IncDownLine(int _str);

	void IncDownSection(int _str);

	// (2) ������� �������� ������ � ������
	void DelNextLine();

	void DelDownLine();

	//--------------------------------------------
	// ������� ��� ������ ������
	void Reset();

	void GoNext();

	bool IsEnd();

	//--------------------------------------------
	// ������� ��� ������ � �������

	TTreeLink* ReadSection(ifstream &ifs);

	void ReadFile(char* fname);

	void SaveSection(TTreeLink*p, ofstream &ofs);

	void SaveText(char* fname);

	//--------------------------------------------
	// ������� ������������ ��������� �� pFirst
	TTreeLink* GetpFirst();

	// (2) ������� ������������� ������ ������� 
	void Allfilling();

	void filling(TTreeLink* p, int count);

	// ������� ����������� int ������ � ���� �����
	int ToInt(int *tmp);

	//--------------------------------------------
	// ������� ����������� ��� ������� ������������ �� ����� ����
	void IncWeight(int mn);

	// ������� ��������� �� ����� ��� �������
	void DontPush();

	// ������� ���������� ���� ������ ����
	void BotMoveTree(int &x, int &y);
};
