#pragma once
#include "header.h"

namespace BarleyBreak
{
	/// <summary>
	/// The class controls the "area" by pressing the arrows on the keyboard of the player.
	/// </summary>
	class playerControl
	{
	public:

		/// <summary>
		/// PlayerControl constructor.
		/// </summary>
		playerControl();

		/// <summary>
		/// PlayerControl constructor with parameter.
		/// </summary>
		/// <param name="field">
		/// Area, thet the player will control.
		/// </param>
		playerControl(area *field);

		~playerControl();

		/// <summary>
		/// Start to control the area.
		/// </summary>
		/// <returns>
		/// Return true if is winner position.
		/// </returns>
		bool launchControl();

		/// <summary>
		/// Save field to file.
		/// </summary>
		/// <param name="getterNameOfSave">
		/// Text for output for input name of save.
		/// </param>
		/// <param name="errorMsgNameOfSave">
		/// Text for output error message if user input forbidden symbols.
		/// </param>
		/// <param name="saveCompleted">
		/// Text for output if save is done.
		/// </param>
		void save(string getterNameOfSave, string errorMsgNameOfSave, string saveCompleted);

	private:
		area *field;
	};
}