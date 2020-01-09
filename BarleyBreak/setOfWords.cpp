#include "header.h"

using namespace std;
using namespace BarleyBreak;

setOfWords::setOfWords(unsigned int countLangueages, unsigned int selectedLanguage)
{		
	countLangs = new unsigned int(countLangueages);
	selectedLang = new unsigned int(selectedLanguage);
	countSet = new unsigned int(34);
	sets = new string*[*countLangs];
	for (int i = 0; i < (int)*countLangs; ++i)
		sets[i] = new string[*countSet];
	// EN
	sets[0][0]  = "New Game";
	sets[0][1]  = "Settings";
	sets[0][2]  = "Load";
	sets[0][3]  = "Exit";
	sets[0][4]  = "Resume";
	sets[0][5]  = "Save";
	sets[0][6]  = "Change font color";
	sets[0][7]  = "Change background color";
	sets[0][8]  = "Change language";
	sets[0][9]  = "Back to Main menu";
	sets[0][10] = "Select the settings you want to change";
	sets[0][11] = "Black";
	sets[0][12] = "Dark blue";
	sets[0][13] = "Green";
	sets[0][14] = "Blue";
	sets[0][15] = "Red";
	sets[0][16] = "Purple";
	sets[0][17] = "Yellow";
	sets[0][18] = "White";
	sets[0][19] = "Gray";
	sets[0][20] = "Light dark blue";
	sets[0][21] = "Light green";
	sets[0][22] = "Light light blue";
	sets[0][23] = "Light red";
	sets[0][24] = "Light purple";
	sets[0][25] = "Light yellow";
	sets[0][26] = "Bright white";
	sets[0][27] = "Select ";
	sets[0][28] = "font color";
	sets[0][29] = "background color";
	sets[0][30] = "Font color should not be the same as the background color.";
	sets[0][31] = "Enter name save: ";
	sets[0][32] = "The save name cannot contain the following characters:";
	sets[0][33] = "Saving done.";
	// en
	// RU
	sets[1][0] = "����� ����";
	sets[1][1] = "���������";
	sets[1][2] = "���������";
	sets[1][3] = "�����";
	sets[1][4] = "����������";
	sets[1][5] = "���������";
	sets[1][6] = "�������� ���� ������";
	sets[1][7] = "�������� ���� ����";
	sets[1][8] = "�������� ����";
	sets[1][9] = "����� � ������� ����";
	sets[1][10] = "�������� ���������, ������� ������ ��������";
	sets[1][11] = "������";
	sets[1][12] = "�����";
	sets[1][13] = "�������";
	sets[1][14] = "�������";
	sets[1][15] = "�������";
	sets[1][16] = "�������";
	sets[1][17] = "������";
	sets[1][18] = "�����";
	sets[1][19] = "�����";
	sets[1][20] = "������-�����";
	sets[1][21] = "������-�������";
	sets[1][22] = "������-�������";
	sets[1][23] = "������-�������";
	sets[1][24] = "������-�������";
	sets[1][25] = "������-������";
	sets[1][26] = "����-�����";
	sets[1][27] = "�������� ";
	sets[1][28] = "���� ������";
	sets[1][29] = "���� ����";
	sets[1][30] = "���� ������ �� ������ ��������� � ������ ����.";
	sets[1][31] = "������� �������� ����������: ";
	sets[1][32] = "���������� �� ����� ��������� ��������� �������:";
	sets[1][33] = "���������� ���������.";
	// ru
	// UA
	sets[2][0] = "���� ���";
	sets[2][1] = "���������";
	sets[2][2] = "�����������";
	sets[2][3] = "�����";
	sets[2][4] = "����������";
	sets[2][5] = "��������";
	sets[2][6] = "������ ���� ������";
	sets[2][7] = "������ ���� ����";
	sets[2][8] = "������ ����";
	sets[2][9] = "����� � ������ ����";
	sets[2][10] = "������ ���������, �� ������� ������";
	sets[2][11] = "������";
	sets[2][12] = "����";
	sets[2][13] = "�������";
	sets[2][14] = "�������";
	sets[2][15] = "��������";
	sets[2][16] = "˳�����";
	sets[2][17] = "������";
	sets[2][18] = "�����";
	sets[2][19] = "ѳ���";
	sets[2][20] = "�����-����";
	sets[2][21] = "�����-�������";
	sets[2][22] = "�����-�������";
	sets[2][23] = "�����-��������";
	sets[2][24] = "�����-������";
	sets[2][25] = "�����-������";
	sets[2][26] = "�������-����";
	sets[2][27] = "������ ";
	sets[2][28] = "���� ������";
	sets[2][29] = "���� ����";
	sets[2][30] = "���� ������ �� ������� �������� � �������� ����.";
	sets[2][31] = "������ ����� ����������: ";
	sets[2][32] = "���������� �� ���� ������ ������� �������:";
	sets[2][33] = "���������� ��������.";
	// ua
}

setOfWords::~setOfWords()
{
	delete countSet;
	for (int i = 0; i < (int)*countLangs; ++i)
		delete[] sets[i];
	delete[] sets;
	delete countLangs;
	delete selectedLang;
}

string setOfWords::operator[](int n)
{
	return sets[*selectedLang][n];
}

unsigned int setOfWords::getCountSets()
{
	return *countSet;
}