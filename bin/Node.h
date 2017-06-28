#include "board.h"
#include <vector>

struct Node {
private:
	float weight;
	Board board;
	vector<Node*> children;
public:
	Node(Board b){
		board = b;
	}

	~Node(){
		delete board;
		vector<Node*>().swap(children);	
	}

	void addChild(Node *n){
		children.push_back(n);
	}

};
