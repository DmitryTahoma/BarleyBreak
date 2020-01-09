#pragma once
#include "header.h"

using namespace std;

namespace BarleyBreak
{
	/// <summary>
	/// Class settings of program.
	/// </summary>
	class settings
	{
	public:

		/// <summary>
		/// Settings constructor.
		/// </summary>
		settings();

		~settings();

		/// <summary>
		/// The method sets the program interface language.
		/// </summary>
		/// <param name="lang">
		/// Short name of language.
		/// </param>
		void setLanguage(string lang);

		/// <summary>
		/// The method sets the font color.
		/// </summary>
		/// <param name="colorName">
		/// Name of color.
		/// </param>
		void setFontColor(char colorName);

		/// <summary>
		/// The method sets the background color.
		/// </summary>
		/// <param name="colorName">
		/// Name of color.
		/// </param>
		void setBgColor(char colorName);

		/// <summary>
		/// Makes color settings active.
		/// </summary>
		void useColorString();

		/// <summary>
		/// Checks - whether the data is the default settings.
		/// </summary>
		/// <returns>
		/// Are these settings the default.
		/// </returns>
		bool isDefaultSettings();

		/// <summary>
		/// Resets to default settings.
		/// </summary>
		void resetSettings();

		/// <summary>
		/// Check if a language exists.
		/// </summary>
		/// <param name="language">
		/// Name of language.
		/// </param>
		/// <returns>
		/// Returns true if the language exists.
		/// </returns>
		bool existsLanguage(string language);

		/// <summary>
		/// Check if a color exists.
		/// </summary>
		/// <param name="colorName">
		/// Name of color.
		/// </param>
		/// <retruns>
		/// Returns true if the color exists.
		/// </returns>
		bool existsColor(char colorName);

		/// <summary>
		/// Shows the settings menu in the course of which, they can change.
		/// </summary>
		void showMenuSettings();

		/// <summary>
		/// Returns index of selected language.
		/// </summary>
		/// </returns>
		/// Id selected language.
		/// </returns>
		unsigned short getSelectedLanguageId();

		/// <summary>
		/// Returns setOfWords on selected language by association-key.
		/// </summary>
		/// <param name="key">
		/// Association key.
		/// </param>
		/// <returns>
		/// setOfWords on selected language.
		/// </returns>
		string getSetOfWords(string key);

	private:

		/// <summary>
		/// Saves settings to file.
		/// </summary>
		void saveSettingsToFile();

		/// <summary>
		/// Loads settings from file.
		/// </summary>
		void loadSettingsFromFile();

		/// <summary>
		/// Creates associations with setsAssociations.
		/// </summary>
		void createAssotiations();

		/// <summary>
		/// Shows the color menu to change.
		/// </summary>
		/// <param name="isFont">
		/// This menu associated with font color?
		/// </param>
		void showColorMenu(bool isFont);

		/// <summary>
		/// Shows the language menu to change.
		/// </summary>
		void showLanguageMenu();

		string language;
		string *languages;
		unsigned short *countLangs;

		setOfWords *sow;
		string *setsAssociations;

		char fontColor;
		char bgColor;

	};
}