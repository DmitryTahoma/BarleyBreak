#include "header.h"

using namespace std;
using namespace BarleyBreak;

settings::settings()
{
	countLangs = new unsigned short(3);
	languages = new string[3]
	{
		"en",
		"ru",
		"ua"
	};
	loadSettingsFromFile();
	sow = new setOfWords(*countLangs, getSelectedLanguageId());
	setsAssociations = new string[sow->getCountSets()];
	createAssotiations();
	useColorString();
}

settings::~settings()
{
	delete[] languages;
	delete countLangs;
	delete sow;
	delete[] setsAssociations;
	if (!isDefaultSettings())
		saveSettingsToFile();
}

void settings::saveSettingsToFile()
{
	ofstream fout("settings.txt");
	fout << language << '|' << fontColor << '|' << bgColor;
	fout.close();
}

void settings::loadSettingsFromFile()
{
	ifstream fin;
	fin.open("settings.txt");
	if (!fin)
		resetSettings();
	else
	{
		string loadedSettings;

		char *c = new char(fin.get());
		loadedSettings.push_back(*c);
		while (fin.good())
		{
			*c = fin.get();
			loadedSettings.push_back(*c);
		}
		delete c;

		int *distr1 = new int(loadedSettings.find_first_of('|'));
		int *distr2 = new int(loadedSettings.find_last_of('|'));

		for (int i = 0; i < *distr1; ++i)
			language.push_back(loadedSettings[i]);
		if (!existsLanguage(language))
		{
			resetSettings();
			return;
		}

		fontColor = loadedSettings[*distr1 + 1];

		bgColor = loadedSettings[*distr2 + 1];

		delete distr1;
		delete distr2;
	}
	fin.close();
}

void settings::setLanguage(string lang)
{
	if (existsLanguage(lang))
		language = lang;
}

void settings::setFontColor(char colorName)
{
	if (existsColor(colorName) && bgColor != colorName)
		fontColor = colorName;
}

void settings::setBgColor(char colorName)
{
	if (existsColor(colorName) && fontColor != colorName)
		bgColor = colorName;
}

void settings::useColorString()
{
	string str("color ");
	str.push_back(bgColor);
	str.push_back(fontColor);
	system(str.c_str());
	system("cls");
}

bool settings::isDefaultSettings()
{
	return fontColor == '7' && bgColor == '0' && language == "en";
}

void settings::resetSettings()
{
	fontColor = '7';
	bgColor = '0';
	language = "en";
}

bool settings::existsLanguage(string language)
{
	for (int i = 0; i < *countLangs; ++i) 
	{
		if (languages[i] == language)
		{
			return true;
		}
	}
	return false;
}

bool settings::existsColor(char colorName)
{

	switch (colorName)
	{
	default: return false;
	case '0': case '1': case '2': case '3': case '4': case '5':
	case '6': case '7': case '8': case '9': case 'a': case 'b':
	case 'c': case 'd': case 'e': case 'f': return true;
	}
}

void settings::showMenuSettings()
{
	menu *settingsMenu = new menu(new string[4]
		{
			getSetOfWords("SettingsMenuItem1"),
			getSetOfWords("SettingsMenuItem2"),
			getSetOfWords("SettingsMenuItem3"),
			getSetOfWords("SettingsMenuItem4")
		}, 4);
	bool exit = false;
	unsigned short *langId = new unsigned short(getSelectedLanguageId());
	bool *updateLang = new bool(false);

	while (!exit)
	{
		if (*updateLang)
		{
			*updateLang = false;
			delete settingsMenu;
			settingsMenu = new menu(new string[4]
				{
					getSetOfWords("SettingsMenuItem1"),
					getSetOfWords("SettingsMenuItem2"),
					getSetOfWords("SettingsMenuItem3"),
					getSetOfWords("SettingsMenuItem4")
				}, 4);
		}

		unsigned int *selectedItem = new unsigned int(settingsMenu->use(getSetOfWords("SettingsMenuPredText")));
		switch (*selectedItem)
		{
		case 0: case 1: showColorMenu(*selectedItem == 0); break;
		case 2: 
			showLanguageMenu(); 
			if (*langId != getSelectedLanguageId())
			{
				*langId = getSelectedLanguageId();
				*updateLang = true;
			}
			break;
		case 3: exit = true; break;
		}
		delete selectedItem;
	}
	delete settingsMenu;
	delete langId;
	delete updateLang;
}

unsigned short settings::getSelectedLanguageId()
{
	for (int i = 0; i < *countLangs; ++i)
		if (languages[i] == language)
			return i;
	return NULL;
}

