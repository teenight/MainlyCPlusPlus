#ifndef LAB3_NODE_H
#define LAB3_NODE_H

#include <string>

using namespace std;

class Node {
public:
	Node();
	Node(string newName);
	void setNodeName(string newName);
	string getNodeName();
	void attachNewNode(Node *newNode, int direction);
	Node *getAttachedNode(int direction);
	void attachSnakeLadderNode(Node *newNode);
	Node *getSnakeLadderNode();

private:
	string name;
	Node *attachedNodes[4];
	Node *snakeOrLadderNodes;
};


#endif //LAB3_NODE_H
