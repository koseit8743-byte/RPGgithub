//Fill out this comment with your names and which bullet points you did
//Partners: DeRaffaele, Romero, Rangel, Osei Tutu,
//Bullet Points: 1,2,3,4,5
//Extra Credit: 2,3
//URL to cover art and music:

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "/public/colors.h"
#include "/public/read.h"
using namespace std;

//START
void printMap(vector<string>& currentMap) {
	clearscreen();
	for (int i = 0; i < currentMap.size(); i++) {
		for (int j = 0; j < currentMap.at(i).size(); j++) {
			char currentChar = currentMap.at(i).at(j);
			if (currentChar == '.') {
				cout << RED;
			} else if (currentChar == 'X') {
				cout << BLUE;
			}
			cout << currentChar;
			resetcolor();
		}
		cout << endl;
	}
}

void getMap(string findMap, vector<string>& returnMap) {
	ifstream ins(findMap);
	if (!ins) {
		cout << "The map: " << findMap << " cannot be found.\nMake sure the name is spelt correctly or points to the correct file location.";
		return;
	}

	while (true) {
		string temp = "";
		temp = readline(ins);
		if (!ins) break;
		//cout << temp << endl;;
		for (char& c : temp) {
			if (c == ',') c = ' ';
		}
		returnMap.push_back(temp);
	}
	return;
}


int main() {
	vector<string> map;
	getMap("tutorialMap.csv", map);
	printMap(map);


	return 0;
}
