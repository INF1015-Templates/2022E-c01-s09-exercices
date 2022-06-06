#pragma once


#pragma region "Includes" //{

#include <cstddef>
#include <cstdint>
#include <new>

#include <ostream>
#include <memory>
#include <iomanip>
#include <vector>
#include <deque>
#include <stack>
#include <span>
#include <unordered_map>

#include <cppitertools/itertools.hpp>
#include <cppitertools/zip.hpp>

using namespace std;
using namespace iter;

#pragma endregion //}


bool checkBrackets(const string& text, span<const char> brackets) {
	if (brackets.size() % 2 == 1)
		return false;
	// Associer les ouvrantes et fermantes à l'aide deux hash map (dictionnaires).
	unordered_map<char, char> openingBrackets; // Ouvrants à fermants
	unordered_map<char, char> closingBrackets; // Fermants à ouvrants
	for (auto i : range(0, (int)brackets.size(), 2)) {
		auto& opening = brackets[i];
		auto& closing = brackets[i + 1];
		openingBrackets[opening] = closing;
		closingBrackets[closing] = opening;
	}

	// Vérifier les ouvertures/fermetures
	stack<char> bracketStack;
	// Pour chaque char de la string
	for (auto&& c : text) {
		// Si ouvrant:
		if (openingBrackets.contains(c)) {
			// On empile
			bracketStack.push(c);
		// Si fermant
		} else if (closingBrackets.contains(c)) {
			// Si la pile est vide ou on n'a pas l'ouvrant associé au top de la pile
			if (bracketStack.empty() or bracketStack.top() != closingBrackets.at(c)) {
				// Pas bon
				return false;
			}
			// On dépile
			bracketStack.pop();
		}
	}
	// On vérifie que la pile est vide à la fin (au cas où il y aurait des ouvrants de trop)
	return bracketStack.empty();
}

