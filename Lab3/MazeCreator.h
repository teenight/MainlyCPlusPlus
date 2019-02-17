#ifndef LAB3_MAZECREATOR_H
#define LAB3_MAZECREATOR_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include "Node.h"

typedef Node* NodePointer;

using namespace std;

class MazeCreator {
public:
	NodePointer createMaze();

	bool traversal();
private:
	Node *search(Node *head, string target);
	int numberOfColumns(string fileName);
	bool contains(vector<char> characters, char target);
	void mapLayout(int column, int row);
	void attachPoints(string connectionPoints, string start, string finish);
	int possiblePaths(string paths, string location);
	void ending(string path, int steps);
	void endingForLosers(string path, int steps);
	NodePointer find(string nodeName);
	NodePointer startPoint();
	NodePointer finishPoint();

	NodePointer *nodeArray;
	NodePointer head, tail;
	string path;
	int steps;

};


#endif //LAB3_MAZECREATOR_H
