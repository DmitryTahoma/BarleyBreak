#include "header.h"

using namespace std;
using namespace BarleyBreak;

area::area()
{
	items = new short*[4];
	for (int i = 0; i < 4; ++i)
		items[i] = new short[4];

	short *counter = new short(0);
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			items[i][j] = ++*counter % 16;
	delete counter;

	mixMe(new unsigned int(256));
}

area::area(string filePath)
{
	areaStream *as = new areaStream(filePath);
	items = as->loadFromFile();
	delete as;
}

area::~area()
{
	for (int i = 0; i < 4; ++i)
		delete[] items[i];
	delete[] items;
}

void area::mixMe(unsigned int *countMixing)
{
	int x = 3, y = 3;
	for (int i = 0; i < (int)*countMixing; ++i)
	{
		short dir = rand() % 4;
		int x2 = x;
		int y2 = y;
		switch (dir)
		{
			default: ++x2; break;
			case 1: --x2; break;
			case 2: ++y2; break;
			case 3: --y2; break;
		}

		if (x2 >= 0 && x2 < 4 && y2 >= 0 && y2 < 4)
		{
			swap(items[x][y], items[x2][y2]);
			x = x2;
			y = y2;
		}
	}
	delete countMixing;
}

void area::showArea()
{
	cout << "|----|----|----|----|\n";
	for (int i = 0; i < 4; ++i, cout << "\n|----|----|----|----|\n")
		for (int j = 0; j < 4; ++j)
		{
			if (j == 0)
			{
				cout << "| " << (items[i][j] == 0 ? " " : "");
				if (items[i][j] != 0)
					cout << items[i][j];
				cout << ((items[i][j] - 9 > 0) ? "" : " ") << ' ';
			}
			else
			{
				cout << "| " << (items[i][j] == 0 ? " " : "");
				if (items[i][j] != 0) 
					cout << items[i][j];
				cout << ((items[i][j] - 9 > 0) ? "" : " ") << ' ';
			}
			if (j == 3)
				cout << "|";
		}
}

void area::getMainItem(short *x, short *y)
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (items[i][j] == 0)
			{
				*x = i;
				*y = j;
			}
}

void area::moveUp()
{
	short *x = new short();
	short *y = new short();
	getMainItem(x, y);
	if (*x != 0)
		swap(items[*x][*y], items[*x - 1][*y]);
	delete x;
	delete y;
}

void area::moveLeft()
{
	short *x = new short();
	short *y = new short();
	getMainItem(x, y);
	if (*y != 0)
		swap(items[*x][*y], items[*x][*y - 1]);
	delete x;
	delete y;
}

void area::moveDown()
{
	short *x = new short();
	short *y = new short();
	getMainItem(x, y);
	if (*x != 3)
		swap(items[*x][*y], items[*x + 1][*y]);
	delete x;
	delete y;
}

void area::moveRight()
{
	short *x = new short();
	short *y = new short();
	getMainItem(x, y);
	if (*y != 3)
		swap(items[*x][*y], items[*x][*y + 1]);
	delete x;
	delete y;
}

bool area::isWinnerPosition()
{
	short *checkVar = new short(0);
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			if (*checkVar == 15)
				*checkVar = -1;
			++*checkVar;
			if (*checkVar != items[i][j])
			{
				delete checkVar;
				return false;
			}
		}
	delete checkVar;
	return true;
}

void area::save(string saveName)
{
	stringstream fileName;
	fileName << "Saves/" << saveName << ".bin";
	string res;
	fileName >> res;
	areaStream *as = new areaStream(res);
	as->saveToFile(items);
	delete as;
}