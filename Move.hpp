//
//  Move.hpp
//  TicTacToe
//
//  Created by Severn Lortie on 2021-07-20.
//

#ifndef Move_hpp
#define Move_hpp

#include <array>

class Move {
    
private:
    // Holds X or O
    char piece;
    
    // Position on the board
    std::array<int, 2> position;
    
public:
    void setMove(int row, int col, char piece);
    char getPiece();
    std::array<int, 2> getPosition();
};

#endif
