#pragma once
#include "header.h"

using namespace std;

namespace BarleyBreak
{
	/// <summary>
	///	Represents the playing field.
	/// </summary>
	class area
	{
	public:

		/// <summary>
		///	Area constructor.
		/// </summary>
		area();

		area(string filePath);

		~area();

		/// <summary>
		///	Shows the playing field.
		/// </summary>
		void showArea();

		/// <summary>
		///	The method swaps the empty item with the top.
		/// </summary>
		void moveUp();

		/// <summary>
		///	The method swaps the empty item with the left.
		/// </summary>
		void moveLeft();

		/// <summary>
		///	The method swaps the empty item with the bottom.
		/// </summary>
		void moveDown();

		/// <summary>
		///	The method swaps the empty item with the right.
		/// </summary>
		void moveRight();

		/// <summary>
		/// The method determines - a winning attitude?
		/// </summary>
		/// <returns>
		/// Method return true if is winner position,
		/// </returns>
		bool isWinnerPosition();

		/// <summary>
		/// Makes saving.
		/// </summary>
		/// <param name="saveName">
		/// Name of save.
		/// </param>
		void save(string saveName);

	private:
		/// <summary>
		///	Method shuffles the playing field.
		/// </summary>
		/// <param name="countMixing">
		/// Count of mixing.
		/// </param>
		void mixMe(unsigned int *countMixing);

		/// <summary>
		///	Method finds the main cell and saves its coordinates in parameters.
		/// </summary>
		/// <param name="x">
		/// X cord, which will be defined in the method.
		/// </param>
		/// <param name="y">
		/// Y cord, which will be defined in the method.
		/// </param>
		void getMainItem(short *x, short *y);

		short** items;
	};
}