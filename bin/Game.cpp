#include "Game.h"
#include <stdio.h>
#include <stdlib.h>

int Game::run(){
	if(gametype == 1){
		return pvarun();
	}else if(gametype == 2){
		return avarun();
	}else{
		return pvprun();
	}
}

int Game::pvprun(){
	int player = 0;
	int row, col;
	printf("Player vs Player chosen...\n");
	printf("Setting up board...\n");
	printf("Press enter to being...\n");
	getchar();
	system("clear");
	gameboard->printBoard();

	do{
		player = (player+1)%2;

		printf("Player %d's turn: ", player+1);
		scanf("%d", &col);
		col-=1;
		row = turn(col, player+1);
		system("clear");
		gameboard->printBoard();


	}while(!checkWin(row, col, player+1));
	
	return player;
}

int Game::pvarun(){
}

int Game::avarun(){
}

int Game::turn(int col, int player){
	if(gameboard->getValue(0, col) != 0){
		printf("Cannot place piece in column %d. Please choose another column.\n", col);
		return -1;
	}

	int row = 0;

	while(row+1 < height && (gameboard->getValue(row+1, col) != 1 && gameboard->getValue(row+1,col) != 2))
		row++;

	gameboard->setValue(row, col, player);
	return row;
}

bool Game::checkHori(int row, int col, int player){
	int val = player;
	int count = 1;
	int connect = this->connect;
	Board* board = this->gameboard;
	int width = this->width;
	int height = this->height;

	int c;
	for(c = col - 1; c >= 0 && c > col-connect; c--){
		if(board->getValue(row,c) == val){
			if(++count == connect) return true;
		} else break;	
	}
	for(c = col + 1; c < width && c < col+connect; c++){
		if(board->getValue(row,c) == val){
			if(++count == connect) return true;
		} else break;
	}
	return false;
}

bool Game::checkVert(int row, int col, int player){
	int val = player;
	int count = 1;
	int connect = this->connect;
	Board* board = this->gameboard;
	int width = this->width;
	int height = this->height;

	int r;
	for(r = row - 1; r >= 0 && r > row-connect; r--){
		if(board->getValue(r,col) == val){
			if(++count == connect) return true;
		} else break;	
	}
	for(r = row + 1; r < height && r < row+connect; r++){
		if(board->getValue(r,col) == val){
			if(++count == connect) return true;
		} else break;
	}
	return false;

}

bool Game::checkDiag(int row, int col, int player){
	//Check bottom/top left/right
	bool checkbr = true, checkbl = true, checktr = true, checktl = true;
	int val = player;
	int connect = this->connect;
	int count = 1;
	Board* board = this->gameboard;
	int width = this->width;
	int height = this->height;

	if(checkbr || checktl){
		if(checkbr){
			for(int r = row+1, c = col+1; (r < height && r < row+connect) && (c < width  && c < col+connect); r++, c++){

				if(board->getValue(r,c) == val){
					if(++count == connect) return true;
				} else break;
			}
			checkbr = false;
		}
		if(checktl){
			for(int r = row-1, c = col-1;
					(r >= 0 && r > row-connect) &&
					(c >= 0  && c > col-connect);
					r--, c--){

				if(board->getValue(r,c) == val){
					if(++count == connect) return true;
				} else break;
			}
			checktl = false;
		}
	}

	count = 1;
	if(checktr || checkbl){
		if(checktr){
			for(int r = row-1, c = col+1;
					(r >= 0 && r > row-connect) &&
					(c < width  && c < col+connect);
					r--, c++){

				if(board->getValue(r,c) == val){
					if(++count == connect) return true;
				} else break;
			}
			checktr = false;
		}
		if(checkbl){
			for(int r = row+1, c = col-1;
					(r < height && r < row+connect) &&
					(c >= 0  && c > col-connect);
					r++, c--){

				if(board->getValue(r,c) == val){
					if(++count == connect) return true;
				} else break;
			}
			checkbl = false;
		}
	}

	return false;
}
