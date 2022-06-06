///
/// Ce projet utilise quelques librairies disponibles sur Vcpkg et permet entre autre d'en tester le bon fonctionnement.
///


#include <cstddef>
#include <cstdint>

#include <array>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <span>
#include <utility>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <cppitertools/itertools.hpp>
#include <cppitertools/zip.hpp>

#include "MyClass.hpp"
#include "List.hpp"
#include "brackets.hpp"
#include "School.hpp"

using namespace std;
using namespace iter;


void runBracketsExample() {
	char brackets[] = {'(', ')', '{', '}', '[', ']'};
	string yeet = "(yeet){yeet}";
	string yeeet = "({yeet})";
	string yeeeet = "({yeet)}";
	string yeeeeet = "(yeet";
	cout << checkBrackets(yeet, brackets) << "\n";
	cout << checkBrackets(yeeet, brackets) << "\n";
	cout << checkBrackets(yeeeet, brackets) << "\n";
	cout << checkBrackets(yeeeeet, brackets) << "\n";
}

void runSchoolExample() {
	School school;
	Professor prof(0xC0FFEE);
	school.addNewGrad(0xDEADBEEF, "Marjolaine", "Perreault", "Infologie", &prof);
	GraduateStudent& foo = *school.findGrad(0xDEADBEEF);
	Student& bar = foo;
	foo.changeSupervisor(nullptr);
	foo.updateGpa(2.5);
	bar.updateGpa(3.8);
	bar.changeProgram("whatever idk my life is meaningless");
}

void runListExample() {
	unordered_map<List<int>, string> myMap = {
		{{0xDEAD, 0xBEEF}, "mooo"},
		{{0xFED, 0xBABE, 0xBAD, 0xC0FFEE}, "oops"},
		{{420, 69}, "nice"}
	};

	cout << myMap.contains({420, 69}) << "\n";
	cout << myMap.contains({69, 420}) << "\n";
	cout << myMap.at({0xDEAD, 0xBEEF}) << "\n";
	map<List<int>, string> myMap2 = {
		{{0xDEAD, 0xBEEF}, "mooo"},
		{{0xFED, 0xBABE, 0xBAD, 0xC0FFEE}, "oops"},
		{{420, 69}, "nice"}
	};
}


int main() {
	cout.setf(ios::boolalpha);

	runBracketsExample(); cout << "\n\n\n\n";
	runSchoolExample(); cout << "\n\n\n\n";
	runListExample(); cout << "\n\n\n\n";
}

