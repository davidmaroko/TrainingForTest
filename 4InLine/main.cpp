#include <iostream>
#include <string>
#include <vector>

int ROWS = 6;
int COLS = 7;
enum class Situation{
	EMPTY,
	X,
	O
};

std::string to_string(Situation situation){
	switch(situation){
		case Situation::X: return "X";
		case Situation::O: return "O";
		default: return " ";
	}
}
	
class Board{
public:
	Board(){
		m_board = std::vector<std::vector<Situation>>(ROWS, std::vector<Situation>(COLS,Situation::EMPTY));
	}
	void setX(int row, int col){
		if(!(row >= 0 && row < ROWS && col >= 0 && col < COLS))return;
		m_board[row][col] = Situation::X;
	}
	void setY(int row, int col){
		if(!(row >= 0 && row < ROWS && col >= 0 && col < COLS))return;
		m_board[row][col] = Situation::O;
	}
	void draw_board(){
		for (int i = 0; i < m_board.size(); ++i) {
			std::cout << i+1 << " ";
			for(auto& situation : m_board[i]) {
				std::cout<<"["<< to_string(situation)<<"] ";
			}
			std::cout<<std::endl;
		}
		std::cout << "  ";
		for (int i = 0; i < m_board[0].size(); ++i)
			std::cout << " " << i+1 << "  ";
		std::cout << std::endl;
	}
				
			
private:
	std::vector<std::vector<Situation>> m_board;
};


int main(){
	Board board = Board();
	board.draw_board();
	return 0;
}
	
