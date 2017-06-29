#include "Tree.h"

Tree* Tree::buildTree(){

}

float max(float a, float b){
	return a > b ? a : b;
}

float min(float a, float b){
	return a < b ? a : b;
}

Node* Tree::miniMax(Node* node, int depth, bool maxPlayer){
	if(depth == 0 || node.isLeaf()) return node.getScore();
	
	float value;
	float tempmax;
	if(maxPlayer){
		value = INT_MIN;
		for(int i = 0; i < node->children.size(); i++){
			tempmax = miniMax(node->children[i], depth-1, false);
			value = max(value, tempmax); 
		}
		return value;
	}
	else{
		value = INT_MAX;
		for(int i = 0; i < node->children.size(); i++){
			tempax = miniMax(node->children[i], depth-1, true);
			value = max(value, tempmax);
		}
		return value;
	}
}

int Tree::alphabeta(Node* node, int depth, float alpha, float beta, bool maxPlayer){
	if(depth == 0 || node.isLeaf()) return node.getScore();
	
	float value;
	if(maxPlayer){
		value = INT_MIN;
		for(int i = 0; i < node->children.size(); i++){
			value = max(value, alphabeta(node->children[i], depth-1, alpha, beta, false));
			alpha = max(alpha, value);
			if(beta <= alpha) break;
		}
		return value;
	}
	else{
		value = INT_MAX;
		for(int i = 0; i < node->children.size(); i++){
			value = min(value, alphabeta(node->children[i], depth-1, alpha, beta, true));
			beta = min(beta, value);
			if(beta <= alpha) break;
		}
		return value;
	}

}

