#pragma once
#include "header.h"

using namespace std;

namespace BarleyBreak
{
	/// <summary>
	/// Vocabulary of sets of words for multilingualism in program.
	/// </summary>
	class setOfWords
	{
	public:

		/// <summary>
		/// setOfWords constructor.
		/// </summary>
		/// <param name="countLanguages">
		/// Count of languages.
		/// </param>
		/// <param name="selectedLanguage">
		/// Index of selected language.
		/// </param>
		setOfWords(unsigned int countLangueages, unsigned int selectedLanguage);

		~setOfWords();

		/// <summary>
		/// Set operator square brackets.
		/// </summary>
		/// <param name="n">
		/// Element index (counting from 0).
		/// </param>
		/// <returns>
		/// Oration on selected langage.
		/// </returns>
		string operator[](int n);

		/// <summary>
		/// Returns count of sets.
		/// </summary>
		/// <returns>
		/// Count of sets.
		/// </returns>
		unsigned int getCountSets();

	private:

		string **sets;
		unsigned int *countSet;
		unsigned int *countLangs;
		unsigned int *selectedLang;

	};
}