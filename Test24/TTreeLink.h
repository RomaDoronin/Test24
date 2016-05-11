#pragma once
#include <C:\Users\Roma\Desktop\HierarchicalList-master2\Stack\TStack.h>
#include <fstream>
#include <string>
#include <iostream>
#include "TTree.h"

using namespace std;

const int MaxLen = 9;

class TTreeLink;

class TTree;

class TTreeLink
{
public:

	// ������ �������� ��������� �������� ���� � ������� �������
	int battlefield[MaxLen];

	// ���������� �������� ��� �������, ������������ ����������� ������ �� ��� ����
	int weight;

	// ���������� �������� ��������� �������� ���� � ������� ������� � ���� �����
	int position;

	// ��������� �� ��������� "�������" � ������ "������"
	TTreeLink *pNext;

	// ��������� �� ������� "�������"
	TTreeLink *pDown;

	TTreeLink()
	{
		pNext = NULL;
		pDown = NULL;

		for (int i = 0; i < 9; i++)
		{
			battlefield[i] = 0;
		}

		weight = 10;
		// "1" - ������ ��� ���� ������
		// "2" - ������ ��� � ���� ����� �
		// "3" - ������ ��� � ���� ����� � 
		position = 111111111;
	}

	TTreeLink(int _weight, int _position, TTreeLink *_pNext = NULL, TTreeLink *_pDown = NULL)
	{
		pNext = _pNext;
		pDown = _pDown;

		position = _position;
		weight = _weight;

		for (int i = 8; i >= 0; i--)
		{
			battlefield[i] = _position % 10;
			_position = _position / 10;
		}
	}

	~TTreeLink(){}
};

