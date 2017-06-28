#include "Game.h"
#include <stdio.h>

void run(){
	
}

bool checkHori(int row, int col, bool player){
	int val = player ? 2 : 1;
	int count = 1;

	int c;
	for(c = col - 1; c >= 0 && c >= col-connect; c--){
		if(board[row][c] == val)
			count++ == connect ? return true : continue;
		else break;	
	}
	for(c = col + 1; c <= width && c <= col+connect; c++){
		if(board[row][c] == val)
			count++ == connect ? return true : continue;
		else break;
	}
	return false;
}

bool checkVert(int row, int col, bool player){
	int val = player ? 2 : 1;
	int count = 1;

	int r;
	for(r = row - 1; r >= 0 && r >= row-connect; r--){
		if(board[r][col] == val)
			count++ == connect ? return true : continue;
		else break;	
	}
	for(r = row + 1; r <= height && r <= row+connect; r++){
		if(board[r][col] == val)
			count++ == connect ? return true : continue;
		else break;
	}
	return false;

}

bool checkDiag(int row, int col, bool player){
	//Check bottom/top left/right
	bool checkbr = true, checkbl = true, checktr = true, checktl = true;
	int val = player ? 2 : 1;
	
	int count = 1;
	
	if(checkbr || checktl){
		if(checkbr){
			for(int r = row+1, int c = col+1;
				(r <= height && r <= row+connect) &&
				(c <= width  && c <= col+connect);
				r++, c++){
				
				if(board[r][c] == val)
					count++ == connect ? return true : continue;
				else break;
			}
			checkbr = false;
		}
		if(checktl){
			for(int r = row-1, int c = col-1;
				(r >= 0 && r >= row-connect) &&
				(c >= 0  && c >= col-connect);
				r--, c--){
				
				if(board[r][c] == val)
					count++ == connect ? return true : continue;
				else break;
			}
			checktl = false;
		}
	}

	count = 1;
	if(checktr || checkbl){
		if(checktr){
			for(int r = row-1, int c = col+1;
				(r >= 0 && r >= row-connect) &&
				(c <= width  && c <= col+connect);
				r--, c++){
				
				if(board[r][c] == val)
					count++ == connect ? return true : continue;
				else break;
			}
			checktr = false;
		}
		if(checkbl){
			for(int r = row, int c = col;
				(r <= height && r <= row+connect) &&
				(c >= 0  && c >= col-connect);
				r++, c--){
				
				if(board[r][c] == val)
					count++ == connect ? return true : continue;
				else break;
			}
			checkbl = false;
		}
	}

	return false;
}
