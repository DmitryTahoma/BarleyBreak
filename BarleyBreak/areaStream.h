#pragma once
#include "header.h"

using namespace std;

namespace BarleyBreak
{
	/// <summary>
	/// File stream for area.
	/// </summary>
	class areaStream
	{
	public:

		/// <summary>
		/// areaStream constructor.
		/// </summary>
		/// <param name="filePath">
		/// Path to file.
		/// </param>
		areaStream(string filePath);

		/// <summary>
		/// Makes a save to file.
		/// </summary>
		/// <param name="items">
		/// Items for save.
		/// </param>
		void saveToFile(short **items);

		/// <summary>
		/// Loads items from file.
		/// </summary>
		/// <returns>
		/// Items from file.
		/// </returns>
		short** loadFromFile();

		static vector<string> getAvailableSaves(string path);

	private:

		string path;
	};
}