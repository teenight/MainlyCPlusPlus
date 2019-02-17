#include "MazeCreator.h"

NodePointer MazeCreator::createMaze() {
	ifstream file;
	string fileName;
	cout << "Please enter file name: ";
	getline(cin, fileName);
	file.open(fileName.c_str());

	if (!file.fail()) {
		int numberOfNodes;
		file >> numberOfNodes;
		string startingPoint;
		file >> startingPoint;
		string finish;
		file >> finish;
		int numberOfPointersToMake;
		numberOfPointersToMake = numberOfColumns(fileName);
		nodeArray = new NodePointer[numberOfPointersToMake];
		int numberOfRows = numberOfNodes / numberOfPointersToMake;
		for (int i = 0; i < numberOfPointersToMake; i++) {
			nodeArray[i] = new Node[numberOfRows];
		}
		mapLayout(numberOfPointersToMake, numberOfRows);
		string connectionPoints;
		getline(file, connectionPoints);

		while (!file.eof()) {
			getline(file, connectionPoints);
			attachPoints(connectionPoints, startingPoint, finish);
		}
	}
	file.close();
	return head;
}

Node *MazeCreator::search(Node *head, string target) {
	Node *here = head;
	for (int i = 0; i < 4; i++) {
		if (here->getAttachedNode(i) != NULL && here->getNodeName() != target) {
			here = here->getAttachedNode(i);
			search(here, target);
		}
		else
			return here;
	}
	return NULL;
}

int MazeCreator::numberOfColumns(string fileName) {
	ifstream file;
	file.open(fileName.c_str());
	vector<char> chars;
	for(int i = 0; i < 3; i++) {
		string temp;
		getline(file, temp);
	}
	while(1){
		string stringForChars;
		getline(file, stringForChars);
		char temp = stringForChars[0];
		if (!contains(chars,temp)){
			chars.push_back(temp);
		}
		else {
			file.close();
			break;
		}
	}
	return chars.size();
}

bool MazeCreator::contains(vector<char> characters, char target) {
	for(int i = 0; i < characters.size(); i++){
		if(characters[i] == target){
			return true;
		}
	}
	return false;
}

void MazeCreator::mapLayout(int column, int row) {
	for(int i = 0; i < column; i++){
		char temp = (char) (i + 65);
		stringstream ss;
		ss << temp;
		string combination;
		ss >> combination;
		for(int j = 0; j < row; j++){
			stringstream ss2;
			string name;
			ss2 << j + 1;
			string temp2;
			ss2 >> temp2;
			name = combination + temp2;
			nodeArray[i][j].setNodeName(name);
		}
	}
}

void MazeCreator::attachPoints(string connectionPoints, string start, string finish) {
	NodePointer node = NULL;
	stringstream ss;
	ss << connectionPoints;
	string checker;
	for(int i = -1; i < 6; i++){
		ss >> checker;
		if(i == -1) {
			node = find(checker);
			if(node->getNodeName() == start)
				head = node;
			if(node->getNodeName() == finish)
				tail = node;
			i++;
			continue;
		}
		if ("*" != checker && i <= 4){
			NodePointer nodeAttachment;
			nodeAttachment = find(checker);
			node->attachNewNode(nodeAttachment, i - 1);
			continue;
		}
		if (i > 4) {
			NodePointer nodeAttachment;
			if (checker == "*")
				nodeAttachment = NULL;
			else
				nodeAttachment = find(checker);
			node->attachSnakeLadderNode(nodeAttachment);
			continue;
		}
		else
			node->attachNewNode(NULL, i - 1);
	}
}

NodePointer MazeCreator::find(string nodeName) {
	char part1 = nodeName[0];
	int part2 = nodeName[1] - 49;
	int column = part1 - 65;
	NodePointer node = &nodeArray[column][part2];
	return node;
}

NodePointer MazeCreator::startPoint() {
	return head;
}

NodePointer MazeCreator::finishPoint() {
	return tail;
}

bool MazeCreator::traversal() {
	steps = 1;
	NodePointer node;
	node = startPoint();
	path = node->getNodeName() + " ";
	while (node->getNodeName() != finishPoint()->getNodeName()){
		string possibleDirections;
		NodePointer temp;
		if(node->getSnakeLadderNode() != NULL) {
			temp = node->getSnakeLadderNode();
			node = temp;
			path += node->getNodeName() + " ";
		}
		else {
			int test = 0;
			for(int i = 0; i < 4; i++){
				temp = node->getAttachedNode(i);
				if(temp != NULL){
					if(test > 0){
						possibleDirections += " or ";
					}
					test++;
					if(i == 0){
						possibleDirections += "North";
					}
					if(i == 1){
						possibleDirections += "East";
					}
					if(i == 2){
						possibleDirections += "South";
					}
					if(i == 3){
						possibleDirections += "West";
					}
				}
			}
			int pathChosen =  possiblePaths(possibleDirections, node->getNodeName());
			if (pathChosen == -1) {
				return false;
			}

			node = node->getAttachedNode(pathChosen);
			path += node->getNodeName() + " ";
			steps++;
		}

	}
	steps++;
	ending(path, steps);
	return true;
}

int MazeCreator::possiblePaths(string paths, string location) {
	string choice;
	while(1) {
		cout << "You are currently in Node " + location + " of the Maze Game, you can go " + paths + ". What is your choice? ";
		cin >> choice;
		cout << endl;
		if (choice == "N" || choice == "S" || choice == "E" || choice == "W")
			break;
		else
			cout << "Invalid input: Possible inputs are N, S, E or W" << endl;
	}
	int direction = -1;
	if (choice == "N"){
		direction = 0;
	}
	if (choice == "E"){
		direction = 1;
	}
	if (choice == "S"){
		direction = 2;
	}
	if (choice == "W"){
		direction = 3;
	}
	return direction;
}

void MazeCreator::ending(string path, int steps) {
	stringstream ss;
	ss << steps;
	string temp;
	ss >> temp;
	cout << string("Congratulations, you are the winner! You have reached the destination point.") << endl;
	cout << "You took " + temp + " steps." << endl;
	cout << "The nodes you visited are : " + path << endl;
}
