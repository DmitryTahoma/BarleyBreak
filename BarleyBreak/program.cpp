#include "header.h"

using namespace std;
using namespace BarleyBreak;

program::program()
{
	p = nullptr;
	Settings = new settings();
	exit = new bool(false);
	uploadMainMenu();
	langId = new unsigned short(Settings->getSelectedLanguageId());
	updateLang = new bool(false);
}

void program::uploadMainMenu()
{
	mainMenu = new menu(new string[4]
	{
		Settings->getSetOfWords("MainMenuItem1"),
		Settings->getSetOfWords("MainMenuItem2"),
		Settings->getSetOfWords("MainMenuItem3"),
		Settings->getSetOfWords("MainMenuItem4")
	}, 4);
}

program::~program()
{
	if (p != nullptr)
		delete p;
	delete Settings;
	delete exit;
	delete mainMenu;
	delete langId;
	delete updateLang;
}

void program::start()
{
	unsigned int *selectedItem = nullptr;
	while (!*exit)
	{
		if (*updateLang)
		{
			*updateLang = false;
			delete mainMenu;
			uploadMainMenu();
		}

		if (selectedItem != nullptr)
			delete selectedItem;
		selectedItem = new unsigned int(getUsedMenu());
		
		switch (*selectedItem)
		{
		case 0: startOrResume(); break;
		case 1: updateSettings(); break;
		case 2: loadSave(); break;
		case 3: *exit = true; break;
		case 4: p->save(
					Settings->getSetOfWords("GetterNameOfSave"),
					Settings->getSetOfWords("ErrorMsgNameOfSave"), 
					Settings->getSetOfWords("SaveCompleted")
				); break;
		case 5: createNewGame(); break;
		}
	}
}

unsigned int program::getUsedMenu()
{
	string selectedItem = *((*mainMenu)[mainMenu->use()]);
	if (selectedItem == Settings->getSetOfWords("MainMenuItem1Updated"))
		return 0;
	else if (selectedItem == Settings->getSetOfWords("MainMenuItem2"))
		return 1;
	else if (selectedItem == Settings->getSetOfWords("MainMenuItem3"))
		return 2;
	else if (selectedItem == Settings->getSetOfWords("MainMenuNewItem"))
		return 4;
	else if (selectedItem == Settings->getSetOfWords("MainMenuItem1"))
		return 5;
	return 3;
}

void program::startOrResume()
{
	if (p == nullptr)
	{
		createNewGame();
		return;
	}
	play();
}

void program::updateSettings()
{
	Settings->showMenuSettings();
	if (*langId != Settings->getSelectedLanguageId())
	{
		*langId = Settings->getSelectedLanguageId();
		*updateLang = true;
	}
}

void program::loadSave()
{
	vector<string> savesV = areaStream::getAvailableSaves("Saves\\*.bin");
	const int sizeV = savesV.size();

	string *savesA = new string[sizeV + 1];
	for (int i = 0; i < sizeV; ++i)
		savesA[i] = savesV[i];
	savesA[sizeV] = Settings->getSetOfWords("SettingsMenuItem4");

	menu *savesMenu = new menu(savesA, sizeV + 1);
	unsigned int *resMenuItem = new unsigned int(savesMenu->use("Choose save to load: "));
	if (*resMenuItem != sizeV)
	{
		if (p != nullptr)
			delete p;
		stringstream ss;
		ss << "Saves\\" << savesV[*resMenuItem] << ".bin";
		p = new playerControl(new area(ss.str()));
		*((*mainMenu)[0]) = Settings->getSetOfWords("MainMenuItem1Updated");
		if(*((*mainMenu)[3]) != Settings->getSetOfWords("MainMenuNewItem"))
			mainMenu->addItem(Settings->getSetOfWords("MainMenuNewItem"), 2);

		play();
	}

	delete savesMenu;
}

void program::play()
{
	if (p->launchControl())
	{
		mainMenu->removeItem(Settings->getSetOfWords("MainMenuItem1"));
		mainMenu->addItem(Settings->getSetOfWords("MainMenuItem1"), 0);
		mainMenu->removeItem(Settings->getSetOfWords("MainMenuNewItem"));
		mainMenu->removeItem(Settings->getSetOfWords("MainMenuItem1Updated"));
		mainMenu->removeItem(Settings->getSetOfWords("MainMenuNewItem"));
	}
}

void program::createNewGame()
{
	if (p != nullptr)
		delete p;
	p = new playerControl();

	*((*mainMenu)[0]) = Settings->getSetOfWords("MainMenuItem1Updated");
	if(*((*mainMenu)[3]) != Settings->getSetOfWords("MainMenuNewItem")
		&& (mainMenu->getCount() <= 4 || *((*mainMenu)[4]) != Settings->getSetOfWords("MainMenuNewItem")))
		mainMenu->addItem(Settings->getSetOfWords("MainMenuNewItem"), 2);
	if (*(*mainMenu)[1] != Settings->getSetOfWords("MainMenuItem1"))
		mainMenu->addItem(Settings->getSetOfWords("MainMenuItem1"), 0);

	play();
}