#pragma once
#include "header.h"

namespace BarleyBreak
{
	/// <summary>
	/// Main program.
	/// </summary>
	class program
	{
	public:

		/// <summary>
		/// Program constructor.
		/// </summary>
		program();

		~program();

		/// <summary>
		/// Program starts.
		/// </summary>
		void start();

	private:

		/// <summary>
		/// Initializes the main menu.
		/// </summary>
		void uploadMainMenu();

		/// <summary>
		/// Returns the selected menu item.
		/// </summary>
		/// <returns>
		/// Selected menu item.
		/// </returns>
		unsigned int getUsedMenu();

		/// <summary>
		/// Starts or resumes game.
		/// </summary>
		void startOrResume();

		/// <summary>
		/// Displays the settings menu.
		/// </summary>
		void updateSettings();

		/// <summary>
		/// Loads save.
		/// </summary>
		void loadSave();

		/// <summary>
		/// Starts control with playing field.
		/// </summary>
		void play();

		/// <summary>
		/// Creates a new game.
		/// </summary>
		void createNewGame();

		playerControl *p;

		settings *Settings;
		bool *exit;
		menu *mainMenu;

		unsigned short *langId;
		bool *updateLang;
	};
}