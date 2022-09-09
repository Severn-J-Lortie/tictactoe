#include "Move.hpp"

// Set the move this move object represents
void Move::setMove(int row, int col, char piece) {
    position.at(0) = row;
    position.at(1) = col;
    this->piece = piece;
}

char Move::getPiece() {
    return piece;
}

std::array<int, 2> Move::getPosition() {
    return position;
}
