
#include <iostream>
#include <string>
#include <vector>

int ROWS = 6;
int COLS = 7;
enum class situation{
	EMPTY,
	X,
	O};
	
class Board{
public:
	Board(){
		m_board = std::vector<std::vector<situation>>(ROWS, std::vector<situation>(COLS,situation::EMPTY));
	}
	void setX(int row, int col){
		if(!(row >= 0 && row < ROWS && col >= 0 && col < COLS))return;
		m_board[row][col] = situation::X;
	}
	void setY(int row, int col){
		if(!(row >= 0 && row < ROWS && col >= 0 && col < COLS))return;
		m_board[row][col] = situation::Y;
	}
	void draw Board();
			
private:
	std::vector<std::vector<situation>> m_board;
};


int main(){
	Board board = Board();
	std::cout<<int(board.m_board[0][1])<<std::endl;
	return 0;
}
	
