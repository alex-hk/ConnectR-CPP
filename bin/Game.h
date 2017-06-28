#include "Board.h"
#include <stdio.h>
#include <stdlib.h>

struct Game{
private:
	int width, height, connect;
	Board* gameboard;

public:
	Game(int width, int height){
		this->width = width;
		this->height = height;
	}
	void run();
	void init(){
		gameboard = new Board(width, height);	
	}
	bool checkWin(int row, int col){
		if(checkHori(row,col) && checkVert(row,col) && checkDiag(row,col)) return true;
		else return false;
	}
	bool checkHori(int row, int col);
	bool checkVert(int row, int col);
	bool checkDiag(int row, int col);
	void turn(int row, int col);
};
