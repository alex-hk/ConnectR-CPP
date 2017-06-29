#include "Node.h"

struct Tree{
private:
	Node* root;
public:
	Tree();
	~Tree();
	Tree* buildTree();
	Node* miniMax(Node* node, int depth, bool maxPlayer);
	Node* alphabeta(Node* node, int depth, float alpha, float beta, bool maxPlayer);
};
