#ifndef Board_hpp
#define Board_hpp

#include "Constants.hpp"
#include "Move.hpp"

#include <array>
#include <utility>
#include <iostream>

class Board {
private:
    std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE> board;
    std::pair<bool, char> isSequenceWinning(std::array<char, BOARD_SIZE> sequence);
    
public:
    Board();
    void copyFrom(Board board);
    std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE> getBoard();
    void setBoard(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE> board);
    void makeMove(Move move);
    std::array<char, BOARD_SIZE> getRow(int row);
    std::array<char, BOARD_SIZE> getColumn(int col);
    char getPieceAtPosition(int row, int col);
    void display();
    std::pair<bool, char> hasGameBeenWon();
};


#endif
