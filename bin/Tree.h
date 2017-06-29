#include "Node.h"

struct Tree{
private:
	Node* root;
public:
	Tree();
	~Tree();
	Tree buildTree();
};
