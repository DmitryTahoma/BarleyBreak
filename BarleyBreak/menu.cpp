#include "header.h"

using namespace std;
using namespace BarleyBreak;

menu::menu(string items[], unsigned int countItems)
{
	count = new unsigned int(countItems);
	this->items = new string[*count];
	for (int i = 0; i < (int)*count; ++i)
	{
		this->items[i] = items[i];
	}
}

menu::~menu()
{
	delete count;
	delete[] items;
}

unsigned int menu::use(string predText) const
{
	int *keyStore = new int(-1);
	int *page = new int(0);
	bool *update = new bool(true);

	while (*keyStore != KC_ENTER)
	{
		if(*update)
			showMenu(page, predText);
		*keyStore = _getch();
		switch (*keyStore)
		{
		case KC_ARROW_UP: *page == 0 ? *page = *count - 1 : --*page; *update = true; break;
		case KC_ARROW_DOWN: *page == *count - 1 ? *page = 0 : ++*page; *update = true; break;
		default: *update = false;
		}
	}

	system("cls");
	delete keyStore;
	delete update;
	return *page;
}

void menu::showMenu(int *p, string predText) const
{
	system("cls");
	cout << predText << endl;

	for (int i = 0; i < (int)*count; i++)
	{
		if (*p == i)
		{
			cout << ">>";
		}
		cout << '\t' << items[i] << endl;
	}
}

string* menu::operator[](int n)
{
	if (n >= (int)*count || n < 0)
		return nullptr;
	return &items[n];
}

void menu::addItem(string value, int position)
{
	if (position <= -1)
		position = 0;
	else if (position > (int)*count)
		position = *count;
	else
		position++;
	
	string *newItems = new string[*count + 1];
	newItems[position] = value;

	bool *_throw = new bool(false);
	for (int i = 0; i < (int)*count; ++i)
	{
		if (i == position)
			*_throw = true;
		newItems[i + (int)*_throw] = items[i];
	}
	
	delete _throw;
	delete[] items;
	++*count;
	items = newItems;
}

void menu::removeItem(string item)
{
	for (int i = 0; i < (int)*count; ++i)
		if (items[i] == item)
			return menu::removeItem(i);
}

void menu::removeItem(unsigned int index)
{
	if (index >= *count)
		return;

	string* newItems = new string[*count - 1];
	bool *_throw = new bool(false);
	for (int i = 0; i < (int)*count - 1; ++i)
	{
		if (i == index)
			*_throw = true;
		newItems[i] = items[i + (int)*_throw];
	}

	delete _throw;
	delete[] items;
	--*count;
	items = newItems;
}

unsigned int menu::getCount()
{
	return *count;
}