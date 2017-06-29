#include "Game.h"

int main(int argc, char* argv[]){
	int winner;
	
	Game* game = new Game(6,7, 4, 0);
	game->init();
	
	winner = game->run();

	printf("Player %d is the winner!\n", winner+1);
	return 0;
}
