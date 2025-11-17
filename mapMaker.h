#ifndef MAP_DEVKIT_H
#define MAP_DEVKIT_H
#include <fstream>
#include <string>
#include "/public/read.h"
using namespace std;

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
        for (int i = 0; i < temp.size(); i++) {
			if(temp.at(i) == ','){
				for (int j = i; j < temp.size() - 1; j++){
					temp.at(j) = temp.at(j + 1);
				}
			}
        }
        returnMap.push_back(temp);
    }
    return;
}
bool setCharacterPosition(vector<int>& currentPos, vector<string>& outputMap, char characterLetter, bool movementOverride = false) {
    set_raw_mode(true);
    show_cursor(false);
    int c = toupper(quick_read());
    int row = currentPos.at(0);
    int col = currentPos.at(1);
    int prevRow = row;
    int prevCol = col;
	if(!movementOverride){
		if (c == ERR) return false;
		if (c == 'W' or c == UP_ARROW) row -= 3;
		if (c == 'S' or c == DOWN_ARROW) row += 3;
		if (c == 'A' or c == LEFT_ARROW) col -= 3;
		if (c == 'D' or c == RIGHT_ARROW) col += 3;
	}
	if(row < 0 || col < 0 || row >= outputMap.size() || col >= outputMap.at(0).size()) return false;
    switch (outputMap.at(row).at(col)) {
    case '-':
    case '|':
    case 'X':
    case 'B':
		return false;
    }

    currentPos.at(0) = row;
    currentPos.at(1) = col;
    outputMap.at(row - 1).at(col - 1) = characterLetter;
    outputMap.at(row - 1).at(col) = characterLetter;
    outputMap.at(row - 1).at(col + 1) = characterLetter;
    outputMap.at(row).at(col - 1) = characterLetter;
    outputMap.at(row).at(col) = characterLetter;
    outputMap.at(row).at(col + 1) = characterLetter;
    outputMap.at(row + 1).at(col - 1) = characterLetter;
    outputMap.at(row + 1).at(col) = characterLetter;
    outputMap.at(row + 1).at(col + 1) = characterLetter;
	return true;
}
void updateMap(vector<string>& currentMap, vector<vector<int>>& currentCharacterPos, vector<char> characterLetterList) {
    const int FPS = 30;
    //vector<int> prevPlayerPos = currentPlayerPos;
	vector<vector<int>> prevCharacterPos = currentCharacterPos;
    vector<string> updatedMap = currentMap;
	bool hasMoved = false;
	for(int i = 0; i < currentCharacterPos.size(); i++){
		bool movement = setCharacterPosition(currentCharacterPos.at(i), updatedMap, characterLetterList.at(i));
		if(movement) hasMoved = true;
	}
    if(!hasMoved){
		usleep(1'000'000 / FPS);
		return;
	}
	for(int i = 0; i < currentCharacterPos.size(); i++){
		if(currentCharacterPos.at(i) == prevCharacterPos.at(i)) continue;
		else{
			for(int j = prevCharacterPos.at(i).at(0) - 1; j < prevCharacterPos.at(i).at(0) + 2; j++){
				for(int k = prevCharacterPos.at(i).at(1) - 1; k < prevCharacterPos.at(i).at(1) + 2; k++){
					char currentChar = updatedMap.at(j).at(k);
					movecursor(j % currentMap.size() + 1, k % currentMap.at(j).size() + 1);
					if(currentChar == '.'){
                        cout << RED;
                    } else if (currentChar == 'X'){
                        cout << BLUE;
                    } else if (currentChar == 'C'){
                        cout << YELLOW;
                    } else if (currentChar == 'T'){
                        cout << GREEN;
                    } else if (currentChar == 'E'){
                        cout << MAGENTA;
                    }

					cout << currentMap.at(j).at(k);
					resetcolor();
				}
			}
			for(int j = currentCharacterPos.at(i).at(0) - 1; j < currentCharacterPos.at(i).at(0) + 2; j++){
				for(int k = currentCharacterPos.at(i).at(1) - 1; k < currentCharacterPos.at(i).at(1) + 2; k++){
					char currentChar = updatedMap.at(j).at(k);
					movecursor(j % currentMap.size() + 1, k % currentMap.at(j).size() + 1);
					if(currentChar == '.'){
						cout << RED;
					} else if (currentChar == 'X'){
						cout << BLUE;
					} else if (currentChar == 'C'){
						cout << YELLOW;
					} else if (currentChar == 'T'){
						cout << GREEN;
					} else if (currentChar == 'E'){
						cout << MAGENTA;
					}
					cout << updatedMap.at(j).at(k);
					resetcolor();
				}
			}
		}
	}

    //TODO: fix the framerate
    usleep(1'000'000 / FPS);
}
void printMap(vector<string>& currentMap, vector<vector<int>>& currentPlayerPos, vector<char> characterLetterList){
	for(int i = 0; i < currentMap.size(); i++){
		for(int j = 0; j < currentMap.at(i).size(); j++){
			char currentChar = currentMap.at(i).at(j);
			movecursor(i % currentMap.size() + 1, j % currentMap.at(i).size() + 1);
			if(currentChar == '.'){
                        cout << RED;
                    } else if (currentChar == 'X'){
                        cout << BLUE;
                    } else if (currentChar == 'C'){
                        cout << YELLOW;
                    } else if (currentChar == 'T'){
                        cout << GREEN;
                    } else if (currentChar == 'E'){
                        cout << MAGENTA;
                    }

			cout << currentChar;
			resetcolor();
		}
	}
}
/*
   put something like this in main. player's first position is 35,2
vector<string> map;
    vector<vector<int>> characterPos;

    vector<char> characterLetters;
    //just used to put stuff in characterPos
    vector<int> tempIntVec;
    tempIntVec.push_back(35);
    tempIntVec.push_back(2);
    characterPos.push_back(tempIntVec);
    //
    characterLetters.push_back('C');
    getMap("tutorialMap.csv", map);
    cout << characterPos.at(0).at(0);
    printMap(map, characterPos, characterLetters);
    while (true) {
        updateMap(map, characterPos, characterLetters);
    }
	
   */
#endif
