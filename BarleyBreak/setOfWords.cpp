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
	sets[1][0] = "Новая игра";
	sets[1][1] = "Настройки";
	sets[1][2] = "Загрузить";
	sets[1][3] = "Выход";
	sets[1][4] = "Продолжить";
	sets[1][5] = "Сохранить";
	sets[1][6] = "Изменить цвет шрифта";
	sets[1][7] = "Изменить цвет фона";
	sets[1][8] = "Изменить язык";
	sets[1][9] = "Назад в главное меню";
	sets[1][10] = "Выберите настройки, которые хотите изменить";
	sets[1][11] = "Черный";
	sets[1][12] = "Синий";
	sets[1][13] = "Зеленый";
	sets[1][14] = "Голубой";
	sets[1][15] = "Красный";
	sets[1][16] = "Лиловый";
	sets[1][17] = "Желтый";
	sets[1][18] = "Белый";
	sets[1][19] = "Серый";
	sets[1][20] = "Светло-синий";
	sets[1][21] = "Светло-зеленый";
	sets[1][22] = "Светло-голубой";
	sets[1][23] = "Светло-красный";
	sets[1][24] = "Светло-лиловый";
	sets[1][25] = "Светло-желтый";
	sets[1][26] = "Ярко-белый";
	sets[1][27] = "Выберите ";
	sets[1][28] = "цвет шрифта";
	sets[1][29] = "цвет фона";
	sets[1][30] = "Цвет шрифта не должен совпадать с цветом фона.";
	sets[1][31] = "Введите название сохранения: ";
	sets[1][32] = "Сохранение не может содержать следующие символы:";
	sets[1][33] = "Сохранение выполнено.";
	// ru
	// UA
	sets[2][0] = "Нова гра";
	sets[2][1] = "Настройки";
	sets[2][2] = "Завантажити";
	sets[2][3] = "Вихід";
	sets[2][4] = "Продовжити";
	sets[2][5] = "Зберегти";
	sets[2][6] = "Змінити колір шрифту";
	sets[2][7] = "Змінити колір фону";
	sets[2][8] = "Змінити мову";
	sets[2][9] = "Назад в главне меню";
	sets[2][10] = "Оберіть настройки, які потрібно змінити";
	sets[2][11] = "Чорний";
	sets[2][12] = "Синій";
	sets[2][13] = "Зелений";
	sets[2][14] = "Голубий";
	sets[2][15] = "Червоний";
	sets[2][16] = "Ліловий";
	sets[2][17] = "Жовтий";
	sets[2][18] = "Білий";
	sets[2][19] = "Сірий";
	sets[2][20] = "Світло-синій";
	sets[2][21] = "Світло-зелений";
	sets[2][22] = "Світло-голубий";
	sets[2][23] = "Світло-червоний";
	sets[2][24] = "Світло-ліловый";
	sets[2][25] = "Світло-жовтий";
	sets[2][26] = "Яскраво-білий";
	sets[2][27] = "Оберіть ";
	sets[2][28] = "колір шрифту";
	sets[2][29] = "колір фону";
	sets[2][30] = "Колір шрифту не повинен збігатися з кольором фону.";
	sets[2][31] = "Введіть назву збереження: ";
	sets[2][32] = "Збереження не може містити наступні символи:";
	sets[2][33] = "Збереження виконано.";
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