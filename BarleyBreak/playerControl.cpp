#include "header.h"

using namespace std;
using namespace BarleyBreak;

playerControl::playerControl()
{
	field = new area();
}

playerControl::playerControl(area *field)
{
	this->field = new area(*field);
}

playerControl::~playerControl()
{
	delete field;
}

bool playerControl::launchControl()
{
	int *keystore = new int(-1);
	bool *update = new bool(true);
	while (*keystore != KC_ESCAPE)
	{
		if (*update)
		{
			system("cls");
			field->showArea();
		}
		if (field->isWinnerPosition())
			return true;
		*keystore = _getch();
		switch (*keystore)
		{
		case KC_ARROW_LEFT: field->moveLeft(); *update = true; break;
		case KC_ARROW_UP: field->moveUp(); *update = true; break;
		case KC_ARROW_RIGHT: field->moveRight(); *update = true; break;
		case KC_ARROW_DOWN: field->moveDown(); *update = true; break;
		default: *update = false;
		}
	}
	delete keystore;
	delete update;
	return false;
}

void playerControl::save(string getterNameOfSave, string errorMsgNameOfSave, string saveCompleted)
{
	char *forbiddenSymb = new char[10]
	{ '\\', '/', ':', '*', '?', '"', '<', '>', '|', '.' };
	bool *correctInput = new bool(false);
	string nameOfSave;
	while (!*correctInput)
	{
		cout << getterNameOfSave;
		cin >> nameOfSave;
		*correctInput = true;
		for (int i = 0; i < 10; ++i)
		{
			for (auto& symb : nameOfSave)
			{
				if (symb == forbiddenSymb[i])
				{
					*correctInput = false;
					break;
				}
			}

			if (!*correctInput)
			{
				cout << errorMsgNameOfSave << endl;
				for (int i = 0; i < 10; ++i)
					cout << forbiddenSymb[i] << ' ';
				cout << endl;
				break;
			}
		}
	}
	delete[] forbiddenSymb;
	delete correctInput;

	field->save(nameOfSave);
	cout << saveCompleted << endl;
	system("pause");
}