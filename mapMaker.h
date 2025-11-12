#ifndef MAP_DEVKIT_H
#define MAP_DEVKIT_H
#include <function>
#include <fstream>
#include <string>
#include <"/public/read.h">
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
        for (char& c : temp) {
            if (c == ',') c = ' ';
        }
        returnMap.push_back(temp);
    }
    return;
}
void setCharacterPosition(vector<int>& currentPos, vector<string>& currentMap, vector<string>& outputMap) {
    set_raw_mode(true);
    show_cursor(false);
    int c = toupper(quick_read());
    int row = currentPos.at(0);
    int col = currentPos.at(1);
    int prevRow = row;
    int prevCol = col;

    if (c == 'W' or c == UP_ARROW) row -= 3;
    if (c == 'S' or c == DOWN_ARROW) row += 3;
    if (c == 'A' or c == LEFT_ARROW) col -= 3;
    if (c == 'D' or c == RIGHT_ARROW) col += 3;


    switch (currentMap.at(row).at(col)) {
    case '-':
    case '|':
    case 'X':
    case 'B':
        row = prevRow;
        col = prevCol;
    }

    currentPos.at(0) = row;
    currentPos.at(1) = col;
    outputMap = currentMap;
    outputMap.at(row - 1).at(col - 1) = 'C';
    outputMap.at(row - 1).at(col) = 'C';
    outputMap.at(row - 1).at(col + 1) = 'C';
    outputMap.at(row).at(col - 1) = 'C';
    outputMap.at(row).at(col) = 'C';
    outputMap.at(row).at(col + 1) = 'C';
    outputMap.at(row + 1).at(col - 1) = 'C';
    outputMap.at(row + 1).at(col) = 'C';
    outputMap.at(row + 1).at(col + 1) = 'C';
}
void printMap(vector<string>& currentMap, vector<int>& currentPlayerPos) {
    const int FPS = 30;
    clearscreen();
    vector<int> prevPlayerPos = currentPlayerPos;
    vector<string> updatedMap = currentMap;
    setCharacterPosition(currentPlayerPos, currentMap, updatedMap);
    for (int i = 0; i < updatedMap.size(); i++) {
        for (int j = 0; j < updatedMap.at(i).size(); j++) {
            char currentChar = updatedMap.at(i).at(j);
            movecursor(i % updatedMap.size() + 1, j % updatedMap.at(i).size() + 1);
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
    //TODO: fix the framerate
    usleep(1'000'000 / FPS);
}
/*
   put something like this in main. player's first position is 35,2
	vector<string> map;
    vector<int> playerPos;
    playerPos.push_back(35);
    playerPos.push_back(2);
    getMap("tutorialMap.csv", map);
    while (true) {
        printMap(map, playerPos);
    }

    return 0;

   */
