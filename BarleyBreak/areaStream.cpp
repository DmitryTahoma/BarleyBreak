#include "header.h"

using namespace std;
using namespace BarleyBreak;

areaStream::areaStream(string filePath)
{
	path = filePath;
}

void areaStream::saveToFile(short **items)
{
	ofstream os(path, ios::binary);

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			os.write((char*)&items[j][i], sizeof(items[j][i]));

	os.close();
}

short** areaStream::loadFromFile()
{
	short** items = new short*[4];
	for (int i = 0; i < 4; ++i)
		items[i] = new short[4];
	ifstream is(path, ios::binary);

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			short t = 0;
			is.read((char*)&t, sizeof(t));
			items[j][i] = t;
		}

	is.close();
	return items;
}

vector<string> areaStream::getAvailableSaves(string path)
{
	vector<string> names;
	WIN32_FIND_DATA fd;

	HANDLE hFind = ::FindFirstFile(path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				names.push_back(fd.cFileName);
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}

	for (int i = 0; i < names.size(); ++i)
		names[i].resize(names[i].size() - 4);

	return names;
}