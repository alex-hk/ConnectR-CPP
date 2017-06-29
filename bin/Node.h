#include "board.h"
#include <vector>

struct Node {
private:
	float weight;
	int move;
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

	void removeChild(Node *root, int index){
		children.erase(children.begin()+index);
	}

	void removeAllButOne(int index){
		for(int i = children.size()-1; i >= 0; i--){
			if(children.size() == 1) return;
			if(i != index)
				children.erase(children.begin()+i);
		}	
	}

};
