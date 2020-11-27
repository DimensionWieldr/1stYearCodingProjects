#include "geesespotter_lib.h"

bool isMarked(char * board, std::size_t index);
bool isRevealed(char * board, std::size_t index);
char getValue(char * board, std::size_t index);
void revealNeighbors(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc);

char * createBoard(std::size_t xdim, std::size_t ydim){
	char * board{new char[xdim*ydim]{0}};
	return board;
}

void computeNeighbors(char * board, std::size_t xdim, std::size_t ydim){
	std::size_t index{};
	unsigned int count{};

	for(std::size_t yloc{0}; yloc < ydim; yloc++){
		for(std::size_t xloc{0}; xloc < xdim; xloc++){

			index = xdim*yloc + xloc;
			if(!(board[index] == 9)){

				count = 0;
				for(int i{(int)yloc-1}; i <= (int)yloc+1; i++){
					for(int j{(int)xloc-1}; j <= (int)xloc+1; j++){

						if(i >= 0 && i < (int)ydim && j >= 0 && j < (int)xdim){
							index = xdim*i + j;
							if(board[index] == 9){
								count++;
							}
						}

					}
				}
				index = xdim*yloc + xloc;
				board[index] = count;

			}

		}
	}
}

void hideBoard(char * board, std::size_t xdim, std::size_t ydim){
	for(std::size_t i{0}; i < xdim*ydim; i++){
		//hide i
		board[i] |= hiddenBit();
	}
}

void cleanBoard(char * board){
	delete[] board;
	board = nullptr;
}

void printBoard(char * board, std::size_t xdim, std::size_t ydim){
	for(std::size_t i{0}; i < xdim*ydim; i++){
		if(isMarked(board, i)){
			std::cout << "M";
		}else if(!isRevealed(board, i)){
			std::cout << "*";
		}else{
			std::cout << (unsigned int)board[i];
		}

		//new row
		if((i+1)%xdim == 0){
			std::cout << std::endl;
		}
	}
}

int reveal(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
	std::size_t index{xdim*yloc + xloc};

	if(isMarked(board, index)){
		return 1;
	}

	if(isRevealed(board, index)){
		return 2;
	}

	//if goose
	if(getValue(board, index) == 9){
		board[index] = 9;
		return 9;
	}

	//performs reveal
	board[index] = getValue(board, index);

	if(board[index] == 0){
		revealNeighbors(board, xdim, ydim, xloc, yloc);
	}

	return 0;
}

int mark(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
	std::size_t index{xdim*yloc + xloc};

	if(isRevealed(board, index)){
		return 2;
	}

	//mark/unmark index
	if(isMarked(board, index)){
		board[index] = getValue(board, index);
		board[index] |= hiddenBit();
	}else{
		board[index] |= markedBit();
	}
	return 0;
}

bool isGameWon(char * board, std::size_t xdim, std::size_t ydim){
	for(std::size_t i{0}; i < xdim*ydim; i++){
		//if field is not a goose and is hidden/marked, game is not won
		if((getValue(board, i) != 9) && ((!isRevealed(board, i)) || (isMarked(board, i)))){
			return false;
		}
	}
	//all fields not geese are revealed, so game is won
	return true;
}

bool isMarked(char * board, std::size_t index){
	if((board[index] & markedBit()) == markedBit()){
		return true;
	}
	return false;
}

bool isRevealed(char * board, std::size_t index){
	if((board[index] & hiddenBit()) == hiddenBit()){
		return false;
	}
	return true;
}

char getValue(char * board, std::size_t index){
	return board[index] & valueMask();
}

void revealNeighbors(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
	std::size_t index{};

	for(int i{(int)yloc-1}; i <= (int)yloc+1; i++){
		for(int j{(int)xloc-1}; j <= (int)xloc+1; j++){
			if(i >= 0 && i < (int)ydim && j >= 0 && j < (int)xdim){
				index = xdim*i + j;
				if(!(getValue(board, index) == 9)){
					board[index] = getValue(board, index);
				}
			}
		}
	}
}
