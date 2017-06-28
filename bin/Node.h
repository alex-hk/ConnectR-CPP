#include "board.h"

struct Node {
private:
	float weight;
	Board board;
	vector<Board*> children;
public:
	Node(Board b){
		board = b;
	}

}
