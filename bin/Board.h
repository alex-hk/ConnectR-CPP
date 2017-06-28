#include <vector>

using namespace std;

struct Board {
private:
	int width = 6, height = 7;
	vector<vector<int>> board;

public:
	Board(int w, int h){
		width = w;
		height = h;
		board = vector<vector<int>>(height, vector<int>(width));
	}

	public int getValue(int row, int col){
		return board[row][col];
	}

	public int setValue(int row, int col, int value){
		board[row][col] = value;
	}

	Board& operator=(const Board &bc){
		if(this == &bc){
			return *this;
		}
		this.width = bc.width;
		this.height = bc.height;
		this.board = bc.board;
	}
}



