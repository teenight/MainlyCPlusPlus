// Lab 3:       L3
// Name:        Zejian Zhong
// Class:       COMP 2710 Section 2
// Date:        11/15/2017
// E-Mail:      zzz0065@auburn.edu
//
// Description: This program names multi-player snakes and ladderse maze game that let players compete in a selected map.

#include <iostream>
#include "MazeCreator.h"
#include <cstdlib>
#include <string>
#include <limits>

using namespace std;

MazeCreator map;

int main() {

	cout << "\t===========================================================" << endl;
	cout << "\t|      Welcome to the Snakes and Ladders Maze Game        |" << endl;
	cout << "\t===========================================================" << endl;
	/*cout << "\nEnter the number of players: ";
	int count;
	cin >> count;
	vector<string> name(count);
	for (int i = 0; i < count; i++) {
		cout << "Enter the name of Player#" + to_string(i + 1) + ": ";
		cin >> name[i];
	}
	for (int i = 0; i < count; i++) {
		cout << "=====================" << endl;
		cout << "|    " + name[i] + "’s turn    |" << endl;
		cout << "=====================" << endl;
		cout << name[i] + "'s turn to throw the dice, just hit enter" << endl;
		cin.ignore();
		int dice = rand() % 6 + 1;
		cout << name[i] + "'s Dice throw is " + to_string(dice) << endl;
		cout << name[i] + " can move to " + to_string(dice) + " nodes" << endl;
		map.possiblePaths;
	}*/
	map.createMaze();
	if (map.traversal()) {
		return 1;
	}
}
