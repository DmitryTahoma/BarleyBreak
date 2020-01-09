#include "header.h"

using namespace std;
using namespace BarleyBreak;

int main()
{
	srand((unsigned int)time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	program *Program = new program();
	Program->start();

	delete Program;
	return 0;
}