void settings::createAssotiations()
{
	setsAssociations[0]  = "MainMenuItem1";
	setsAssociations[1]  = "MainMenuItem2";
	setsAssociations[2]  = "MainMenuItem3";
	setsAssociations[3]  = "MainMenuItem4";
	setsAssociations[4]  = "MainMenuItem1Updated";
	setsAssociations[5]  = "MainMenuNewItem";
	setsAssociations[6]  = "SettingsMenuItem1";
	setsAssociations[7]  = "SettingsMenuItem2";
	setsAssociations[8]  = "SettingsMenuItem3";
	setsAssociations[9]  = "SettingsMenuItem4";
	setsAssociations[10] = "SettingsMenuPredText";
	setsAssociations[11] = "ColorMenuItem1";
	setsAssociations[12] = "ColorMenuItem2";
	setsAssociations[13] = "ColorMenuItem3";
	setsAssociations[14] = "ColorMenuItem4";
	setsAssociations[15] = "ColorMenuItem5";
	setsAssociations[16] = "ColorMenuItem6";
	setsAssociations[17] = "ColorMenuItem7";
	setsAssociations[18] = "ColorMenuItem8";
	setsAssociations[19] = "ColorMenuItem9";
	setsAssociations[20] = "ColorMenuItem10";
	setsAssociations[21] = "ColorMenuItem11";
	setsAssociations[22] = "ColorMenuItem12";
	setsAssociations[23] = "ColorMenuItem13";
	setsAssociations[24] = "ColorMenuItem14";
	setsAssociations[25] = "ColorMenuItem15";
	setsAssociations[26] = "ColorMenuItem16";
	setsAssociations[27] = "ColorMenuPredTextPart1";
	setsAssociations[28] = "ColorMenuPredTextPart2.1";
	setsAssociations[29] = "ColorMenuPredTextPart2.2";
	setsAssociations[30] = "ColorMenuErrorText";
	setsAssociations[31] = "GetterNameOfSave";
	setsAssociations[32] = "ErrorMsgNameOfSave";
	setsAssociations[33] = "SaveCompleted";
	setsAssociations[34] = "WinCongratulation";
}

string settings::getSetOfWords(string key)
{
	for (int i = 0; i < (int)sow->getCountSets(); ++i)
		if (setsAssociations[i] == key)
			return (*sow)[i];
	return "ERROR in: string settings::getSetOfWords(string key)";
}

void settings::showColorMenu(bool isFont)
{
	menu colorMenu(new string[16]
		{
			getSetOfWords("ColorMenuItem1"),
			getSetOfWords("ColorMenuItem2"),
			getSetOfWords("ColorMenuItem3"),
			getSetOfWords("ColorMenuItem4"),
			getSetOfWords("ColorMenuItem5"),
			getSetOfWords("ColorMenuItem6"),
			getSetOfWords("ColorMenuItem7"),
			getSetOfWords("ColorMenuItem8"),
			getSetOfWords("ColorMenuItem9"),
			getSetOfWords("ColorMenuItem10"),
			getSetOfWords("ColorMenuItem11"),
			getSetOfWords("ColorMenuItem12"),
			getSetOfWords("ColorMenuItem13"),
			getSetOfWords("ColorMenuItem14"),
			getSetOfWords("ColorMenuItem15"),
			getSetOfWords("ColorMenuItem16")
		}, 16);
	bool exit2lvl = false;
	while (!exit2lvl)
	{
		string previousText = getSetOfWords("ColorMenuPredTextPart1");
		char *previousColor = new char();
		if (isFont)
		{
			previousText.append(getSetOfWords("ColorMenuPredTextPart2.1"));
			*previousColor = fontColor;
		}
		else
		{
			previousText.append(getSetOfWords("ColorMenuPredTextPart2.2"));
			*previousColor = bgColor;
		}

		switch (colorMenu.use(previousText))
		{
		case 0:	 isFont ? fontColor = '0' : bgColor = '0'; break;
		case 1:	 isFont ? fontColor = '1' : bgColor = '1'; break;
		case 2:	 isFont ? fontColor = '2' : bgColor = '2'; break;
		case 3:	 isFont ? fontColor = '3' : bgColor = '3'; break;
		case 4:	 isFont ? fontColor = '4' : bgColor = '4'; break;
		case 5:	 isFont ? fontColor = '5' : bgColor = '5'; break;
		case 6:	 isFont ? fontColor = '6' : bgColor = '6'; break;
		case 7:	 isFont ? fontColor = '7' : bgColor = '7'; break;
		case 8:	 isFont ? fontColor = '8' : bgColor = '8'; break;
		case 9:	 isFont ? fontColor = '9' : bgColor = '9'; break;
		case 10: isFont ? fontColor = 'a' : bgColor = 'a'; break;
		case 11: isFont ? fontColor = 'b' : bgColor = 'b'; break;
		case 12: isFont ? fontColor = 'c' : bgColor = 'c'; break;
		case 13: isFont ? fontColor = 'd' : bgColor = 'd'; break;
		case 14: isFont ? fontColor = 'e' : bgColor = 'e'; break;
		case 15: isFont ? fontColor = 'f' : bgColor = 'f'; break;
		}

		if (!isFont && fontColor == bgColor)
			fontColor = *previousColor;
		else if (isFont && fontColor == bgColor)
			bgColor = *previousColor;
		else
			exit2lvl = true;
		delete previousColor;
		if (!exit2lvl)
		{
			cout << getSetOfWords("ColorMenuErrorText") << endl;
			system("pause");
		}
	}

	useColorString();
}

void settings::showLanguageMenu()
{
	menu languageMenu(new string[3]
		{
			"English",
			"Русский",
			"Українська"
		}, 3);
	switch (languageMenu.use())
	{
	case 0: language = "en"; break;
	case 1: language = "ru"; break;
	case 2: language = "ua"; break;
	}
	delete sow;
	sow = new setOfWords(*countLangs, getSelectedLanguageId());
}