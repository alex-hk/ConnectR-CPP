#include "Board.h"
#include "Agent.h"
#include <stdio.h>
#include <stdlib.h>

struct Game{
private:
	int width, height, connect;
	float time;
	
	/* Gametype:
	 * 0 - Player vs Player
	 * 1 - Player vs AI
	 * 2 - AI vs AI
	 *
	 * Anything below 0 and above 2 will be PvAI
	 *
	 */
	int gametype;
	Board* gameboard;

public:
	Game(int width = 6, int height = 7, int connect = 4, int gt = 0){
		this->width = width;
		this->height = height;
		this->connect = connect;
		this->gametype = gt;
	}

	~Game(){
		delete gameboard;
	}

	// Handles runtype
	int run();

	// Handles Player vs Player
	int pvprun();

	// Handles Player vs Agent 
	int pvarun();

	// Handles Agent vs Agent
	int avarun();


	void init(){
		gameboard = new Board(width, height);	
	}
	bool checkWin(int row, int col, int player){
		if(checkHori(row,col, player) || checkVert(row,col, player) || checkDiag(row,col, player)) return true;
		else return false;
	}
	bool checkHori(int row, int col, int player);
	bool checkVert(int row, int col, int player);
	bool checkDiag(int row, int col, int player);
	int turn(int col, int player);
};
