#include <vector>
#include <stdio.h>

using namespace std;

struct Board {
	private:
		int count = 0;
		int width = 6, height = 7;
		vector<vector<int>> board;

	public:
		Board(int w, int h){
			width = w;
			height = h;
			board = vector<vector<int>>(height, vector<int>(width));
		}

		~Board(){
			board.erase(board.begin(), board.end());
		}

		int getValue(int row, int col){
			if((row < height && row >= 0) && (col < width && col >= 0))
				return board[row][col];
			else return -1;
		}

		int setValue(int row, int col, int value){
			if(row < height && col < width){
				board[row][col] = value;
				count++;
				return 1;
			}
			return 0;
		}

		Board& operator=(const Board &bc){
			if(this == &bc){
				return *this;
			}
			this->count = bc.count;
			this->width = bc.width;
			this->height = bc.height;
			this->board = bc.board;

			return *this;
		}

		void printBoard(){
			for(int row = 0; row < board.size(); row++){
				for(int col = 0; col < board[row].size(); col++){
					printf("%d",board[row][col]);
				}
				printf("\n");
			}
			printf("\n");
		}
};
