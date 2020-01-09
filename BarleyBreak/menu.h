#pragma once
#include "header.h"

using namespace std;

namespace BarleyBreak
{
	/// <summary>
	/// Menu controlled by arrow buttons.
	/// </summary>
	class menu
	{
	public:

		/// <summary>
		///	Menu constructor.
		/// </summary>
		/// <param name="items">
		///	An array of strings to display in the menu.
		/// </param>
		/// <param name="countItems">
		///	Length of items array.
		/// </param>
		menu(string items[], unsigned int countItems);

		~menu();

		/// <summary>
		/// Menu call method.
		/// </summary>
		/// <param name="predText">
		///	The text that will be displayed in front of the menu.
		/// </param>
		/// <returns>
		/// Return number selected menu item (counting from 0).
		/// </returns>
		unsigned int use(string predText = "") const;

		/// <summary>
		/// Set operator square brackets.
		/// </summary>
		/// <param name="n">
		/// Element index (counting from 0).
		/// </param>
		/// <returns>
		/// Reference to menu item with index n.
		/// </returns>
		string* operator[](int n);

		/// <summary>
		/// Adds item on position in menu.
		/// </summary>
		/// <param name="value">
		/// New item, which will added.
		/// </param>
		/// <param name="position">
		/// Position new item. HINT: if position less 0, then value has been added ahead of all; if position >= count elements in menu, then value has been added behind all.
		/// </param>
		void addItem(string value, int position = -1);

		/// <summary>
		/// Removes an item from menu.
		/// </summary>
		/// <param name="item">
		/// Item to delete.
		/// </param>
		void removeItem(string item);

		/// <summary>
		/// Removes an item from menu.
		/// </summary>
		/// <param name="index">
		/// Index of item to delete (counting from 0).
		/// </param>
		void removeItem(unsigned int index);

		/// <summary>
		/// Returns count of items.
		/// </summary>
		/// <returns>
		/// Count of items.
		/// </returns>
		unsigned int getCount();

	private:

		/// <summary>
		///	Method that displays the menu.
		/// </summary>
		/// <param name="p">
		///	Number selected menu item.
		/// </param>
		/// <param name="predText">
		///	The text that will be displayed in front of the menu.
		/// </param>
		void showMenu(int *p, string predText) const;

		unsigned int *count;
		string *items;
	};
}